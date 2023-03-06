#include <iostream>
#include <omp.h>
#include <cmath>
#include <chrono>
#include <stdlib.h>
#include<thread>
#include <fstream>  
#include <vector>
using namespace std::chrono_literals;
void serial(){
    /*int n=175740;
     int* data = new int [n];
     srand(time(NULL));
        for(int i=0;i<n;i++){
            data[i]=rand()%100;
        }
        //printf("%d \n",data[5]);*/
         std::ifstream input("datos.txt");
         std::vector<int>data;
         std::string tmp;
        while(std::getline(input,tmp)){
     
            data.push_back(std::stoi(tmp));
        }
       
        int a[100][2];
        int cont=0;
        auto start = std::chrono::high_resolution_clock::now();
        while(cont<100){
            int cont2=0;
            for(int i=0;i<data.size();i++){
                if(data[i]==cont){
                    cont2++;
                }
            }
            a[cont][0]=cont;
            a[cont][1]=cont2;
            cont++;
        }
        printf("serial \n");
        for(int i=0;i<100;i++){
            
            double por=(double)a[i][1]*100.00/data.size();
            printf("%d | %d | %f\n",i,a[i][1],por);
        }
        auto end = std::chrono::high_resolution_clock::now();
         std::chrono::duration<double> tiempo_total = end - start;
        printf("Tiempo serial: %f s \n", tiempo_total.count()/1000.0);
   
    

    
}
void frecuencia(){
    /* int n=175740;
     int* data = new int [n];
     srand(time(NULL));
        for(int i=0;i<n;i++){
            data[i]=rand()%100;
        }*/
        std::ifstream input("datos.txt");
         std::vector<int>data;
         std::string tmp;
        while(std::getline(input,tmp)){
     
            data.push_back(std::stoi(tmp));
        }
        int a[100][2];
        int cont=0;
       auto start = std::chrono::high_resolution_clock::now();
        while(cont<100){
        #pragma omp parallel shared(a)
            {
             
                int cont2=0;
                #pragma omp for
                for(int i=0;i<data.size();i++){
                    if(data[i]==cont){
                        cont2++;
                    }
                }
                
                a[cont][0]=cont;
                a[cont][1]=cont2;
            //printf("cont %d",a[cont][1]);
               
            }
            
          cont++;
        }
        
              
        
        for(int i=0;i<100;i++){
            
            double por=(double)a[i][1]*100.00/data.size();
            printf("%d | %d | %f\n",i,a[i][1],por);
        }
         
   
     auto end = std::chrono::high_resolution_clock::now();
         std::chrono::duration<double> tiempo_total = end - start;
        printf("Tiempo omp: %f s \n", tiempo_total.count()/1000.0);
        
}

int main(){
  // printf("la suma tota es: %d\n",vectorPunto(70));
  //serial();
   frecuencia();
        return 0;
}