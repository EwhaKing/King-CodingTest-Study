#include <string>
#include <vector>

using namespace std;

void recur(vector<int> numbers, int target, int sum, int count, int* answer){
    if (numbers.size() == count){
        if (target == sum)
            *answer += 1;
        return;
    }
    recur(numbers, target, sum - numbers[count], count+1, answer);
    recur(numbers, target, sum + numbers[count], count+1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    recur(numbers, target, 0, 0, &answer);
    return answer;
}