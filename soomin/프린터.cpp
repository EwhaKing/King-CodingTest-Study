#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> priorities, int location) {
    stack<int> s;
    int index = 0;
    int n = *max_element(priorities.begin(), priorities.end());
    while (true) {
        for (int i = index; i < priorities.size(); i++) {
            if (priorities[i] == n) {
                s.push(i);
                if (i == location)
                    return s.size();
            }
        }
        for (int i = 0; i < index; i++) {
            if (priorities[i] == n) {
                s.push(i);
                if (i == location)
                    return s.size();
            }
        }
        index = s.top();
        n--;
    }
}