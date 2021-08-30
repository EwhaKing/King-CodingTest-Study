#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>> N;
    
    long long road[N], oil[N], money[N], small_oil ;
    
    for(int i=0; i<N-1; i++)
        cin>> road[i];
        
    for(int i=0; i<N; i++)
        cin>> oil[i];
    
    small_oil = oil[0];
    money[0] = 0;
    
    for(int i=0; i<N-1; i++)
    {
        if( oil[i] < small_oil )
            small_oil = oil[i];
        
        money[i+1] = money[i]+small_oil*road[i];
    }
    
    cout<<money[N-1];
    return 0;
}
