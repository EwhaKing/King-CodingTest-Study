def solution(n, final):
    bridge = 0
    # bubble sort를 이용하여 순차적으로 정렬을 맞춰내려간다
    # swap이 필요할때마다 bridge 값을 증가시킨다
    for i in range(1, n):
        for j in range(i-1, -1, -1):
            if final[j] > final[i]:
                bridge += 1
    return bridge
if __name__=='__main__':
    n = int(input())
    final = list(map(int, input().split()))
    print(final)
    print(solution(n, final))