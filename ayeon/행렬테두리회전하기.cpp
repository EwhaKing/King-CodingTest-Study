// P
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> vec(rows, vector<int>(columns));
    
    int k=1;
    
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec[i].size(); j++)
            vec[i][j] = k++; 
    
    for(int i=0; i<queries.size(); i++)
    {
        int x1,y1,x2,y2;
        x1= queries[i][0] -1;
        y1= queries[i][1] -1;
        x2= queries[i][2] -1;
        y2= queries[i][3] -1;
        
        int s= vec[x1][y1];
        
        int min=s;
        int next;
        
        for(int i=x1; i<x2; i++){
            next = vec[i+1][y1];
    	    vec[i][y1] = next;
            if(min>next) min = next;
        }
        for(int i=y1; i<y2; i++){
            next = vec[x2][i+1];
            vec[x2][i]=next;
            if(min>next) min = next;
        }
        for(int i=x2; i>x1; i--){
            next = vec[i-1][y2];
            vec[i][y2] = next;
            if(min>next) min = next;
        }
        for(int i=y2; i>y1; i--){
            next = vec[x1][i-1];
            vec[x1][i] = next;
            if(min>next) min = next;
        }
        vec[x1][y1+1] = s;
        
        answer.push_back(min);
    }
    
    return answer;
}
