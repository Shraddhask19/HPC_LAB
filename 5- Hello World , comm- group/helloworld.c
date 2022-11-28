#include <mpi.h>
#include <stdio.h>

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

    // Print off a hello world message
    printf("Hello world, rank %d out of %d processors\n", world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}

// sudo apt install mpich
// mpicc helloworld.c -o helloworld
// mpirun -np 10 ./helloworld


#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int world_rank,world_size;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    float arr[5]={1.1,2.2,3.3,4.4,5.5};
    
    float brr[5]={0.0,0.0,0.0,0.0,0.0};
    if (world_rank == 0) {
        MPI_Send(&arr, 5, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&brr, 5, MPI_FLOAT, 0, 0, MPI_COMM_WORLD,
                MPI_STATUS_IGNORE);
        for(int i=0;i<5;i++){
            cout<<"brr["<<i<<"] = "<<brr[i]<<"\n";
        }
    }   
    
    MPI_Finalize();
	return 0;
}






#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

int main(){
    int world_rank,world_size;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    float arr[5]={1.1,2.2,3.3,4.4,5.5};
    
    float brr[5]={0.0,0.0,0.0,0.0,0.0};
    if (world_rank == 0) {
        MPI_Send(&arr, 5, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&brr, 5, MPI_FLOAT, 0, 0, MPI_COMM_WORLD,
                MPI_STATUS_IGNORE);
        for(int i=0;i<5;i++){
            cout<<"brr["<<i<<"] = "<<brr[i]<<"\n";
        }
    }   
}

//int main(int argc, char **argv)
//{
//    // Initialize the MPI environment
//    MPI_Init(NULL, NULL);
//
//    // Get the number of processes
//    int world_size;
//    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//
//    // Get the rank of the process
//    int world_rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
//
//    // Print off a hello world message
//    printf("Hello world, rank %d out of %d processors\n", world_rank, world_size);
//
//    // Finalize the MPI environment.
//    MPI_Finalize();
//}

// sudo apt install mpich
// mpicc helloworld.c -o helloworld
// mpirun -np 10 ./helloworld
