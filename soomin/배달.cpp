#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000000

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int, int>> graph[51];
    priority_queue<pair<int, int>> pq;
    vector<int> dist(51, INF);
    
    for(int i = 0; i < road.size(); i++){
        int a, b, c;
        
        a = road[i][0];
        b = road[i][1];
        c = road[i][2];
        
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
    //다익스트라
    pq.push(make_pair(1, 0));
    dist[1] = 0;
    
    while(!pq.empty()){
        int current = pq.top().first;
        int cost = -pq.top().second;
        
        pq.pop();
        
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i].first;
            int nextCost = graph[current][i].second;
            
            if(dist[next] > dist[current] + nextCost){
                dist[next] = dist[current] + nextCost;
                pq.push(make_pair(next, -dist[next]));
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K){
            answer++;
        }
    }
    
    return answer;
}