#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++) {
        string result = "";
 
        string ss = s.substr(0, i);
        int count = 1;
 
        for (int j = i; j <= s.size(); j += i) {

            if (ss == s.substr(j, i))   count += 1;
            else {
                //같은 것 처리
                if (count == 1) {
                    result += ss;
                }
                else {
                    result += (to_string(count) + ss);
                }
                //다른 것부터 다시 비교 시작
                ss = s.substr(j, i);
                count = 1;
            }
        }
        //나머지
        if ((s.size()%i) != 0) {
            result += s.substr((s.size()/i)*i);
        }
        //최소
        if (answer > result.size()) answer = result.size();
    }
 
    return answer;
}
