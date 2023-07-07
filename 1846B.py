for _ in range(int(input())):
    la = input()
    lb = input()
    lc = input()
    
    if la[0] == la[1] == la[2] and "." not in la:
        print(la[0])
    elif lb[0] == lb[1] == lb[2] and "." not in lb:
        print(lb[0])
    elif lc[0] == lc[1] == lc[2] and "." not in lc:
        print(lc[0])
    elif la[0] == lb[0] == lc[0] and la[0] != ".":
        print(la[0])
    elif la[1] == lb[1] == lc[1] and la[1] != ".":
        print(la[1])
    elif la[2] == lb[2] == lc[2] and la[2] != ".":
        print(la[2])
    elif (la[0] == lb[1] == lc[2] or la[2] == lb[1] == lc[0]) and lb[1] != ".":
        print(lb[1])
    else:
        print("DRAW")
