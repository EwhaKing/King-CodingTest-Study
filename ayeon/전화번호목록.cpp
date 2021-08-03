/* 효율성 테스트 통과 못함 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    int i,j,k;
    sort(phone_book.begin(), phone_book.end(),compare);
    
    for(i=0; i<phone_book.size()-1; i++)
    {
        for(j=i+1; j<phone_book.size(); j++)
        {
            int c=0;
            for(k=0; k<phone_book[i].size(); k++)
            {
                if(phone_book[i][k] == phone_book[j][k]) c++;
            }
            if (c==phone_book[i].size()) answer=false;
        }
    }
    
    return answer;
}
