#include <iostream>
#include <stdlib.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(true){
        if(abs(b-a)==1 && MIN(a,b)%2 == 1)
            break;
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }
    return answer;
}