#include <mpi.h>
#include "board.h"
#include <stdbool.h>
using namespace std;

const int DEPTH = 6; // default dubina stabla

bool provjeri_kraj()
{
}

int master(int argc, char **argv)
{
  return 0;
}

int slave()
{
}

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

  // tu sad neka funkcija

  if (argc < 2)
  {
    cout << "Uporaba: <program> <fajl s trenutnim stanjem> [<dubina>]" << endl;
    return 0;
  }

  Board B;
  int iBestCol, iDepth = DEPTH;

  B.Load(argv[1]);
  if (argc > 2)
    iDepth = atoi(argv[2]);

  for (int iCol = 0; iCol < B.Columns(); iCol++)
  {
    if (B.GameEnd(iCol))
    {
      cout << "Igra zavrsena!" << endl;
      return 0;
    }
  }

  
  if (world_rank == 0)
  {
    master(argc, argv);
  }
  else
  {
    slave();
  }
  // Finalize the MPI environment.
  MPI_Finalize();
}
