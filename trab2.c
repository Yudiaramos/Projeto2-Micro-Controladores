char counter = 0;
int TH;  // HIGH Timer0
int TL;  // LOW Timer0

void configMCU(){
  // pinos digitais
  ADCON1 |= 0X0F;

  TRISB.RB0 = 1; // define pino 0 da porta B como entrada
  TRISB.RB1 = 1; // define pino 1 da porta B como entrada
  TRISD = 0;  // define porta D como Display

  PORTD = 0;  // Display inicialmente apagado
}
void displayNumbers(unsigned char counter){
    if (counter < 0 || counter > 9) {
        LATD = 0x00;  // Desliga todos os segmentos se inválido
        return;
    }
    // Tabela de correspondência para os dígitos 0 a 9 em um display de 7 segmentos comum anodo
    switch(counter){
              case 0:
                   LATD = 0b00111111;
                   break;
              case 1:
                   LATD = 0b00000110;
                   break;
              case 2:
                   LATD = 0b01011011;
                   break;
              case 3:
                   LATD = 0b01001111;
                   break;
              case 4:
                   LATD = 0b01100110;
                   break;
              case 5:
                   LATD = 0b01101101;
                   break;
              case 6:
                   LATD = 0b01111101;
                   break;
              case 7:
                   LATD = 0b00000111;
                   break;
              case 8:
                   LATD = 0b01111111;
                   break;
              case 9:
                   LATD = 0b01101111;
                   break;
              default:
                   break;
     }
}

void interrupcaoSetup(){         // setup das interrupções
     INTCON.GIEH = 1; // Alta prioridade
     INTCON.INT0IE = 1;  //  interrupcao especifica INT0
     INTCON3.INT1IE = 1;  // interrupcao especifica INT1
     INTCON.TMR0IE = 1;   //interrupcao individual do TIMER0

     INTCON.INT0IF = 0;    //Flag responsavel em gerar/acionar a interrupcao
     INTCON3.INT1IF = 0;    //Flag acionar a interrupcao

     RCON.IPEN = 1;  //  niveis de prioridade
     INTCON2.TMR0IP = 1;  // TIMER0 = alta prioridade
     INTCON3.INT1IP = 1;       // Coloca INT1 como alta prioridade

     INTCON2.INTEDG0 = 1;  // Borda de subida
     INTCON2.INTEDG1 = 1;  // Borda de subida
}


// Rotina de interrupção de alta prioridade
void INTERRUPT_HIGH() iv 0x0008 ics ICS_AUTO {
    //interrupção do Timer0
    if (INTCON.TMR0IF == 1) {
        counter++;  // Incrementa o counter
        if (counter >= 10) counter = 0; // Reseta se alcançar 10

        displayNumbers(counter);  // Atualiza o display

        // Reinicializa o Timer0
        T0CON.TMR0ON = 0;   // Desativa temporariamente para configuração
        TMR0H = TH;         // Configura valor alto
        TMR0L = TL;         // Configura valor baixo
        T0CON.TMR0ON = 1;   // Reativa o Timer0

        INTCON.TMR0IF = 0;  // Limpa a flag de interrupção
    }

    // interrupção do botão INT0 (RB0)
    if (INTCON.INT0IF == 1) {
        // Configura Timer0 para 1 segundo
        TH = 0x0B;
        TL = 0xDC;

        // Reinicializa o Timer0
        T0CON.TMR0ON = 0;
        TMR0H = TH;
        TMR0L = TL;
        T0CON.TMR0ON = 1;
        INTCON.INT0IF = 0;  // Limpa a flag de interrupção
    }

    // interrupção do botão INT1 (RB1)
    if (INTCON3.INT1IF == 1) {
        // Configura Timer0 para 0.25 segundo
        TH = 0xC2;
        TL = 0xF7;

        // Reinicializa o Timer0
        T0CON.TMR0ON = 0;
        TMR0H = TH;
        TMR0L = TL;
        T0CON.TMR0ON = 1;
        INTCON3.INT1IF = 0; // Limpa a flag de interrupção
    }
}




void main() {
    // Configuração da entrada - Botões RB0 e RB1
    configMCU();

    T0CON = 0b00000100;  //TIMER_OFF, MOD_16BITS, TIMER, PRES_1:32

    interrupcaoSetup();

    INTCON.TMR0IF = 0;  //zera Flag do TIMER0

    while(1){}  //rotina de interrupção em funcionamento
}