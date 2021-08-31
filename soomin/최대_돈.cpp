#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> moneyBag;

int solution(int n, vector<int> moneyList) {
	int result = 0;
	
	moneyBag.push_back(moneyList[0]);
	moneyBag.push_back(moneyList[0] + moneyList[1]);
	//moneyBag[0]=moneyList[0];
	//moneyBag[1]=moneyBag[0] + moneyList[1];

	for (int i = 2; i < n; i++) {
		result = max({ moneyBag[i - 1],moneyBag[i - 3] + moneyList[i - 1] + moneyList[i],moneyBag[i - 2] + moneyList[i] });

		moneyBag.push_back(result);

	}

	result = moneyBag[n - 1];
	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> M(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> M[i];
	}

	int ans = solution(n, M);
	cout << ans << endl;
	return 0;
}