#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<int, int> maxNum; // 메뉴 갯수, 최대값
    map<int, vector<string>> result; // 메뉴 갯수, string들 

    for(int i=0; i<orders.size(); i++){
        // includes 사용을 위해 sort해두기
        sort(orders[i].begin(), orders[i].end());
    }

    for(int i=0; i<course.size(); i++){
        maxNum[course[i]] = 1;
        vector<string> tmp;
        result[course[i]] = tmp;
    }

    while(orders.size()){ // orders 돌면서
        string target = orders[0]; 
        orders.erase(orders.begin());
        int t_size = target.size();
        vector<int> tmp(t_size, 0); // 조합을 만들기 위한 tmp vector

        for(int i=0; i<course.size(); i++){
            int size = course[i]; // 몇 개의 조합을 찾을 건지 결정
            if(t_size<size) // 현재 order의 크기보다 필요로하는 조합 갯수가 더 크면 건너뛰기
                continue;

            // 뒤부터 size개만큼 1 채우기
            // next_permutation 적용시 오름차순으로 구성되어있어야 함
            for(int j=t_size-1; j>=t_size-size; j--){
                tmp[j] = 1;
            }

            do{
                string t_string = ""; // 포함되어있는지 검사할 string
                for(int j=0; j<tmp.size(); j++){
                    if(tmp[j]==1)
                        t_string += target[j];
                }

                int num = 1; // 겹치는 횟수 측정
                for(int j=0; j<orders.size(); j++){ // 해당 target string을 포함하고 있는 문자열이 orders에 있는지 확인
                    if(includes(orders[j].begin(), orders[j].end(), t_string.begin(), t_string.end())){
                        // 포함하고 있으면 num 증가
                        num += 1;
                    }
                }

                if(num == 1) // 겹치는게 없으면 그냥 넘어가기
                    continue;

                if(maxNum[size]<num){
                    // max보다 크면 vector 초기화 및 추가
                    result[size].clear();
                    maxNum[size] = num;
                    result[size].push_back(t_string);
                }else if(maxNum[size]==num){
                    // max와 같으면 string 추가
                    result[size].push_back(t_string);
                }
            }while(next_permutation(tmp.begin(), tmp.end())); // 조합 사용
        }
    }

    // answer 추출
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            answer.push_back(result[i][j]);
        }
    }

    // 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

