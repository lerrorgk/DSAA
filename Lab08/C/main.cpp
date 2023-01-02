#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    vector<int> children;
};

int main() {
    int n, m;
    cin >> n >> m;
    Node* nodes[n];
    for(int i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    for(int i = 0; i < m; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        idx1--, idx2--;
        nodes[idx1]->children.push_back(idx2);
        nodes[idx2]->children.push_back(idx1);
    }
    string result = "Good";
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    int que[n];
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++){
        int countNode = 0;
        int countEdge = 0;
        if(visited[i]) continue;
        que[++tt] = i;
        visited[i] = true;
        while(hh <= tt){
            int cur = que[hh];
            hh++;
            countNode++;
            countEdge += nodes[cur]->children.size();
            for(int child : nodes[cur]->children){
                if(visited[child]) continue;
                que[++tt] = child;
                visited[child] = true;
            }
        }
        if(countNode - 1 != countEdge / 2){
            result = "Bad";
            break;
        }
    }
    cout << result;
    return 0;
}
