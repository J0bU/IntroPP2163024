# MPI Implementation here!

Esta carpeta llamada ```MPI``` contiene los siguientes archivos:
- Código original C++
- Código paralelizado usando MPI C
- *Archivo sbatch*: Contiene comandos SLURM, para su ejecución usar ``` sbatch sparse_matrix.sbatch ```
- *Archivo in.txt*: Contiene los valores de entrada para el programa
    - Primera línea: Primer valor (filas matriz), segundo valor (columnas matriz)
    - Filas restantes: Cantidad de valores en función del tamaño de la matriz.
- *Archivo de salida*: Contiene la salida después de ejecutar el programa en Guane a través del sbatch. 

## ```Código```

- *Explicación*: El código original permite saber si una matriz es una matriz "esparcida", ¿qué quiere decir esto?, 
si la cantidad de ceros que hay en la matriz es mayor a la cantidad de los demás números diferentes de cero
entonces la matriz es una matriz esparcida, de lo contrario no lo es. Así que en eso se enfoca este código
calcular la cantidad de ceros que hay en dicha matriz por medio de un contador y finalmente dar un resultado.

### ```Instrucciones de uso```

- *Ejecución código paralelizado C++*:
    - 1. Compilación código mediante el comando: ```mpicc -o mpi_sparse_matrix mpi_sparse_matrix.c ```, posteriormente para ejecución directa usar ./mpi_sparse_matrix (necesario compilar antes)
    - 2. Ejecución del código compilado mediante el uso de ```./mpi_sparse_matrix ```

- *Ejecución código Guane-1*:
    - 1. Compilación código mediante el comando: ```mpicc -o mpi_sparse_matrix mpi_sparse_matrix.cpp```
    - 2. Ejecución del código compilado mediante el uso de ```./mpi_sparse_matrix ```
    - 3. *Otra opción*: correr el archivo sbatch ya que allí contiene la ejecución. ``` sbatch  sparse_matrix.sbatch ```


