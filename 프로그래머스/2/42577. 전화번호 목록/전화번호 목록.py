def solution(phone_book):
    answer = True
    phone_book.sort()
    for idx, value in enumerate(phone_book):
        if idx == len(phone_book)-1:
            break
        is_find = phone_book[idx+1].find(value)
        if is_find != -1 and is_find == 0:
            return False
        
    return True