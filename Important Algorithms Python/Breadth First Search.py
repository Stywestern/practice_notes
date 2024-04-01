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


def breadth_first_search(start, goal, graph):
    queue = collections.deque([start])
    reached_list = {start: None}
    steps_number = 1
    while queue:
        steps_number += 1
        current_node = queue.popleft()
        if current_node == goal:
            break

        next_nodes = graph[current_node]
        for next_node in next_nodes:
            if next_node not in reached_list:
                queue.append(next_node)
                reached_list[next_node] = current_node
    return reached_list, steps_number


visited_list, steps_number = breadth_first_search(start, goal, graph)
print(visited_list)

current_node = goal
print(f"\nPath from {start} to {goal}: \n {goal}", end=" ")

while current_node != start:
    current_node = visited_list[current_node]
    print(f"<---- {current_node}", end=" ")
print("\nNumber of steps taken:", steps_number)
