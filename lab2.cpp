#include <mpi.h>



int main(int argc, char **argv)
{
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  //tu sad neka funkcija

  // Finalize the MPI environment.
  MPI_Finalize();
}
