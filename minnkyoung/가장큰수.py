def solution(numbers): 
    numbers = list(map(str, numbers)) 
    numbers.sort(key=lambda x: x*3, reverse=True) 
    return str(int(''.join(numbers)))

#string 대소비교
#첫 문자부터 비교하여 동일한 인덱스에 더 작은 문자열이 나오면 작은 것임. 
#'121121121', '121212'의 경우 4번째 인덱스에서 '121212'가 더 크다고 인식함. 
    