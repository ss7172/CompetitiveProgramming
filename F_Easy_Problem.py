import sys

def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    a = list(map(int, sys.stdin.readline().split()))
    
    INF = float('inf')
    dp = [INF] * 4
    dp[0] = 0  

    for i in range(n):
        c = s[i]
        cost = a[i]
        new_dp = [INF] * 4
        print("dp:", dp)
        print("new_dp:", new_dp)
        print("c:", c)
        print("cost:", cost)
        
        for j in range(4):
            if dp[j] == INF:
                continue
            
            if new_dp[j] > dp[j] + cost:
                new_dp[j] = dp[j] + cost
            
            if j == 0 and c == 'h':
                new_j = 1
                if new_dp[new_j] > dp[j]:
                    new_dp[new_j] = dp[j]
            elif j == 1 and c == 'a':
                new_j = 2
                if new_dp[new_j] > dp[j]:
                    new_dp[new_j] = dp[j]
            elif j == 2 and c == 'r':
                new_j = 3
                if new_dp[new_j] > dp[j]:
                    new_dp[new_j] = dp[j]
            elif j == 3 and c == 'd':
                pass  
            else:
                if new_dp[j] > dp[j]:
                    new_dp[j] = dp[j]
        
        dp = new_dp
    
    print(min(dp))

if __name__ == "__main__":
    main()