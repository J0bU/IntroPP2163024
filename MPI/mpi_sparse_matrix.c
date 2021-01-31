/******************************************************************************
* PURPOSE: Transform serial code to parallel code using MPI.
* FILE: mpi_sparse_matrix.cpp
* DESCRIPTION:
*   This program wants to resolve a problem, the problema is a sparse matrix, 
*   however, this problem don't have a great useful because MPI pass information
*   and in this case we need to handle a matrix.
*
* AUTHOR: Jonathan Buitrago
* MODIFIED: 30/01/2021
******************************************************************************/

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{

   // Initializations

  freopen("inmpi.txt", "r", stdin);
  MPI_Status status;
  int num, rank, size, tag, next, from;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);


  tag = 201;
  next = (rank + 1) % size;
  from = (rank + size - 1) % size;


  if (rank == 0) {
    printf("\nEnter the number of rows and columns of the matrix \n\n");
    scanf("%d", &num);

    printf("Process numer %d sent %d to the process %d\n", rank, num, next);
    MPI_Send(&num, 1, MPI_INT, next, tag, MPI_COMM_WORLD); 
  }


  do {

    MPI_Recv(&num, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
    printf("process %d have received %d\n", rank, num);

    if (rank == 0) {
      --num;
      printf("Process 0 minus 1\n");
    }

    printf("Process %d sents %d to the process %d\n", rank, num, next);
    MPI_Send(&num, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
  } while (num > 0);
  printf("Process %d ends\n", rank);


  if (rank == 0)
    MPI_Recv(&num, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);

  MPI_Finalize();
  return 0;
}