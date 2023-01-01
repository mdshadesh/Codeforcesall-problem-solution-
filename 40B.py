letters = list(map(str, input()))
c = set()

for letter in letters:
    if letter.isalpha():
        c.add(letter)
print(len(c))

