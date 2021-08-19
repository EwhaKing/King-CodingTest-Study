from itertools import combinations

def solution(relation):
    
    answer = 0
    
    all = list() #모든 col의 조합 리스트
    uniqeIndex = [] #유일성을 만족하는 조합 리스트
    
    if len(relation) > 0:

        colSize = len(relation[0]) #col개수

        rowSize = len(relation) #row개수

        for i in range(1, colSize + 1): #모든 col의 조합 구하기(set)

            all.extend([set(k) for k in combinations([j for j in range(colSize)], i)])

        for comb in all: #조합들의 유일성 검사

            vaildSet = set() #set에 추가하여 원래의 row크기와 비교

            for row in range(rowSize): #조합에 해당되는 row를 하나의 문자열로 만들어 set에 넣기
                temp = ''
    
                for col in comb:
                    temp += relation[row][col]
                
                vaildSet.add(temp)

            if len(vaildSet) == rowSize: 
                uniqeIndex.append(comb)

    delSet = set() #최소성을 위배하는 set

    for i in uniqeIndex:
        for idx, j in enumerate(uniqeIndex):

            if i.issubset(j) and i != j:
                delSet.add(uniqeIndex.index(j))

    answer = len(uniqeIndex)-len(delSet)
    
    return answer