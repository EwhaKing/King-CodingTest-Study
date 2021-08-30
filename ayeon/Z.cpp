#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N,r,c,k,count = 0;
    cin>>N>>r>>c;
    r++; c++;
    while(N)
    {
        k = pow(2,N-1);
        if(r<=k && c<=k)
        	;
        else if (r<=k)
        	count += pow(k,2);
        else if (c<=k)
        	count += 2*pow(k,2);
        else
        	count += 3*pow(k,2);
        r%=k; if(r==0) r=k;
        c%=k; if(c==0) c=k;
        N--;
    }
    cout<<count;
    return 0;
}
