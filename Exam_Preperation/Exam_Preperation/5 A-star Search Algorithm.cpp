#include <queue>
#include <unordered_set>

class AStarSearch {
public:
    static std::vector<SearchNode> findPath(SearchNode start, SearchNode goal) {
        std::priority_queue<SearchNode, std::vector<SearchNode>, std::function<bool(SearchNode, SearchNode)>> openList(
            [](SearchNode a, SearchNode b) {
                return a.getCost() > b.getCost();
            });

        std::unordered_set<SearchNode> closedList;
        openList.push(start);

        while (!openList.empty()) {
            SearchNode current = openList.top();
            openList.pop();

            if (current == goal) {
                // Goal reached, reconstruct the path
                return reconstructPath(current);
            }

            closedList.insert(current);

            // Expand neighbors
            std::vector<SearchNode> neighbors = getNeighbors(current);

            for (const SearchNode& neighbor : neighbors) {
                if (closedList.find(neighbor) == closedList.end()) {
                    if (std::find(openList.c.begin(), openList.c.end(), neighbor) == openList.c.end()) {
                        // Neighbor is not in the open list
                        openList.push(neighbor);
                    }
                }
            }
        }

        // No path found
        return std::vector<SearchNode>();
    }

private:
    static std::vector<SearchNode> reconstructPath(SearchNode current) {
        std::vector<SearchNode> path;
        while (current != nullptr) {
            path.push_back(current);
            current = current.parent;
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    static std::vector<SearchNode> getNeighbors(SearchNode node) {
        // Implement logic to get neighboring nodes based on your map/graph representation
    }
};
