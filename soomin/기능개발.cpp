#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 0;
    while (progresses.size() > 0) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
            if (progresses[i] >= 100) progresses[i] = 100; //옵션
        }

        int n = 0;
        for (int i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 100)
                break;
            else {
                n++;
                progresses.erase(progresses.begin() + i);
                speeds.erase(speeds.begin() + i);
                i--;
            }
        }
        if (n > 0) answer.push_back(n);
    }
    return answer;
}