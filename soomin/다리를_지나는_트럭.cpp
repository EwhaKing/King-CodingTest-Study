#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int on_bridge = 0;
    queue<int> q;
    int j = 0;
    int i = 0;
    while (i < truck_weights.size()) {
        if (!q.empty()) {
            if (answer - q.front() == bridge_length) {
                q.pop();
                on_bridge -= q.front();
                q.pop();
                j--;
            }
        }
        if (on_bridge + truck_weights[i] <= weight && j < bridge_length) {
            on_bridge += truck_weights[i];
            q.push(answer);
            q.push(truck_weights[i]);
            j++;
            i++;
        }

        answer++;

    }
    answer += bridge_length;
    return answer;
}