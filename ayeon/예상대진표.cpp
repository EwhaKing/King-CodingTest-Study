#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int t, answer = 0;
    
    if(b<a)
    {   t=a; a=b; b=t;  }

    while(a!=b){
    while(a<b && b<=n/2)
    {
        n/=2;
    }       
    while(n/2<a && a<b)
    {
        a = a-n/2;
        b = b-n/2;
        n /= 2;
    }
    while(a<=n/2 && n/2 <b)
    {
        answer++; //1
        a = (a-1)/2+1;
        b = (b-1)/2+1;
        n/=2;
    }
    }
    return answer;
}
