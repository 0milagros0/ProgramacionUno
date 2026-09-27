#include <stdio.h>//faltaba un #
#include <conio.h>
#include <string.h>

#define A "c:\\arch.dat"//xambie a por A

struct registro
{
	int cliente;
	char nombre[20];
	float saldo;
};

int main()
{
	FILE *arch;
	struct registro reg;
	char seguir;
	//si el fopen falla se sigue ejecutando,agrego return 1
	if ((arch = fopen(A, "wb")) == NULL)
	{
		printf("No se pudo abrir el archivo");
		return 1;
	}
	
	do
	{
		printf("\nIngrese numero de cliente: ");
		scanf("%d", &reg.cliente);
		
		printf("Ingrese el nombre: ");
		scanf("%19s", reg.nombre);//arreglo no necesario el &
		
		printf("Ingrese el saldo: ");
		scanf("%f", &reg.saldo);
		
		fwrite(&reg, sizeof(reg), 1, arch);
		
		printf("Desea terminar? (s/n): ");
		scanf(" %c", &seguir);
		
	} while (seguir == 'n' || seguir == 'N');//minu y mayu
	
	fclose(arch);
	getch();
	
	return 0;
}
