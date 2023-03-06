#include <iostream>
#include <mpi.h>
#include <cmath>
#include <stdlib.h>
#include <chrono>
#include <fstream>  
#include <vector>
using namespace std::chrono_literals;
using namespace std;
int main(int argc, char** argv){
    
    int rank;
    int size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    //int data[17574103];
   //std::vector<int>data;
    std::ifstream input("datos.txt");
    //std::string tmp;
  // while(std::getline(input,tmp)){
     //printf("%d",std::stoi(tmp));
   //  data.push_back(std::stoi(tmp));
 // }
   /*
    for (int i = 0; i < data.size(); i++) {
       printf("%d \n",data[i]);
    }*/
   /* for (int i = 0; i < 17574103; i++) {
        printf("%d",data[i]);
    }*/
    
    
    //int n=175740;
     //int* data = new int [n];
     int div;

    if (rank==0){
        srand(time(NULL));
        /*for(int i=0;i<n;i++){
            data[i]=rand()%100;
        }*/
       
        std::vector<int>data;
        std::string tmp;
        while(std::getline(input,tmp)){
     
            data.push_back(std::stoi(tmp));
            }
        div=data.size()/size;
        printf("div %d",div);
        int part=0;
        auto start = std::chrono::high_resolution_clock::now();
        for(int i=1;i<4;i++){
            MPI_Send(&data(part),div,MPI_INT,i,0,MPI_COMM_WORLD);
            part+=div;

        }
         int a[100][2];
        int cont=0;
        
        while(cont<100){
            int cont2=0;
            for(int i=part;i<part-div;i++){
                if(data[i]==cont){
                    cont2++;
                }
            }
            a[cont][0]=cont;
            a[cont][1]=cont2;
            cont++;
        }
        int a1[100][2];
        MPI_Recv(a1,100*2,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
       /*for(int i=0;i<100;i++){
            printf("%d - %d\n",a1[i][0],a1[i][1]);
        }*/
        int a2[100][2];
        MPI_Recv(a2,100*2,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int a3[100][2];
        MPI_Recv(a3,100*2,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int total[100][3];
        for(int i=0;i<100;i++){
            int suma=a[i][1]+a1[i][1]+a2[i][1]+a3[i][1];
            double por=(double)suma*100.00/data.size();
            printf("%d | %d | %f\n",i,suma,por);
        }

        auto end = std::chrono::high_resolution_clock::now();
         std::chrono::duration<double> tiempo_total = end - start;
        printf("Tiempo mpi: %f s \n", tiempo_total.count()/1000.0);

    }else{
         std::vector<int>data(div);
       // int data[div];
      MPI_Recv(data.data(),div,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int a[100][2];
        int cont=0;
        
        while(cont<100){
            int cont2=0;
            for(int i=0;i<div;i++){
                if(data[i]==cont){
                    cont2++;
                }
            }
            a[cont][0]=cont;
            a[cont][1]=cont2;
            cont++;
        }
        
        MPI_Send(&a[0][0],100*2,MPI_INT,0,0,MPI_COMM_WORLD);
        
    }
        MPI_Finalize(); 
    return 0;
}