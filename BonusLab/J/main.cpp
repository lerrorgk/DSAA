#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    bool flag = false;
    vector<Node*> children;
    vector<long> distance;
};
struct heapNode{
    long distance;
    Node* curNode;
    Node* nextNode;
    heapNode(Node* n, Node* nn, long x){
        distance = x;
        curNode = n;
        nextNode = nn;
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
    long minDistance = LONG_MAX;
    Node* minL;
    Node* minR;
    for(long i = 0; i < m; i++){
        long index1, index2, distance;
        cin >> index1 >> index2 >> distance;
        index1--, index2--;
        nodes[index1]->children.push_back(nodes[index2]);
        nodes[index1]->distance.push_back(distance);
        nodes[index2]->children.push_back(nodes[index1]);
        nodes[index2]->distance.push_back(distance);
        if(distance < minDistance){
            minDistance = distance;
            minL = nodes[index1];
            minR = nodes[index2];
        }
    }
    long sumChoose = minDistance;
    long sumChooseNegative = minDistance < 0 ? minDistance : 0;
    minL->flag = true;
    minR->flag = true;
    priority_queue<heapNode> heapNodes;
    for(long i = 0; i < minL->children.size(); i++){
        if(minL->children[i]->flag) continue;
        heapNodes.push({minL, minL->children[i], minL->distance[i]});
    }
    for(long i = 0; i < minR->children.size(); i++){
        if(minR->children[i]->flag) continue;
        heapNodes.push({minR, minR->children[i], minR->distance[i]});
    }
    while(!heapNodes.empty()){
        long cDistance = heapNodes.top().distance;
        Node* pre = heapNodes.top().curNode;
        Node* nex = heapNodes.top().nextNode;
        heapNodes.pop();
        if(nex->flag && pre->flag) continue;
        sumChoose += cDistance;
        nex->flag = true;
        for(long i = 0; i < nex->children.size(); i++){
            if(nex->children[i]->flag) continue;
            heapNodes.push({nex, nex->children[i], nex->distance[i]});
        }
    }
    cout << sumChoose;
    return 0;
}
