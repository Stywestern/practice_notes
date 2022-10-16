import heapq

graph = {"S": [(3, "A"), (5, "B")],
         "A": [(4, "B"), (3, "D")],
         "B": [(4, "A"), (4, "C")],
         "C": [(4, "B"), (6, "E")],
         "D": [(3, "A"), (5, "G")],
         "E": [(6, "C")],
         "G": [(5, "D")]
         }
start = "S"
goal = "G"


def dijkstra(start, goal, graph):
    queue = []
    heapq.heappush(queue, (0, start))
    reached_list = {start: None}
    reached_cost_list = {start: 0}
    steps_number = 1
    while queue:
        steps_number += 1
        current_cost, current_node = heapq.heappop(queue)
        if current_node == goal:
            break
        next_nodes = graph[current_node]
        for next_node in next_nodes:
            nextt_cost, nextt_node = next_node
            new_cost = reached_cost_list[current_node] + nextt_cost

            if nextt_node not in reached_list or new_cost < reached_cost_list[nextt_node]:
                heapq.heappush(queue, (new_cost, nextt_node))
                reached_cost_list[nextt_node] = new_cost
                reached_list[nextt_node] = current_node

    return reached_list, reached_cost_list, steps_number


visited_list, visited_cost_list, steps_number = dijkstra(start, goal, graph)

current_node = goal
print(f"\nPath from {start} to {goal}: \n {goal}", end=" ")

path_cost = 0
while current_node != start:
    path_cost = visited_cost_list[goal]
    current_node = visited_list[current_node]
    print(f"<---- {current_node}", end=" ")

print("\nNumber of steps taken:", steps_number)
print("\nTotal cost:", path_cost)
