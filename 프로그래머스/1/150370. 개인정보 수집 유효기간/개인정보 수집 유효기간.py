def solution(today, terms, privacies):
    answer = []
    privacy = []
    date = []
    terms_dict = {}
    today_date_list = today.split('.')
    today_date_list = [int(value) for value in today_date_list]
    today_date = today_date_list[0] * 10000 + today_date_list[1] * 100 + today_date_list[2]
    i = 1
    
    for term in terms:
        temp_list = term.split()
        terms_dict[temp_list[0]] = int(temp_list[1])
    
    for item in privacies:
        privacy = item.split()
        date = privacy[0].split('.')
        date = [int(value) for value in date]
        date[1] += terms_dict[privacy[1]]
        if (date[1] > 12): 
            date[0] += int(date[1] / 12)
            date[1] = int(date[1] % 12)
        date[2] -= 1
        if date[2] == 0: 
            date[2] = 28 
            date[1] -= 1
        if date[1] == 0:
            date[1] = 12
            date[0] -= 1
        item_date = date[0] * 10000 + date[1] * 100 + date[2]
        if (today_date > item_date): answer.append(i)
        i += 1

    return answer