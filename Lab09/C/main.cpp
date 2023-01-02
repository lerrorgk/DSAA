#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int color = -1;
    vector<int> children;
};

int main() {
    int n, m, k, c;
    scanf("%d %d %d %d", &n, &m, &k, &c);
    int data[n][k];
    Node* nodes[n];
    for(int i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    vector<int> colors[k];
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        temp--;
        nodes[i]->color = temp;
        colors[temp].push_back(i);
    }
    for(int i = 0; i < m; i++){
        int index1, index2;
        scanf("%d %d", &index1, &index2);
        index1--, index2--;
        nodes[index1]->children.push_back(index2);
        nodes[index2]->children.push_back(index1);
    }

    for(int i = 0; i < k; i++){
        vector<bool> visited(n, false);
        queue<int> que;
        for(int & node : colors[i]){
            data[node][i] = 0;
            que.push(node);
            visited[node] = true;
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int & child : nodes[cur]->children){
                if(visited[child]) continue;
                data[child][i] = data[cur][i] + 1;
                que.push(child);
                visited[child] = true;
            }
        }
    }


    int result[n];
    for(int i = 0; i < n; i++){
        sort(data[i], data[i] + k);
        int sum = 0;
        for(int j = 0; j < c; j++){
            sum += data[i][j];
        }
        result[i] = sum;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", result[i]);
    }
    return 0;
}
