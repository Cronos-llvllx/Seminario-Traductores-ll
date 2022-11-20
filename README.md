# Seminario-Traductores-ll
Proyecto Final
Hecho por: Gomez Medina Hector Daniel
Mtro: Michel Emanuel Lopez Franco
10/11/2022

Etapa 1  
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

Etapa 2 Analizador Semantico:
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

Analizador Sintáctico Terminado
Etapa 3


Objetivo General
El objetivo general es realizar un compilador, un compilador es un tipo de traductor que transforma un programa entero de un lenguaje de programación
(llamado código fuente) a otro. Usualmente el lenguaje objetivo es código máquina, aunque también puede ser traducido a un código intermedio o a texto.
A diferencia de los intérpretes, los compiladores reúnen diversos elementos o fragmentos en una misma unidad (un programa ejecutable o una librería), 
que puede ser almacenada y reutilizada. Este proceso de traducción se conoce como compilación.

Objetivo Particular
El objetivo particular es crear un analizador sintáctico de un lenguaje el cual tendrá diferentes estructuras de lenguaje mediante el uso de autómatas que acepten dicho lenguaje.
El programa pedirá como entrada que escriba el nombre de un archivo de .txt el cual contiene el código a analizar, notificando que en caso de algún error de sintaxis lo muestre en pantalla.
Tomando en cuenta que pueden existir anidaciones de diferentes estructuras de código:

Ejemplos de ejecución
Se abre el programa y se ingresa el nombre del archivo a analizar
El programa detectó un error en la línea 1 ya que como podemos observar en la imagen le falta un ‘;’ y por lo general realiza un análisis de las llaves y las posteriores anidaciones
![Ejemplo1](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sintactico/codigo/capturas/EjEjecuci%C3%B3n.PNG)
![Ejemplo2](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sintactico/codigo/capturas/EjEjecuci%C3%B3n2.PNG)
![Ejemplo3](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sintactico/codigo/capturas/EjemploEjecuci%C3%B3n3.PNG)


Diagrama:
![Ejemplo4](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Analizador%20Sintactico/codigo/capturas/DiagramaCadenasAcept.PNG)

Etapa 4 Generador de código  
Introducción    
En esta actividad vamos a realizar el generador de código, para esto hicimos uso del lenguaje C++.
La generación de código consiste en relacionar todo lo que hemos hecho en nuestro compilador el cual ha llevado ya por tres fases de desarrollo:
-Analizador Léxico.
-Analizador Sintáctico.
-Analizador Semántico.
Se trata así pues de la última fase del compilador que hemos desarrollado, el cual tiene como función vincular las funciones de nuestro lenguaje con las puras de 
ensamblador.Existe una relación muy estrecha entre la programación en C y la programación en ensamblador. C fue creado para evitarle a los programadores del sistema 
operativo UNIX seguir escribiéndolo en ensamblador. Las ventajas de programar en C lo mismo que antes se programaba en ensamblador son obvias: portabilidad y legibilidad
a través de un código bien estructurado. Sin embargo las partes del sistema en las que es necesario trabajar con características específicas del hardware no pueden ser 
escritas en C.
En general hay dos estrategias para mezclar código en C con código en ensamblador. La primera consiste en compilar archivos escritos en C y ensamblar otros escritos en
código de ensamblador para luego enlazarlos todos juntos. La segunda se trata de embeber código escrito en ensamblador dentro de código escrito en C a través de algún 
mecanismo que ofrezca el compilador usado. En este artículo se tratará sólo la primera estrategia.
Muchos programadores se sienten más cómodos escribiendo en C, y por una buena razón: C es un lenguaje de nivel medio (en comparación con Assembly, que es un lenguaje 
de bajo nivel), y les ahorra a los programadores algunos de los detalles de la implementación real.
Sin embargo, hay algunas tareas de bajo nivel que pueden implementarse mejor en ensamblador o solo pueden implementarse en lenguaje ensamblador. Además,
con frecuencia es útil para el programador observar la salida del ensamblaje del compilador de C, y editar a mano u optimizar manualmente el código de ensamblaje de
formas que el compilador no puede. El ensamblaje también es útil para procesos críticos o en tiempo real, porque a diferencia de los lenguajes de alto nivel, 
no hay ambigüedad sobre cómo se compilará el código. El tiempo puede controlarse estrictamente, lo cual es útil para escribir controladores de dispositivo simples.

Objetivo General  
Análisis: se trata de la comprobación de la
corrección del programa fuente, según la definición del lenguaje en términos de teoría de lenguajes formales. 
Incluye las fases correspondientes al análisis léxico (que consiste en la descomposición del programa fuente en componentes léxicos), 
análisis sintáctico (agrupación de los componentes léxicos en frases gramaticales) y análisis semántico 
(comprobación de la validez semántica de las sentencias aceptadas en la fase de análisis sintáctico).
Síntesis: su objetivo es la generación de la salida
expresada en el lenguaje objeto y suele estar formado 
por una o varias combinaciones de fases de generación de código (normalmente se trata de código intermedio o de código objeto) 
y de optimización de código (en las que se busca obtener un programa objetivo lo más eficiente posible, según su complejidad 
computacional o complejidad de Kolmogórov: tiempo de ejecución, espacio durante ejecución, espacio para ser almacenado fuera de ejecución, etc.)

Objetivo particular  
El objetivo particular es crear un generador de código de un lenguaje el cual tendrá diferentes estructuras de lenguaje mediante el uso de autómatas que acepten dicho lenguaje.
El programa consiste en un menú con diferentes operaciones tanto aritméticas, trigonométricas e hiperbólicas donde el usuario puede capturar los datos y realizar la operación. Las operaciones se realizan mediante lenguaje de ensamblador, con la función _ASM_ _VOLATILE_ que es la que permite combinar las instrucciones de ensamblador con el lenguaje C y así mismo, usar nuestro lenguaje para poder cargar dichas funciones.
El generador de código reconocerá las siguientes cuestiones:
OPERACIONES ARITMÉTICAS (SUMA Y RESTA): Mediante código de ensamblador y el lenguaje creado previamente, el programa permitirá ejecutar las operaciones de Suma y Resta de dos números enteros.
OPERACIONES ARITMÉTICAS (MULTIPLICACIÓN Y DIVISION): Mediante código de ensamblador y el lenguaje creado previamente, el programa permitirá ejecutar las operaciones de Multiplicación y División validando esta ultima la división por 0, así como el uso de números en punto flotante.
OPERACIONES ARITMÉTICAS (POTENCIA Y RAIZ): Mediante código de ensamblador y el lenguaje creado previamente, el programa permitirá ejecutar las operaciones de Potencia y Raiz Cuadrada. Dicho programa valida el uso de potencias negativas y restringe la raíz cuadrada de negativos.
FUNCIONES TRIGONOMÉTRICAS: Mediante código de ensamblador y el lenguaje creado previamente, el programa permitirá ejecutar las funciones de seno, coseno y tangente en degrados.
FUNCIONES HIPERBOLICAS: Mediante código de ensamblador y el lenguaje creado previamente, el programa permitirá ejecutar las funciones de seno, coseno y tangente hiperbólicas en degrados.
USO DE LA FUNCIÓN VOLATILE: Con el uso de la función de ensamblador se podrá efectuar todas las operaciones.
USO DEL ANALIZADOR LÉXICO, SINTÁCTICO Y SEMÁNTICO: Con el uso del compilador se garantiza el uso de nuestro lenguaje.

Ejemplos de ejecución:

![Ejemplo1](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/DiagramaSitDelGeneradorDeC%C3%B3digo.PNG)  
A continuación, se muestra una captura del archivo que se va a analizar
![Ejemplo2](
https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/ArchivoAnalizar.PNG)  
Se abre el programa y aparece un menú para escoger  

![Ejemplo3](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/Funciones.PNG)   

![Ejemplo4](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/MenuGeneradorDC%C3%B3digo.PNG)   
Si escogemos la opción de suma por ejemplo veremos que aparece analizando sintáctica y semánticamente el archivo, de la siguiente forma. Si está correctamente escrito, procede a cargar la función de ensamblador para ejecutar la operación, de lo contrario no lo hará.  
![Ejemplo5](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSuma.PNG)  
Se ejecuta la suma de acuerdo al código de ensamblador
![Ejemplo6](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSuma2.PNG)  
Aquí se muestran resultados de operaciones como el seno, raíz o tangente hiperbólica.
![Ejemplo7](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSeno%2CRaiz%2CTangenteHipe.PNG)  
