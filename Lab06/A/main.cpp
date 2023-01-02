#include <iostream>
#include <vector>
using namespace std;

struct Node {
public:
    int val = 0;
    bool flag = false;
    vector<Node*> children;
    vector<int> length;
};

int main() {
    int n, num;
    cin >> n >> num;
    Node* allNodes[n];
    for(int i = 0; i < n; i++){
        allNodes[i] = new Node();
    }

    for(int i = 0; i < n - 1; i++){
        int index1, index2, length;
        cin >> index1 >> index2 >> length;
        index1--, index2--;
        allNodes[index2]->children.push_back(allNodes[index1]);
        allNodes[index2]->length.push_back(length);
        allNodes[index1]->children.push_back(allNodes[index2]);
        allNodes[index1]->length.push_back(length);
    }

    int result = 0;
    Node* queue[1000010];
    int hh = 0, tt = -1;
    queue[++tt] = allNodes[0];
    while(hh <= tt){
        int size = tt - hh + 1;
        for(int i = 0; i < size; i++){
            Node* cur = queue[hh++];
            cur->flag = true;
            for (int j = 0; j < cur->children.size(); j++) {
                if(!cur->children[j]->flag){
                    cur->children[j]->val = cur->length[j] + cur->val;
                    if(cur->children[j]->val == num && cur->children[j]->children.size() == 1){
                        result++;
                    }
                    queue[++tt] = cur->children[j];
                }
            }
        }
    }
    cout << result;
    return 0;
}
