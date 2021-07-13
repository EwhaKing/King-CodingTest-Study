#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int result=0;
    vector<int> day;
 
    queue<int> q;
    
    for(int i=0;i<progresses.size();i++){
        
      
        int b=(100-progresses[i])/speeds[i];
        if(progresses[i]+b*speeds[i]!=100) b++;
        
        day.push_back(b);
        
    }
    
    q.push(day[0]);
    
   for(int i=1; i<day.size(); i++) {
       if(q.front() >= day[i]) { 
           q.push(day[i]); 
       } 
       else { 
           answer.push_back(q.size()); 
           while(!q.empty()) q.pop();
           q.push(day[i]); 
            } 
   } 
    if(!q.empty()) answer.push_back(q.size());


    
    return answer;
}
