#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n>0){
        int a = n%3;
        if (a == 1) answer.insert(0, "1");
        else if (a == 2) answer.insert(0, "2");
       else {
           answer.insert(0, "4");
           a = 3;
        }
        n -= a;
        n = n / 3;

    }

    return answer;
}