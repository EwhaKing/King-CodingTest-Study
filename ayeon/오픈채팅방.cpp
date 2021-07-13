/* 미해결 */

// https://greenapple16.tistory.com/71

#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector <string> answer;
	vector <string> uid; //record에서 아이디만 따로 저장
	map <string, string> nick_Info; //key:아이디 / value:닉네임
	stringstream ss; string action; string id; string nickname;
	for (int i = 0; i < record.size(); i++) {
		ss.str(record[i]);
		ss >> action; //Enter, Leave, Change
		if (action == "Enter") {
			ss >> id;
			ss >> nickname;
			answer.push_back("님이 들어왔습니다.");
			uid.push_back(id);
			nick_Info[id] = nickname;
		}
		else if (action == "Leave") {
			ss >> id;
			answer.push_back("님이 나갔습니다.");
			uid.push_back(id);
		}
		else {
			ss >> id;
			ss >> nickname;
			nick_Info[id] = nickname;
		}
		ss.clear();
	}
	for (int i = 0; i < answer.size(); i++) {
		answer[i] = nick_Info[uid[i]] + answer[i]; //아이디에 해당하는 닉네임을 붙여줌
	}
	return answer;
}

// Mine
/*
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> user_id;
    vector<string> nickname;
    map< vector<string> ,  vector<string> > user;
    
    for(int i=0; i<record.size(); i++)
    {
        char first = record[i][0];
        if ( first == 69 )
        {
            int j;
            for(j=7; record[i][j] !=' ' ;j++)
            {
                user_id.push_back(record[i][j]);
            }
            
            for(j=j+1; record[i][j] != '\0'; j++)
            {
                nickname.push_back(record[i][j]);
            }
            user.insert(user_id,nickname);
        }
        else if ( first == "L")
        {
            
        }
        else if (first == "C")
        {
            
        }
    }
  
    //record - line 단위로 분류
    
    //line 별로 첫번째 단어가
    // enter 일 때
        // 유저 아이디 와 닉네임 쌍으로 저장 - dictionary
        // 들어왔습니다 문구 
    // leave 일 때
        // 나갔습니다 문구
    // change 일 때
        // 유저 아이디에 저장된 닉네임 변경
        // dictionary 수정
    
    return answer;
}
*/
