#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int low = 0;
    int kMinUpper = 0;
    int left = 0;
    int right = 0;
    int size = 1;
    vector<Node*> children;
    Node* father = nullptr;
};

void findFather(Node* node);
void findSize(Node* node);
bool DFS(Node* node);
bool check(vector<Node*> nodes, int k);
int main(){
    int n;
    cin >> n;
    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    for(int i = 0; i < n - 1; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        idx1--;
        idx2--;
        nodes[idx1]->children.push_back(nodes[idx2]);
        nodes[idx2]->children.push_back(nodes[idx1]);
    }

    findFather(nodes[0]);
    findSize(nodes[0]);

    bool valid = true;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int index1, index2, nA;
        cin >> index1 >> index2 >> nA;
        index1--;
        index2--;
        if (nodes[index2]->father == nodes[index1]){
            if (nA > n - nodes[index2]->size){
                valid = false;
            }
            nodes[index2]->kMinUpper = max(nodes[index2]->kMinUpper, nA);
        }
        if (nodes[index1]->father == nodes[index2]){
            if (nA > nodes[index1]->size){
                valid = false;
            }
            nodes[index1]->low = max(nodes[index1]->low, nA);
        }
    }

    int left = 0, right = n;
    while(left + 1 < right){
        int mid = left + (right - left) / 2;
        if(!check(nodes, mid)){
            left = mid;
        } else{
            right = mid;
        }
    }
    if(!valid){
        cout << -1;
    } else if(check(nodes, left)){
        cout << left;
    } else{
        cout << right;
    }
}
void findFather(Node* node) {
    for (Node *child: node->children) {
        if (child == node->father) continue;
        child->father = node;
        findFather(child);
    }
}

void findSize(Node* node) {
    for (Node *child: node->children) {
        if (child == node->father) continue;
        findSize(child);
        node->size += child->size;
    }
}
bool check(vector<Node*> nodes, int k){
    for (auto & child : nodes){
        child->right = min(k - child->kMinUpper, child->size);
        if (child->right < 0){
            return false;
        }
    }
    if (DFS(nodes[0]) && nodes[0]->right >= k && nodes[0]->left <= k){
        return true;
    }
    return false;
}
bool DFS(Node* node){
    int minR = 0;
    int maxR = 1;

    for (Node *child: node->children){
        if (child == node->father) continue;
        if (!DFS(child)) return false;
        minR += child->left;
        maxR += child->right;
    }
    node->left = max(node->low, minR);
    node->right = min(node->right, maxR);
    if (node->left <= node->right){
        return true;
    }
    return false;
}
