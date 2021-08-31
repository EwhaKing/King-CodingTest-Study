#include <cstdio>

long long solution(int cities,int distance[], int price[]){
    long long totalPrice=0;
    int i=0;
    long long minCost=price[0];
    
    for(int i=0;i<cities-1;i++){
        if(price[i]<minCost)
            minCost=price[i];
            
        totalPrice+=minCost*distance[i];
        
        
    }
     return totalPrice;
}

int main(){
    int cities;
    int distance[100000]={0};
    int price[100000]={0};
    int i;
    long long answer=0;
    scanf("%d",&cities);
    for(i=0;i<cities-1;i++)
        scanf("%d",&distance[i]);
    for(i=0;i<cities;i++)
        scanf("%d",&price[i]);
    answer=solution(cities,distance,price);
    printf("%11d",answer);
}
