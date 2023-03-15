from sys import stdin, stdout

counter = 0
temp = 0
step = 1

for num in map(int, stdin.readline().rstrip()):
    temp += num
    if not num % 3 or not temp % 3 or step == 3:
        counter += 1
        temp = 0
        step = 0
    step += 1

stdout.write(f'{counter}\n')