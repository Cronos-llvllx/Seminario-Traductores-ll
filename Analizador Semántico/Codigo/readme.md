Analizador Semántico Completo

Cosas a analizar:
Errores semánticos: Hemos mencionado algunos de los errores que la semántica analizador semántico se espera para reconocer:
-No coinciden los tipos
-Variable no declarada
-Identificador reservado uso indebido.
-Declaración de variables múltiples en un ámbito.
-Acceder a una variable fuera de alcance.
-Parámetro formal y real no coincide.

El objetivo particular es crear un analizador semántico de un lenguaje el cual tendrá diferentes estructuras de lenguaje mediante el uso de autómatas que acepten dicho lenguaje.
El programa pedirá como entrada que escriba el nombre de un archivo de .txt el cual contiene el código a analizar, notificando que en caso de algún error de semántica lo muestre en pantalla. Tomando en cuenta que pueden existir anidaciones de diferentes estructuras de código:
El analizador semántico reconocerá las siguientes cuestiones y situaciones.
-REDECLARACIONES: Mostrará errores si existen re-declaraciones de variables en el código, solo puede declararse un nombre a la vez.
-USO DE VARIABLES: Mostrará alertas el compilador si alguna variable no ha sido usada.
-CONVERSIONES DE VARIABLES: Si una variable está queriendo tomar un valor que no corresponde a su tipo de dato, este mostrará un error.
-VARIABLES INCOMPATIBLES: No se pueden asignar variables de diferentes tipos de dato.
-REPETICIONES DE FUNCIONES: Las variables no pueden tener el mismo nombre que determinadas funciones declaradas.
-VARIABLES SIN DECLARACIÓN PREVIA: No se pueden usar variables que no hayan sido declaradas previamente.
-USO DE VARIABLES EN CONDICIONALES: Similar que el anterior pero enfocado a las condicionales usadas en el If y While.

Ejemplos de ejecución:
A continuación, se muestra una captura del archivo que se va a analizar después
Se abre el programa y se ingresa el nombre del archivo a analizar  
![Ejemplo1](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/AnalizarArchivo.PNG)  
![Ejemplo1.2](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/Ejemplo.PNG)  
El programa detectó un error en la línea 1 ya que como podemos observar se está declarando otra variable con el mismo nombre, 
después los errores posteriores son los de conversión de variables ya que var2; es una variable de tipo entero y si le asignamos v
alores de carácter o cadena mostrará dichos errores. También la variable var no ha sido declarada por lo cual no puede ser usada, 
el error de conversión de la variable hola siendo char o que la variable b tampoco ha sido declarada
![Ejemplo2](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/Ejemplo2.PNG)  
El programa detectó un error en la línea 10 de error de conversión de variable por tratar la asignación de char como un booleano,
y lo mismo con la asignación de strings con errores de conversiones de variable como se ve en la imagen.
![Ejemplo3](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/Ejemplo3.PNG)  
A su vez el programa muestra alertas cuando hay variables que no han sido utilizadas pero sí declaradas como se ve a continuación:
![Ejemplo4](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/ejemplo4.PNG)  


Diagrama de situaciones Semánticas:  
![Diagrama](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sem%C3%A1ntico/Codigo/capturas/DiagramaSitSemant.PNG)
