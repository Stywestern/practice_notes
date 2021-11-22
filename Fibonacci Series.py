# A bit of code to generate the Fibonacci Series up to it's nth element.

fibonacci_list = [1, 1]
until_n = 5
iteration = 2
if until_n >= 3:
    while iteration < until_n:
        iteration += 1
        x = fibonacci_list[-2]
        y = fibonacci_list[-1]
        fibonacci_list.append(x + y)
    print(fibonacci_list)
elif until_n == 1:
    print([1])
elif until_n == 2:
    print([1, 1])


