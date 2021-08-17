#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int s_length = s.length();
   
    
    
    string temp = "";
    for (int i = 0; i < s_length; i++) {//i칸만큼 회전
        temp = s.substr(i, s_length - i) + s.substr(0, i);//앞에서 i개만큼 자른 뒤 뒤에 붙여주기->회전
        stack <int> stk;
        for (int j = 0; j < s_length; j++) {
            if ((stk.size() > 0) && (temp[j] - stk.top()) > 0 && (temp[j] - stk.top()) <= 2) //맞는 괄호 짝인 경우
                stk.pop();
            else
                stk.push(temp[j]);
        }
        if (stk.size() == 0)
            answer++;
    }
    return answer;
}
