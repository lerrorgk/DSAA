#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int max;
    vector<int> children;
    Node(int x): max(x){}
};

void traverse(int node, Node** nodes, int max, bool visited[]);

int main() {
    int n, m;
    cin >> n >> m;
    Node* nodes[n + 1];
    for(int i = 0; i <= n; i++){
        nodes[i] = new Node(i);
    }
    for(int i = 0; i < m; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        nodes[idx2]->children.push_back(idx1);
    }
    bool visited[n + 1];
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
    for(int i = n; i > 0; i--){
        traverse(i, nodes, i, visited);
    }
    for(int i = 1; i <= n; i++){
        cout << nodes[i]->max << " ";
    }
    return 0;
}

void traverse(int cur, Node** nodes, int max, bool visited[]){
    if(visited[cur]) return;
    visited[cur] = true;
    for(int child : nodes[cur]->children){
        if(max > nodes[child]->max){
            nodes[child]->max = max;
        }
        traverse(child, nodes, max, visited);
    }
}
