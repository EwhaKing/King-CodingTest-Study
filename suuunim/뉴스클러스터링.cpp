#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0, min = 0, max = 0;
    vector<string> s1, s2, words;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);//대문자와 소문자의 차이는 무시하므로
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);//소문자로 모두 변환해준다
    
    for(int i = 0; i < str1.size() - 1; i++)
    {
        string tmp = str1.substr(i, 2);//str1을 2글자씩 자른다
        if(tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')//이때 영문자인 경우에만
            s1.push_back(tmp);//s1에 저장해준다
    }
    
    for(int i = 0; i < str2.size() - 1; i++)//str1과 마찬가지
    {
        string tmp = str2.substr(i, 2);
        if(tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            s2.push_back(tmp);
    }
    
    if(s1.empty() && s2.empty())//두 vector에 아무값도 없다면 공집합이므로 결과는 
        return 65536;//그냥 65536(함께 공집합이므로 유사도 1)
    
    max = s1.size() + s2.size(); //그냥 두 vector의 원소 갯수의 합
    
    if(s1.size() > s2.size())//둘 중에 큰 vector에 따라서 다른 for문을 돈다
    {
        for(int i = 0; i < s2.size(); i++)
        {
            auto itr = find(s1.begin(), s1.end(), s2[i]);//s1에 s2와 겹치는 원소 있는지 찾기
            if(itr != s1.end())
            {
                min++;
                s1.erase(itr);//찾았으면 지우기
            }
        }
    }
    else
    {
        for(int i = 0; i < s1.size(); i++)
        {
            auto itr = find(s2.begin(), s2.end(), s1[i]);//위와 반대로 s2에 s1원소가 있는지 찾기
            if(itr != s2.end())
            {
                min++;
                s2.erase(itr);
            }
        }
    }
    
    max -= min;//교집합에 있는건 합집합에 한번 더 포함되므로 중복되는거 한번 삭제
    
    if(max == 0)//합집합이 0이라면 유사도 1
        return 65536;
        
    double tmp = (double)min / (double)max;// 자카드 유사도 계산
    
    return tmp * 65536;//조건에서 65536을 구한 후 정수부만 출력하므로 int로 반환
}
