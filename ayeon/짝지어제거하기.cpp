#include <iostream>
#include <string>
#include <stack>

using namespace std;

int anwser(string s)
{
    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if( st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
            //cout <<"PUSH "<< s[i] << " i = "<< i<< "\n";
        }
        else
        {
            while(!st.empty() && i<s.size())
            {
                if(st.top() == s[i])
                {
                    //cout << "POP " << st.top() << " i = "<< i<< "\n";
                    st.pop();
                    i++;
                }
                break;
            }
            i--;
            
        }
    }
    if (st.empty())
    {
        //cout << st.top();
        return 1;
    }
    else
    {
        //cout << st.top();
        return 0;
    }
}

int solution(string s)
{
    if (s.size()%2 == 1)
    {
        return 0;
    }
    
    else
    {      
        return anwser(s);
    }

}

int main()
{
    cout << "\n"<<solution("baabaa");
    return 0;
}
