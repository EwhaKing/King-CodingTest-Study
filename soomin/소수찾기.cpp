#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int is_prime(int n){
    if(n <= 1) return 0;
    for(int i = 2; i<= sqrt(n); i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int x=0;
    vector<int> v;
    
    sort(numbers.begin(), numbers.end());
    int max = stoi(numbers);
    
    do{
        for(int i=1; i<numbers.size()+1; i++){
           x = stoi(numbers.substr(0,i));
            if(is_prime(x) == 1 && find(v.begin(), v.end(), x) == v.end()) 
                v.push_back(x);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    return v.size();
}