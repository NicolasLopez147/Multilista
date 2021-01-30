#ifndef MULTILISTA
#define MULTILISTA

#include<iostream>
#include<fstream>
using namespace std;
//Esta es la estructura donde estan las cabezas 
struct cabecera{
	string caract;
	int pos;
};
//Aqui estan las personas 
struct info{
	string nombre;
    string carrera;
    string hobby;
	int edad;
	int sign;
	int sigc;
	int sigh;
	int sige;
};

//Esta es la multilista como tal
class multilista{
	cabecera *lista_cab=new cabecera[10];
	cabecera cab;
	info *personas=new info[100];
	int indexPersonas=-1;
	info per;
	
	public:
		multilista(){
			crearCabecera();
			indexPersonas=-1;
			cab;
			per;
			personas;
			lista_cab;	
		}
		void mostrarNombres();
		void mostrarCarrera(int i);
		void mostrarHobby(int i);
		void mostrarEdad();
		bool mEmpty();
		bool mFull();
		void mostrarCabecera();
		void ingresarPersona(string nombre, string hobby,string carrera, int edad);	
		void mostrarPersonas();
        void guardar();
        void cargar();

	private:
		void crearCabecera();
		void ordenarNombre();
		void ordenarCarrera();
		void ordenarHobby();
		void ordenarEdad();
        
};

void multilista :: mostrarCabecera(){
	for (int i=0;i<10;i++){
			//Se imprime toda la lista de cabeceras
			cout<<lista_cab[i].caract+" ";
			cout<<lista_cab[i].pos<<endl;
	}
}


void multilista :: ordenarNombre(){
	int j;
	int i=lista_cab[0].pos;  
	
	if(indexPersonas==0){
		lista_cab[0].pos=0;
		return;
	}
	
	string str1=personas[indexPersonas].nombre;
	string str2=personas[i].nombre;
	if(str1.compare(str2)<0){
		personas[indexPersonas].sign=lista_cab[0].pos;
		lista_cab[0].pos=indexPersonas;
				
	}else{
		while(personas[i].sign!=-1){
			j=personas[i].sign;
			str2=personas[j].nombre;
			
			if(str1.compare(str2)<0){
				personas[indexPersonas].sign=j;
				personas[i].sign=indexPersonas;	
				return;	
			}	
			i=j;
		}
		personas[j].sign=indexPersonas;
		personas[indexPersonas].sign=-1;		
	}	
}

void multilista :: ordenarCarrera(){
	cabecera auxC;
	//info auxI,auxIU;
	string carrera;
	int i,a,b;
	
	//auxI=personas[indexPersonas];
	carrera=personas[indexPersonas].carrera;
	
	if(carrera=="catastral"){
		auxC=lista_cab[1];
		i=1;
	}
	if(carrera=="industrial"){
	 	auxC=lista_cab[2];
	 	i=2;
	 }
	if(carrera=="sistemas"){
		auxC=lista_cab[3];
		i=3;
	}
	if(carrera=="electronica"){
	 	auxC=lista_cab[4];
	 	i=4;
	}

	if(auxC.pos==-1){
		auxC.pos=indexPersonas;
		lista_cab[i].pos=indexPersonas;
		personas[indexPersonas].sigc=-1;
	}else{
		int aux;
		aux=lista_cab[i].pos;
		while(personas[aux].sigc!=-1){
			b=personas[aux].sigc;
			aux=b;
		}
		personas[aux].sigc=indexPersonas;
		personas[indexPersonas].sigc=-1;
	}
}

void multilista :: ordenarHobby(){
	cabecera auxH;
	info auxI,auxIU;
	string hobby;
	int auxPos,i;
	
	auxI=personas[indexPersonas];
	hobby=personas[indexPersonas].hobby;
	
	if(hobby=="danza") {
	auxH=lista_cab[5];
	i=5;
	 }
	if(hobby=="natacion") {
	auxH=lista_cab[6];
	i=6;
	 }
	if(hobby=="beisbol") {
	auxH=lista_cab[7];
	i=7;
	 }
	if(hobby=="basquet") {
	auxH=lista_cab[8];
	i=8;
	 }
	
	if(auxH.pos==-1){
		lista_cab[i].pos=indexPersonas;
		personas[indexPersonas].sigh=-1;
	}else{
		auxH.pos=auxPos;
		lista_cab[i].pos=indexPersonas;
		personas[indexPersonas].sigh=auxPos;
	
	}
}

void multilista :: ordenarEdad(){
	cabecera auxE;
	info auxI,auxIU;
	int indexSiguiente,indexAnterior,index,a,b;
	
	auxI=personas[indexPersonas];
	cout<<auxI.nombre<<endl;
    auxE = lista_cab[9];
	int aux=lista_cab[9].pos;
	int edad1;
	int edad2;
	int aux1;
	
	if(auxE.pos==-1){
        cout<<"Se esta ingresando la primera persona"<<endl;
		lista_cab[9].pos=indexPersonas;
		personas[indexPersonas].sige=-1;
	}
	auxIU=personas[auxE.pos];
	if(auxI.edad>auxIU.edad){
		indexSiguiente=auxE.pos;
		lista_cab[9].pos=indexPersonas;
		personas[indexPersonas].sige=indexSiguiente;
	}else{
		while(personas[aux].sige!=-1){
			aux1=personas[aux].sige;
			edad1=personas[aux].edad;
			edad2=personas[aux1].edad;
		
		if(edad1>edad2){
			personas[indexPersonas].sige=aux1;
			personas[aux].sige=indexPersonas;		
			return;	
		}	
		aux=aux1;	
		}
		personas[aux1].sige=indexPersonas;
		personas[indexPersonas].sige=-1;
	}
}

//Se crea la lista de cabecera 
void multilista :: crearCabecera(){
		lista_cab[0].caract="nombre";
		lista_cab[0].pos=-1;
		lista_cab[1].caract="catastral";
		lista_cab[1].pos=-1;
		lista_cab[2].caract="industrial";
		lista_cab[2].pos=-1;
		lista_cab[3].caract="sistemas";
		lista_cab[3].pos=-1;
		lista_cab[4].caract="electronica";
		lista_cab[4].pos=-1;
		lista_cab[5].caract="danza";
		lista_cab[5].pos=-1;
		lista_cab[6].caract="natacion";
		lista_cab[6].pos=-1;
		lista_cab[7].caract="beisbol";
		lista_cab[7].pos=-1;
		lista_cab[8].caract="basquet";
		lista_cab[8].pos=-1;
		lista_cab[9].caract="edad";
		lista_cab[9].pos=-1;
}

//Aqui  se ingresa una persona en las lista de personas
void multilista :: ingresarPersona(string nombre, string hobby,string carrera, int edad){
	info auxP;
	if(indexPersonas<101){	
		auxP.carrera=carrera;
		auxP.edad=edad;
		auxP.hobby=hobby;
		auxP.nombre=nombre;
		auxP.sigc=-1;
		auxP.sign=-1;
		auxP.sigh=-1;
		auxP.sige=-1;
		indexPersonas++;
		personas[indexPersonas]=auxP;
	}else{
		cout<<"arreglo de datos lleno"<<endl;
        return;
	}
	ordenarNombre();
	ordenarCarrera();
	ordenarHobby();
	ordenarEdad();
	cout<<"Estudiante ingresado con exito"<<endl;
	cout<<"salio de ingresar"<<endl;
}

void multilista :: mostrarPersonas(){
    for(int i=0; i<=indexPersonas;i++){
    	cout<<personas[i].nombre+" ";
    	cout<<personas[i].carrera+" ";
    	cout<<personas[i].hobby+" ";
    	cout<<personas[i].edad;
    	cout<<" ";
    	cout<<personas[i].sign;
    	cout<<" ";
    	cout<<personas[i].sigc;
    	cout<<" ";
    	cout<<personas[i].sigh;
    	cout<<" ";
    	cout<<personas[i].sige;
    	cout<<endl;
	}
}

void multilista ::mostrarNombres(){
	int b=lista_cab[0].pos;
	int a;
	if (b == -1){
		cout<<"No se ha ingresado ninigun estudiante"<<endl;
		return;
	}
	do{
		a=b;
		cout<<personas[a].nombre<<"\n";
		b=personas[a].sign;	
			
	}while(personas[a].sign!=-1);
}
void multilista ::mostrarCarrera(int i){
	int a=lista_cab[i].pos;
	int b;  
	if(lista_cab[i].pos==-1){
		cout<<"Sin estudiantes de esta carrera\n";
		return;
	}
	do{
		cout<<personas[a].nombre<<"\n";
		b=personas[a].sigc;	
        a=b;
			
	}while(a!=-1);
}
void multilista ::mostrarHobby(int i){
	int b=lista_cab[i].pos;
	int a;  
	if(lista_cab[i].pos==-1){
		cout<<"Sin estudiantes de esta hobby\n";
		return;
	}
	do{
		a=b;
		cout<<personas[a].nombre<<"\n";
		b=personas[a].sigh;	
			
	}while(personas[a].sigh!=-1);
	
}
void multilista ::mostrarEdad(){
	int b=lista_cab[9].pos;
	int a;
	if (b == -1){
		cout<<"No se ha ingresado ninigun estudiante"<<endl;
		return;
	}
	do{
		a=b;
		cout<<personas[a].nombre<<" "<<personas[a].edad<<"\n";
		b=personas[a].sige;	
			
	}while(personas[a].sige!=-1);
}
bool multilista ::mEmpty(){
	if(indexPersonas<0){
		return true;
	}else{
		return false;
	}
}
bool multilista ::mFull(){
	if(indexPersonas>50){
		return true;
	}else{
		return false;
	}
}
void multilista :: guardar(){
    fstream archivo("cabeceras.txt");
    if (!archivo.is_open()){
        archivo.open("cabeceras.txt",ios::out);
    }
    for (int i = 0 ; i < 10 ; i++){
        archivo<<lista_cab[i].caract<<" ";
        archivo<<lista_cab[i].pos<<endl;
    }
    archivo.close();

	fstream archivo1("personas.txt");
    if (!archivo1.is_open()){
        archivo1.open("personas.txt",ios::out);
    }
    for (int i =0 ; i <= indexPersonas ; i++){
        archivo1 << personas[i].nombre<<" ";
        archivo1 << personas[i].carrera<<" ";
        archivo1 << personas[i].hobby<<" ";
        archivo1 << personas[i].edad<<" ";
        archivo1 << personas[i].sign<<" ";
        archivo1 << personas[i].sigc<<" ";
        archivo1 << personas[i].sigh<<" ";
        archivo1 << personas[i].sige<<endl;
    }
    archivo1.close();
}
void multilista :: cargar(){
    ifstream archivo;
    archivo.open("cabeceras.txt");
    if (archivo.fail()){
        cout<<"Se prodijo un error abriendo el archivo"<<endl;
        return;
    }
    string linea;
    string palabra;
	string espacio = " ";
	int pos;
    while(!archivo.eof()){
        getline(archivo,linea);
		while ((pos = linea.find(espacio)) <= string::npos) {
			palabra = linea.substr(0, pos);
			if (isdigit(palabra[1])){
				lista_cab->pos = stoi(palabra,nullptr,10);	
			}else{
				lista_cab->caract = palabra;				
			}
			linea.erase(0, pos + espacio.length());
			if (pos == string::npos){
				break;
			}
		}
    }
    archivo.close();
}

#endif