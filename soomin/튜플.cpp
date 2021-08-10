#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair <int, int>> tmp;
    int position = 0;
    int start=0;
    int num = 0;
    int length = 0;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '}') {
            num += stoi(s.substr(start, length));
            printf("%d %d\n", position, num);
            tmp.push_back(make_pair(position, num));
            position = 0;
            length = 0;
            num = 0;
            
        }
        else if (s[i] == ',' && s[i - 1] != '}') {
            num += stoi(s.substr(start, length));
            start = i+1;
            length = 0;
            position++;
        }
        else if (s[i] == '{' || s[i] == ',') {
            start = i+1;
            continue;
        }
        else { //숫자인 경우
            length++;
        }
            
    }
    sort(tmp.begin(), tmp.end());

    answer.push_back(tmp[0].second);
    for (int i = 1; i < tmp.size(); i++) {
        answer.push_back(tmp[i].second - tmp[i - 1].second);
    }

    return answer;
    

}