/* 채점 결과 */
/* 정확성: 61.1 */
/* 합계: 61.1 / 100.0 */

#include <cmath>

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    int div = gcd(w, h);
    
    int small_w = w / div;
    int small_h = h / div;
    
    double inclin = (double)small_w / (double)small_h;

    int high = 0;
    int low = 0;

    int i = 1;
    int j = 0;

    int count = 0;

    if (small_h>small_w) std::swap(small_h,small_w);
    
    while (i <= small_w and high <= small_h)
    {
        high = ceil(inclin * i);
        count = count + (high - low);
        low = floor(inclin * i);
        i++;
    }
    
    answer = w*h- count*div;
    
    return answer;
}

/*

***최대공약수를 이용한 풀이***

long long gcd(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w,int h) {
    long long W = w;    
    long long H = h;
    long long tmp=(w+h)-gcd(w,h);
    
    return (W*H)-tmp;
}
*/
