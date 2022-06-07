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
	
	Alumno *aux=inicio;
	Alumno *anterior;
	
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
	
	Alumno *aux=inicio;
	
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
	
	ostringstream clave_str, telefono_str;
	string sql, t1, t2, clave_s, telefono_s; 
	int resultado;
	
	conexion=mysql_init(0);
	conexion=mysql_real_connect(conexion, "localhost", "root", "Accesorios1", "proyecto-3", 3306, NULL, 0);
	const char* query;
	
	system("cls");
	int opc;
	
	Alumno *aux=inicio;
	
	while(aux!=NULL){

		clave_str<<aux->clave;
		clave_s=clave_str.str();
		telefono_str<<aux->telefono;
		telefono_s=telefono_str.str();
		
		sql="DELETE FROM alumno WHERE clave='"+clave_s+"'";
		query=sql.c_str();
		resultado=mysql_query(conexion, query); 
		
		t1="INSERT INTO alumno(clave, nombre, correo, fecha_nacimiento, telefono, direccion, grado, seccion)"; 
		t2="VALUES ('"+clave_s+"', '"+aux->nombre+"', '"+aux->correo+"', '"+aux->fecha+"', '"+telefono_s+"', '"+aux->direccion+"', '"+aux->grado+"', '"+aux->seccion+"')";
		sql=t1+t2;
		query=sql.c_str();
		resultado=mysql_query(conexion, query);
		
		
		aux=aux->siguiente;
	}
	
	sql = "SELECT * FROM alumno";
	query = sql.c_str();
	resultado=mysql_query(conexion, query);

	data=mysql_store_result(conexion);
	int countColumns=mysql_num_fields(data);
	int countRows=mysql_num_rows(data);
	cout<<endl<<endl;
	columna = mysql_fetch_field(data);
	
	Alumno *alumno2=new Alumno();
	
	
	
	
	while(row=mysql_fetch_row(data)){
		
	//	for(int i=0;i<countColumns;i++){
		cout<<row[1]<<endl;
	//	}
		alumno2->nombre=row[1];
		
		cout<<endl;
	}
	
	cout<<alumno2->nombre;
	
	
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
	
	if(inicio==NULL){
		
		cout<<"\t\t\t\tNo hay datos en la lista"<<endl;
		return;
	}
	int buscar;
	Alumno *aux=inicio;
	
	cout<<"Ingrese el codigo del alumno";
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
