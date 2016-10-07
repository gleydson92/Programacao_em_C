all: main.c RaspberryGPIO.c
	gcc main.c RaspberryGPIO.c FilaCircular.c Sistema.c -o main -LRaspberryGPIO -lpthread
main:	main.c
	gcc main.c -o main
fila:	FilaCircular.c
	gcc -c FilaCircular.c -o FilaCircular.o
debug: main.c RaspberryGPIO.c
	gcc -g main.c RaspberryGPIO.c FilaCircular.c -o main -LRaspberryGPIO -lpthread
gpio:	RaspberryGPIO.c
	gcc -c RaspberryGPIO.c -o RaspberryGPIO.o 
botoes:	BotoesTeste.c RaspberryGPIO.c
	gcc BotoesTeste.c RaspberryGPIO.c -o testeBotoes -LRaspberryGPIO
exec: main
	sudo ./main -run
config:
	sudo ./main -config
clear:
	rm main
	rm testeBotoes
	rm *.o
