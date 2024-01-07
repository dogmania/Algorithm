def solution(park, routes):
    answer = []
    max_x = len(park)
    max_y = len(park[0])
    x_position = 0
    y_position = 0
    
    for i in range(max_x):
        for j in range(max_y):
            if park[i][j] == 'S':
                x_position = i
                y_position = j
    
    for move in routes:
        move = move.split()
        
        if (move[0] == 'E'):
            if y_position + int(move[1]) < max_y: 
                if 'X' not in park[x_position][y_position:y_position + int(move[1]) + 1]:
                    y_position += int(move[1])
        elif (move[0] == 'W'):
            if y_position - int(move[1]) >= 0: 
                if 'X' not in park[x_position][y_position - int(move[1]):y_position + 1]:
                    y_position -= int(move[1])
        elif (move[0] == 'S'):
            if (x_position + int(move[1]) < max_x): 
                accessable = True
                for i in range(x_position, x_position + int(move[1]) + 1):
                    accessable = park[i][y_position] != 'X'
                    if (accessable == False): break
                if (accessable): x_position += int(move[1])
        elif (move[0] == 'N'):
            if (x_position - int(move[1]) >= 0): 
                accessable = True
                for i in range(x_position - int(move[1]), x_position + 1):
                    accessable = park[i][y_position] != 'X'
                    if (accessable == False): break
                if (accessable): x_position -= int(move[1])
            
    answer.append(x_position)
    answer.append(y_position)
    
    return answer