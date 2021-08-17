#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_minimality(const vector<int> &keys, const int bit)
{
    for (int i = 0; i < keys.size(); ++i)
    {
        if ((keys[i] & bit) == keys[i]) //비트의 속성 이용. 같다면 새로운 키가 기존 키를 포함. 최소성 불만족.
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {

    vector<int> keys;
    int cnt = 0;
    int row = relation.size();
    int col = relation[0].size();

    // 후보키 속성 구성을 비트마스크 순열로 조합하기
    for (int bit = 1; bit < (1 << col); ++bit)
    {
        if (!check_minimality(keys, bit))
        {
            continue;
        }

        // 유일성
        unordered_set<string> set;
        for (int i = 0; i < row; ++i)
        {
            string key;
            for (int j = 0; j < col; ++j)
            {
                if (bit & (1 << j))
                {
                    key += relation[i][j] + ' ';    // 속성간 구분자 추가
                }
            }
            set.insert(key);
        }

        if (set.size() == row) //겹치는 것이 없고 하나씩 모두 있다면 유일성 만족
        {
            keys.push_back(bit);
            ++cnt;
        }
    }
    
    return cnt;
}