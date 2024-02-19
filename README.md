# Get Next Line
---
La función get_next_line se utiliza para leer líneas de texto de un archivo o descriptor de archivo en C. Está diseñada para leer de manera eficiente líneas de un archivo, una a la vez, sin tener que leer todo el archivo de una sola vez en la memoria.

Aquí hay una descripción detallada de lo que hace la función:

Lee una línea del archivo: Utiliza la función read_line para leer una línea completa del archivo. Esta función se encarga de leer una línea del descriptor de archivo proporcionado.

Extrae la primera línea: Utiliza la función ft_printer para extraer la primera línea de la cadena de caracteres obtenida del archivo. Esta función encuentra el índice del primer salto de línea o el final de la cadena y extrae la parte de la cadena hasta ese punto.

Actualiza el estado interno: La función get_next_line utiliza una variable estática para mantener el estado entre llamadas. Esto le permite continuar leyendo desde donde lo dejó en la última llamada. Después de leer una línea, actualiza la variable estática para excluir la línea que acaba de leer.

Devuelve la línea leída: Devuelve un puntero a la línea leída del archivo. El usuario puede entonces utilizar esta línea en su programa.

En resumen, la función get_next_line proporciona una forma conveniente y eficiente de leer líneas de un archivo en C, facilitando el procesamiento de archivos de texto línea por línea sin cargar todo el archivo en la memoria.
---
## get_next_line
```c
char	*get_next_line(int fd)
```
### Descripción
Esta función toma un descriptor de archivo y devuelve la próxima línea disponible desde ese descriptor. Utiliza una variable estática para mantener el estado entre llamadas y asegurar que pueda continuar leyendo desde donde lo dejó en la última llamada.

### Parámetros
fd: El descriptor de archivo del cual se leerá la próxima línea.
Devolución
La función devuelve un puntero a la siguiente línea disponible desde el descriptor de archivo especificado.

### Uso
```c
char *line = get_next_line(fd);
```
---

## read_line
```c
char	*read_line(int fd, char *strs)
```
### Descripción
Esta función se encarga de leer una línea desde el descriptor de archivo especificado (fd) y almacenarla en una cadena de caracteres (strs). Utiliza un bucle para leer bloques de datos del archivo hasta encontrar un salto de línea o hasta que no haya más datos para leer.

### Parámetros
fd: El descriptor de archivo del cual se leerá la línea.
strs: La cadena de caracteres en la que se almacenará la línea leída.
Devolución
La función devuelve un puntero a la cadena de caracteres que contiene la línea leída, o NULL si ocurre algún error durante la lectura.

### Uso
```c
char *line = read_line(fd, NULL);
```
---
## ft_printer
```c
char	*ft_printer(char **s)
```
### Descripción
Esta función toma un puntero a una cadena de caracteres y extrae la primera línea de la cadena. Luego, actualiza la cadena original para excluir la línea extraída y devuelve la línea extraída.

### Parámetros
s: Un puntero al puntero de la cadena de caracteres de la cual se extraerá la línea.
Devolución
La función devuelve un puntero a la primera línea extraída de la cadena de caracteres.

### Uso
```c
char *line = ft_printer(&str);
```
---
Espero que esta documentación sea útil. Si necesitas más ayuda, ¡no dudes en preguntar!


