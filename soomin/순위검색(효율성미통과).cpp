#include <string>
#include <vector>

using namespace std;

vector<string> split(string s) {
    vector<string> result;
    string temp;
    for (char c : s) {
        if (c == ' ') {
            if (temp != "and") {
                result.push_back(temp);
                temp = "";
            }
            if(temp == "and")
                temp = "";
        }
        else temp += c;
    }
    result.push_back(temp);
    return result;
}

vector<int> findindex(vector<string> one_query) {
    vector<int> index;

    if (one_query[0] != "-") {
        index.push_back(0);
    }
    if (one_query[1] != "-") {
        index.push_back(1);
    }
    if (one_query[2] != "-") {
        index.push_back(2);
    }
    if (one_query[3] != "-") {
        index.push_back(3);
    }
    return index;
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;


    int n = 0;
    for (int i = 0; i < query.size(); i++) {
        vector<string> one_query = split(query[i]);

        vector<int> index = findindex(one_query);

        for (int j = 0; j < info.size(); j++) {
            vector<string> one_info = split(info[j]);
            int t=0;
            if (!empty(index)) {

                for (int k = 0; k < index.size(); k++) {

                    if (one_info[index[k]] == one_query[index[k]]) {
                        t = 1;
                    }
                    else {
                        t = 0;
                        break;
                    }

                }
            }
            else t = 1;
            if (t == 1 && (stoi(one_info[4]) >= stoi(one_query[4])))
                n++;
            

        }
        answer.push_back(n);
        n = 0;
    }
    return answer;
}