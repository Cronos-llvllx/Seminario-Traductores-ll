#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <vector>

#define _USE_MATH_DEFINES
#define M_PI   3.14159265358979323846
#define M_E    2.71828182818281828182

using namespace std;

#include "lexico.h"
#include "sintactico.h"
#include "semantico.h"
#include "stdio.h"

int suma( int $a, int $b){
int $result;
__asm__ __volatile__(
		"movl %1, %%eax;"
		"movl %2, %%ebx;"
		"addl %%ebx, %%eax;"
	    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
);
return $result ;
}

int resta( int $a, int $b){
int $result;
__asm__ __volatile__(
		"movl %1, %%eax;"
		"movl %2, %%ebx;"
		"subl %%ebx, %%eax;"
	    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
);
return $result ;
}

float multiplicacion( float x, float y ) {
    float resultado;
    __asm__ __volatile__ (
        "fld %1;"
        "fld %2;"
        "fmulp;"
        "fst %0;" : "=m" (resultado) : "g" (x), "g" (y)
    ) ;
    return resultado;
}

float division( float x, float y ) {
    float resultado;
    __asm__ __volatile__ (
        "fld %2;"
        "fld %1;"
        "fdivp;"
        "fst %0;" : "=m" (resultado) : "g" (x), "g" (y)
    ) ;
    return resultado;
}

int potencia( int $a, int $b ) {
    int $result;
    __asm__ __volatile__(		// Invoca funciones de ensamblador

        "movl %1, %%eax;"	// Registro EAX = variable $a (base)
        "movl %1, %%ebx;"	// Registro EBX = variable $a (base)
        "movl %2, %%ecx;"	// Registro ECX = variable $b (exponente)
        "cmpl $1, %%ecx;"	// Compara el exponente con 1
        "je UNO;"			// Si es igual a 1 salta a UNO
        "jl CERO;"			// Si es igual a 0 salta a CERO
        "decl %%ecx;"		// Decrementa en uno a ECX
        "POTENCIA: imull %%ebx;"	// EAX = EAX * EBX
            "loopl POTENCIA;"		// Cicla POTENCIA hasta que ECX = 0
        "jmp FIN;"				// Salta a FIN
        "UNO: jmp FIN;"			// Salta a FIN
        "CERO: movl $1,%%eax;"	// EAX = 1 (Si exponente es 0)
            "jmp FIN;"			// Salta a FIN
        "FIN: movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result;
}

float raiz( float x) {
    float resultado;
    __asm__ __volatile__ (
        "fld %1;"
        "fsqrt;"
        "fst %0;" : "=m" (resultado) : "g" (x)
    ) ;
    return resultado;
}

long double seno(long double grados)
{
    grados=(grados*M_PI)/180;
    register long double resultado;

    __asm__ __volatile__(
        "fsin" : "=t" (resultado) : "0" (grados)
    );
    return resultado;
}

long double coseno(long double grados)
{
    grados=(grados*M_PI)/180;
    register long double resultado;

    __asm__ __volatile__(
        "fcos" : "=t" (resultado) : "0" (grados)
    );
    return resultado;
}

float potencia_euler( float x, int y ) {
    float resultado = 1;
    __asm__ __volatile__ (
        "movl %2,%%eax;"
        "cmp $0,%%eax;"
        "je SALIR;"
        "cmp $1,%%eax;"
        "je POT_UNO;"
        "decl %%eax;"
        "fld %1;"
        "fld %1;"
        "REPITE:"
        "fmulp;"
        "decl %%eax;"
        "cmp $0, %%eax;"
        "je FINAL;"
        "fst %0;"
        "fld %0;"
        "fld %1;"
        "jmp REPITE;"
        "FINAL:"
        "fst %0;"
        "jmp SALIR;"
        "POT_UNO:"
        "movl %1,%%eax;"
        "movl %%eax,%0;"
        "SALIR:"

        : "=m" (resultado) : "g" (x), "g" (y)
    ) ;
    return resultado;
}

float seno_hiperbolico( float x, float y ) {
    float resultado,div=2;
    __asm__ __volatile__ (
        "fld %3;"
        "fld %2;"
        "fld %1;"
        "fsubp;"
        "fdivp;"
        "fst %0;" : "=m" (resultado) : "g" (x), "g" (y), "g" (div)
    ) ;
    return resultado;
}

float coseno_hiperbolico( float x, float y ) {
    float resultado,div=2;
    __asm__ __volatile__ (
        "fld %3;"
        "fld %2;"
        "fld %1;"
        "faddp;"
        "fdivp;"
        "fst %0;" : "=m" (resultado) : "g" (x), "g" (y), "g" (div)
    ) ;
    return resultado;
}

int main()
{

        setlocale(LC_CTYPE,"Spanish");
        int op;
        int a,b;
        bool procede;
        string prototype;
        float x,y;
        system("color F1");
        while(true)
        {
            system("cls");
            procede=false;
            declaraciones.clear();
            cout<<"\t::Generación de Codigo::";
            cout<<"\n\nOperación a realizar: "<<endl<<endl;
            cout<<"1.Suma (+).";
            cout<<"\n2.Resta (-).";
            cout<<"\n3.Multiplicación (*).";
            cout<<"\n4.División (/).";
            cout<<"\n5.Potencia (^).";
            cout<<"\n6.Raíz Cuadrada. (V¯¯)";
            cout<<"\n7.Seno.";
            cout<<"\n8.Coseno.";
            cout<<"\n9.Tangente.";
            cout<<"\n10.Seno Hiperbólico.";
            cout<<"\n11.Coseno Hiperbólico.";
            cout<<"\n12.Tangente Hiperbólica.";
            cout<<"\n0.Salir.";
            cout<<"\n\nIngresa una opción (número): "; fflush(stdin); cin>>op;
            if(op==1){
                cout<<"\nSuma (+).";
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSuma (+).";
                        cout<<endl<<endl<<"Ingresa el primer número: "; cin>>a;
                        cout<<"Ingresa el segundo número: "; cin>>b;
                        cout<<"\nResultado = "<<suma(a,b)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==2){
                cout<<"\nResta (-).";
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nResta (-).";
                        cout<<endl<<endl<<"Ingresa el primer número: "; cin>>a;
                        cout<<"Ingresa el segundo número: "; cin>>b;
                        cout<<"\nResultado = "<<resta(a,b)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==3){
                cout<<"\nMultiplicación (*)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nMultiplicación (*)."<<endl;
                        cout<<endl<<endl<<"Ingresa el primer número: "; cin>>x;
                        cout<<"Ingresa el segundo número: "; cin>>y;
                        cout<<"\nResultado = "<<multiplicacion(x,y)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==4){
                cout<<"\nDivisión (/)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nDivisión (/)."<<endl;
                        cout<<endl<<endl<<"Ingresa el primer número: "; cin>>x;
                        cout<<"Ingresa el segundo número: "; cin>>y;
                        if(y==0){
                            cout<<"\nERROR: Division por cero";
                        }
                        else{
                            cout<<"\nResultado = "<<division(x,y)<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==5){
                cout<<"\nPotencia (^)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nPotencia (^)."<<endl;
                        cout<<endl<<endl<<"Ingresa el primer número: "; cin>>a;
                        cout<<"Ingresa el segundo número: "; cin>>b;
                        if(b>=0){
                            cout<<"\nResultado = "<<potencia(a,b)<<endl;
                        }
                        else{
                            b=b*-1;
                            cout<<"\nResultado = "<<division(1,potencia(a,b))<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==6){
                cout<<"\nRaíz Cuadrada (V¯¯)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nRaíz Cuadrada (V¯¯)."<<endl;
                        cout<<endl<<endl<<"Ingresa un número: "; cin>>x;
                        if(x<0){
                            cout<<"\nERROR: Las raíces negativas no forman parte de los reales.";
                        }
                        else{
                            cout<<"\nResultado = "<<raiz(x)<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==7){
                cout<<"\nSeno."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSeno."<<endl;
                        cout<<endl<<endl<<"Ingresa un número: "; cin>>x;
                        cout<<"\nResultado = "<<seno(x)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==8){
                cout<<"\nCoseno."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nCoseno."<<endl;
                        cout<<endl<<endl<<"Ingresa un número: "; cin>>x;
                        cout<<"\nResultado = "<<coseno(x)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==9){
                cout<<"\nTangente."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nTangente."<<endl;
                        cout<<endl<<endl<<"Ingresa un número: "; cin>>x;
                        cout<<"\nResultado = "<<seno(x)/coseno(x)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==10){
                float euler_pos,euler_neg;
                cout<<"\nSeno Hiperbólico."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSeno Hiperbólico."<<endl;
                        cout<<endl<<endl<<"Ingresa el número en grados: "; cin>>x;
                        euler_pos=potencia_euler(M_E,x);
                        euler_neg=division(1,euler_pos);
                        cout<<"\nResultado = "<<seno_hiperbolico(euler_pos,euler_neg)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==11){
                float euler_pos,euler_neg;
                cout<<"\nCoseno Hiperbólico."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nCoseno Hiperbólico."<<endl;
                        cout<<endl<<endl<<"Ingresa el número en grados: "; cin>>x;
                        euler_pos=potencia_euler(M_E,x);
                        euler_neg=division(1,euler_pos);
                        cout<<"\nResultado = "<<coseno_hiperbolico(euler_pos,euler_neg)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==12){
                float euler_pos,euler_neg;
                long double grado;
                cout<<"\nTangente Hiperbólica."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nTangente Hiperbólica."<<endl;
                        cout<<endl<<endl<<"Ingresa el número en grados: "; cin>>grado;
                        euler_pos=potencia_euler(M_E,grado);
                        euler_neg=1/euler_pos;
                        //cout<<"\nResultado = "<<division(seno_hiperbolico(euler_pos,euler_neg),coseno_hiperbolico(euler_pos,euler_neg))<<endl;
                        cout<<"\nResultado = "<<sinh(grado)/cosh(grado)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontró la función del lenguaje.";
                }
            }
            else if(op==0){
             break;
            }
         getch();
        }
	return 0;
}
