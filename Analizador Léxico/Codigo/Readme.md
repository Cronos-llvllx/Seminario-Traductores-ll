Analizador Léxico Completo

Este programa está basado en un autómata de estados. Las gramáticas que acepta son las siguientes:

identificadores = letra(letra|digito)*

Real = entero.entero+

Real= entero.entero

Operador de adición: + | -

Operador de multiplicación: * | /

Operador de asignación: =

Operador relacional: < | > | <= | >= | != | ==

Operador And: &&

Operador Or: ||

Operador Not: !

Parentesis: ( , )

Llave: { , }

Punto y coma: ;

Además de las siguientes palabras reservadas: if, while, return, else, int, float

Funciones:

EsLetra
Esta función retorna true si el caracter analizado corresponde a una letra

EsDigito
Esta función retorna true si el caracter analizado corresponde a un dígito

AutomataLexico
Esta función recibe una cadena y la analiza. Está basada en el siguiente autómata:

![Image text](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20L%C3%A9xico/Codigo/Capturas/FullLexicoAutomata.PNG)

Donde:

Cada estado está dentro de una sentencia switch
Si al final del switch no se encuentra en un estado de aceptación, retorna error -1
Dependiendo del estado de aceptación retorna un valor entero
Imprime en pantalla el tipo de Símbolo identificado
Imprime en pantalla el estado donde se quedó de ocurrir un error.


Ejemplo de salida:
![Image text2](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20L%C3%A9xico/Codigo/Capturas/EjemploSalidaError.PNG)
![Image text3](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20L%C3%A9xico/Codigo/Capturas/EjemploSalidaId.PNG)
![Image text4](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20L%C3%A9xico/Codigo/Capturas/EjemploSalidaOp.PNG)
