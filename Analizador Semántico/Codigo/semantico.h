#ifndef SEMANTICO_H_INCLUDED
#define SEMANTICO_H_INCLUDED
#include "lexico.h"
#include "conio.h"
#include "semantico.h"
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <stack>


struct variable
{
    string nombre;
    string tipo_de_dato;
    bool usado = false;
};

vector<variable> declaraciones;

bool existe_variable(string identificador){
    for(int i=0;i<declaraciones.size();i++){
        if(declaraciones[i].nombre==identificador){
            return true;
        }
    }
    return false;
}

bool mismo_tipo(string x1,string x2){
    string tipo1,tipo2;
    for(int i=0;i<declaraciones.size();i++){
        if(declaraciones[i].nombre==x1){
            tipo1=declaraciones[i].tipo_de_dato;
        }
        if(declaraciones[i].nombre==x2){
            tipo2=declaraciones[i].tipo_de_dato;
        }
    }
    if(tipo1==tipo2){
        return true;
    }
    else{
        return false;
    }
}

bool coincide_tipo(string identificador,string tipo){
    for(int i=0;i<declaraciones.size();i++){
        if(declaraciones[i].nombre==identificador){
            if(declaraciones[i].tipo_de_dato==tipo){
                return true;
            }
        }
    }
    return false;
}

void cambiar_estado(string identificador){
    for(int i=0;i<declaraciones.size();i++){
        if(declaraciones[i].nombre==identificador){
            declaraciones[i].usado = true;
        }
    }
}

void mostrar_no_usadas(){
    for(int i=0;i<declaraciones.size();i++){
        if(declaraciones[i].usado==false){
            cout<<endl<<"\t<WARNING: VARIABLE "<<declaraciones[i].nombre<<" DECLARADA PERO NO USADA>"<<endl;
        }
    }
}


#endif // SEMANTICO_H_INCLUDED
