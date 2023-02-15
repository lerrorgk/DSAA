#include <iostream>
#include <vector>
#pragma GCC optimize(2)
using namespace std;

inline int rd() {
    char ch = getchar();
    int x = 0, w = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();

    }
    return x * w;
}

inline void print(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;

    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

inline void print(string s)
{
    for(int i=0; s[i]!='\0'; i++) putchar(s[i]);
}

struct Node {
    int idx;
    int inDegree;
    vector<Node *> children;

    Node(int _idx, int _inDegree) {
        idx = _idx;
        inDegree = _inDegree;
    }
};

struct heapNode {
    int idx = -1;
    Node *node = nullptr;
    heapNode(int x, Node *n) {
        idx = x;
        node = n;
    }
    heapNode() {
    }
};

void up(heapNode *heap[], int x);
void down(heapNode *heap[], int x, int size);

int main() {
    int T = rd();
    while (T--) {
        int n = rd();
        int m = rd();
        Node *nodes[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i, 0);
        }
        for (int i = 0; i < m; i++) {
            int A = rd();
            int B = rd();
            A--, B--;
            nodes[A]->children.push_back(nodes[B]);
            nodes[B]->inDegree++;
        }
        heapNode* heap[n];
        int tt = 0;
        for (int i = 0; i < n; i++) {
            if (nodes[i]->inDegree == 0) {
                heap[++tt] = new heapNode(i, nodes[i]);
                up(heap, tt);
            }
        }

        int result[n];
        int cnt = -1;
        while (tt > 0) {
            Node *cur = heap[1]->node;
            swap(heap[1], heap[tt]);
            tt--;
            down(heap, 1, tt);
            result[++cnt] = cur->idx + 1;
            for (Node *child: cur->children) {
                child->inDegree--;
                if (child->inDegree == 0) {
                    heap[++tt] = new heapNode(child->idx, child);
                    up(heap, tt);
                }
            }
        }
        if (cnt + 1 != n) {
            print("impossible");
            printf("\n");
        } else {
            for (int i = 0; i < n; i++) {
                print(result[i]);
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

void up(heapNode *heap[], int x) {
    while (x > 1 && heap[x]->idx < heap[x / 2]->idx) {
        swap(heap[x], heap[x / 2]);
        x = x / 2;
    }
}

void down(heapNode *heap[], int x, int size) {
    while (2 * x <= size) {
        int min = 2 * x;
        if (2 * x + 1 <= size && heap[2 * x + 1]->idx < heap[min]->idx)
            min = 2 * x + 1;
        if (heap[x]->idx < heap[min]->idx) break;
        swap(heap[x], heap[min]);
        x = min;
    }
}
