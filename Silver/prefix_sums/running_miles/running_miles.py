def solve():
    N = int(input())
    B = list(map(int, input().split()))

    PSB = [0] * N
    SSB = [0] * N

    for i in range(N):
        PSB[i] = B[i] + i
        SSB[i] = B[i] - i

    for i in range(1, N):
        PSB[i] = max(PSB[i], PSB[i - 1])

    for i in range(N-2, 0, -1):
        SSB[i] = max(SSB[i], SSB[i + 1])

    ans = 0
    for i in range(1, N-1):
        ans = max(ans, PSB[i - 1] + B[i] + SSB[i + 1])

    print(ans)
    return

T = int(input())

for _ in range(T):
    solve()