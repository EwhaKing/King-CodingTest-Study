#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
 
vector<pair<string, int>> orderSet;
 
bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}
 
void checkSet(string order, vector<int> course, string s, int location, int depth)
{
    int index;
 
     for (int i = 0; i < course.size(); ++i)
      {
           if (course[i] == depth){
                index = orderSet.size();
                for (int k = 0; k < orderSet.size(); ++k){
                    if (orderSet[k].first == s){
                        index = k;
                        break;
                    }
               }
               if (index == orderSet.size()){
                    orderSet.push_back({s, 1});
                }
                else
                    ++orderSet[index].second;
            }
        }
    for (int i = location + 1; i < order.length(); ++i)
        checkSet(order, course, s + order[i], i, depth + 1);
}
 
vector<string> solution(vector<string> orders, vector<int> course)
{
    int len;
    int count[11];
    string s = "";
    vector<string> answer;
 
    memset(count, 0, sizeof(count));
 
    for (int i = 0; i < orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end()); //메뉴 알파벳순 정렬
 
    for (int i = 0; i < orders.size(); ++i){
        for (int j = 0; j < orders[i].length(); ++j)
        checkSet(orders[i], course, s + orders[i][j], j, 1);
    } //조합
 
    sort(orderSet.begin(), orderSet.end(), compare); //정렬
 
    for (int i = 0; i < orderSet.size(); ++i){
        if (orderSet[i].second < 2)
            continue;
        //메뉴 2개 이상
        len = orderSet[i].first.length();
        if ((count[len] == 0 || count[len] == orderSet[i].second) && orderSet[i].second != 1){
            answer.push_back(orderSet[i].first);
            count[len] = orderSet[i].second;
        }
    }
 
    sort(answer.begin(), answer.end()); //알파벳 순으로
 
    return answer;
}