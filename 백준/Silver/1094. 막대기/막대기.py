size = int(input())
answer = [64]
while True:
    if sum(answer) == size:
        break
    elif sum(answer) > size:
        temp = answer.pop()
        answer.append(int(temp / 2))
        if sum(answer) < size:
            answer.append(int(temp / 2))
print(len(answer))