#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool isVisit[5][5];
bool flag = false;

void checkMHL(vector<string>& place, int x, int y, int deep){
    
    for(int i = 0; i < 4; i++){
        if(deep == 2 || flag) return;
        
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5 &&
          !isVisit[next_x][next_y] && place[next_x][next_y] != 'X'){
            if(place[next_x][next_y] == 'P'){
                flag = true;
                return;
            } else {
                isVisit[next_x][next_y] = true;
                checkMHL(place, next_x, next_y, deep + 1); 
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& e : places){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                isVisit[i][j] = false;
            }
        }
        flag = false;
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(e[i][j] == 'P' && !isVisit[i][j]){
                    isVisit[i][j] = true;
                    checkMHL(e, i, j, 0);
                }
                if(flag){
                    answer.emplace_back(0);
                    break;
                }
            }
            if(flag) break;
        }
        
        if(!flag) answer.emplace_back(1);
    }
    return answer;
}
