# Projeto2 Microcontroladores

## Objetivo da prática:

Desenvolvimento de um projeto em linguagem C para PIC18F que explore os seguintes recursos: interrupções, temporização, portas de entradas e saídas, e periféricos (botões, LEDs e displays de 7 segmentos).

## Passos para a realização do projeto:

● Quando um botão conectado na porta RB0 for pressionado, um display de 7 segmentos ligado na Porta D deve contar (de 0 a 9 em loop) com período de 1s.

● Quando um segundo botão, conectado na porta RB1, for pressionado, o mesmo display de 7 segmentos deve contar com período de 0,25s.

● O display se inicia desligado e a contagem começa somente quando qualquer um dos botões é pressionado.

● Utilizar o temporizador TMR0 com Interrupção externa (nos botões) para gerar as bases de tempo da contagem e provocar suas mudanças. Importa destacar que os botões (chaves) considerados agora são aqueles do tipo momentâneo, ou seja, deve-se pressionar e soltar logo em seguida pois o que conta para acionamento da interrupção é a mudança de borda


## Explicação da solução do projeto:

### Projeto2.simu

Aqui foi projetado o circuito s ser simulado do PIC18F. Foi utilizado dois botões, 3 resistores (1k, 1k e 150) e o display para simular o projeto. As entradas são mostradas abaixo:

![image](https://github.com/Yudiaramos/Projeto2-Micro-Controladores/assets/71808184/b11feef5-0eb8-419e-89f6-5f0280b606ae)

### Projeto2.c

Finalmente, o projeto2.c é onde se encontra o código em si, que possui o controle do PIC, onde é possível entender a lógica da programação. Para que possamos utiliza-lo no SimuLIDE, temos que:
1. Selecionar a janela "build"
2. Clicar "build"
3. salvar em uma pasta

Assim, será gerado um arquivo "Projeto2.hex" que possuirá as instruções em hex.

### Projeto2.hex:

O código de nome "projeto2.hex" possui o "script" que controlará as entrada do PIC em hex. Para inserir-lo no PIC no SimuLIDE e rodar o programa, você deve seguir as instruções:
1. Abrir projeto2.simu
2. Clicar botão direito do mouse no PIC18F
3. selecionar "Carregar firmare"
4. selecionar o arquivo "Projeto2.hex


## Funcionamento:

Ao rodar o código, podemos clicar dois botões, ao clicar o botão 1 (de cima), temos a contagem do segmento de 0 a 9 com delay de 1000ms. Ao clicar o botão 2 (de baixo) temos a contagem do segmento com delay de 250ms.
