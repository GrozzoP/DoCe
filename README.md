# DoCe
**Nombre de grupo**: Mango

--------
## Requisitos previos para jugar

### Descargar e instalar cURL

1) Se debe descargar cURL según el sistema operativo que poseas en esta URL: https://curl.se/windows/
![image](https://github.com/user-attachments/assets/3bcdde58-ad96-41e2-a752-fbc47faeadcf)

2) Una vez descargado, descomprimir el archivo.
3) Almacenar la carpeta donde sepa que dificilmente la elimine a futuro.
4) Se debe agregar a la _variable de entorno del sistema_ la ubicacion de la carpeta BIN, con origen en la carpeta descomprimida.
 
![Screenshot_60](https://github.com/user-attachments/assets/04cb740e-db2a-41a4-a62b-02d51b88dcef)
![Screenshot_58](https://github.com/user-attachments/assets/7e0b33fc-44ea-4433-8a0a-5a6939a681c9)
![Screenshot_59](https://github.com/user-attachments/assets/8ee42e82-37a5-4cff-9a64-81c2c508fb57)

5) Ejecutar Codeblocks, e ingresar en la parte de _Settings_ -> _Compiler_ -> _Linker Settings_
6) Agregar la ubicación de **lib\libcurl.a** relativo a la libreria cURL.
![Screenshot_61](https://github.com/user-attachments/assets/a67b6885-0c3c-442b-8d6b-91721cd3fae7)

5) Ingresar en la parte de _Settings_ -> _Compiler_ -> _Search directories_
6) Agregar la ubicación de **include** relativo a la libreria cURL, en la solapa de _Compiler_ y _Resource Compiler_.

![Screenshot_62](https://github.com/user-attachments/assets/77a62563-264d-4208-9944-aec3f06f49b8)

6) Agregar la ubicación de **lib** relativo a la libreria cURL, en la solapa de _Linker_.

![Screenshot_63](https://github.com/user-attachments/assets/afe35b04-1106-4b40-9c2b-06919ae38418)

7) En caso de que no todavía no pueda acceder al uso de la librería, agregar en _Other linker options_, lo siguiente:
```
-lcurl
-lws2_32
-lssl
-lcrypto
-lz
```

---------------
## Instrucciones para jugar
En el inicio del juego, se presenta un menú con tres opciones.

* **[1] Jugar**
+ **[2] Ver Ranking**
- **[3] Salir**

### [1] Jugar
Permite acceder a jugar _DoCe_ contra la IA.

1) Se ingresa el nombre del jugador.
2) Seleccionar la dificultad de la IA
	* [1] Facil
 	* [2] Normal
   	* [3] Difícil
3) Se muestra la interfaz gráfica del juego, el usuario puede ver sus cartas y claramente no puede visualizar las del rival.
4) Además de exhibirlas gráficamente, se mostrará una lista de las cartas en mano con un respectivo identificador numérico, para seleccionar la carta por consola.
5) Cada vez que se acaben las cartas del mazo del cual se toman para tener 3 cartas en mano, se vuelve a ordenar el mazo.
6) La partida continua hasta que uno de los dos jugadores llega a 12 o más puntos.

Una vez finalizada la partida, se dictamina y se muestra el ganador por pantalla, el cual será subido a la API para quedar registrado en el ranking.
Se genera un informe mediante un archivo de texto, con el siguiente formato:
```
informe-juego_AAAA-MM-DD-HH-MM
A -> Año
M -> Mes
D -> Dia
H -> Hora
M -> Minuto
```
El informe generado automáticamente, contendrá la siguiente información vinculada a la partida:
* **CARTA_SELECCIONADA**: La carta que se jugó por cada jugador
* **PUNTAJE_ACUMULADO**: El puntaje que posee el jugador hasta el momento de un determinado turno.
* **TURNO**: Indica el número de turno.
  
_Partida a modo de ejemplo_
![Screenshot_64](https://github.com/user-attachments/assets/1e2752fc-6300-47f7-b59f-9a7200cc7383)

### [2] Ver Ranking
Visualizar los jugadores de mayor a menor cantidad de victorias en forma descendente.

### [3] Salir
En el caso de que no se quiera acceder a ninguna de las anteriores opciones, se puede optar por salir de la consola para jugar o ver el ranking.

