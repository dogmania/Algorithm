def solution(s, skip, index):
    answer = ''
    alphabet = 'abcdefghijklmnopqrstuvwxyz' #26개
    alphabet_index = 0
    
    for i in range(len(skip)):
        alphabet_index = alphabet.find(skip[i])
        alphabet = alphabet.replace(alphabet[alphabet_index], '')
        
    for i in range(len(s)):
        alphabet_index = alphabet.find(s[i])
        alphabet_index += index
        while (alphabet_index >= len(alphabet)):
            alphabet_index -= len(alphabet)
        answer += alphabet[alphabet_index]
    
    return answer