#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = scoville.size();
    for (int i = 0; i < size; ++i)
        pq.push(scoville[i]);
    
    if(pq.top() > K) // 애초부터 min_heap이 K를 넘으면 그대로 0 return
        return answer;
    
    while (pq.size() != 1 && pq.top() < K){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int cal = f+s*2;
        pq.push(cal);
        ++answer;
    }
    if (pq.size() == 1 && pq.top() < K)
        answer = -1;
    return answer;
}
