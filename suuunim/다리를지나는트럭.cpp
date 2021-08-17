//1. 큐에 넣을 수 있으면 넣고 시간 1증가
//  1-1 큐에 다음 수를 넣어도 10이 안 넘는다면 큐에 넣고 1증가
//  1-2 다음 수를 넣을 수 없다면 그냥 1증가
//2. (다리의 길이와 같아지면) 큐에서 수 하나 빼고 올라와있는 차가 모두 건널 동안의 시간 구하기
//1번과 2를 반복

#include <string>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; 
    int sum = 0; 
    int idx = 0; 
    queue<int> q; 
    
    while(1) { 
        if(idx == truck_weights.size()) { //트럭이 모두 다리 위에 올라갔으면
            answer += bridge_length; //해당 트럭이 이동하는 시간 더해주고
            break; //while문 끝
        } 
        
    answer++; 
    int tmp = truck_weights[idx]; //트럭 하나 저장
    if(q.size()==bridge_length) { //큐의 사이즈가 다리의 길이와 같으면
        sum -= q.front(); //다리위에 올라가있는 차들중 
        q.pop(); //가장 먼저 올라온 차를 빼준다
    } 
    if(sum + tmp <= weight) {//새로운 차가 들어와도 되는 상황이면
        q.push(tmp); //q에 넣어주고 
        sum += tmp; //다리 위 전체 트럭의 합에 합쳐주고
        idx++; //다음 차가 올라올 수 있도록 인덱스 늘려줌
    } 
    else { 
        q.push(0); //올라올 수 없으면 그냥 0을 넣어서 q사이즈를 늘림(==시간 계산)
    } 
             } 
    return answer; 
}

