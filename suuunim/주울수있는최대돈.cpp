#include <iostream>
#include <vector>
using namespace std;

// 돈의개수 n과 크기가 n인 수열 M이 주어졌을 때 
// 주울 수 있는 최대 돈을 구하는 함수

int max(int a, int b, int c){
	
	if(a>b)
		if(a>c)
			return a;
	
	if(b>a)
		if(b>c)
			return b;
	
	if(c>a)
		if(c>b)
			return c;
	
}


int solution(int n, vector<int> M)
{
  int answer = 0;
	
	vector<int> maxNum(n+1,0);
	maxNum[1]=M[0];
	
	if(n>1){maxNum[2]=M[0]+M[1];}
	if(n>2){
		for(int i=3;i<=n;i++){
			
			maxNum[i]=max(maxNum[i-2]+M[i-1], maxNum[i-1],maxNum[i-3]+M[i-2]+M[i-1]);
			
			
		}
		
	}
	
	
	return maxNum[n];
}

int main() {
	int n;
	cin >> n;
	
	vector<int> M(n, 0);
	for(int i=0; i<n; i++){
       cin >> M[i];  
   }
	
	int ans=solution(n,M);
	cout << ans << endl;
	return 0;
}
