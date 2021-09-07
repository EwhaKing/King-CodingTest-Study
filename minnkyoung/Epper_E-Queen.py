def promising(x):
    # row[x]는 열, x는 행
    for i in range(x): 
        # 같은 열, 같은 대각선
        if row[x] == row[i] or abs(row[x] - row[i]) == x - i:
            return False
        # 놓을 수 없는 자리
        if board[row[x]][x] == 1: return False
    return True
    #backtracking 함수
def solution(x):
    global answer
    if x == N: # 백트래킹 종료 조건
    #print(row)
        answer += 1
        return answer
    else:
        for i in range(N): # 0 ~ N까지 놓아보기
            row[x] = I
            # 가능하다면 재귀호출해서 계속 진행
            if promising(x):
                solution(x + 1)

N = int(input())
k = int(input())
x_arr = list(map(int, input().split()))
y_arr = list(map(int, input().split()))
board = [[0] * N for i in range(N)]
for i in range(k): # 놓을 수 없는 자리 저장
    board[x_arr[i] - 1][y_arr[i] - 1] = 1
#for i in range(N):
# print(board[i])
#print()
row = [0] * N
answer = 0
solution(0)
print(answer)
