def solution(n, r, c) : 
    ans =0
    x = 1 << (n-1)
    y=x
    while (n > 0) :
        n -= 1
        if (n==0) : temp = 1 << 0
        else : temp = 1 << (n-1)
        skip = 1 << (2 * n) 
        if (r < y and c < x ) :
            x = x -temp
            y = y -temp
        elif (r < y and x <=c):
            ans = ans + skip
            x = x+ temp
            y = y-temp
        elif (y<=r and c<x) : 
            ans = ans + (skip *2)
            x = x - temp
            y = y + temp
        else :
            ans = ans + (skip *3)
            x = x+ temp
            y = y +temp; 
    return ans

n, r, c = map(int, input().split())
answer=solution(n,r,c)
print(answer)