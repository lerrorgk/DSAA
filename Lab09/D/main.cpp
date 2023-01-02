#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int scc = -1;
    vector<int> children;
};
void reverseDFS(int cur, Node** nodes, vector<bool> &visited);
void sccDFS(int cur, Node** nodes, vector<bool> &visited, int sccCount);

vector<int> order;
int main() {
    int n, m, S;
    cin >> n >> m >> S;
    Node* graph[n];
    Node* reverseGraph[n];
    for(int i = 0; i < n; i++){
        graph[i] = new Node();
        reverseGraph[i] = new Node();
    }
    for(int i = 0; i < m; i++){
        int index1, index2;
        cin >> index1 >> index2;
        graph[index1 - 1]->children.push_back(index2 - 1);
        reverseGraph[index2 - 1]->children.push_back(index1 - 1);
    }


    vector<bool> visited1(n, false);
    for(int i = 0; i < n; i++){
        if(visited1[i]) continue;
        reverseDFS(i, reverseGraph, visited1);
    }
    reverse(order.begin(), order.end());


    vector<bool> visited2(n, false);
    int sccCount = 0;
    for(int i = 0; i < n; i++){
        if(visited2[order[i]]) continue;
        sccDFS(order[i], graph, visited2, sccCount);
        sccCount++;
    }


    vector<int> inDegree(sccCount, 0);
    for(int i = 0; i < n; i++){
        for(int child : graph[i]->children){
            if(graph[i]->scc != graph[child]->scc){
                inDegree[graph[child]->scc]++;
            }
        }
    }


    int count = 0;
    for(int i = 0; i < sccCount; i++){
        if(inDegree[i] == 0){
            count++;
        }
    }
    if(inDegree[graph[S - 1]->scc] == 0){
        cout << count - 1;
    } else{
        cout << count;
    }
    return 0;
}

void reverseDFS(int cur, Node** nodes, vector<bool> &visited){
    if(visited[cur]) return;
    visited[cur] = true;
    for(int child : nodes[cur]->children){
        reverseDFS(child, nodes, visited);
    }
    order.push_back(cur);
}

void sccDFS(int cur, Node** nodes, vector<bool> &visited, int sccCount){
    if(visited[cur]) return;
    visited[cur] = true;
    nodes[cur]->scc = sccCount;
    for(int child : nodes[cur]->children){
        sccDFS(child, nodes, visited, sccCount);
    }
}
