#include <mpi.h>
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int my_rank;
	int p;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	std::cout << "Hello from process " << my_rank + (rand() % 5) * (argc - 1) << " of " << p << std::endl;	
	MPI_Finalize();

	return 0;
}
