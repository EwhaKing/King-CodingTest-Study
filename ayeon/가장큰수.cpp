// NP
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortsort(int a, int b)
{
    if (a==b) return true;
    
	string aa=to_string(a);
	string bb=to_string(b);
	int s = min(aa.size(), bb.size());

    int i=0;
	while(i<s){
		if(aa[i]-'0' > bb[i]-'0') return true;
		else if (aa[i]-'0' == bb[i]-'0')
			i++;
		else return false;
	}

    if(s == aa.size())
    {
        if( bb[i-1]-'0' > bb[i]-'0' ) return true;
        else return false;
    }
    else{
        if(aa[i-1]-'0' > aa[i]-'0') return false;
        else return true;
    }
}


string solution(vector<int> numbers) {
    
    // TEST 11 
    // [0, 0, 0, 0, 0, 0] "0"
    
    int i=0;
    while(i<numbers.size())
    {
        if (numbers[i] == 0) i++;
        else break;
    }
    if(i==numbers.size()) return "0";
    
    
    // TEST
    string answer="";
    
    sort(numbers.begin(),numbers.end(),sortsort);

    for(int i=0; i<numbers.size(); i++)
    {
        answer+=to_string(numbers[i]);
    }

    return answer;
}
*/
