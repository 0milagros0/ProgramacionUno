#include <stdio.h>
#include <conio.h>

struct alumno
{
	int dni;
	char apellido[20];
	char nombre[20];
	float nota;
};

int main()
{
	FILE *arch;
	struct alumno alu;
	struct alumno mejor, peor;
	char seguir;
	int total = 0;
	int aprobados = 0;
	int desaprobados = 0;
	float sumaNotas = 0;
	float sumaDesaprobados = 0;
	float promedioGeneral;
	float promedioDesaprobados;
	float porcentajeAprobados;

	arch = fopen("alumnos.dat","wb");//carga archivo
	
	if(arch == NULL){
		printf("Error al crear el archivo");
		getch();
		return 1;
	}
	do
	{
		printf("\nDNI: ");
		scanf("%d",&alu.dni);
		
		printf("Apellido: ");
		scanf("%s",alu.apellido);
		
		printf("Nombre: ");
		scanf("%s",alu.nombre);
		
		printf("Nota: ");
		scanf("%f",&alu.nota);
		
		fwrite(&alu,sizeof(alu),1,arch);
		
		printf("Desea ingresar otro alumno? (s/n): ");
		scanf(" %c",&seguir);
		
	}while(seguir=='s' || seguir=='S');
	
	fclose(arch);

	arch = fopen("alumnos.dat","rb");//informe
	
	if(arch == NULL){
		printf("Error al abrir el archivo");
		getch();
		return 1;
	}
	
	fread(&alu,sizeof(alu),1,arch);
	
	if(!feof(arch)){
		mejor = alu;
		peor = alu;
	}
	
	printf("\n         Listado de Alumnos");
	printf("\n___________________________________________\n\n");
	
	printf("%-10s %-15s %-15s %-10s\n",
		   "DNI","Apellido","Nombre","Notaa");
	
	while(!feof(arch))
	{
		printf("%-10d %-15s %-15s %-10.2f\n",
			alu.dni,
			alu.apellido,
			alu.nombre,
			alu.nota);
		total++;
		sumaNotas += alu.nota;
		
		if(alu.nota > mejor.nota)
			mejor = alu;
		if(alu.nota < peor.nota)
			peor = alu;
		if(alu.nota >= 6){
			aprobados++;
		}
		else{
			desaprobados++;
			sumaDesaprobados += alu.nota;
		}
		
		fread(&alu,sizeof(alu),1,arch);
	}
	fclose(arch);
	
	promedioGeneral = sumaNotas / total;
	porcentajeAprobados = (float)aprobados * 100 / total;
	
	if(desaprobados > 0)
		promedioDesaprobados = sumaDesaprobados / desaprobados;
	else
		promedioDesaprobados = 0;
	
	printf("\n\nTotal de alumnos: %d", total);
	printf("\nAlumno con la nota mas alta: %s %s (%.2f)",
		mejor.apellido,
		mejor.nombre,
		mejor.nota);
	printf("\nAlumno con la nota mas baja: %s %s (%.2f)",
		peor.apellido,
		peor.nombre,
		peor.nota);
	printf("\nPromedio general de los alumnos: %.2f", promedioGeneral);
	printf("\nCantidad de alumnos con nota mayor o igual a 6: %d", aprobados);
	printf("\nCantidad de alumnos con nota menor a 6: %d", desaprobados);
	printf("\nPorcentaje de alumnos con nota mayor o igual a 6: %.2f%%", porcentajeAprobados);
	printf("\nPromedio de alumnos con nota menor a 6: %.2f", promedioDesaprobados);
	
	getch();
	return 0;
}
