/* 채점 결과 */

/* 정확성: 27.3 */
/* 합계: 27.3 / 100.0 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 작업의 개수 N
    int N = progresses.size();

    vector<int> finish_day(N);

    for (int i = 0; i < N; i++)
    {
        int j = 0;

        while (progresses[i] < 100)
        {
            progresses[i] = progresses[i] + speeds[i];
            j++;
        }
        finish_day[i] = j;
    }

    int update = finish_day[0];
    int day = 1;

    for (int i = 1; i < N; i++)
    {
        if (update >= finish_day[i])
            day++;
        else
        {
            answer.push_back(day);
            day = 1;
        }
        update = finish_day[i];
    }
    answer.push_back(day);

    return answer;
}
