def solution(nums):
    answer = 0
    pick = len(nums) // 2
    nums = set(nums)
    # 중복을 제거했는데 처음보다 크거나 같다 --> 고를 수 있는 수는 pick으로 제한
    if len(nums) >= pick:
        answer = pick 
    else:
        answer = len(nums)
        
    return answer