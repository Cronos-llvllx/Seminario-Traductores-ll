#include <stdlib.h>
#include <iostream>
using namespace std;

struct palabra{
    string tipo;
    string caracter;
    string descripcion;
};

int main(){
string cadena;
palabra arreglo[54];
//Aritmeticos
arreglo[0].tipo="Aritmetico";
arreglo[0].caracter="+";
arreglo[0].descripcion="Suma";
arreglo[1].tipo="Aritmetico";
arreglo[1].caracter="-";
arreglo[1].descripcion="Resta";
arreglo[2].tipo="Aritmetico";
arreglo[2].caracter="*";
arreglo[2].descripcion="Multiplicacion";
arreglo[3].tipo="Aritmetico";
arreglo[3].caracter="/";
arreglo[3].descripcion="Division";
arreglo[4].tipo="Aritmetico";
arreglo[4].caracter="%";
arreglo[4].descripcion="Modulo";
arreglo[5].tipo="Aritmetico";
arreglo[5].caracter="=";
arreglo[5].descripcion="Asignacion";

//Comparacion
arreglo[6].tipo="Comparacion";
arreglo[6].caracter="<";
arreglo[6].descripcion="Menor que";
arreglo[7].tipo="Comparacion";
arreglo[7].caracter="<=";
arreglo[7].descripcion="Menor o igual que";
arreglo[8].tipo="Comparacion";
arreglo[8].caracter=">";
arreglo[8].descripcion="Mayor";
arreglo[9].tipo="Comparacion";
arreglo[9].caracter=">=";
arreglo[9].descripcion="Mayor o igual que";
arreglo[10].tipo="Comparacion";
arreglo[10].caracter="!=";
arreglo[10].descripcion="Diferente de";
arreglo[11].tipo="Comparacion";
arreglo[11].caracter="==";
arreglo[11].descripcion="Igual";

//Lógicos
arreglo[12].tipo="Logico";
arreglo[12].caracter="!";
arreglo[12].descripcion="Negacion logica";
arreglo[13].tipo="Logico";
arreglo[13].caracter="&&";
arreglo[13].descripcion="AND Logico";
arreglo[14].tipo="Logico";
arreglo[14].caracter="||";
arreglo[14].descripcion="OR Logico";

//Palabras reservadas
arreglo[15].tipo="Palabra reservada";
arreglo[15].caracter="break";
arreglo[15].descripcion="Permite salir de un bucle";
arreglo[16].tipo="Palabra reservada";
arreglo[16].caracter="if";
arreglo[16].descripcion="Estructura de control - Condicional Simple";
arreglo[17].tipo="Palabra reservada";
arreglo[17].caracter="else";
arreglo[17].descripcion="Estructura de control - Condicional Doble";
arreglo[18].tipo="Palabra reservada";
arreglo[18].caracter="while";
arreglo[18].descripcion="Ciclo";
arreglo[19].tipo="Palabra reservada";
arreglo[19].caracter="for";
arreglo[19].descripcion="Ciclo";
arreglo[20].tipo="Palabra reservada";
arreglo[20].caracter="do";
arreglo[20].descripcion="Ciclo";
arreglo[21].tipo="Palabra reservada";
arreglo[21].caracter="switch";
arreglo[21].descripcion="Estructura de control - Condicional Multiple";
arreglo[22].tipo="Palabra reservada";
arreglo[22].caracter="delete";
arreglo[22].descripcion="Liberar memoria dinamica";
arreglo[23].tipo="Palabra reservada";
arreglo[23].caracter="const";
arreglo[23].descripcion="Almacenamiento permanente de variable";
arreglo[24].tipo="Palabra reservada";
arreglo[24].caracter="class";
arreglo[24].descripcion="Define una clase";
arreglo[25].tipo="Palabra reservada";
arreglo[25].caracter="continue";
arreglo[25].descripcion="Finaliza un bucle";
arreglo[26].tipo="Palabra reservada";
arreglo[26].caracter="struct";
arreglo[26].descripcion="Define una estructura";
arreglo[27].tipo="Palabra reservada";
arreglo[27].caracter="new";
arreglo[27].descripcion="asigna memoria dinamica";
arreglo[28].tipo="Palabra reservada";
arreglo[28].caracter="true";
arreglo[28].descripcion="Variable con valor asignado verdadero";
arreglo[29].tipo="Palabra reservada";
arreglo[29].caracter="false";
arreglo[29].descripcion="Variable con valor asignado falso";
arreglo[30].tipo="Palabra reservada";
arreglo[30].caracter="private";
arreglo[30].descripcion="Declara elemento privado";
arreglo[31].tipo="Palabra reservada";
arreglo[31].caracter="public";
arreglo[31].descripcion="Declara elemento publico";
arreglo[32].tipo="Palabra reservada";
arreglo[32].caracter="protected";
arreglo[32].descripcion="Declara elemento protegido";
arreglo[33].tipo="Palabra reservada";
arreglo[33].caracter="return";
arreglo[33].descripcion="Indica valor de retorno";
arreglo[34].tipo="Palabra reservada";
arreglo[34].caracter="static";
arreglo[34].descripcion="Variable ubicada estaticamente";
arreglo[35].tipo="Palabra reservada";
arreglo[35].caracter="this";
arreglo[35].descripcion="Puntero a objeto actual";
arreglo[36].tipo="Palabra reservada";
arreglo[36].caracter="nullptr";
arreglo[36].descripcion="Puntero a nulo";
arreglo[37].tipo="Palabra reservada";
arreglo[37].caracter="case";
arreglo[37].descripcion="Etiqueta a casos de sentencia";

//Tipo de Dato
arreglo[38].tipo="Tipo de Dato";
arreglo[38].caracter="int";
arreglo[38].descripcion="Entero";
arreglo[39].tipo="Tipo de Dato";
arreglo[39].caracter="float";
arreglo[39].descripcion="Flotante";
arreglo[40].tipo="Tipo de Dato";
arreglo[40].caracter="bool";
arreglo[40].descripcion="Booleano";
arreglo[41].tipo="Tipo de Dato";
arreglo[41].caracter="char";
arreglo[41].descripcion="Caracter";
arreglo[42].tipo="Tipo de Dato";
arreglo[42].caracter="string";
arreglo[42].descripcion="Cadena";
arreglo[43].tipo="Tipo de Dato";
arreglo[43].caracter="signed";
arreglo[43].descripcion="Entero con signo";
arreglo[44].tipo="Tipo de Dato";
arreglo[44].caracter="short";
arreglo[44].descripcion="Entero pequeño";
arreglo[45].tipo="Tipo de Dato";
arreglo[45].caracter="long";
arreglo[45].descripcion="Entero largo";
arreglo[46].tipo="Tipo de Dato";
arreglo[46].caracter="void";
arreglo[46].descripcion="Indica no existencia un valor de retorno";

//Signos de agrupacion
arreglo[47].tipo="Signos de agrupacion";
arreglo[47].caracter="{";
arreglo[47].descripcion="Abre llave";
arreglo[48].tipo="Signos de agrupacion";
arreglo[48].caracter="}";
arreglo[48].descripcion="Cierra llave";
arreglo[49].tipo="Signos de agrupacion";
arreglo[49].caracter="[";
arreglo[49].descripcion="Abre corchete";
arreglo[50].tipo="Signos de agrupacion";
arreglo[50].caracter="]";
arreglo[50].descripcion="Cierra corchete";
arreglo[51].tipo="Signos de agrupacion";
arreglo[51].caracter="(";
arreglo[51].descripcion="Abre parentesis";
arreglo[52].tipo="Signos de agrupacion";
arreglo[52].caracter=")";
arreglo[52].descripcion="Cierra parentesis";

int op=0;
int transiciones_reales[4][3] = {{1,3,2},{3,3,2},{3,1,2},{3,3,3}};
int transiciones_identificadores[3][3] = {{1,2,1},{1,1,1,},{2,2,2}};
int estado,columna;
bool encontrado,invalido;
do{
    estado=0; columna=0;
    encontrado=false; invalido=false;
    system("cls");
    system("color B1");
    cout<<"\t\t::Analizador Lexico::"<<endl;
    cout<<"\nIngresa una cadena para analizar: "; cin>>cadena;
    cout<<endl;
    for(int i=0;i<54;i++){
        if(cadena==arreglo[i].caracter){
            cout<<"\n\t"<<"'"<<cadena<<"'"<<" : "<<arreglo[i].descripcion<<"\n\t"<<arreglo[i].tipo<<endl<<endl;
            encontrado=true;
        }
    }
    if(encontrado==false){
        for(int i=0;i<cadena.length();i++){
            switch(cadena[i]){
                case '+':case '-':
                    columna = 0;
                    break;
                case '.':
                    columna = 1;
                    break;
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    columna = 2;
                    break;
                default:
                    invalido = true;
                    break;
            }
            estado = transiciones_reales[estado][columna];
            if(estado==3){
                break;
            }
        }
        if(estado == 2 && invalido == false){
            cout<<"\n\t"<<"'"<<cadena<<"'"<<" : "<<"es un numero real."<<endl<<endl;
            encontrado=true;
        }
        if(encontrado==false){
            invalido=false;
            estado=0; columna=0;
            for(int i=0;i<cadena.length();i++){
                switch(cadena[i]){
                    case '_':
                        columna = 0;
                        break;
                    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                        columna = 1;
                        break;
                    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
                        columna = 2;
                        break;
                    default:
                        invalido = true;
                        break;
                }
                estado = transiciones_identificadores[estado][columna];
                if(estado==2){
                    break;
                }
            }
            if(estado == 1 && invalido == false){
                cout<<"\n\t"<<"'"<<cadena<<"'"<<" : "<<"es un identificador."<<endl<<endl;
                encontrado=true;
            }
            if(encontrado==false){
                cout<<endl<<"\tLa palabra no forma parte del lenguaje."<<endl<<endl;
            }
        }
    }
    cout<<"\nDeseas intentar de nuevo (1=Si | 2=No): ";
    cin>>op;
}
while(op==1);
return 0;
}
