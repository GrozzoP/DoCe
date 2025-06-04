# **ESTRATEGIA DoCe**

## **Estructuras utilizadas**

* Para los mazos se utilizó la estructura ***lista simple enlazada***, debido a su sencilla utilización y libertad para recorrerla. También consideramos que el guardado de forma aleatoria sería más fácil de realizar. En un primer momento, se consideró utilizar una pila, ya que cada carta será tomada desde el tope y esto simularía un mazo perfectamente, pero se descartó la idea debido a que esto complejizaba innecesariamente el ordenamiento aleatorio de las cartas.  
* Para guardar los informes se utilizó la estructura ***cola***, debido a su lógica, cada informe de turno será guardado al final de la cola y al grabar en un archivo se tomará desde el comienzo, por lo que no habrá recorridos innecesarios y se grabará en el orden que ocurrieron los hechos.

*Aparte de estas estructuras, hemos creado algunas específicas para la aplicación…*

### ***tipoPoder***  
Es un *enum* que contiene todos los posibles poderes de las cartas. Sirve para diferenciar las cartas entre sí para realizar la aplicación adecuada del efecto.  
### ***tipoJugador***  
Identifica a los jugadores con nombre, el puntaje acumulado, y la mano de cartas que posee en cierto momento de la partida. Puede ser tanto la IA como una persona.  
### ***tMano***  
Es un vector estático de 3 cartas, que simbolizan la *mano* del jugador durante la partida. Es una forma de abstraer el código y hacerlo más legible.  
###***tJugada***  
Almacena la información relativa a ambos jugadores en cada turno, como el nombre, la carta jugada, y el puntaje acumulado.  
### ***tCarta***  
Simboliza una carta dentro del juego. Simplemente contiene el *tPoder* con el fin de abstraer el código y que el uso de las cartas sea más entendible.  
### ***tRespuesta***  
Almacena la información extraída desde la API en forma de un puntero a cadena junto a su tamaño, para que luego pueda ser leida y procesada por otras funciones.  
### ***tJugadorAPI***  
Simboliza la manera de comprender al jugador en la API, con su nombre y la cantidad de partidas ganadas. De esta manera, a la hora de mostrar el ranking o querer realizar una operacion con el listado de jugadores, se puede almacenar la información directamente en esta estructura.

**JUEGO**  
Para la estrategia del juego, se pensó un manejo genérico que no dependa completamente de quién juega primero o segundo al momento de procesar la lógica de una partida, la cual únicamente está condicionada por la dificultad de la IA a la hora de devolver qué carta utilizada, pero se maneja de la misma manera para todas las dificultades.

## Inicio  
Al comienzo del juego, se crea un archivo informe, que contendrá las rondas por partida con información relevante sobre el juego por cada turno:

* Número de turno  
* Nombre de jugador  
* Carta jugada  
* Puntos hasta el momento

Además, se procesarán los mazos, que son dos:

* **MazoA**: El principal de la partida, que contendrá todas las cartas ordenadas de forma aleatoria.  
* **MazoB**: El mazo de destino para las cartas descartadas.

Una vez finalizada la creación de mazos se crean y cargan ambos jugadores, tanto la IA, seleccionando la dificultad *(FÁCIL, NORMAL, DIFÍCIL)*, como la persona real, a los cuales se les asigna de forma aleatoria quién será el primer jugador y quién el segundo, guardando la posición en la que fue asignada la IA para su futura usanza.  
Del **mazoA** se cargará para cada jugador su primera mano, la cual consta de 3 cartas por jugador.  
Ambos jugadores junto a los mazos son enviados a una función *“partida”* la cual sirve como discriminante de la dificultad, basándonos en el nombre que contenga la IA, en este caso hardcodeado como IA\_(*FACIL o NORMAL o DIFICIL)* , dependiendo de dicho nombre, se envía una función llamada **obtener\_pos\_carta\_IA\_\[dificultad\]**, la cual seleccionará las cartas a jugar dependiendo del criterio de la dificultad seleccionada. La información vinculada con los mazos, registro de turnos, el primer jugador, segundo jugador, si empieza o no la IA, y la función vinculada con la elección de la carta según la dificultad, se envía a una función genérica **procesar\_partida**.

## Transcurso Partida  
La función internamente se ejecutará mientras que ningún jugador haya superado o igualado los *12 puntos*, verificando si el primer jugador es IA utilizando la posición dada al cargar los jugadores, o si es humano. En el caso de ser IA, actuará la función enviada por parámetro la cual devolverá la posición de la carta en la mano de la IA, así mismo de ser el primer jugador una persona, se le pedirá que seleccione la posición de su carta a utilizar. Una vez seleccionada, se descarta en el **mazoB** guardandola de forma aleatoria. De esto surge la siguiente cuestión:  
*¿Por qué de forma aleatoria cuando se descarta o se carga el mazoA?* Esto se debe a que si primero cargamos todo el mazo linealmente y luego procedemos a mezclarlo, estaríamos haciendo un doble proceso innecesario con las cartas, para evitar esto se guarda de forma aleatoria y así con un único manejo se obtiene un resultado más óptimo.  
Retomando con el curso del juego, se vuelve a tomar una carta del mazoA, que en caso de estar vacío, se intercambiara con el mazoB y se volverá a tomar una carta del mazoA ya con todas las cartas. Si dicha carta descartada por el jugador fuera una tipo *“REPETIR TURNO”*, primero que nada se registra hasta el momento la información de la partida *(carta descartada , carta del contrincante, que todavía no fue ninguna, y puntos al momento de ambos),* y luego se repetirá el proceso anteriormente mencionado.   
Una vez terminada la mano del primer jugador, sucedería exactamente lo mismo pero con el segundo jugador, verificando esta vez de forma inversa donde está la IA.  
En este caso de utilizar *“REPETIR TURNO”* el registro ya podría contener ambas cartas utilizadas hasta el momento.   
A continiuación de que ambos hayan seleccionado la carta a descartar, dependiendo que cartas sean, se asignan/restan los puntos a cada jugador acumulandolos turno tras turno, y se guardará nuevamente en la *cola informe* ambas cartas utilizadas y los puntos acumulados al momento con el número de turno en el que se jugaron. Esto se debe a que el primer registro de cada jugador es por sí solo utilizaron la carta especial _“REPETIR TURNO”_ ya que si no se hiciera esto, se perdería ese movimiento.  

## Final Partida  
Tan pronto como alguien obtenga los puntos necesarios *(\>=12)* el juego terminará. Se grabarán los informes por turno en un archivo, se escogerá el ganador basándose en la posición como tal de los jugadores, ya que, suponiendo que ambos tengan 12 puntos, o uno tenga 12 y otro 13, no importa la cantidad debido a que se toma a consideración que ambos jugadores llegaron a los puntos al mismo tiempo/turno por ende el primer jugador será el ganador, ya que por lógica fue el primero en llegar a la meta.   
Una vez obtenido el ganador, de ser una persona, se realizará una petición POST al ranking de victorias con el nombre del jugador.

Finalizado toda la lógica en torno al juego se vaciaron ambos mazos , así mismo la cola de informes ,esto por seguridad ya que se debería haber vaciado al momento de guardar el informe , las manos de cada jugador ya que al final ambos quedan con 3 cartas, se cerrará el archivo de informe y se dará por terminado el programa.
