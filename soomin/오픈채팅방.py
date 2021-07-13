def solution(record):
    answer = []
    dict = {}
    for i in range(len(record)):
        #s_record[i] = record[i].split(' ')
        if record[i].split(' ')[0] == 'Enter' or record[i].split(' ')[0] == 'Change':
            dict[record[i].split(' ')[1]] = record[i].split(' ')[2]
    for i in range(len(record)):
        if record[i].split(' ')[0] == "Enter":
            answer.append(dict.get(record[i].split(' ')[1]) + "님이 들어왔습니다.")
        elif record[i].split(' ')[0] == "Leave":
            answer.append(dict.get(record[i].split(' ')[1]) + "님이 나갔습니다.")
    
    return answer