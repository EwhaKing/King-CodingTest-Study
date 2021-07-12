using namespace std;

int gcd(int a, int b){
    int n;
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    int a;
    if (w>h)
        a = gcd(w, h);
    else a = gcd(h,w);
    
    answer = (long long)w*h - (w+h-a); //형변환 주의
    
    return answer;
}