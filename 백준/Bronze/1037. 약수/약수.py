input_count = int(input())
input_list = list(map(int, input().split()))
input_list.sort()
if (input_count % 2 == 1):
    print(input_list[int(input_count / 2)] * input_list[int(input_count / 2)])
else:
    print(input_list[0] * input_list[len(input_list) - 1])