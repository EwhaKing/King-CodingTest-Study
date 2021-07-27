#include <string>
#include <vector>
 
using namespace std;

bool check(string p) { //올바른지 확인
    int l=0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')       l++;
        else {
            if (l-1<0)     return false;
            l--;
        }
    }
    return true;
}
 
string recursion(string p) {
    if (p == "")    return p;
    string u, v;
    int L = 0, R =0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')     L++;
        else        R++;
        if (L == R) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (check(u))     return u + recursion(v);
    else{
        string temp= "(" ;
        temp += recursion(v) + ")";
        u = u.substr(1, u.length()-2);
        for (size_t i = 0; i < u.length(); i++) {
            if (u[i] == '(')    temp += ')';
            else    temp += '(';
        }
        return temp;
    }
}
 
string solution(string p) {
    if (check(p))
        return p;
    return recursion(p);
}