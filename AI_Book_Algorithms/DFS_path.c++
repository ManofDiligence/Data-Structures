#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

using namespace std;

vector<pair<int, int>> get_neighbors(vector<vector<string>>& maze, pair<int, int>& point) {
    int row = point.first, col = point.second;
    vector<pair<int, int>> neighbors;
    for (pair<int, int> dir : {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)}) {
        int new_row = row + dir.first, new_col = col + dir.second;
        if (new_row >= 0 && new_row < maze.size() && new_col >= 0 && new_col < maze[new_row].size()) {
            if (maze[new_row][new_col] != "wall") {
                neighbors.push_back(make_pair(new_row, new_col));
            }
        }
    }
    return neighbors;
}

vector<pair<int, int>> get_path(pair<int, int>& point, unordered_map<pair<int, int>, pair<int, int>>& neighbor_parent) {
    vector<pair<int, int>> path;
    while (point != make_pair(-1, -1)) {
        path.push_back(point);
        point = neighbor_parent[point];
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int, int>> run_dfs(vector<vector<string>>& maze, pair<int, int>& root_point, set<pair<int, int>>& visited_points) {
    vector<pair<int, int>> path;
    vector<pair<int, int>> s;
    s.push_back(root_point);
    unordered_map<pair<int, int>, pair<int, int>> neighbor_parent;
    neighbor_parent[root_point] = make_pair(-1, -1); // Added root_point to neighbor_parent
    while (!s.empty()) {
        pair<int, int> current_point = s.back();
        s.pop_back();
        if (visited_points.find(current_point) == visited_points.end()) {
            visited_points.insert(current_point);
            if (maze[current_point.first][current_point.second] == "goal") {
                return get_path(current_point, neighbor_parent);
            }
            else {
                vector<pair<int, int>> neighbors = get_neighbors(maze, current_point);
                for (pair<int, int> neighbor : neighbors) {
                    neighbor_parent[neighbor] = current_point;
                    s.push_back(neighbor);
                }
            }
        }
    }
    return path; // Return empty list if no path is found
}

int main() {
    vector<vector<string>> maze = {
        {"wall", "wall", "wall", "wall", "wall"},
        {"wall", "start", " ", " ", "wall"},
        {"wall", " ", "wall", " ", "wall"},
        {"wall", " ", "goal", " ", "wall"},
        {"wall", "wall", "wall", "wall", "wall"}
    };
    pair<int, int> start_point = make_pair(1, 1);
    set<pair<int, int>> visited_points;
    vector<pair<int, int>> path = run_dfs(maze, start_point, visited_points);
    for (pair<int, int> point : path) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
    return 0;
}
