#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    
    if(n<2) return false;
    
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return false;
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> number;
    
    for(int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }
    sort(v.begin(),v.end());
    
    do{
        string a="";
        for(int i=0;i<v.size();i++){
            a.push_back(v[i]);
            number.push_back(stoi(a));
        }
        
    }while(next_permutation(v.begin(),v.end()))
    
    sort(number.begin(),number.end());
    number.erase(unique(number.begin(),number.end()),number.end())
    
    for(int i=0;i<number.size();i++){
        
        if(isPrime(number[i]))
            answer++;
    }
    return answer;
}
