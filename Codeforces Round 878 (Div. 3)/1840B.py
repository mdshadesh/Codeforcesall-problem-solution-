for _ in range(int(input())):
  n, k = map(int, input().split())
  print(min(1 << min(k, 30), n + 1))