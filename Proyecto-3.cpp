#include<iostream>
#include<stdlib.h>
#include<mysql.h>
#include "agregaralumno.h"
//#include "ListarAlumno.h"

using namespace std;




void AgregarAlumno();
//void ListarAlumno();

int main()
{
	int exit, opc;
	
	system("cls");
	system("color 7");
	cout<<"\t\t              PROYECTO III           "<<endl<<endl;
	cout<<"\t\t\t 1. Cargar Registros"<<endl;
	cout<<"\t\t\t 2. Agregar Alumno"<<endl;
	cout<<"\t\t\t 3. Buscar a un Alumno"<<endl;
	cout<<"\t\t\t 4. Modificar Datos de un Alumno"<<endl;
	cout<<"\t\t\t 5. Listar los Alumnos"<<endl;
	cout<<"\t\t\t 6. Eliminar Alumno"<<endl;
	cout<<"\t\t\t 7. Deshacer Ultimos Cambios"<<endl;
	cout<<"\t\t\t 8. Rehacer Cambios"<<endl;
	cout<<"\t\t\t 9. Listar Cambios Realizados"<<endl;
	cout<<"\t\t\t10. Guardar Cambios"<<endl;
	cout<<"\t\t\t11. Salir"<<endl<<endl;
	cout<<"\t\t\t    Ingrese una opcion: ";
	cin>>opc;
	
	while(opc<=0||opc>12)
	{
		cout<<"\n\t\t\t    Opcion Invalida"<<endl;
		cout<<"\t\t\t    Ingrese una opcion: ";
		cin>>opc;
	}
	
	switch(opc){
		
		case 1:
			
			break;
			
		case 2:
			AgregarAlumno();
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 5:
			ListarAlumno();
			break;
			
		case 6:
			break;
		
		case 7:
			break;
		
		case 8:
			break;
		
		case 9:
			ListarAlumnos();
			break;
		
		case 10:
			GuardarCambios();
			break;
			
		case 11:
			break;
	}

	return main();
}



