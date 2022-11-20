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
![Ejemplo2](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/ArchivoAnalizar.PNG)
Si escogemos la opción de suma por ejemplo veremos que aparece analizando sintáctica y semánticamente el archivo, de la siguiente forma. Si está correctamente escrito, procede a cargar la función de ensamblador para ejecutar la operación, de lo contrario no lo hará.
![Ejemplo3](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSuma.PNG)
Se ejecuta la suma de acuerdo al código de ensamblador
![Ejemplo4](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSuma2.PNG)

![Ejemplo5](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/Funciones.PNG)
Se abre el programa y aparece un menú para escoger
![Ejemplo6](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/MenuGeneradorDC%C3%B3digo.PNG)
Aquí se muestran resultados de operaciones como el seno, raíz o tangente hiperbólica.
![Ejemplo7](https://github.com/Cronos-llvllx/Seminario-Traductores-ll/blob/main/Generaci%C3%B3n%20de%20c%C3%B3digo/codigo/capturas/EjSeno%2CRaiz%2CTangenteHipe.PNG)



