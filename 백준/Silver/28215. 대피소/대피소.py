from itertools import combinations
import sys

# sys.stdin = open('input.txt')
N, K = map(int, input().split())
X = []
Y = []

for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

def sol(c):
    b = 0
    for h_idx in range(N):
        a = 100000
        for c_idx in c:
            a = min(a, abs(X[h_idx] - X[c_idx]) + abs(Y[h_idx] - Y[c_idx]))

        b = max(b, a)
    return b

final = 100000
for c in combinations(range(N), K):
    final = min(final, sol(c))

print(final)