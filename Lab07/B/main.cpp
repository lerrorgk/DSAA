#include <iostream>
#include <algorithm>

using namespace std;

void up(int *heap, int x);
void down(int *heap, int x, int size);
void addNode(int val, int *heap, int &size);
void deleteNode(int *heap, int &size);


int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int data[N + 1];
        int length = 0;
        for(int i = 1; i <= N; i++){
            cin >> data[i];
            length += data[i];
        }
        int heap[N + 1];
        int tt = 0;
        int sum = 0;
        int tmpSum = 0;
        for(int i = 1; i <= N; i++){
            addNode(data[i], heap, tt);
        }
        while(tt > 1){
            tmpSum += heap[1];
            deleteNode(heap, tt);
            tmpSum += heap[1];
            deleteNode(heap, tt);
            sum += tmpSum;
            addNode(tmpSum, heap, tt);
            tmpSum = 0;
        }
        cout << sum << endl;
    }
    return 0;
}

void addNode(int val, int *heap, int &size){
    heap[++size] = val;
    up(heap, size);
}

void deleteNode(int *heap, int &size){
    swap(heap[1], heap[size]);
    size--;
    down(heap, 1, size);
}

void up(int *heap, int x){
    while(x > 1 && heap[x] < heap[x / 2]){
        swap(heap[x], heap[x / 2]);
        x = x / 2;
    }
}

void down(int *heap, int x, int size){
    while(2 * x <= size){
        int min = 2 * x;
        if(2 * x + 1 <= size && heap[2 * x + 1] < heap[min])
            min = 2 * x + 1;
        if(heap[x] < heap[min]) break;
        swap(heap[x],heap[min]);
        x = min;
    }
}
