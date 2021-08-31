def solution(src) :
	answer = ""
	count = 0
	
	if src[0] == '1':
		answer += '1'
		
	for i in range(len(src) - 1) :
		if src[i] != src[i+1] :
			answer += chr(ord('A') + count)
			count = 0
		else :
			count += 1
	
	answer += chr(ord('A') + count)
	return answer