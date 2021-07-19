#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.size(); i++){
        if(stack.empty() || stack.top() != s[i])
            stack.push(s[i]); 
        else
            stack.pop();
    }
    if(stack.empty())
        return 1;
    return 0;
}