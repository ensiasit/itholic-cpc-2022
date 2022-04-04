# Author: El Mehdi ASSALI
# Original: https://codeforces.com/contest/785/problem/C

n, m = map(int, input().split())

if n <= m:
  print(n)
else:
  n -= m
  l, r, ans, M = 0, int(3e9), -1, m

  while l <= r:
    mid = (l + r) // 2

    if n <= (mid * (mid + 1)) // 2:
      ans = mid
      r = mid - 1
    else:
      l = mid + 1

  print(ans + M)