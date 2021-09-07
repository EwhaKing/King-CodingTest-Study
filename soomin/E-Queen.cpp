#include <iostream>
#include <vector>
using namespace std;
int N;
int col[15];
int xy[15][15];
int ans;

int abs(int a, int b){
	return a-b > 0 ? a-b:b-a;
}

bool promising(int i){
	int k;
	bool flag;
	k = 1;
	flag = true;
	while(k<i && flag){
		if(col[i] == col[k] || abs(col[i], col[k]) == i-k){
			flag = false;
		}
		k++;
	}
	return flag;
}

void queens(int i){
	int j;
	
	if(promising(i)){
		if(i == N){
			ans++;
		}
		else{
			for(j = 1; j<=N;j++){
				if(xy[i][j]) continue;
				col[i+1] = j;
				queens(i+1);
			}
		}
	}
}

int solution(int n, int k, vector<int> X, vector<int> Y){
	N= n;
	for(int i = 0; i<k; i++)
		xy[X[i]-1][Y[i]] = 1;
	queens(0);
	return ans;
}


 int main(void) {
	 int n,k;
	 cin >> n;
	 cin >> k;
	 vector<int> X(k);
	 vector<int> Y(k);
	for (int i = 0; i < k; i++) {
		cin >> X[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> Y[i];
	}
	 int result = solution(n, k, X, Y);
	 cout << result;
	return 0;
}