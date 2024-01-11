def solution(s):
    answer = 0
    alphabet = s[0]
    count1 = 1
    count2 = 0
    
    for i in range(1, len(s)):
        if (alphabet == s[i]):
            count1 += 1
        else:
            count2 += 1
        
        if (count1 == count2):
            answer += 1
            if (i < len(s) - 1):
                alphabet = s[i + 1]
                count1 = 0
                count2 = 0
    
    if (count1 != count2): answer += 1
    
    return answer