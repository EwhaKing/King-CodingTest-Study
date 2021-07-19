#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    //for(int i=0; i<scoville.size(); i++) pq.push(scoville[i]);
    
    while (pq.top() < K){
       if(pq.size()==1) return -1;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        int new_scoville = a+b*2;
        pq.push(new_scoville);
        
        answer++;
    }
    return answer;
}