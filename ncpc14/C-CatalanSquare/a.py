
n = int(input())
n += 1

ans = int(1)
for i in range(1, n+1):
    ans *= 2*n - i + 1
    ans = ans // i

ans = ans // (n+1)

print(ans)
