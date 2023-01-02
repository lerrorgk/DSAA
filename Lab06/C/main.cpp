#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int low = 0;
    int kMinUpper = 0;
    int left = 0;
    int right = 0;
    int size = 0;
    Node* father = nullptr;
    vector<Node *> children;
};
void findFather(Node* root);
void findSize(Node* root);
bool check(Node* node, int k);
void DFS(Node* node, int k);

bool flag = true;

int main() {
    int n;
    cin >> n;
    Node* nodes[n];
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
        if(!check(nodes[0], mid)){
            left = mid;
        } else{
            right = mid;
        }
    }
    if(!check(nodes[0], right) || !valid){
        cout << -1;
    } else if(check(nodes[0], left)){
        cout << left;
    } else{
        cout << right;
    }
    return 0;
}

void findFather(Node* root){
    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i] != root->father)
        {
            root->children[i]->father = root;
            findFather(root->children[i]);
        }
    }
}
void findSize(Node* root){
    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i] != root->father)
        {
            findSize(root->children[i]);
            root->size += root->children[i]->size;
        }
    }
}

bool check(Node* node, int k){
    flag = true;
    DFS(node, k);
    if(k >= node->left && k <= node->right && flag){
        return true;
    }
    return false;
}

void DFS(Node* node, int k){
    if(node == nullptr) return;
    for(Node* child : node->children){
        if(child == node->father) continue;
        DFS(child, k);
    }
    node->left = node->low;
    node->right = k - node->kMinUpper;
    if(node->children.size() == 1){
        node->right = 1;
    }
    int min = 0, max = 0;
    for(Node* child : node->children){
        if(child == node->father) continue;
        min += child->left;
        max += child->right;
    }
    if(min > node->left){
        node->left = min;
    }
    if(max + 1 < node->right){
        node->right = max + 1;
    }
    if(node->right > node->size){
        node->right = node->size;
    }
    if(node->left > node->size){
        flag = false;
    }
    if(node->left > node->right){
        flag = false;
    }
}
