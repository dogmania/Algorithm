input_count = int(input())
input_list = [input() for _ in range(input_count)]
sum = 0
add_num = 0
for str in input_list:
    for i in range(len(str)):
        if (str[i] == 'O'):
            add_num += 1
            sum += add_num
        else:
            add_num = 0
    print(sum)
    sum = 0
    add_num = 0