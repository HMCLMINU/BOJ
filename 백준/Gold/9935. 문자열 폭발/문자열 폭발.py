string = input()
exp = input()
ex_len = len(exp)
# while True:
#     s = string.partition(exp)
#     if s[1] == '':
#         break
#     string = str(s[0]) + str(s[2])

# if string == '':
#     print('FRULA')
# else:
#     print(string) 

stack = []
for i in range(len(string)):
    stack.append(string[i])
    if ''.join(stack[-ex_len:]) == exp:
        for _ in range(ex_len):
            stack.pop()

if stack:
    print(''.join(stack))
else:
    print('FRULA')