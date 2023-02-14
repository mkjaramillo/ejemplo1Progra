#include <iostream>
#include <mpi.h>
//#include <chrono>
#include<thread>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
using namespace std::chrono_literals;
/*
//ejercio1
int main(int argc, char** argv){
    int rank;
    int size;
    int data[10000];
    int div=10000/4;
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size );
    if(rank==0){
        for(int i=1;i<=10000;i++){
        data[i]=i;
        }
        int part=div;
        for(int i=1;i<4;i++){
            MPI_Send(&data[part],div,MPI_INT,i,0,MPI_COMM_WORLD);
            part=part+div;

        }
        for(int i=0;i<div;i++){
             int numero=data[i];
                int suma=0;
                for(int j=1;j<numero;j++){
                    if(numero%j==0){
                        suma=suma+j;
                    }
                }
                if(suma==numero){
                    printf("los numeros puros son : %d \n",numero);
                }
        }
        
        for(int i=1;i<4;i++){
            int aux2=0;
            MPI_Recv(&aux2,1,MPI_INT,i,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int puros2[aux2];
            MPI_Recv(puros2,aux2,MPI_INT,i,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int j=0;j<aux2;j++){
                printf("los numeros puros son : %d \n",puros2[j]);
            }
        }
            
            
            
        
       
        
    }
    else
    {
        MPI_Recv(data,div,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int aux=0;
        int puros[10];
        for(int i=0;i<div;i++){
             int numero=data[i];
                int suma=0;
                for(int j=1;j<numero;j++){
                    if(numero%j==0){
                        suma=suma+j;
                    }
                }
                if(suma==numero){
                    puros[aux]=numero;
                    aux=aux+1;
                }
        }
        
         MPI_Send(&aux,1,MPI_INT,0,0,MPI_COMM_WORLD);

         MPI_Send(&puros[0],aux,MPI_INT,0,0,MPI_COMM_WORLD);
    }

}*/
//ejercicio 2
/*
int main(int argc, char** argv){
    int rank;
    int size;
    int data[10];
 
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size );
     srand(time(NULL));
   
   if(rank==0){
        for(int i=0;i<10;i++){
                data[i]=rand()%101;
                
                    printf(" R %d\n",data[i]);
        }
        MPI_Request request;
        
        MPI_Isend(&data[5],5,MPI_INT,1,0,MPI_COMM_WORLD,&request);
    //MPI_Send(&data[5],5,MPI_INT,1,0,MPI_COMM_WORLD);
        for(int i=0;i<5-1;i++){
            int aux=0;
            for(int j=0;j<5-1-i;j++){
                if(data[j]>data[j+1]){
                    aux=data[j];
                    data[j]=data[j+1];
                    data[j+1]=aux;

                }
            }
        }
       MPI_Status status;

        int burbuja2[5];

        MPI_Irecv(burbuja2,5,MPI_INT,1,0,MPI_COMM_WORLD,&request);
        
        MPI_Wait(&request, &status);
        int cont=0;
        for(int i=5;i<10;i++){
            data[i]=burbuja2[cont];
            cont++;
               
        }
        for(int i=5;i>-1;i--){
            int aux=0;
            for(int j=i;j<10;j++){
                if(data[j]>data[j+1]){
                    aux=data[j];
                    data[j]=data[j+1];
                    data[j+1]=aux;

                }
            }
        }
    for (int i=0;i<10;i++) {
        printf("arreglo ordenado %d\n",data[i]);

    }



   }else{
        MPI_Request request;
        MPI_Status status;
        MPI_Irecv(&data,5,MPI_INT,0,0,MPI_COMM_WORLD,&request);
         
       MPI_Wait(&request, &status);
        for(int i=0;i<5-1;i++){
            int aux=0;
            for(int j=0;j<5-1-i;j++){
                if(data[j]>data[j+1]){
                    aux=data[j];
                    data[j]=data[j+1];
                    data[j+1]=aux;
                
                }
            }
        }
       
        MPI_Isend(&data[0],5,MPI_INT,0,0,MPI_COMM_WORLD,&request);
   }
 
}
*/

bool  esPrimo(int numero){

    bool primo=true;
    for(int i=2;i<(numero/2+1);i++){
        if(numero%i==0){
           primo=false;
        }
    }
    //printf("%d, %d\n",primo,numero);

    return primo;
}
//ejercio3
int main(int argc, char** argv){
    int rank;
    int size;
    int data[100];
    int div=100/4;
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    std::printf("hola soy el rank %d, de un total de %d procesos\n" ,rank,size );
    if(rank==0){
        for(int i=0;i<100;i++){
            data[i]=i*2;
        }
        MPI_Request request;
        int part=div;
        for(int i=1;i<4;i++){
            MPI_Isend(&data[part],div,MPI_INT,i,0,MPI_COMM_WORLD,&request);
            part+=div;
        }
        for(int i=1;i<)
        int b[25][3];
         
        MPI_Status status;
        MPI_Irecv(b,div*3,MPI_INT,1,0,MPI_COMM_WORLD,&request);
        MPI_Wait(&request,&status);
        for(int i= 0; i<25;i++){
            printf("%d : %d + %d ",b[i][0],b[i][1],b[i][2]);
        }
    }else{
        MPI_Request request;
        MPI_Status status;
        MPI_Irecv(data,div,MPI_INT,0,0,MPI_COMM_WORLD,&request);
        int a[25][3];
        MPI_Wait(&request,&status);
        for(int i=0;i<div;i++){
            int numero=data[i];
            a[i][0] = numero;
            bool end=false;
            for(int l=2;l<numero;l++){
                bool isPrimo= esPrimo(l);
                if(isPrimo==true){
                    for(int j=l;j<numero;j++){
                        bool isPrimo2= esPrimo(j);
                        int suma=0;
                        if(isPrimo2==true){
                            suma=l+j;
                            if(suma==numero){
                                printf("numero es : %d con suma %d +%d \n",numero,l,j);
                                end=true;
                                a[i][1]=l;
                                a[i][2]=j;
                                break;
                            }
                            }
                        }
                    }
                if(end){
                    break;
                }

            }
        }

      /* for(int i= 0; i<25;i++){
            printf("%d : %d + %d ",a[i][0],a[i][1],a[i][2]);
        
         MPI_Isend(&a[0][0],75,MPI_INT,0,0,MPI_COMM_WORLD,&request);
    }*/
}

