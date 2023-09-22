def calculate_score(grid):
    s = 0
    points = [1, 2, 3, 4, 5]
    for row in range(10):
        for col in range(10):
            if grid[row][col] == 'X':
                distance = min(row, 9 - row, col, 9 - col)
                s += points[distance]
    
    return s
for i in range(int(input())):
    grid = [input() for _ in range(10)]
    print(calculate_score(grid))
