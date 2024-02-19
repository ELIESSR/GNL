# Get Next Line

## read_line


```c
char	*read_line(int fd, char *strs)
```
### Descripción
Esta función se encarga de leer una línea desde el descriptor de archivo especificado (fd) y almacenarla en una cadena de caracteres (strs). Utiliza un bucle para leer bloques de datos del archivo hasta encontrar un salto de línea o hasta que no haya más datos para leer.

###Parámetros
fd: El descriptor de archivo del cual se leerá la línea.
strs: La cadena de caracteres en la que se almacenará la línea leída.
Devolución
La función devuelve un puntero a la cadena de caracteres que contiene la línea leída, o NULL si ocurre algún error durante la lectura.

###Uso
