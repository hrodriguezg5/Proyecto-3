#include<sstream>

using namespace std;

struct Alumno{
	int clave;
	string nombre;
	string correo;
	string fecha;
	int telefono;
	string direccion;
	string grado;
	string seccion;
	Alumno *siguiente;
};

Alumno *inicio=NULL;

int carga=0;

void CargarRegistros(){
	MYSQL* conexion;
	MYSQL_ROW row;
	MYSQL_RES* data;
	string sql; 
	int resultado, opc;
	const char* query;
	
	conexion=mysql_init(0);
	conexion=mysql_real_connect(conexion, "localhost", "root", "Accesorios1", "proyecto-3", 3306, NULL, 0);
	
	while(carga==1){
		sql="DELETE FROM alumno WHERE clave IS NOT NULL";
		query=sql.c_str();
		resultado=mysql_query(conexion, query);
		carga=0;
	}
	
	if(carga==0){
		system("cls");
		sql="SELECT * FROM alumno";
		query=sql.c_str();
		resultado=mysql_query(conexion, query);
	
		data=mysql_store_result(conexion);
		int nrows=mysql_num_rows(data);
	
		string clave_1[nrows], nombre_1[nrows], correo_1[nrows], fecha_1[nrows], telefono_1[nrows], direccion_1[nrows], grado_1[nrows], seccion_1[nrows];
		string clave_int, telefono_int;
		int i=0;
		
		while(row=mysql_fetch_row(data)){
			
			clave_1[i]=row[0];
			nombre_1[i]=row[1];
			correo_1[i]=row[2];
			fecha_1[i]=row[3];
			telefono_1[i]=row[4];
			direccion_1[i]=row[5];
			grado_1[i]=row[6];
			seccion_1[i]=row[7];
			i++;
		}
		
		for(i=0;i<nrows;i++){
			Alumno *alumno = new Alumno();
			
			clave_int="0";
			telefono_int="0";
			clave_int=clave_1[i];
			istringstream(clave_int)>>alumno->clave;
			alumno->nombre=nombre_1[i];
			alumno->correo=correo_1[i];
			alumno->fecha=fecha_1[i];
			telefono_int=telefono_1[i];
			istringstream(telefono_int)>>alumno->telefono;
			alumno->direccion=direccion_1[i];
			alumno->grado=grado_1[i];
			alumno->seccion=seccion_1[i];
			alumno->siguiente = NULL;
			
			if(inicio == NULL){
				inicio = alumno;
			}
			
			else if(alumno->clave<inicio->clave){
				alumno->siguiente=inicio;
				inicio=alumno;
			}
			
			else{
				Alumno* aux=inicio;
				Alumno* anterior;
				
				while(aux!=NULL){
					
					if(alumno->clave<aux->clave){
						
						anterior->siguiente=alumno;
						alumno->siguiente=aux;
					}
					else{
						anterior=aux;
						aux=aux->siguiente;	
					}
					
				}
				anterior->siguiente=alumno;		
			}
		}
		
		if(inicio==NULL){
			
			cout<<"\t\t\t\tNo hay registros en la base de datos"<<endl;
		}
		
		else if(resultado==0){
			
			cout<<"\t\t\t\tRegistros Cargados"<<endl;
		}
		
		cout<<"\n\t\t\t\tIngrese 1 para volver al menu: ";
		cin>>opc;
		
		while(opc!=1)
		{
			cout<<"\n\t\t\t\tOpcion Invalida"<<endl;
			cout<<"\t\t\t\tIngrese 1 para volver al menu: ";
			cin>>opc;
		}
		carga=1;	
	}
	
}

void InsertarNodo(){	
	Alumno *alumno=new Alumno();
	
	cout<<"\t\t\t\tIngrese la Clave: ";
	cin>>alumno->clave;
	cin.ignore();
	cout<<"\t\t\t\tIngrese el Nombre: ";
	getline(cin, alumno->nombre);
	cout<<"\t\t\t\tIngrese el Correo: ";
	getline(cin, alumno->correo);
	cout<<"\t\t\t\tIngrese la Fecha de Nacimiento: ";
	getline(cin, alumno->fecha);
	cout<<"\t\t\t\tIngrese el Telefono: ";
	cin>>alumno->telefono;
	cin.ignore();
	cout<<"\t\t\t\tIngrese la Direccion Domiciliar: ";
	getline(cin, alumno->direccion);
	cout<<"\t\t\t\tIngrese el Grado: ";
	getline(cin, alumno->grado);
	cout<<"\t\t\t\tIngrese la Seccion: ";
	getline(cin, alumno->seccion);
	
	alumno->siguiente=NULL;
	
	if(inicio==NULL){
		
		inicio=alumno;
		cout<<"\n\t\t\t\tRegistro agregado";
		return;	
	}
	
	if(alumno->clave<inicio->clave){
	
		alumno->siguiente=inicio;
		inicio=alumno;
		return;
	}
	
	Alumno* aux=inicio;
	Alumno* anterior;
	
	while(aux!=NULL){
		
		if(alumno->clave==aux->clave){
			
			cout<<"\n\t\t\t\tLa clave ya existe, no es posible agregar"<<endl;
			return;
		}
		
		if(alumno->clave<aux->clave){
			
			anterior->siguiente=alumno;
			alumno->siguiente=aux;
			cout<<"\n\t\t\t\tRegistro agregado"<<endl;
			return;
		}
		anterior=aux;
		aux=aux->siguiente;
	}
	anterior->siguiente=alumno;
}

void AgregarAlumno(){
	
	int agregar;
	
	do{
		system("cls");
		cout<<"\t\t\t\t\tAgregar Alumno"<<endl<<endl;
   		InsertarNodo();
		cout<<"\n\t\t\t\tDesea agregar otro alumno"<<endl;
		cout<<"\t\t\t\tPresiona 1 para si, presiona cualquier tecla para no: ";
		cin>>agregar; 
	}while(agregar==1);		
}

void ListarAlumno(){
	
	system("cls");
	int opc;
	
	if(inicio==NULL){
		
		cout<<"\t\t\t\tNo hay datos en la lista"<<endl;
		return;
	}
	
	Alumno* aux=inicio;
	
	while(aux!=NULL){
		
		cout<<"\t\t\t\tClave: "<<aux->clave<<endl;
		cout<<"\t\t\t\tNombre: "<<aux->nombre<<endl;
		cout<<"\t\t\t\tCorreo: "<<aux->correo<<endl;
		cout<<"\t\t\t\tFecha de Nacimiento: "<<aux->fecha<<endl;
		cout<<"\t\t\t\tTelefono: "<<aux->telefono<<endl;
		cout<<"\t\t\t\tDireccion Domiciliar: "<<aux->direccion<<endl;
		cout<<"\t\t\t\tGrado: "<<aux->grado<<endl;
		cout<<"\t\t\t\tSeccion: "<<aux->seccion<<endl<<endl;
		
		aux=aux->siguiente;
	}
	
	cout<<"\n\t\t\t\tIngrese 1 para volver al menu: ";
	cin>>opc;
	
	while(opc!=1)
	{
		cout<<"\n\t\t\t\tOpcion Invalida"<<endl;
		cout<<"\t\t\t\tIngrese 1 para volver al menu: ";
		cin>>opc;
	}
}

void GuardarCambios(){
	
	MYSQL* conexion;
	MYSQL_ROW row;
	MYSQL_RES* data;
	MYSQL_FIELD *columna;
	
	string sql, t1, t2, clave_s, telefono_s;
	int i=0;
	int resultado, clave1[i];
	
	conexion=mysql_init(0);
	conexion=mysql_real_connect(conexion, "localhost", "root", "Accesorios1", "proyecto-3", 3306, NULL, 0);
	const char* query;
	
	system("cls");
	int opc;
	
	Alumno* aux=inicio;
	
	while(aux!=NULL){
		ostringstream clave_str, telefono_str;
	
		clave_str<<aux->clave;
		clave_s=clave_str.str();
		telefono_str<<aux->telefono;
		telefono_s=telefono_str.str();
		
		sql="DELETE FROM alumno WHERE clave IS NOT NULL";
		query=sql.c_str();
		resultado=mysql_query(conexion, query);
		
		t1="INSERT INTO alumno(clave, nombre, correo, fecha_nacimiento, telefono, direccion, grado, seccion)"; 
		t2="VALUES ('"+clave_s+"', '"+aux->nombre+"', '"+aux->correo+"', '"+aux->fecha+"', '"+telefono_s+"', '"+aux->direccion+"', '"+aux->grado+"', '"+aux->seccion+"')";
		sql=t1+t2;
		query=sql.c_str();
		resultado=mysql_query(conexion, query);
	
		aux=aux->siguiente;
		i++;
	}
	
	if(resultado==0){
		
		cout<<"\t\t\t\tCambios guardados"<<endl;
	}
	
	else{
		
		cout<<"\t\t\t\tCambios no guardados"<<endl;
	}
	
	cout<<"\n\t\t\t\tIngrese 1 para volver al menu: ";
	cin>>opc;
	
	while(opc!=1)
	{
		cout<<"\n\t\t\t\tOpcion Invalida"<<endl;
		cout<<"\t\t\t\tIngrese 1 para volver al menu: ";
		cin>>opc;
	}
}

void ListarAlumnos(){
	
	system("cls");
	int opc;
	int buscar;
	
	if(inicio==NULL){
		
		cout<<"\t\t\t\tNo hay datos en la lista"<<endl;
		return;
	}
	
	Alumno *aux=inicio;
	
	cout<<"\t\t\tIngrese el codigo del alumno: ";
	cin>>buscar;
	
	while(aux!=NULL){
		
		if(aux->clave==buscar){
		
			cout<<"\t\t\t\tClave: "<<aux->clave<<endl;
			cout<<"\t\t\t\tNombre: "<<aux->nombre<<endl;
			cout<<"\t\t\t\tCorreo: "<<aux->correo<<endl;
			cout<<"\t\t\t\tFecha de Nacimiento: "<<aux->fecha<<endl;
			cout<<"\t\t\t\tTelefono: "<<aux->telefono<<endl;
			cout<<"\t\t\t\tDireccion Domiciliar: "<<aux->direccion<<endl;
			cout<<"\t\t\t\tGrado: "<<aux->grado<<endl;
			cout<<"\t\t\t\tSeccion: "<<aux->seccion<<endl<<endl;
		}
		
		aux=aux->siguiente;
	}
	
	cout<<"\n\t\t\t\tIngrese 1 para volver al menu: ";
	cin>>opc;
	
	while(opc!=1)
	{
		cout<<"\n\t\t\t\tOpcion Invalida"<<endl;
		cout<<"\t\t\t\tIngrese 1 para volver al menu: ";
		cin>>opc;
	}
}
