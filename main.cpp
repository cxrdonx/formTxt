#include <iostream>

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std; 

       class usuario{
		   public: 
		      string nombre;
		      string  apellido;
		      string direccion; 
		      string departamento;
		      string municipio;
		      int telefono;
		      
		      usuario(string _nombre, string _apellido, string _direccion, string _departamento, string _municipio, int _telefono){
		      
		      nombre = _nombre;
		      apellido = _apellido;
		      direccion = _direccion;
		      departamento = _departamento;
		      municipio = _municipio;
		      telefono = _telefono;
		    
      }
      
      void save(){
      		fstream archivo("registros.txt");
      			if(!archivo.is_open()){
		        	archivo.open("registro.txt", ios::app);             
      	            archivo <<"============================="<<endl;
	             	archivo <<"nombre: "<<nombre<<endl;
	                archivo <<"apellido: "<<apellido<<endl;
		            archivo <<"direccion: "<<direccion<<endl;
	            	archivo <<"telefono: "<<telefono<<endl;
	            	archivo <<"departamento: "<<departamento<<endl;	
	            	archivo <<"municipio: "<<municipio<<endl;
	            	archivo <<"============================="<<endl;
		            system("cls");		
	             	cout<<"\t\t\tregistro guardado"<<endl;
	            	system("pause");
	             	system("cls");
	             	archivo.close();
      }
      
      void find(){
      	
      	
      	
	  }
}
         	
       
        	
            
};


int menu_principal();       //inicializar funcion principal para que muestre el men          
bool encontrado=false;          
                                     //faltan variaables globales

void buscar_dep(){                                    //busqueda por departamento (R)
		fstream archivo;
	    string cadena, ln, ln1, ln2, ln3, ln4, ln5, ln6, nombre, municipio;
	    int res = 0; 
	    int telefono;
	
	cout<<"\t\t\tbuscar por departamento: \n"<<endl;
	cin>>cadena;
	
	if(!archivo.is_open()){
		archivo.open("registro.txt", ios::in);
	}
   while(getline(archivo, ln4))
   {
   	if(ln4.find(cadena) != string::npos)
	   {
	   	cout<<nombre<<endl;
   		cout<<ln4<<endl;
   		getline(archivo, ln3);
   		cout<<municipio<<endl;
   		getline(archivo, nombre);
   		cout<<telefono<<endl;
   		getline(archivo, ln1);
   		cout<<ln1<<endl;
   		getline(archivo, ln);
   		cout<<ln<<endl;
   	res=1;
	   }
   }
   if(res == 0){
   	cout<<cadena<<"\t\t\tno se encontro "<< endl;
   }
   system("pause");
   menu_principal();
	
		
}

void escribir_registro2(){                                               //funcion que crea un nuevo registro 
	string nombre, apellido, direccion, departamento;
	string municipio;
	int telefono, pre, op2, cantidad, id,reg;
	int y, n;
		cout<<"\t\t\tcrear un nuevo registro"<<endl;
		cout<<"\t\t\t============================"<<endl;
		cin.ignore();
	cout<<"\t\t\tnombre: ";
	getline(cin, nombre);
	cout<<"\t\t\tapellido: ";
	getline(cin, apellido);
	cout<<"\t\t\tdireccion: ";
	getline(cin, direccion);
	cout<<"\t\t\tdepartamento: ";
	getline(cin, departamento);
	cout<<"\t\t\tmunicipio: ";
    getline(cin, municipio);
    cout<<"\t\t\ttelefono: ";
    cin>>telefono;
	  usuario us(nombre, apellido, direccion, departamento, municipio, telefono);
	cout << "\t\t\t-¿Desea guardar el registro?\n"<<endl;
	cout <<"\t\t\t[1] si / [2] no"<<endl;
    cin>>op2;
    
    switch(op2){
	     
	  case 1 :
	  	    us.save();
	     
		break;	
		
	
	case 2:
		menu_principal();
		break;
	
	}




	 system("pause");
	
}

void buscar_archivo(){                                  //funvion de buscar por el nombre
	

	fstream archivo;
	string cadena, ln, ln1, ln2, ln3, ln4;
	int res = 0; 
	
	cout<<"buscar por el nombre: \n"<<endl;
	cin>>cadena;
	
	if(!archivo.is_open()){
		archivo.open("registro.txt", ios::in);
	}
   while(getline(archivo, ln))
   {
   	if(ln.find(cadena) != string::npos)
	   {
	   	cout<<"================"<<endl;
   		cout<<ln<<endl;
   		getline(archivo, ln2);
   		cout<<ln2<<endl;
   		getline(archivo, ln3);
   		cout<<ln3<<endl;
   		getline(archivo, ln4);
   		cout<<ln4<<endl;
   		cout<<"================"<<endl;
   	res=1;
	   }
   }
   if(res == 0){
   	cout<<cadena<<"no se encontro "<< endl;
   }
   system("pause");
   menu_principal();
}


void salir(){
    cout<<"Programa Finalizado"<<endl;
}
	
	

void buscar(){
	string busccar_nombre, buscar_municipio, buscar_departamento;           //menu buscar 
	int busc;
	cout<<"[1] buscar por nombre"<<endl;
	cout<<"[2] buscar por departamento"<<endl;
	cout<<"[3] buscar por municipio"<<endl;
	cin>>busc;
	switch (busc){
		case 1:
		    cout<<"\t\t********************"<<endl;
		    buscar_archivo();
		    break;
		case 2:
			cout<<"\t\t********************"<<endl;
			buscar_dep();
			break;
		case 3: 
		    cout<<"buscar por municipio"<<endl;
		    break;
	}

}

fstream archivo;                                               //mostrar listado general de registros
void LeerArchivo1(){
	int seleccion;
	archivo.open("registro.txt",ios::in);
	if(archivo.is_open()){
		string linea;
		while(getline(archivo,linea)){
			cout<<linea<<endl;
		}
		archivo.close();
	}
	else{
		cout<<"\t\t\tno se pudo abrir el archivo";
	}
system("pause");
menu_principal();
	
}


int menu_principal(){                                  //menu principal
	int x;
	system("cls");
cout<<"\t\t\t----------------------------------------\n\n"<<endl;
cout<<"\t\t\t----MENU AGENDA TELEFONICA----"<<endl;          
cout<<"\t\t\teliga una opcion:"<<endl;
cout<<"\t\t\t[1] Registrar un nuevo contacto"<<endl;                    //submenus
cout<<"\t\t\t[2] Buscar"<<endl;
cout<<"\t\t\t[3] Mostrar listado de contactos"<<endl;
cout<<"\t\t\t[4] Eliminar un contacto"<<endl;
cout<<"\t\t\t[5] Modificar un contacto"<<endl;
cout<<"\t\t\t[6] Salir"<<endl; 
cin>>x;
return x;



}


int main(){                                       //funcion principal
 ofstream ESC;        
 int op;
 do{
system("cls");
 	op = menu_principal();//funcion principal
 	switch (op){
 		case 1:
 		    escribir_registro2();        // crear un nuevo contacto
 		break;
 		case 2:                           
 			buscar();                    //buscar contacto
 		break;
 		case 3:LeerArchivo1();           //mostrar listado de todos los contactos
 		break;
 		case 4:
 		   //buscar por departamento
 		break;
 		case 5:
            //eliminar contacto
 		
 		break;
 			
 			
	 }
	 
 }while(op!=6);

}
  
