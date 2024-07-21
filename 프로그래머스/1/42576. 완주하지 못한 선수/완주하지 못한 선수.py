import collections

def solution(participant, completion):
    answer = ''
#     dict = {}
#     for name in participant:
#         if not dict.get(name, 0):
#             dict[name] = 1
#         else:
#             dict[name]+=1
    
#     for name in completion:
#         dict[name]-=1
    
#     for key, value in dict.items():
#         if value:
#             return key
    
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]
    
