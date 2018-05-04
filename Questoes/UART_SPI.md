

    Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).
  A comunicação assíncrona permite a transmissão e recepção de dados de forma simultânea e reduz o número de barramentos necessários (2), devido a ausência de um barramento de sincronísmo. Por outro lado, a ausência de um clock de sincronismo podem gerar erros de bits a distâncias longas ou em sistemas com perdas/ atrasos elevados.

(b) SPI.
  A comunicação SPI, assim como a comunicação UART, permite a transmissão e recepção de dados de forma simultânea. Por possuir um barramento de sincronismo(CLK), é menos versátil quanto ao número de barramentos. Por outro lado, a presença de CLK diminui a chances de erro de bits.
 
    Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

    Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

    Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?

    Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?

