#include <string>
#include <vector>

using namespace std;
int answer = 0;
void findexecution(vector<int> numbers, int target,int sum, int count){
    
    if(numbers.size()==count){
        if(sum==target) answer++;
        return;
        
    }
    
    findexecution(numbers,target,sum+numbers[count],count+1);
    findexecution(numbers,target,sum-numbers[count],count+1);
    
    
}


int solution(vector<int> numbers, int target) {
    findexecution(numbers,target,0,0);
    return answer;
}
