#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int idx;
    int inDegree;
    bool flag = false;
    vector<Node*> children;
    Node(int _idx, int _inDegree){
        idx = _idx;
        inDegree = _inDegree;
    }
};
struct heapNode{
    int idx;
    Node* node;
    heapNode(int x, Node* n){
        idx = x;
        node = n;
    }
};
bool operator<(heapNode a, heapNode b) {
    return a.idx > b.idx;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        Node* nodes[n];
        for(int i = 0; i < n; i++){
            nodes[i] = new Node(i, 0);
        }
        for(int i = 0; i < m; i++){
            int A, B;
            scanf("%d %d", &A, &B);
            A--, B--;
            nodes[A]->children.push_back(nodes[B]);
            nodes[B]->inDegree++;
        }
        priority_queue<heapNode> heapNodes;
        for(int i = 0; i < n; i++){
            if(nodes[i]->inDegree == 0){
                heapNodes.push({i, nodes[i]});
                nodes[i]->flag = true;
            }
        }
        vector<int> result;
        bool error = false;
        while(!heapNodes.empty()){
            Node* cur = heapNodes.top().node;
            heapNodes.pop();
            result.push_back(cur->idx + 1);
            for(Node* child : cur->children){
                if(child->flag) {
                    error = true;
                    break;
                }
                child->inDegree--;
                if(child->inDegree == 0){
                    heapNodes.push({child->idx, child});
                    child->flag = true;
                }
            }
            if(error) break;
        }
        if(result.size() != n || error) {
            printf("impossible\n");
        }else {
            for(int & i : result)
                printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}
