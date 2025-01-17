import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
tri = [list(map(int, input().split())) for _ in range(n)]
dp = [[0] * i for i in range(1, n + 1)]
dp [0][0] = tri[0][0]

for i in range(1, n):
    for j in range(i + 1):
        if j == i:
            dp[i][j] = tri[i][j] + dp[i - 1][j - 1]
        elif j == 0:
            dp[i][j] = tri[i][j] + dp[i - 1][j]
        else:
            dp[i][j] = tri[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1])
        
print(str(max(dp[-1])))