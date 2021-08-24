/* UN SOLVED */
/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int need = number.length() - k;
	int cmax = 0;
	int ccount = 0;
	int j;
	vector<int> temp;
	for (int i = need; i>0; i--) {
		cmax = 0;
		ccount = 0;
		for (j = 0; j<number.length() - i+1; j++) {
			if (cmax<number[j]) {
				cmax = number[j];
				ccount = j;
			}
		}
		number.replace(0,ccount+1," ");
		
		temp.push_back(cmax);
	}
	for (int i = 0; i<temp.size(); i++)
		answer += temp[i];
	return answer;
}
*/
