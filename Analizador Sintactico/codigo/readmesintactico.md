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
