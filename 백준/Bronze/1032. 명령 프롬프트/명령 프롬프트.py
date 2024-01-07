input_count = int(input())
input_list = [input() for _ in range(input_count)]
result = ''
is_same = True
for i in range(len(input_list[0])):
    for j in range(input_count):
        if input_list[j][i].find(input_list[0][i]) == -1:
            is_same = False
            break
    if is_same:
        result += input_list[0][i]
    else: 
        result += '?'
    is_same = True
print(result)