#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node{
public:
    int val;
    vector<Node*> neighbors;
    explicit Node(int x){
        val = x;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Node* nodes[n];
    for(int i = 0; i < n; i++){
        nodes[i] = new Node(i);
    }
    for(int i = 0; i < m; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        nodes[idx2]->neighbors.push_back(nodes[idx1]);
        nodes[idx1]->neighbors.push_back(nodes[idx2]);
    }
    queue<Node*> queue;
    unordered_map<Node*, int> distance;

    queue.push(nodes[0]);
    distance[nodes[0]] = 0;

    while(!queue.empty()){
        Node* cur = queue.front();
        queue.pop();
        for(Node* neighbor : cur->neighbors){
            if(distance.find(neighbor) != distance.end()){
                continue;
            }
            distance[neighbor] = distance[cur] + 1;
            queue.push(neighbor);
        }
    }
    return 0;
}
