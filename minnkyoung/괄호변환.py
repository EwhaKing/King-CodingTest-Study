def solution(p):
    if not p:
        return ""
    u,v = seperate(p)
    
    if isBalanced(u):
        return u + solution(v) 

    else:
        answer = '('
        answer += solution(v)
        answer += ')'

        for i in u[1:-1]:
            if i == '(':
                answer += ')'
            else:
                answer += '('
                
        return answer

def seperate(p):
    left = 0
    right = 0
    for i in range(len(p)):
        if p[i] == '(':
            left += 1
        elif p[i] == ')':
            right += 1
        if left == right:
            return p[:i+1], p[i+1:] 

def isBalanced(u):
    stack = []

    for i in u:
        if i == '(':
            stack.append(i)
        else:
            if not stack:
                return False
            stack.pop()
    return True