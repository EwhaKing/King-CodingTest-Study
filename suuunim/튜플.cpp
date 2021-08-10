#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool asc(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    bool check[100001] = {false, }, open = false;
    vector<vector<int>> v;
    vector<int> num;
    string tmp = "";
    
    for(int i = 1; i < s.size() - 1; i++)//string을 돌면서
    {
        if(open == false && s[i] == '{')//괄호가 시작되면 open 은 true
            open = true;
        else if(open == true && (s[i] >= '0' && s[i] <= '9'))//괄호안인데 숫자이면 숫자를 tmp에 넣기
        {
            tmp.push_back(s[i]);
        }
        else if(open == true && s[i] == ',')//쉼표는 숫자가 나오다가 한번 끝난거니까
        {
            int t = stoi(tmp);
            num.push_back(t);//모아진 숫자들을 num에 넣고
            tmp = "";//tmp초기화
        }
        else if(open == true && s[i] == '}')
        {
            int t = stoi(tmp);;//모아진 숫자들을 num에 넣고
            num.push_back(t);
            v.push_back(num);//그걸 또 v에 넣기
            open = false;
            tmp = "";
            num.clear();
        }
    }
    
    sort(v.begin(), v.end(), asc);//오름차순으로 정렬해줌
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(check[v[i][j]] == false)//중복이 아니라는 이야기이므로
            {
                check[v[i][j]] = true;//true로 바꾸고
                answer.push_back(v[i][j]);//값 저장
            }
        }
    }
    return answer;
}
