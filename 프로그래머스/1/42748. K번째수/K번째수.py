def solution(array, commands):
    answer = []
    #for idx, command in enumerate(commands):
            #answer.append(sorted(array[command[0]-1:command[1]])[command[2]-1])
    
    return list(map(lambda x : sorted(array[x[0]-1:x[1]])[x[2]-1], commands))
    #return answer
    