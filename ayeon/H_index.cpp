/* UN SOLVED */

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());
    
    int size = citations.size();
    
    int i;
    for(i = size/2 ; ; i--)
    {
        if( citations[i-1] < citations[size/2] ) break;
    }
    
    int j = citations[i];
    
    while( j>size-i )
    {
        j--;
    }
    
    return j;
}
*/
