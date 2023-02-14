#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <cmath> 
int main(int argc, char** argv){
    int rank;
    int size;
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int a[30][3];
    int c[30] [3];

    srand(time(NULL));
    for(int i=0;i<30;i++){
        a [i][0]=rand()%11;
        a [i][1]=rand()%11;
        a [i][2]=rand()%11;
    }
    for(int i=0;i<30;i++){
        c [i][0]=rand()%11;
        c [i][1]=rand()%11;
        c [i][2]=rand()%11;
    }
   /* for(int i= 0; i<30;i++){
            printf("(%d , %d , %d) ",a[i][0],a[i][1],a[i][2]);

        }*/
   std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size ); 
    if(rank==0){
        MPI_Send(&a[7][0],21,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(&a[15][0],21,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(&a[23][0],21,MPI_INT,1,0,MPI_COMM_WORLD);
         int posicion1[6];
         int cont=0;
        for(int i=0;i<6;i++){
            int min=10000000;
            for(int j=0;j<30;j++){
                int x=(int)pow((a[i][0]-c[j][0]),2);
                int y=(int)pow((a[i][1]-c[j][1]),2);
                int z=(int)pow((a[i][2]-c[j][2]),2);
                int resul=x+y+z;
               int raiz =(int)sqrt(resul);
               if(raiz<min){
                min=raiz;
                 //printf("min (%d ) \n",min);
                 cont=j;
               }
            }
            posicion1[i]=cont;

        }
        for(int i=0;i<6;i++){
           printf("(%d , %d , %d)= %d ",a[i][0],a[i][1],a[i][2],posicion[cont]); 
           cont++; 
        }
        int posicion[7]
        MPI_Recv(posicion,21,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int cont=0;
        for(int i=7;i<15;i++){
           printf("(%d , %d , %d)= %d ",a[i][0],a[i][1],a[i][2],posicion[cont]); 
           cont++; 
        }
        int posicion2[7]
        MPI_Recv(posicion2,21,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int cont=0;
        for(int i=15;i<23;i++){
           printf("(%d , %d , %d)= %d ",a[i][0],a[i][1],a[i][2],posicion[cont]); 
           cont++; 
        }
        int posicion3[7]
        MPI_Recv(posicion3,21,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int cont=0;
        for(int i=23;i<30;i++){
           printf("(%d , %d , %d)= %d ",a[i][0],a[i][1],a[i][2],posicion[cont]); 
           cont++; 
        }

    }else{
        MPI_Recv(a,21,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
       
        int posicion[7];
         int cont=0;
        for(int i=0;i<7;i++){
            int min=10000000;
            for(int j=0;j<30;j++){
                int x=(int)pow((a[i][0]-c[j][0]),2);
                int y=(int)pow((a[i][1]-c[j][1]),2);
                int z=(int)pow((a[i][2]-c[j][2]),2);
                int resul=x+y+z;
               int raiz =(int)sqrt(resul);
               if(raiz<min){
                min=raiz;
                 //printf("min (%d ) \n",min);
                 cont=j;
               }
            }
            posicion[i]=cont;

        }
        
           MPI_Send(&posicion[0],7,MPI_INT,0,0,MPI_COMM_WORLD);  
        
    }
   MPI_Finalize(); 
    return 0;
}