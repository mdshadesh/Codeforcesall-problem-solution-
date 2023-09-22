def max_product_after_adding_one(n, arr):
    min_digit = min(arr)
    min_digit_index = arr.index(min_digit)
    
    modified_arr = arr[:]
    modified_arr[min_digit_index] += 1
    
    product = 1
    for digit in modified_arr:
        product *= digit
    
    return product

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    result = max_product_after_adding_one(n, arr)
    print(result)
