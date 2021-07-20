
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include<string.h>
#include<string>
using namespace std;

int solution(string s)
{
    
    int answer = -1;
    stack<char>str;
    for(int i=0;i<s.length();i++){
        if(str.empty()||str.top()!=s[i])
            str.push(s[i]);
        else if(str.top()==s[i]) 
            str.pop();
        
        
    }
    
    
    if(str.empty())
        return 1;
    return 0;
}
