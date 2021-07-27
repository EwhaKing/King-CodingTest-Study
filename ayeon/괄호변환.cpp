/* PROCEEDING */
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



