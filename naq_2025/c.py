import math

# python input will read the entire line...
n = int(input())
k = int(input())

v = []
for _ in range(n):
    v.append(int(input()))

v = sorted(v)

d = {}
for l in v:
    d[l] += 1

res = math.comb(n, k)

for k, v in d:
    if v > 1:
        res /= math.fact(v)

print(v)

