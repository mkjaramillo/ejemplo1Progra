#include <iostream>
#include <mpi.h>
int main(int argc, char** argv){
    int rank;
    int size;
    int data[110];
    int div=110/size 
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 

   std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size ); 
    if(rank==3){

        for(int i=0;i<110;i++){
            data[i]=i;
        }
        
        int part=0;
        for(int i=0;i<3;i++){
            MPI_Send(&data[part],div,MPI_INT,i,0,MPI_COMM_WORLD); 
           part+=div;
        }

        int sumaParcial=0;
        for(int i=part;i<110;i++){
         sumaParcial= sumaParcial+data[i];
        }
        
        int sumaParcial2=0;
        int suma_total=0;
        for(int i=0;i<3;i++){
           MPI_Recv(&sumaParcial2,1,MPI_INT,i,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
           suma_total=sumaParcial2+suma_total;
        }

        suma_total= sumaParcial+suma_total;
        std::printf("la suma total es : %d \n" ,suma_total);

    }else{
        MPI_Recv(data,div,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int sumaParcial=0;
        for(int i=0;i<div;i++){
            sumaParcial=sumaParcial+data[i]; 
        }
         std::printf("data[0]: %d ....data[26]:%d \n" ,data[0],data[26]);
         
        MPI_Send(&sumaParcial,1,MPI_INT,3,0,MPI_COMM_WORLD); 
    }

/*
  if(rank==0){ 
    for(int i=0;i<100;i++){
        data[i]=i;
    }
   std::printf("rank enviando... \n" ); 

    MPI_Send(&data[50],50,MPI_INT,1,0,MPI_COMM_WORLD); 
    int sumaParcial=0;

    for(int i=0;i<50;i++){
        sumaParcial= sumaParcial+data[i];
    }
     int sumaParcial2=0;
        MPI_Recv(&sumaParcial2,1,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
 
    int suma_total= sumaParcial+sumaParcial2;
    std::printf("la suma total es : %d \n" ,suma_total);
}else if(rank==1){ 

    std::printf("rank%d recibiendo... s\n" ,rank); 

    MPI_Recv(data,50,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE); 

    std::printf("rank %d, recibiendo... data[99]= %d\n" ,rank,data[0] ); 
    int sumaParcial=0;
    for(int i=0;i<50;i++){
        sumaParcial=sumaParcial+data[i];
    }
    MPI_Send(&sumaParcial,1,MPI_INT,0,0,MPI_COMM_WORLD);     

} */
   

MPI_Finalize(); 
    return 0;
}
