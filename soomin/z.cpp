#include <cmath>
#include <iostream>
using namespace std;

int solution(int N, int r, int c) {
    int result = 0;
    int i_end = pow(2, N);
    int i_start = 0;
    int j_end = pow(2, N);
    int j_start = 0;
    int k = pow(2, N) * pow(2, N);

    while (k > 0) {
        int j_new = (j_start + j_end) / 2;
        int i_new = (i_start + i_end) / 2;
        if (c < j_new && r < i_new) { //Z의 첫번째
            result += 0;
            i_end = i_new;
            j_end = j_new;
        }
        else if (c >= j_new && r < i_new) { //Z의 두번째
            result += (k / 4);
            i_end = i_new;
            j_start = j_new;
        }
        else if (c < j_new && r >= i_new) { //Z의 세번째
            result += (k / 4) * 2;
            i_start = i_new;
            j_end = j_new;
        }
        else if (c >= j_new && r >= i_new) { //Z의 마지막
            result += (k / 4) * 3;
            i_start = i_new;
            j_start = j_new;
        }
        k = k / 4;
    }
    return result;
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    int result = solution(N, r, c);
    cout << result;
}