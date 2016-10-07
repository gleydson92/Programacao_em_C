#include"RaspberryGPIO.h"

int main(void)
{
	printf("\nUnexport pins\n");
	if(GPIOUnexport(14) == true && GPIOUnexport(15) == true && GPIOUnexport(18) == true && GPIOUnexport(23) == true && GPIOUnexport(25) == true)
		printf("\nTerminais Exportados com Sucesso!\n");
	else 
		printf("\n\t\tUm erro Foi detectado! \n\t\t\tOu os pinos já foram extraídos, \n\t\t\tou você está com problemas na GPIO! \n");
}
