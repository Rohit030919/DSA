#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Define a structure for graph node
struct GraphNode {
    string name;
    vector<GraphNode*> neighbors;
    bool visited;

    GraphNode(string name) : name(name), visited(false) {}
};

// Function to perform DFS traversal
void DFS(GraphNode* node) {
    if (node == nullptr || node->visited)
        return;

    cout << node->name << " ";
    node->visited = true;

    for (auto neighbor : node->neighbors) {
        DFS(neighbor);
    }
}

// Function to perform BFS traversal
void BFS(GraphNode* node) {
    if (node == nullptr)
        return;

    queue<GraphNode*> q;
    q.push(node);
    node->visited = true;

    while (!q.empty()) {
        GraphNode* current = q.front();
        q.pop();
        cout << current->name << " ";

        for (auto neighbor : current->neighbors) {
            if (!neighbor->visited) {
                q.push(neighbor);
                neighbor->visited = true;
            }
        }
    }
}

int main() {
    // Create nodes for landmarks
    GraphNode* college = new GraphNode("College");
    GraphNode* park = new GraphNode("Park");
    GraphNode* library = new GraphNode("Library");
    GraphNode* museum = new GraphNode("Museum");
    GraphNode* cafe = new GraphNode("Cafe");

    // Connect nodes based on proximity
    college->neighbors = {park, library, cafe};
    park->neighbors = {college, library};
    library->neighbors = {college, park, museum};
    museum->neighbors = {library, cafe};
    cafe->neighbors = {college, museum};

    // Perform DFS and BFS
    cout << "DFS traversal: ";
    DFS(college);
    cout << endl;

    // Reset visited flags
    college->visited = false;
    park->visited = false;
    library->visited = false;
    museum->visited = false;
    cafe->visited = false;

    cout << "BFS traversal: ";
    BFS(college);
    cout << endl;

    // Clean up
    delete college;
    delete park;
    delete library;
    delete museum;
    delete cafe;

    return 0;
}
