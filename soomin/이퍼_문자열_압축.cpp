//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string solution(char input[]){
	string result = "";
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n=1;
	if(input[0] == '1')  result += "1";
	for(int i = 0; i<strlen(input)-1; i++){
		if(input[i] == input[i+1]) n++;
		else {
			result = result + alphabet[n-1];
			n = 1;
		}
	}
	result = result + alphabet[n-1];
	return result;
}

int main() {
	char input[10000];
	cin >> input;
	//cout << "Hello Goorm! Your input is " << input << "\n";
	string result = solution(input);
	cout << "" << result << "";
	return 0;
}
