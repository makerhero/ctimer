# Biblioteca cTimer


Essa biblioteca implementa uma classe que utiliza a função millis() para capturar o tempo decorrido. A função inicializa com zero quando o Arduino é ligado e seu valor é incrementado a cada milissegundo. Como é armazenado como um número longo sem sinal, o registrador ‘capota’ aproximadamente a cada 50 dias. Embora nem todos os sistemas irão rodar direto por tanto tempo, a classe leva isso em conta e trata esse overflow corretamente.

Como a implementação é feita na forma de classe, pode-se criar quantos timers forem necessários, cada um disparando no momento desejado sem que um interfira no outro, permitindo sincronizar tarefas e executar processos em qualquer intervalo de tempo quase intuitivamente.
