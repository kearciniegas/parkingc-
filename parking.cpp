// librerias
#include <iostream>
#include <stdlib.h>
// declaraciones 
using std::cout; // declaraciones se pueden usar para introducir miembros del espacio de nombres en otros espacios de nombres
using std::cin;
using std::endl;

// constantes 
#define NFILAS 8
#define NCOLUMNAS 8
 
int MostrarMenu(void)
{
    int op;
 
    //Solicito la operacion a realizar -Menu Kawaii

    system("CLS");// «system» permite ejecutar a su vez otras funciones como "cls"
    cout<<"\n\n\n\t\t\t\tParking";
    cout<<"\n\n\n\t\t\t----------------------"<<endl;
    cout << "\n\n\n\t\t\tMenu: " << endl;
    cout << "\t\t\t\1\t 1-Estacionar un vehiculo   \t    \1" << endl;
    cout << "\t\t\t\2\t 2-Retirar un vehiculo      \t    \2" << endl;
    cout << "\t\t\t\1\t 3-Listar estado de puestos \t    \1" << endl;
    cout << "\t\t\t\2\t 0-Salir                    \t    \2" << endl;
    cout<<"\t\t\t-------------------------"<<endl;
    cout << "\n\n\n\t\t\t\tSeleccione una opcion:";
    cin >> op;
    return op;
}
 
int ObtenerNumPuestosLibres(int parqueadero[NFILAS][NCOLUMNAS])
{
    //Formula para aya el numero de puestos libres
    int nLibres=0;
 
    for(int fila=0;fila<NFILAS;fila++) // ciclo for, variable tipo entero= hacer "fila" es igual a cero, hasta la "fila" es menor al numero de filas=8, haga que fila aumente 1+1 
        for(int columna=0;columna<NCOLUMNAS;columna++)// ciclo for,variable tipo entero= hacer "columna" es igual a cero, hasta la "columna" es menor al numero de columnas=8, haga que columna aumente 1+1 
            if(parqueadero[fila][columna]== 0) 
                nLibres++;
    return nLibres;
}
 
void AparcarVehiculo(int parqueadero[NFILAS][NCOLUMNAS],int *nLibres,int *nOcupadas)
{
    bool estacionado;
    int fila,columna;
 
    if(*nLibres > 0){
        do{
            estacionado = false;
            cout << "\t\t\t\1\t Introduce el numero de la fila: ";
            cin >> fila;
            cout << "\t\t\t\2\t Introduce el numero de la columna: ";
            cin >> columna;
            switch(parqueadero[fila][columna])
            {
                case 0:
                    parqueadero[fila][columna]=1;
                    (*nLibres)--;
                    (*nOcupadas)++;
                    estacionado= true;
                    cout << "\n\n\n\t\t\t\tVehiculo aparcado satisfactoriamente" << endl;
                    break;
                case 1:
                    cout << "\n\n\n\t\t\t\tPuesto ya ocupada" << endl;
                    break;
                case 2:
                    cout << "\n\n\n\t\t\t\tNo se puede parquear en las esquinas" << endl;
                    break;
                case 3:
                    cout << "\n\n\n\t\t\t\tNo se puede parquear en los caminos de paso" << endl;
                    break;
                case 4:
                    cout << "\n\n\n\t\t\t\tNo se puede parquear en las entradas" << endl;
                    break;
                case 5:
                    cout << "\n\n\n\t\t\t\tNo se puede parquear en las salidas" << endl;
                    break;
                default:
                    cout << "\n\n\n\t\t\t\tNo existe esa posicion" << endl;
            }
        }while(estacionado != true);
    }else{
        cout << "\n\n\n\t\t\t\tNo quedan puestos libres" << endl;
    }
}
 
void RetirarVehiculo(int parqueadero[NFILAS][NCOLUMNAS],int *nLibres,int *nOcupadas)
{
    bool liberado;
    int fila,columna;
 
    if(*nOcupadas > 0){
        do{
            liberado = false;
            cout << "\t\t\t\1\t Introduce el numero de la fila: ";
            cin >> fila;
            cout << "\t\t\t\2\t Introduce el numero de la columna: ";
            cin >> columna;
            if(parqueadero[fila][columna]==1){
                parqueadero[fila][columna]=0;
                liberado=true;
                (*nLibres)++;
                (*nOcupadas)--;
                cout << "\n\n\n\t\t\t\tEl vehiculo se retiro satisfactoriamente" << endl;
            }else{
                cout << "\n\n\n\t\t\t\tLa posicion indicada no esta ocupada, intentelo de nuevo" << endl;
            }
        }while(liberado == false);
    }else{
        cout << "\n\n\n\t\t\t\tNo hay puestos ocupados" << endl;
    }
}
 
void ListarPuestos(int parqueadero[NFILAS][NCOLUMNAS])
{
    for(int fila=0;fila<NFILAS;fila++)
        for(int columna=0;columna<NCOLUMNAS;columna++)
            if(parqueadero[fila][columna]==1)
                cout << "\n\n\n\t\t\t\tpuesto en fila " << fila << " columna " << columna << " ocupada" << endl;
            else if(parqueadero[fila][columna]==0)
                cout << "\n\n\n\t\t\t\tpuesto en fila " << fila << " columna " << columna << " libre" << endl;
}
 
int main(int argc, char* argv[])
// mapa del parqueadero 2 son esquinas 3 son caminos 4 entrada y 5 salida
{
    int parqueadero[8][8]={{2,0,0,0,0,0,0,4}, // matriz que contiene el parquedero
                           {3,3,3,3,3,3,3,3},
                           {3,0,0,0,0,0,0,3},
                           {3,3,3,3,3,3,3,3},
                           {3,0,0,0,0,0,0,3},
                           {3,3,3,3,3,3,3,3},
                           {3,0,0,0,0,0,0,3},
                           {5,3,3,3,3,3,3,2}};
    int nLibres,nOcupadas=0,op;
 
    nLibres=ObtenerNumPuestosLibres(parqueadero);
 
    do{
        op=MostrarMenu();
 
        bool estacionado,liberado;
 
        switch(op){
            case 0:
                break;
            case 1:
                AparcarVehiculo(parqueadero,&nLibres,&nOcupadas);
                system("PAUSE");
                break;
            case 2:
                RetirarVehiculo(parqueadero,&nLibres,&nOcupadas);
                system("PAUSE");
                break;
            case 3:
                ListarPuestos(parqueadero);
                system("PAUSE");
                break;
            default:
                cout << "\n\n\n\t\t\t\tLo siento opcion incorrecta, vuelva a intentarlo" << endl;
                system("PAUSE");
        }
    }while(op != 0);
    return 0;
}

