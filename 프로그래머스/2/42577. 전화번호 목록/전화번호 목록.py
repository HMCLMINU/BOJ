def solution(phone_book):
    answer = True
    phone_book.sort()
    # Sol. 1
#     for idx, value in enumerate(phone_book):
#         if idx == len(phone_book)-1:
#             continue
#         is_find = phone_book[idx+1].find(value)
#         if is_find != -1 and is_find == 0:
#             return False
        
#     return True

    # Sol. 2 
    for p1, p2 in zip(phone_book, phone_book[1:]):
        if p2.startswith(p1):
            return False
    
    return True
