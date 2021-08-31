#include <cstdio>

int solution(int n, int r, int c){
    int ans=0;
    int x=1 << (n-1);
    int y=x;
    while(n-->0){
        int temp=1<<(n-1);
        int skip=1<<2*n;
        
        
        if(r<y&&c<x){
            x-=temp;
            y-=temp;
        }
        else if(r<y&&x<=c){
            ans+=skip;
            x+=temp;
            y-=temp;
        }
        else if(y<=r&&c<x){
            ans+=skip*2;
            x-=temp;
            y+=temp;
        }
        else{
            ans+=skip*3;
            x+=temp;
            y+=temp;
        }
        
    }
    return ans;
}

int main(){
    int n,r,c;
    scanf("%d %d %d",&n,&r,&c);
    printf("%d",solution(n,r,c));
    return 0;
}
