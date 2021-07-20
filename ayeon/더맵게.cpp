#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int cnt = 0;
    
    priority_queue<int, vector<int>, greater <int>> max;
    priority_queue<int, vector<int>, greater <int>> min;

    vector<int>::iterator it;
    
	for ( it=scoville.begin(); it!=scoville.end(); it++)
	{
        if((*it) < K)
        {
            min.push((*it));
            //cout << "MIN " << *it << " ";
        }
        else{
            max.push((*it));
            //cout << "MAX " << *it << " ";
        }
    }
    int small1;
    while(min.size()>1)
    {
        small1 = min.top();
        min.pop();
        small1 += 2*min.top();
        min.pop();
        cnt++;
        if (small1 < K)
            min.push(small1);
        else
            max.push(small1);
    }
    
    while(min.size() == 1 && !max.empty())
    {
        small1 = min.top() + 2*max.top();
        min.pop();
        max.pop();
        cnt++;
        if(small1 < K)
            min.push(small1);
        else max.push(small1);
    }
    
    if (max.empty())
    {
        cnt = -1;
    }
    
    return cnt;
}

int main() {
    
    std::cout << solution( {1, 2, 3, 9, 10, 12}, 7 );

    return 0;
}
