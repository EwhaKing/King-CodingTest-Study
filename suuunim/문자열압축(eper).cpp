//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <iostream>
using namespace std;


string solution (string s){
	int count=0;
	string answer="";
	if(s[0]=='1') answer.push_back('1');
	for(int i=0;i<s.length()-1;i++){
		if(s[i]!=s[i+1]){
			answer.push_back('A'+count);
			count=0;
		}
		else count++;
	}
	answer.push_back('A'+count);
	return answer;
}


int main() {
	char input[1000];
	cin >> input;
	string str(input);
	string answer=solution(str);
	cout << answer << endl;
	
}
