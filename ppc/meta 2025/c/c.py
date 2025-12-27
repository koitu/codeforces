import math

t = int(input())

for case in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    xor = [0]
    psm = [0]

    result = (n * (n + 1)) // 2
    for i in range(n):
        xor.append(xor[i] ^ lst[i])
        psm.append(psm[i] + lst[i])

    # xor prefix sum is zero when we can find another value in xor that is the same
    matches = {}
    for i in range(1, n+1):
        matches[xor].append(i)

    # using the matches, we need to count the how many times the subset goes over some range between the matches
    # e.g. 1 -- 3 -- 6
    #   - say they all have the same xor value
    #   - then we have subsets 1 -- 3, 1 -- 6, 3 -- 6 that work
    #   - to ensure we stay in O(n) overall we need to count the number of times a subset takes 1 -- 3 and 1 -- 6 (then use prefix sum and multiply)


    print(f"Case #{case+1}: {result}")
