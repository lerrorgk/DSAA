#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Node {
public:
    long val = 0;
    long weight = 0;
    Node* father;
    vector<Node *> children;
};

void DFS1(Node* root);
void DFS2(Node* root);
void changeWeight(Node* cur);

int main() {
    long n;
    cin >> n;
    Node* nodes[n];
    for(long i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    for(long i = 0; i < n - 1; i++){
        long idx1, idx2;
        cin >> idx1 >> idx2;
        idx1--;
        idx2--;
        nodes[idx1]->children.push_back(nodes[idx2]);
        nodes[idx2]->children.push_back(nodes[idx1]);
    }
    long max = LONG_MIN;
    long maxIdx = 0;
    for(long i = 0; i < n; i++){
        long temp;
        cin >> temp;
        nodes[i]->val = temp;
        if(temp > max){
            max = temp;
            maxIdx = i;
        }
    }

    nodes[maxIdx]->weight = nodes[maxIdx]->val;
    for(auto & child : nodes[maxIdx]->children){
        child->father = nodes[maxIdx];
        DFS1(child);
    }

    for(auto & child : nodes[maxIdx]->children){
        DFS2(child);
    }

    if(nodes[maxIdx]->children.size() == 1){
        nodes[maxIdx]->children.front()->weight = nodes[maxIdx]->weight;
        changeWeight(nodes[maxIdx]->children.front());
    } else{
        long maxW = LONG_MIN;
        Node* temp1 = nullptr;
        for(auto & child : nodes[maxIdx]->children){
            if(child == nodes[maxIdx]->father) continue;
            if(child->weight > maxW){
                maxW = child->weight;
                temp1 = child;
            }
        }
        maxW = LONG_MIN;
        Node* temp2 = nullptr;
        for(auto & child : nodes[maxIdx]->children){
            if(child == nodes[maxIdx]->father || child == temp1) continue;
            if(child->weight > maxW){
                maxW = child->weight;
                temp2 = child;
            }
        }
        temp1->weight = nodes[maxIdx]->weight;
        temp2->weight = nodes[maxIdx]->weight;
        changeWeight(temp1);
        changeWeight(temp2);
    }

    long result = 0;
    for(long i = 0; i < n; i++){
        if(nodes[i]->children.size() == 1){
            result += nodes[i]->weight;
        }
    }
    cout << result << endl;
    return 0;
}

void DFS1(Node* root){
    if(root == nullptr) return;
    for(auto & child : root->children){
        if(child == root->father) continue;
        child->father = root;
        DFS1(child);
    }

    if(root->children.size() == 1){
        root->weight = root->val;
    } else{
        long maxWeight = LONG_MIN;
        for(auto & child : root->children){
            if(child == root->father) continue;
            if(child->weight > maxWeight)
                maxWeight = child->weight;
        }
        if(root->val > maxWeight)
            maxWeight = root->val;
        root->weight = maxWeight;
    }
}

void DFS2(Node* root){
    if(root == nullptr) return;
    long max = LONG_MIN;
    Node* temp = nullptr;
    for(auto & child : root->children){
        if(child == root->father) continue;
        if(child->weight > max){
            max = child->weight;
            temp = child;
        }
    }
    if(temp){
        temp->weight = root->weight;
    }
    for(auto & child : root->children){
        if(child == root->father) continue;
        DFS2(child);
    }
}

void changeWeight(Node* cur){
    while(cur){
        long maxWeight = LONG_MIN;
        Node* temp = nullptr;
        for(auto & child : cur->children){
            if(child == cur->father) continue;
            if(child->weight > maxWeight) {
                maxWeight = child->weight;
                temp = child;
            }
        }
        if(temp){
            temp->weight = cur->weight;
        }
        cur = temp;
    }
}
