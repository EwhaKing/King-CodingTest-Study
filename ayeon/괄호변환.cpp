/* PROCEEDING */
==============================================================
#include <string>
#include <vector>
#include <stack>

using namespace std;

int check(string w)
{
    int i=0;
    stack<int> s;
	s.push(w[i++]);
	while(!s.empty())
	{
		if(s.top() == w[i]) s.push(w[i]);
		else s.pop();
        i++;
        if(i==w.size()) return 0;
	}        
    return 1;
}

string solution(string p) {
    string answer = "";
    
    string u = "", v = "";
    
    if (p == "") return "";
    
    int same = 1;
	int different = 0;
    int i=0;
    
	while( i<p.size() && same != different)
	{
		if(p[0] == p[i++]) same++;
		else different++;
	}
    
    u.assign(p,0,i);
    v.assign(p,i+1,p.size()-1);
    
    if (check(u) == 1)
		return u + solution(v);
	else
	{
		answer = "(" + solution(v) + ")";
		u.erase(u.end()-1);
        u.erase(u.begin());
		answer = answer + u;
		return answer;
	}

}
	
==============================================================
string solution(string w)
	if ( w == "" ) return w;
	
	
	same = 1;
	different=0;
	while(same != different)
	{
		if(w[0] == w[i++]) same++;
		else different++;
	}
	u <- slice w [ 0 to i ]
	v <- slice w [ i to w.size()-1 ] 

	if (check (u))
		return u + solution(v);
	else
	{
		answer = "(" + solution(v) + ")"
		u <- delete u[0], u[u.size()-1]
		answer = answer + reverse(u);
		return answer;
	}



// function for check(string w)

	i=0
	stack.push(w[i++])
	while(!stack.empty())
	{
		if(stack.top() == w[i]) stack.push(w[i])
		else stack.pop();
		i++;
	}
	u = slice w[0] ~ w[i] 
	v = w[i+1] ~ w[]



