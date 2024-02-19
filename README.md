# Get Next Line

## get_next_line
```c
char	*get_next_line(int fd)
```
---
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
---
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
get_next_line

char	*get_next_line(int fd)
Descripción
Esta función toma un descriptor de archivo y devuelve la próxima línea disponible desde ese descriptor. Utiliza una variable estática para mantener el estado entre llamadas y asegurar que pueda continuar leyendo desde donde lo dejó en la última llamada.

Parámetros
fd: El descriptor de archivo del cual se leerá la próxima línea.
Devolución
La función devuelve un puntero a la siguiente línea disponible desde el descriptor de archivo especificado.

Uso

