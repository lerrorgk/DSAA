#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    long val, i, j;
    Node() : val(0), i(0), j(0) {}
    Node(long x, long y, long z) : val(x), i(y), j(z) {}
};

void up(Node* heap[], long x);
void down(Node* heap[], long x, long size);

int main() {
    long N, M, K;
    cin >> N >> M >> K;
    long A[N + 1];
    long B[M + 1];
    for(long i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(long i = 1; i <= M; i++){
        cin >> B[i];
    }
    sort(A + 1, A + N + 1);
    Node* heap[M + 1];
    long tt = 0;
    for(long j = 1; j <= M; j++){
        long temp = A[1] * B[j];
        Node* node = new Node(temp, 1, j);
        heap[++tt] = node;
        up(heap, tt);
    }
    long result[K];
    for(long i = 0; i < K; i++){
        long iOfNode = heap[1]->i;
        long jOfNode = heap[1]->j;
        result[i] = heap[1]->val;

        heap[1] = heap[tt];
        tt--;
        down(heap, 1, tt);

        if(iOfNode + 1 > N) continue;
        long temp = A[iOfNode + 1] * B[jOfNode];
        Node* node = new Node(temp, iOfNode + 1, jOfNode);
        heap[++tt] = node;
        up(heap, tt);
    }
    for(long i = 0; i < K; i++){
        cout << result[i] << " ";
    }
    return 0;
}

void up(Node* heap[], long x){
    while(x > 1 && heap[x]->val < heap[x / 2]->val){
        swap(heap[x], heap[x / 2]);
        x = x / 2;
    }
}

void down(Node* heap[], long x, long size){
    while(2 * x <= size){
        long min = 2 * x;
        if(2 * x + 1 <= size && heap[2 * x + 1]->val < heap[min]->val)
            min = 2 * x + 1;
        if(heap[x]->val < heap[min]->val) break;
        swap(heap[x],heap[min]);
        x = min;
    }
}
