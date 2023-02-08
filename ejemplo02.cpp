#include <iostream>
#include <mpi.h>
//#include <chrono>
#include <random>
#include<cmath>
#include<thread>
#include <stdlib.h>
using namespace std::chrono_literals;

int main(int argc, char** argv){
    int rank;
    int size;
    int data[110];
    double aux=0.0;
    std::random_device r;
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size );
    
    MPI_Barrier(MPI_COMM_WORLD);

    double start_time=MPI_Wtime();

    std:: default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1,30);
    int mean=uniform_dist(e1);

    std::this_thread::sleep_for(1000ms*mean);
    double rank_time=MPI_Wtime()-start_time;
    std::printf("time for work is %f seconds with  rank %d \n", rank_time,rank);

    MPI_Barrier(MPI_COMM_WORLD);

    double main_time=MPI_Wtime()-start_time;
       
    if(rank==0){       
     std::printf("tiempo mayor %f \n", main_time);
    }

    
     
     MPI_Finalize(); 
    return 0;
}