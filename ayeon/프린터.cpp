/* PROCEEDING */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct paper{
	int i, priority;
    paper(int a,int b): i(a), priority(b) {}
};

struct compare{
	bool operator()(paper p1, paper p2)
	{
		return p1.priority < p2.priority;
	}
};

int solution(vector<int> priorities, int location) {
    int answer=0;
    priority_queue<paper, vector<paper>, compare> printer;
    
    for(int i=0; i<priorities.size(); i++)
        printer.push(paper(i,priorities[i]));
    
    queue<int> queue;
    
    while (priorities[location] <= printer.top().priority)
    {
        if(priorities[location] == printer.top().priority)
        printer.pop();
        answer++;
        queue.push(location);
        
    }
    return printer.top().i;
}

int main()
{
    int answer = 0;
    priority_queue<paper, vector<paper>, compare> printer;
    
    vector<int> priorities = {2, 1, 3, 2};
    

    
    cout << solution(priorities,1);
    return 0;
}

