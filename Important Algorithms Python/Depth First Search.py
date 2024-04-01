import collections

graph = {"S": ["A", "B"],
         "A": ["B", "D"],
         "B": ["A", "C"],
         "C": ["B", "E"],
         "D": ["A", "G"],
         "E": ["C"],
         "G": ["D"]
         }
start = "S"
goal = "G"


def depth_first_search(start, goal, graph):
    queue = collections.deque([start])
    visited_list = {start: None}
    steps_number = 0
    while queue:
        steps_number += 1
        current_node = queue.pop()
        if current_node == goal:
            break

        next_nodes = graph[current_node]
        for next_node in next_nodes:
            if next_node not in visited_list:
                queue.append(next_node)
                visited_list[next_node] = current_node
    return visited_list, steps_number


visited_list, steps_number = depth_first_search(start, goal, graph)
print(visited_list)

current_node = goal
print(f"\nPath from {start} to {goal}: \n {goal}", end=" ")

while current_node != start:
    current_node = visited_list[current_node]
    print(f"<---- {current_node}", end=" ")
print("\nNumber of steps taken:", steps_number)
