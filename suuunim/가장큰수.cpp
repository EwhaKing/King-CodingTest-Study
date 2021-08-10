

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    if(a+b<b+a) return true;//두개를 비교했을 때 뒤에 있는게 앞으로 와야 숫자가 더 커질것 같으면
    else return false;      //뒤의 숫자를 자리를 교환하여 앞으로 올리는 것
    
}

string solution(vector<int> numbers){
    string answer="";
    vector<string> newNumbers;
    for(int num:numbers){//받은 숫자벡터 numbers를 string으로 변환하여 저장
        newNumbers.push_back(to_string(num));
    }
    stable_sort(newNumbers.rbegin(),newNumbers.rend(),cmp);//처음부터 끝까지 돌면서 두 숫자들을 이어붙였을 때 어느 순서가 더 큰지 확인 후 정렬 -> 내림차순 정렬
    
    for(string str:newNumbers) answer+=str;//내림차순 정렬을 순서대로 붙임
    if(answer[0]=='0') answer='0';//첫번째가 0으로 시작하면 그냥 0임
    
    return answer;
}
