# Projeto2-Micro-Controladores

## Objetivo da prática:

Desenvolvimento de um projeto em linguagem C para PIC18F que explore os seguintes recursos: interrupções, temporização, portas de entradas e saídas, e periféricos (botões, LEDs e displays de 7 segmentos).

## Passos para a realização do projeto:

● Quando um botão conectado na porta RB0 for pressionado, um display de 7 segmentos ligado na Porta D deve contar (de 0 a 9 em loop) com período de 1s.

● Quando um segundo botão, conectado na porta RB1, for pressionado, o mesmo display de 7 segmentos deve contar com período de 0,25s.
● O display se inicia desligado e a contagem começa somente quando qualquer um dos botões é pressionado.

● Utilizar o temporizador TMR0 com Interrupção externa (nos botões) para gerar as bases de tempo da contagem e provocar suas mudanças. Importa destacar que os botões (chaves) considerados agora são aqueles do tipo momentâneo, ou seja, deve-se pressionar e soltar logo em seguida pois o que conta para acionamento da interrupção é a mudança de borda
