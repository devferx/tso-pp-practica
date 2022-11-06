### Descripción
El proyecto tiene 2 alternativas:
1. Modo Prueba
2. Modo Interactivo

- En el modo prueba se manda por parametros los argumentos mostrados en la descripción de ejecutar
- En el modo interactivo mediante comandos conocidos se van ejecutando, hasta que exista una falla o se termine la ejecución con el comando exit
### Compilar

**Modo Prueba**
```bash
gcc prueba.c -o prueba
```

**Modo Interactivo**
```bash
gcc interactivo.c -o interactivo
```

### Ejecutar
**Modo Prueba**
```
./prueba <directorio a listar> <directorio a cambiar> <archivo a mostrar>
```

**Modo Interactivo**
```
./interactivo
```

Comandos:
- pwd -> ver ruta actual
- ls -> mostrar archivos de la ruta actual
- `cd <directorio>` -> moverse dentro de una ruta
- `cat <archivo>` -> Ver archivo dentro del directorio actual
- exit -> salir

### Ejemplo
**Modo Prueba**
```
./prueba . ./nueva-carpeta ejem.txt
```

**Modo interactivo**
```bash
$ ./interactivo
comando a ejecutar:ls
comando a ejecutar:pwd
comando a ejecutar:cd nueva-carpeta
comando a ejecutar:cat ejem.txt
```