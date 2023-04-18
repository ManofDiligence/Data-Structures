import heapq

N = 100

# Define a class for the cells
class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.g = 0
        self.h = 0
        self.parent = None

    def f(self):
        return self.g + self.h

# Define a function to compute the heuristic distance between two cells
def heuristic_distance(cell, target):
    return abs(cell.x - target.x) + abs(cell.y - target.y)

# Define the A* algorithm function
def a_star(start, target, board):
    open_set = []
    closed_set = set()
    heapq.heappush(open_set, (start.f(), start))
    
    while open_set:
        current = heapq.heappop(open_set)[1]
        if current.x == target.x and current.y == target.y:
            path = []
            while current.parent:
                path.append((current.x, current.y))
                current = current.parent
            path.append((start.x, start.y))
            return path[::-1]
        closed_set.add(current)
        for dx, dy in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
            x, y = current.x + dx, current.y + dy
            if x < 0 or x >= N or y < 0 or y >= N or board[x][y] == 1:
                continue
            neighbor = Cell(x, y)
            neighbor.g = current.g + 1
            neighbor.h = heuristic_distance(neighbor, target)
            neighbor.parent = current
            if neighbor in closed_set:
                continue
            if (neighbor.f(), neighbor) not in open_set:
                heapq.heappush(open_set, (neighbor.f(), neighbor))
            else:
                for i, (f, cell) in enumerate(open_set):
                    if cell == neighbor and f > neighbor.f():
                        open_set[i] = (neighbor.f(), neighbor)
                        heapq.heapify(open_set)
    return None


# Set the start and target cells
start = Cell(0, 0)
target = Cell(5, 5)

# Set some obstacles in the board
board = [[0] * N for _ in range(N)]
board[2][2] = 1
board[2][3] = 1
board[3][2] = 1
board[3][3] = 1

    # Find the path using A*
path = a_star(start, target, board)
if path is not None:
    print("Path found from ({}, {}) to ({}, {}):".format(start.x, start.y, target.x, target.y))
    for x, y in path:
        print("({},{})".format(x, y))
else:
    print("No path found from ({}, {}) to ({}, {})".format(start.x, start.y, target.x, target.y))


