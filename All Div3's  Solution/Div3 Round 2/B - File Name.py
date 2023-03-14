import sys

input = sys.stdin.readline
output = sys.stdout.write


def main():
    length_ = int(input().rstrip())
    a = input().rstrip()
    str_ = 'xxx'
    c_ = 0
    for i in range(length_ - 2):
        if a[i:i + 3] == str_:
            c_ += 1
    output(str(c_))


if __name__ == '__main__':
    main()
