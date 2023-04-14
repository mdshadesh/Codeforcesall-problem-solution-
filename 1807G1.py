import sys

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        flag = False
        sum = 1
        for i in range(1, n):
            if arr[i] > sum:
                flag = True
                break
            else:
                sum += arr[i]
        if n == 1 and arr[0] != 1:
            print("NO")
        else:
            if flag:
                print("NO")
            else:
                print("YES")

if __name__ == "__main__":
    if 'PyPy' in sys.version:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    main()
