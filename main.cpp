#include<iostream>
#include "multilista.h"
int main(){
	
    multilista ml;
	string n,c,h;
	int e;
	int i;   
	int k;            
	int opcion; 
	cout<<endl;
    //ml.cargar();
	do
    {
        
        cout << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "1. Ingresar datos de un nuevo estudiante" << endl;
        cout << "2. Mostrar los nombres de todos los estudiantes" << endl;
        cout << "3. Mostrar los nombre de los estudiantes segun su carrera" << endl;
        cout << "4. Mostrar los nombre de los estudiantes segun su hobby"  << endl;
        cout << "5. Mostrar los nombre de los estudiantes segun su edad"  << endl;
        cout << "6. Salir" << endl;

        cin >> opcion;
 
        
        switch(opcion){
            case 1: 
                if (!ml.mFull()){ 
                    cout << "Introduce el nombre del estudiante: ";
                    cin >> n;
                    cout << "Introduce la carrera: ";
                    cin >> c;
                    cout << "Introduce la hobby: ";
                    cin >> h;
                    cout << "Introduce la edad: ";
                    cin >> e;
                    ml.ingresarPersona(n,h,c,e);
                }
                else   
                    cout << "M�ximo de festudiantes (50)!" << endl;
                break;
 
            case 2: 
            	ml.mostrarNombres();
                break;
 
 
            case 3: 
            	
				cout << endl;
		        cout << "Escoje una carrera:" << endl;
		        cout << "1.catastral" << endl;
		        cout << "2.industrial" << endl;
		        cout << "3.sistemas" << endl;
		        cout << "4.electronica"  << endl;
		        cout << "5.Regresar" << endl;            	
                cin >> opcion;
                switch(opcion){
                	case 1:
                		ml.mostrarCarrera(1);
                		break;
                	case 2:
                		ml.mostrarCarrera(2);
                		break;
                	case 3:
                		ml.mostrarCarrera(3);
                		break;
                	case 4:
                		ml.mostrarCarrera(4);
                		break;                		
				}
                break;
 
            case 4: 
            	cout << endl;
		        cout << "Escoje un hobby:" << endl;
		        cout << "1.danza" << endl;
		        cout << "2.natacion" << endl;
		        cout << "3.beisbol" << endl;
		        cout << "4.basquet"  << endl;
		        cout << "5.Regresar" << endl;            	
                cin >> opcion;
                switch(opcion){
                	case 1:
                		ml.mostrarHobby(5);
                		break;
                	case 2:
                		ml.mostrarHobby(6);
                		break;
                	case 3:
                		ml.mostrarHobby(7);
                		break;
                	case 4:
                		ml.mostrarHobby(8);
                		break;
                		
				}
                break;
            	
                
            case 5: // Mostrar seg�n hobby
				ml.mostrarEdad();
                break;
 
            case 6: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                ml.guardar();
                break;
            
            case 7:
                ml.mostrarCabecera();
                break;
            case 8:
                ml.mostrarPersonas();
                break;
            default: // Otra opcion: no v�lida
                cout << "Opci�n desconocida!" << endl;
                break;
        }
    } while (opcion != 6);  // Si la opcion es 5, terminamos 
	return 0;
}