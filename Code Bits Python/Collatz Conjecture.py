# Ptyhon 3.8
# A simple bit of code to see evolution of number in the Collatz Conjecture.

list_of_numbers = []

number = 27

list_of_numbers.append(number)

while not number == 1:
    if not number % 2 == 0:
        number = int(number*3 + 1)
    else:
        number = int(number / 2)
        list_of_numbers.append(number)

print(list_of_numbers)
