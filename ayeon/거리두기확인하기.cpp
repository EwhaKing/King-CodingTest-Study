// UNSOLVED
/*
#include <string>
#include <vector>
#include <iostream>
#define CHECK(x, y) ((x >= 0 && x < 5 && y >= 0 && y < 5) ? (1) : (0))

using namespace std;

bool isPossible(vector<string> place){
    int directX[12] = {-1, 1, 0, 0, -2, 2, 0, 0, -1, -1, 1, 1};
    int directY[12] = {0, 0, -1, 1, 0, 0, -2, 2, -1, 1, -1, 1};
    vector<vector<bool>> state(5, vector<bool>(5, false));
    
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            if(place[x][y] == 'P'){
                for(int k = 0; k < 12; k++){
                    int nx = x + directX[k];
                    int ny = y + directY[k];
                    
                    if(CHECK(nx, ny)){
                        if(k < 4){
                            if(place[nx][ny] == 'P'){
                                return false;
                            }
                            else if(place[nx][ny] == 'X'){
                                state[nx][ny] = true;
                            }
                        }
                        else if(k < 8){
                            if(place[nx][ny] == 'P' && !state[x + directX[k - 4]][y + directY[k - 4]]){
                                return false;
                            }
                        }
                        else{
                            if(place[nx][ny] == 'P'){
                                if(!state[nx][y] || !state[x][ny]){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++){
        bool isOk = true;
        
        for(int j = 0; j < places[i].size(); j++){
            if(!isPossible(places[i])){
                answer.push_back(0);
                isOk = false;
                break;
            }
        }
        
        if(isOk){
            answer.push_back(1);
        }
    }
    return answer;
}
*/
