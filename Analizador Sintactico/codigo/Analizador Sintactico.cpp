#include <stdlib.h>
#include <iostream>

using namespace std;

#include "lexico.h"
#include "sintactico.h"
#include "stdio.h"

void analizarSintacticoArchivo();

int main(){
    llenarAutomatas();

    string cadena;
    system("cls");
    system("color CF");
    /*cout<<"\t\t::Analizador Sintactico - Lenguaje: C+ ::"<<endl;
    cout<<"\nIngresa una cadena para analizar: "; fflush(stdin); getline(cin,cadena);
    analizar_cadena_sintactico(cadena);*/
    analizarSintacticoArchivo();
return 0;
}

string escanearNombreArchivo() {
    string archivo;
    system("CLS");
    setlocale(LC_CTYPE,"Spanish");
    cout << endl << "\t\tAnalizador Sintáctico" << endl;
    cout << endl << "\tIngrese nombre del archivo: ";
    getline(cin,archivo);
    cout << endl << "\t";
    return archivo;
}

void analizarSintacticoArchivo() {
    char opc;
    bool continuarAnalizando = true;
    fflush(stdin);
    while(continuarAnalizando) {
        analizarArchivo(escanearNombreArchivo());
        cout << endl << endl << "\t¿Desea continuar analizando cadenas (S/N)? ";
        cin >> opc;
        if((opc == 's') || (opc == 'S')) {
            continuarAnalizando = true;
        } else {
            continuarAnalizando = false;
        }
        cin.get();
    }
}
