/* SOLVED */

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
	int x; //index
	int y; //priority
}q;


int solution(vector<int> priorities, int location) {
    
    int count = 0;
    queue<q> Q;
    priority_queue<int, vector<int>> heap;
    
    for(int i=0; i<priorities.size(); i++){
        Q.push({i,priorities[i]});
        heap.push(priorities[i]);
    }
    
    while(!Q.empty())
    {
        if (Q.front().y < heap.top())
        {
            	Q.push(Q.front());
	            Q.pop();
        }
        else
        {
            count++;
            if (Q.front().x == location) return count;
            Q.pop();
            heap.pop();
        }           
    }
    return count;
}
