//*수의 위치는 그대로 놓고 숫자가 몇개 사라지는 것*
//길이가 s고 삭제할 숫자의 개수가 k면 만들 수 있는 문자열의 길이는 s-k
//큰 수를 만들어야 하므로 큰 수가 앞에 있으면 좋다
//->앞 쪽에서 작은 수를 지워간다.



#include <string>
#include <vector>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
 
    int numSize = number.size() - k;
    int start = 0;
    for(int i=0; i<numSize; i++) {
        char maxNum = number[start];
        int maxIdx = start;
        for(int j=start; j<=k+i; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }
 
    return answer;
}
