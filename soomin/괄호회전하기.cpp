#include <string>
#include <vector>
#include <stack>

using namespace std;

int check(string s) {
    stack<char> stack;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            if (s[i] == '{') stack.push('{');
            else if (s[i] == '(')  stack.push('(');
            else stack.push('[');
        }
        else {
            if(!stack.empty()){
                if (s[i] == '}' && stack.top() == '{') stack.pop();
                else if (s[i] == '}' && stack.top() != '{') return 0;
                else if (s[i] == ')' && stack.top() == '(') stack.pop();
                else if (s[i] == ')' && stack.top() != '(') return 0;
                else if (s[i] == ']' && stack.top() == '[') stack.pop();
                else if (s[i] == ']' && stack.top() != '[') return 0;
            }
            else return 0;
        }
    }
    if (stack.empty()) return 1;
    else return 0;
}

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        string ns = s.substr(i, s.size() - i) + s.substr(0, i);
        answer += check(ns);
    }
    return answer;
}