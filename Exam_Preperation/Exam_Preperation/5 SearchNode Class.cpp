#include <iostream>
#include <vector>

class SearchNode {
public:
    int x, y;  // Coordinates of the node
    int g;     // Cost from the start node to this node
    int h;     // Heuristic value (estimated cost from this node to the goal)

    SearchNode(int x, int y, int g, int h) : x(x), y(y), g(g), h(h) {}

    int getCost() const {
        return g + h;
    }

    // Assuming that two nodes are equal if their coordinates are the same
    bool operator==(const SearchNode& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const SearchNode& other) const {
        return !(*this == other);
    }
};

namespace std {
    template <>
    struct hash<SearchNode> {
        size_t operator()(const SearchNode& node) const {
            return hash<int>()(node.x) ^ hash<int>()(node.y);
        }
    };
}


