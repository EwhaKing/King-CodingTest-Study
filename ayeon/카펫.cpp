#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int s = brown + yellow;

    for(int i=s; i>= sqrt(s); i--)
    {
        if( (i-2)*(s/i - 2) == yellow )
        {
            answer.push_back(i);
            answer.push_back(s/i);
            break;
        }
    }

    return answer;
}
