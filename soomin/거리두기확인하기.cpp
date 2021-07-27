#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<pair<int, int>> person;

int check_par(vector<string> room, int r1, int c1, int r2, int c2){
    int min_r = min(r1, r2); //작은 row
    int min_c = min(c1, c2); //작은 col
    int max_r = max(r1, r2); //큰 row
    int max_c = max(c1, c2); //큰 col
    /*
        P
        X
        P
    */
    if(r1 == r2){
        if(room[r1][(c1+c2)/2] == 'X')
            return 1;
    }
    // P X P
    else if(c1 == c2){
        if(room[(r1+r2)/2][c1] == 'X')
            return 1;
    }
    /*
        X P
        P X
    */
    else if(r2 == max_r && c2 == max_c){
        if(room[max_r-1][max_c] == 'X' && room[max_r][max_c-1] == 'X')
            return 1;
    }
    /*
        P X
        X P
    */
    else if (r2 == max_r && c1 == max_c){
        if(room[min_r][min_c] == 'X' && room[max_r][max_c] == 'X')
            return 1;
    }
    
    
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i=0; i<5; i++){
        person.clear();
        
        //사람이 있는 위치 저장
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(places[i][j][k] == 'P')
                    person.push_back(make_pair(j, k));;
            }
        }
        
        int sw = 1;
        for(int j=0; j<person.size(); j++){
            //사람1
            int p1_r = person[j].first; //row
            int p1_c = person[j].second; //column
            for(int k=j+1; k<person.size(); k++){
                int dist=0;
                //사람2
                int p2_r = person[k].first;
                int p2_c = person[k].second;
                //맨헤튼거리
                dist = abs(p1_r - p2_r) + abs(p1_c-p2_c);
                
                if(dist <= 2){
                    //거리 가까움
                    if(check_par(places[i], p1_r, p1_c, p2_r, p2_c) == 0){
                        //파티션 없음
                        sw = 0;
                        break;
                    }
                }
            }
            
            if(sw == 0)
                break;
        }
        answer.push_back(sw);
    }
    
    return answer;
}