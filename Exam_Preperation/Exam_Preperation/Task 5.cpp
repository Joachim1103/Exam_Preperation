#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

class SearchNode {
public:
    int x, y; // Coordinates of the node
    int g_cost; // Cost from the start node to this node
    int h_cost; // Heuristic cost from this node to the goal node

    SearchNode(int x, int y, int g_cost, int h_cost)
        : x(x), y(y), g_cost(g_cost), h_cost(h_cost) {}

    int fCost() const {
        return g_cost + h_cost;
    }
};


int calculateHeuristic(int x1, int y1, int x2, int y2) {
    // Euclidean distance as the heuristic
    return static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
}


std::vector<SearchNode> aStarSearch(const SearchNode& start, const SearchNode& goal) {
    // Priority queue to store nodes based on their f_cost
    std::priority_queue<SearchNode, std::vector<SearchNode>,
        std::function<bool(const SearchNode&, const SearchNode&)>> openList(
            [](const SearchNode& a, const SearchNode& b) {
                return a.fCost() > b.fCost();
            }
    );

    // Closed list to keep track of visited nodes
    std::vector<SearchNode> closedList;

    // Start the search from the initial node
    openList.push(start);

    while (!openList.empty()) {
        // Get the node with the lowest f_cost from the open list
        SearchNode current = openList.top();
        openList.pop();

        // Check if the current node is the goal
        if (current.x == goal.x && current.y == goal.y) {
            // Reconstruct the path from the goal to the start
            std::vector<SearchNode> path;
            while (!(current.x == start.x && current.y == start.y)) {
                path.push_back(current);
                current = closedList[getIndex(current)];
            }
            path.push_back(start); // Add the start node
            std::reverse(path.begin(), path.end()); // Reverse the path
            return path;
        }

        // Add the current node to the closed list
        closedList.push_back(current);

        // Generate successor nodes and add them to the open list
        // (Assuming a 2D grid where nodes can move in 8 directions)
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue; // Skip the current node
                int newX = current.x + dx;
                int newY = current.y + dy;

                // Create a new node
                SearchNode successor(newX, newY, current.g_cost + 1, calculateHeuristic(newX, newY, goal.x, goal.y));

                // Check if the successor is valid and not in the closed list
                if (isValid(successor) && !isInList(successor, closedList)) {
                    // Check if the successor is not in the open list or has a lower g_cost
                    if (!isInQueue(successor, openList) || successor.g_cost < getGCost(successor, openList)) {
                        openList.push(successor);
                    }
                }
            }
        }
    }

    // If the open list is empty and the goal is not reached, return an empty path
    return std::vector<SearchNode>();
}
