def solution(participant, completion):
    answer = ''
    dict = {}
    for name in participant:
        dict[name] = 0

    for name in participant:
        dict[name]+=1
    
    for name in completion:
        dict[name]-=1
    
    for key, value in dict.items():
        if value:
            return key
        
