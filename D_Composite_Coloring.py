primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))

        # Step 1: Assign each number a raw color based on its smallest prime factor in primes
        raw_colors = [0]*n          # raw_colors[i] = index among 1..11
        used = [False]*12          # used[k] = True if raw color k is used
                                   # (We'll only use indices 1..11 for simplicity)

        for i, x in enumerate(arr):
            # Find smallest prime factor in our list 'primes'
            for prime_index, p in enumerate(primes, start=1):
                if x % p == 0:
                    raw_colors[i] = prime_index
                    used[prime_index] = True
                    break

        # Step 2: Compress the used raw colors to 1..m
        color_map = [0]*12  # color_map[k] = compressed color for raw color k
        c = 0               # number of used colors
        for k in range(1, 12):
            if used[k]:
                c += 1
                color_map[k] = c

        # Step 3: Print results
        print(c)
        compressed_colors = [str(color_map[rc]) for rc in raw_colors]
        print(" ".join(compressed_colors))
solve()