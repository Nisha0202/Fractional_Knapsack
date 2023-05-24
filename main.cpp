#include <iostream>
#include <algorithm>
#include<stdio.h>
#define A 1000
 
struct state {
   float per_profit;
   float weight;
}; 

bool sort_by_profit(state &a, state &b){
    return a.per_profit < b.per_profit;
}

void knapsack(int n, state a[], float capacity){
  
float tp = 0;
  for (int i = n-1; i >= 0; i--){
     if (capacity > a[i].weight){
            capacity -= a[i].weight;
         // printf("%d",capacity);
           tp = tp+ a[i].weight*a[i].per_profit;
          // printf("%f",tp);
          //printf(" \n");    
        }
    else if (capacity!=0 && capacity<a[i].weight){
       //printf("%f  ",capacity);
      tp = tp+ capacity *a[i].per_profit;
     printf("%.2f  ",tp);
     break;
          }

    }  

}

 
int main() {
   int i, n; float k;
   state st[A];

   scanf("%d%f", &n, &k); 
 
  for (i = 0; i < n; i++) {  
   scanf("%f", &st[i].per_profit);}
  
   for (i = 0; i < n; i++) {
      scanf("%f", &st[i].weight);
 
   }
   
//std::cout << "sorted array"  << std::endl;
std::sort(&st[0],&st[n], sort_by_profit);
//for(int i = 0; i <n ; i++)
//std::cout << st[i].per_profit << " " << st[i].weight << std::endl; 

 knapsack(n, st, k); 

   }


