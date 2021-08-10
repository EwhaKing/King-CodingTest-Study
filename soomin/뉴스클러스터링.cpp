#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    multiset<string> mts1;
    multiset<string> mts2;
    for (int i = 0; i < str1.size() - 1; i++) {
        string s = "";
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')) {
            if ((str1[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')) {
                s += tolower(str1[i]);
                s += tolower(str1[i + 1]);
                mts1.insert(s);
                
            }
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        string s = "";
        if ((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z')) {
            if ((str2[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')) {
                s += tolower(str2[i]);
                s += tolower(str2[i + 1]);
                mts2.insert(s);
            }
        }
    }

    vector<string> v;
    set_intersection(mts1.begin(), mts1.end(), mts2.begin(), mts2.end(), back_inserter(v));

    vector<string> v2;
    set_union(mts1.begin(), mts1.end(), mts2.begin(), mts2.end(), back_inserter(v2));

    float f;
    if(v2.size() == 0) f =1.0;
    else f = (float)v.size() / v2.size();
    int answer = (int)(f * 65536);

    return answer;
}