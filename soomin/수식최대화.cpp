#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer =0;
    vector<char> oper;
    vector<long long> n;
    vector<char> kind;
    int a=0, b=0, c = 0;
    string num = "";
    
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            if (num != "") {
                n.push_back(stoll(num));
                num = "";
            } //숫자넣기
            ////////////////////////////////////
            if (expression[i] == '+' && a == 0) {
                kind.push_back('+');
                a = 1;
            }
            else if (expression[i] == '-' && b == 0) {
                kind.push_back('-');
                b = 1;
            }
            else if (expression[i] == '*' && c == 0) {
                kind.push_back('*');
                c = 1;
            }
            ////////////////////////////
            oper.push_back(expression[i]);
        }
        else
            num = num+expression[i];
    }
    n.push_back(stoll(num));//남은 숫자
    
    sort(kind.begin(), kind.end());
    //계산
   do
    {
        vector<long long>tmp_num = n;
        vector<char> tmp_oper = oper;

        for (int i = 0; i < kind.size(); i++) {
            for (int j = 0; j < tmp_oper.size(); j++) {
                if (kind[i] == tmp_oper[j]) {

                    if (tmp_oper[j] == '+') tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if (tmp_oper[j] == '-') tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if (tmp_oper[j] == '*') tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_oper.erase(tmp_oper.begin() + j);
                    j--;
                }
            }
        }
        if (answer < abs(tmp_num[0])) answer = abs(tmp_num[0]);
    } while (next_permutation(kind.begin(), kind.end())); //순열함수
    
    return answer;
}