#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Vertex {
public:
    int data; // Assuming each vertex has an integer data for simplicity
    vector<Vertex> neighbors; // List of adjacent vertices

    Vertex(int d) : data(d) {}

    void addNeighbor(Vertex& v) {
        neighbors.push_back(v);
    }

    vector<Vertex> getAdjacent() const {
        return neighbors;
    }

    // Overloading the equality operator to simplify the 'exists' function
    bool operator==(const Vertex& other) const {
        return data == other.data;
    }
};

// Function to check if an element exists in a queue
template <typename T>
bool exists(const queue<T>& que, const T& element) {
    queue<T> temp = que;
    while (!temp.empty()) {
        if (temp.front() == element) {
            return true;
        }
        temp.pop();
    }
    return false;
}

void Traversal(Vertex start) {
    queue<Vertex> visited;
    queue<Vertex> q;
    q.push(start);
    visited.push(start);

    while (!q.empty()) {
        Vertex u = q.front();
        q.pop();
        cout << "Vertex: " << u.data << endl;

        vector<Vertex> adj = u.getAdjacent();
        for (const Vertex& z : adj) {
            if (!exists(visited, z) && !exists(q, z)) {
                visited.push(z);
                q.push(z);
            }
        }
    }
}

int main() {
    // Example usage
    Vertex v1(1), v2(2), v3(3), v4(4);

    // Building a simple graph
    v1.addNeighbor(v2);
    v1.addNeighbor(v3);
    v2.addNeighbor(v4);

    // Starting traversal from v1
    Traversal(v1);

    return 0;
}
