/*미해결*/

#include <string>
#include <vector>

using namespace std;


string return124Num(int n) {
	string res = "";
	while (n > 0) {
		int idx = n % 3;
		n /= 3;
		if (idx == 0) {
            res = "4" + res;
            n--;
        }else{
            res = to_string(idx) + res;
        }
	}
	return res;
}

string solution(int n) {
	string answer = "";
	answer = return124Num(n);
	return answer;
}
