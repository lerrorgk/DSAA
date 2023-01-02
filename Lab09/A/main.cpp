#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    long distance = LONG_MAX;
    bool flag = false;
    vector<Node*> children;
    vector<long> weight;
};
struct heapNode{
    long distance;
    Node* node;
    heapNode(long x, Node* n){
        distance = x;
        node = n;
    }
};

bool operator<(heapNode a, heapNode b) {
    return a.distance > b.distance;
}

int main() {
    long n, m;
    cin >> n >> m;
    Node* nodes[n];
    for(long i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    for(long i = 0; i < m; i++){
        long index1, index2, weight;
        cin >> index1 >> index2 >> weight;
        index1--, index2--;
        nodes[index1]->children.push_back(nodes[index2]);
        nodes[index1]->weight.push_back(weight);
    }
    priority_queue<heapNode> heapNodes;
    nodes[0]->distance = 0;
    heapNodes.push({nodes[0]->distance, nodes[0]});
    while(!heapNodes.empty()){
        Node* cur = heapNodes.top().node;
        heapNodes.pop();
        if(cur->flag) continue;
        cur->flag = true;
        for(long i = 0; i < cur->children.size(); i++){
            if(cur->children[i]->flag) continue;
            if(cur->children[i]->distance > cur->distance + cur->weight[i]){
                cur->children[i]->distance = cur->distance + cur->weight[i];
            }
            heapNodes.push({cur->children[i]->distance, cur->children[i]});
        }
    }
    if(nodes[n - 1]->distance == LONG_MAX){
        cout << -1;
    } else{
        cout << nodes[n - 1]->distance;
    }
    return 0;
}
