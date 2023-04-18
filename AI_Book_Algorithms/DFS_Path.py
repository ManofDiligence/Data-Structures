""" Pseudocode for using dfs to search a path

run_dfs(maze, root_point, visited_points):
    let s equal a new stack
    add root_point to s
    while s is not empty:
        pop s and let current_point equal the returned point
        if current_point is not visited:
            mark current_point as visited
            if value at current_node is the goal:
                return path usinf current_point
            else:
                add available cells north, east, south, and west to a list neighbors
                for each neighbor in neighbors:
                    set neighbor parent as current_point
                    push neighbor to s
    return "No path to goal"

"""
def run_dfs(maze, root_point, visited_points):
    s = []
    s.append(root_point)
    neighbor_parent = {root_point: None}  # Added root_point to neighbor_parent
    while s!=[]:
        current_point = s.pop()
        if current_point not in visited_points:
            visited_points.add(current_point)
            if maze[current_point[0]][current_point[1]] == 2:  # Changed goal value to integer
                return get_path(current_point, neighbor_parent)
            else:
                neighbors = get_neighbors(maze, current_point)
                for neighbor in neighbors:
                    neighbor_parent[neighbor] = current_point
                    s.append(neighbor)
    return None  # Return None if no path is found


def get_neighbors(maze, point):
    row, col = point
    neighbors = []
    for (i, j) in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        new_row, new_col = row + i, col + j
        if 0 <= new_row < len(maze) and 0 <= new_col < len(maze[new_row]):
            if maze[new_row][new_col] != 1:  # Changed wall value to integer
                neighbors.append((new_row, new_col))
    return neighbors


def get_path(point, neighbor_parent):
    path = []
    while point:
        path.append(point)
        point = neighbor_parent[point]
    path.reverse()
    if path[0] != (1, 1):  # Check if start is part of the path
        return None
    return path


maze = [
    [1, 1, 1, 1, 1],  # Changed wall value to integer
    [1, 0, 0, 0, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 2, 0, 1],  # Changed goal value to integer
    [1, 1, 1, 1, 1],  # Changed wall value to integer
]
start_point = (1, 1)
visited_points = set()
path = run_dfs(maze, start_point, visited_points)
if path is not None:
    print(path)
else:
    print("No path to goal")
