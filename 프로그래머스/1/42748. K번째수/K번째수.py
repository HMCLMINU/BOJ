def solution(array, commands):
    answer = []
    for idx, command in enumerate(commands):
        try:
            answer.append(sorted(array[command[0]-1:command[1]])[command[2]-1])
        except Exception:
            print(idx, command[0]-1, command[1]-1, command[2]-1)
        
    return answer