def solution(keymap, targets):
    answer = []
    possible = -1
    min_index = 10000
    sum = 0
    
    for target in targets:
        for i in range(len(target)):
            for str in keymap:
                if (str.find(target[i]) != -1 and min_index > str.find(target[i])):
                    possible = 1
                    min_index = str.find(target[i])
            if (possible != 1):
                sum = -1
                break
            else:
                sum += (min_index + 1)
                possible = -1
                min_index = 10000
        answer.append(sum)
        sum = 0
    
    return answer