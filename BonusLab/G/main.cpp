#include <iostream>
using namespace std;

struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
};
bool isCompleteTree(Node* root, int n, bool leaf);

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        Node* nodes[n];
        bool data[n];
        for(int i = 0; i < n; i++){
            nodes[i] = new Node();
            data[i] = false;
        }
        for(int i = 0; i < n; i++){
            int left, right;
            cin >> left >> right;
            left--, right--;
            data[left] = true;
            data[right] = true;
            if(left != -1) nodes[i]->left = nodes[left];
            if(right != -1) nodes[i]->right = nodes[right];
        }
        Node* root;
        for(int i = 0; i < n; i++){
            if(!data[i]){
                root = nodes[i];
                break;
            }
        }
        bool left = false;
        bool result = isCompleteTree(root, n, left);
        if(result) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

bool isCompleteTree(Node* root, int n, bool leaf) {
    if(root == nullptr) return true;
    Node* que[n];
    int hh = 0, tt = -1;
    que[++tt] = root;
    while(hh <= tt){
        Node* cur = que[hh];
        if(leaf && (cur->left != nullptr || cur->right != nullptr)) return false;
        if(cur->left == nullptr && cur->right != nullptr) return false;
        if(cur->left == nullptr|| cur->right == nullptr) leaf = true;
        if(cur->left) que[++tt] = cur->left;
        if(cur->right) que[++tt] = cur->right;
        hh++;
    }
    return true;
}
