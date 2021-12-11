# A bit of code to generate Pascal's Triangle.

to_nth_row = 8

triangle_values = [[1]]
triangle_indent_list = []


for i in range(1, to_nth_row):
    triangle_values.append(triangle_values[-1])
    triangle_values[-1] = [x + y for x, y in zip(triangle_values[-1] + [0], [0] + triangle_values[-1])]

for j in range(1, to_nth_row + 1):
    triangle_indent_list.append(2*j)

for row_num, row in enumerate(triangle_values):
    print(" " * (triangle_indent_list[-(row_num + 1)] // 2), end="")
    print(row, end="")
    print(" " * (triangle_indent_list[-(row_num + 1)] // 2))


