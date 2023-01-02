#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int height = 0;
    bool isGiant = false;
    bool flag = false;
    vector<Node *> children;
};

int main() {
    int n;
    cin >> n;
    Node *allNodes[n];
    for (int i = 0; i < n; i++) {
        allNodes[i] = new Node();
    }

    for (int i = 0; i < n - 1; i++) {
        int index1, index2;
        cin >> index1 >> index2;
        index1--;
        index2--;
        allNodes[index1]->children.push_back(allNodes[index2]);
        allNodes[index2]->children.push_back(allNodes[index1]);
    }


    int giantsNum;
    cin >> giantsNum;
    while (giantsNum--) {
        int index;
        cin >> index;
        allNodes[index - 1]->isGiant = true;
    }


    allNodes[0]->flag = true;
    int result = -1;
    for (auto &k: allNodes[0]->children) {
        vector<int> data;
        Node *queue[1000010];
        int hh = 0, tt = -1;
        k->height = 1;
        queue[++tt] = k;
        data.push_back(k->height);
        while (hh <= tt) {
            Node *cur = queue[hh++];
            for (int i = 0; i < cur->children.size(); i++) {
                if (!cur->children[i]->flag) {
                    cur->children[i]->height = cur->height + 1;
                }
            }
            cur->flag = true;
            for (auto &j: cur->children) {
                if (!j->flag) {
                    if (j->isGiant) {
                        data.push_back(j->height);
                    }
                    queue[++tt] = j;
                }
            }
        }
        for (int i = 1; i < data.size(); i++) {
            if (data[i] <= data[i - 1]) {
                data[i] = data[i - 1] + 1;
            }
        }
        if (data[data.size() - 1] > result) {
            result = data[data.size() - 1];
        }
    }
    cout << result;
    return 0;
}
