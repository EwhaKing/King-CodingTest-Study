#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
    return s1+s2 > s2+s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), comp);
    if(v[0] == "0") return "0";
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    return answer;
}