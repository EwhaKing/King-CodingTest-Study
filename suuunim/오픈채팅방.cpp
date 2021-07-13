#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include <sstream>
using namespace std;

namespace{
    
    vector<string> split(string input, char delimiter){
        
        vector<string> ret;
        stringstream ss(input);
        string tmp;
        
        while(getline(ss,tmp,delimiter))
            ret.push_back(tmp);
        return ret;
        
    }
    
    
    enum ActionType{
        
        NONE=0,
        Enter,
        Leave,
        Change,
    };
    
    
}


void splitRecord(string record,ActionType& action, string& id, string& name ){
    
    const vector<string>& parsed = split(record,' ');
    if(parsed[0]=="Enter"){
        
        action=Enter;
        id=parsed[1];
        name=parsed[2];
        
    }
    
     else if(parsed[0]=="Leave"){
        
        action=Leave;
        id=parsed[1];
       
        
    }
    
    else if(parsed[0]=="Change"){
        
        action=Change;
        id=parsed[1];
        name=parsed[2];
        
    }
    
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> idmap;
    vector<pair<string, ActionType>> records;
    
    for(const string& recordd:record){
        
        ActionType action=NONE;
        string id, name;
        splitRecord(recordd,action,id,name);
        if(action==NONE)
            continue;
        
        switch(action){
                
            case Enter :
                {
                    idmap[id]=name;
                    records.push_back(make_pair(id,Enter));
                }break;
            case Leave:
                {
                    
                    records.push_back(make_pair(id,Leave));
                    
                }break;
            case Change:
                {
                    idmap[id]=name;
                    
                }break;
                
                
        }
        
        
    }
    
    for(const pair<string,ActionType>& recordd : records){
        
        string result=idmap[recordd.first] + "님이 ";
        result+=(recordd.second == Enter) ? "들어왔습니다." : "나갔습니다.";
        
        answer.push_back(result);
    }
    
    return answer;
}

