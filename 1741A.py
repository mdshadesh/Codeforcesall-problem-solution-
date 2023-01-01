 
loop = int(input())
 
for i in range(loop):
    shirt_sizes = list(input().split())
    first_size = shirt_sizes[0]
    second_size = shirt_sizes[1]
 
    if first_size[-1] == second_size[-1]:
        if first_size[-1] == 'S':
            if len(first_size) > len(second_size):
 
                print('<')
            elif len(first_size) < len(second_size):
                print('>')
 
            else:
                print('=')
 
        elif len(first_size) > len(second_size):
            print('>')
        elif len(first_size) < len(second_size):
            print('<')
 
        else:
            print('=')
 
    else:
        if ord(first_size[-1]) < ord(second_size[-1]):
            print('>')
 
        else:
            print('<')
 