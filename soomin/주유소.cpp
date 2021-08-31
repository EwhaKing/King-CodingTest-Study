#include <iostream>
using namespace std;

long long dist[100001];

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num - 1; i++) {
		cin >> dist[i];
	}

	int prevPrice = 1000000001;
	long long sumPrice = 0;

	for (int i = 0; i < num - 1; i++) {
		int price;
		cin >> price;

		if (price < prevPrice) {
			prevPrice = price;
		}

		sumPrice += dist[i] * prevPrice;
	}

	cout << sumPrice;

	return 0;
}