## Sobre el Proyecto

El objetivo de este programa es poner a prueba los distintos algoritmos de ordenamiento como: selectionSort, bubbleSort, insertionSort, shellSort, mergeSort,
quickSort y heapSort. Para esto, el programa prepara una serie de entradas de distintos tamaños que terminarán usando cada uno de los algoritmos mencionados 
para demostrar su eficiencia, esto según el tiempo que tarde su ejecución.   

## Nota Importante

La carga de datos puede tomar varios minutos, sobre todo la "Cola de Espera" debido al gran tamaño que tiene su entrada. Por lo anterior, se recomienda no 
cerrar el programa para no volver a esperar la carga de datos.   

## Instrucciones de Instalación y Ejecución

Siga estos pasos para compilar y ejecutar el proyecto en su sistema.

### Paso 1: Instalar un compilador

Dependiendo de su sistema operativo, elija uno de los siguientes compiladores:

- **macOS o Linux**: Utilice GCC (GNU Compiler Collection).
- **Windows**: Puede usar MinGW (Minimalist GNU for Windows) o MSYS2.

### Paso 2: Descargar el proyecto

Descargue el proyecto y descomprímalo en su sistema.

### Paso 3: Compilar el proyecto

Abra una terminal y vaya al directorio del proyecto. Ejecute el siguiente comando para compilar el proyecto:

```shell
g++ main.cpp imp/impAlgoritmo.cpp imp/impGenerar.cpp imp/impFlujo.cpp -o run
```

### Paso 4: Ejecutar el proyecto

Una vez que el proyecto se haya compilado con éxito, puede ejecutarlo utilizando el siguiente comando:

```shell
./run
```