def solution(start, end_num):
    answer = [i for i in range(end_num, start + 1)]
    answer.sort(reverse = True)
    
    return answer