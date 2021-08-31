def solution(n, M):
    dp=[0]*30001
    dp[1]=M[0] 
    if n > 1 :
        dp[2]=M[0]+M[1] 
    if n > 2 :

        for i in range(3,n+1):
            dp[i]=max(dp[i-1], dp[i-2] + M[i-1],
            dp[i-3] + M[i-2] + M[i-1])
    return dp[n]