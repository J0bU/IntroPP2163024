# OpenMP Implementation here!

Esta carpeta llamada ```OpenMP``` contiene los siguientes archivos:
- Código original C++
- Código paralelizado usando OpenMP C++
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
    - 1. Compilación código mediante el comando: ```g++ -fopenmp omp_sparse_matrix.cpp -o omp_sparse_matrix ```, posteriormente para ejecución directa usar ./omp_sparse_matrix (necesario compilar antes)
    - 2. Ejecución del código compilado mediante el uso de ```./omp_sparse_matrix ```
    - 3. Para la inserción de datos se hace mediante el archivo ``` in.txt `` los dos primeros números hacen referencia a los valores m y n, los y los demás números son la cantidad de valores que contendrá la matriz. (En este caso se definió una sparse matrix con los valores 0 0 0 1).

- *Ejecución código Guane-1*:
    - 1. Compilación código mediante el comando: ```g++ -fopenmp omp_sparse_matrix.cpp -o omp_sparse_matrix
    - 2. Ejecución del código compilado mediante el uso de ```./omp_sparse_matrix ```
    - 3. *Otra opción*: correr el archivo sbatch ya que allí contiene la ejecución. ``` sbatch  sparse_matrix.sbatch ```


