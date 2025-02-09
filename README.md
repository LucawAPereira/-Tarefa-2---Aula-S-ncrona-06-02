# -Tarefa-2---Aula-S-ncrona-06-02
TAREFA - AS_U4C7 - PWM servo motor

# Como executar o código
1-Baixar ou utilizar git clone no repositório.

      git clone https://github.com/LucawAPereira/-Tarefa-2---Aula-S-ncrona-06-02.git
      
2-Ter o VS Code instalado e configurado.

3-Ter a extensão do Raspberry Pi Pico instalada.

4-Compilar o arquivo "ATVPwm.c" utilizando o compilador do Raspberry Pi Pico.

5-Rodar o código um Raspberry ou utilizar o "diagram.json" através da extensão do Wokwi.


# Resposta ao item 6):
percebe-se que há variação no brilho do led, por conta do sinal PWM estar alterando a todo tempo, ou seja, se o pulso permanece por mais tempo no período, a potencia passada ao led é maior do que quando o pulso permanece por menos tempo no mesmo período. Também conseguimos provar utilizando a formula da tensão RMS que é a tensão de pico X a raiz quadrada do duty cicle, quando o duty cicle é igual a 1, ou seja, o pulso permanece por todo o período de tempo, é quando temos a máxima entrega da potencia, que será raiz quadrada de 1 que é igual a 1, portanto seu valor em RMS será igual ao seu valor de pico.
