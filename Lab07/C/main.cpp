#include <iostream>

using namespace std;

class Node {
public:
    long val;
    long index;
    long weight;
    long position;
    Node *next;
    Node *pre;

    Node() : val(-1), index(-1), weight(-1), position(-1), next(nullptr), pre(nullptr) {}

    Node(long x, long y, long w, long z) : val(x), index(y), weight(w), position(z), next(nullptr), pre(nullptr) {}
};

void up(Node *heap[], long x);

void down(Node *heap[], long x, long size);

void swap(Node *heap[], long x, long y);

int main() {
    long N;
    cin >> N;
    Node *nodes[N + 1];
    for (long i = 0; i <= N; i++) {
        nodes[i] = new Node();
    }
    for (long i = 1; i <= N; i++) {
        long val;
        cin >> val;
        long w = (val + 1) * 1000000 + i;
        Node *cur = new Node(val, i, w, i);
        nodes[i] = cur;
    }


    nodes[1]->next = nodes[2];
    for (long i = 2; i <= N - 1; i++) {
        nodes[i]->pre = nodes[i - 1];
        nodes[i]->next = nodes[i + 1];
    }
    nodes[N]->pre = nodes[N - 1];

    for (long i = 1; i <= N; i++) {
        up(nodes, i);
    }


    long tt = N;
    while (tt > 1) {
        Node *tmp1;
        Node *tmp2;
        tmp1 = nodes[1];
        long tmp3_val;
        if (tmp1->pre == nullptr) {
            tmp2 = tmp1->next;
            tmp3_val = (tmp1->next->val ^ tmp1->val) + 1;
        } else if (tmp1->next == nullptr) {
            tmp2 = tmp1->pre;
            tmp3_val = (tmp1->pre->val ^ tmp1->val) + 1;
        } else {
            long preXor = (tmp1->pre->val ^ tmp1->val) + 1;
            long nextXor = (tmp1->next->val ^ tmp1->val) + 1;
            if (preXor >= nextXor) {
                tmp2 = tmp1->pre;
                tmp3_val = preXor;
            } else {
                tmp2 = tmp1->next;
                tmp3_val = nextXor;
            }
        }


        long tmp3_w = (long) ((tmp3_val + 1) * 1000000) + tmp1->index;
        Node *tmp3 = new Node(tmp3_val, tmp1->index, tmp3_w, tt - 1);
        if (tmp2 == tmp1->pre) {
            tmp3->pre = tmp2->pre;
            tmp3->next = tmp1->next;
            if (tmp2->pre != nullptr) tmp2->pre->next = tmp3;
            if (tmp1->next != nullptr) tmp1->next->pre = tmp3;
        } else {
            tmp3->pre = tmp1->pre;
            tmp3->next = tmp2->next;
            if (tmp1->pre != nullptr) tmp1->pre->next = tmp3;
            if (tmp2->next != nullptr) tmp2->next->pre = tmp3;
        }


        swap(nodes[1]->position, nodes[tt]->position);
        swap(nodes, 1, tt);
        tt--;
        down(nodes, 1, tt);


        long tmp2_position = tmp2->position;
        swap(nodes[tmp2_position]->position, nodes[tt]->position);
        swap(nodes, tmp2_position, tt);
        tt--;
        if (tmp2_position > 1 && nodes[tmp2_position / 2]->weight > nodes[tmp2_position]->weight) {
            up(nodes, tmp2_position);
        } else {
            down(nodes, tmp2_position, tt);
        }

        tt++;
        nodes[tt] = tmp3;
        up(nodes, tt);
    }
    cout << nodes[1]->val << endl;
    return 0;
}


void up(Node *heap[], long x) {
    while (x > 1 && heap[x]->weight < heap[x / 2]->weight) {
        swap(heap[x]->position, heap[x / 2]->position);
        swap(heap[x], heap[x / 2]);
        x = x / 2;
    }
}

void down(Node *heap[], long x, long size) {
    while (2 * x <= size) {
        long min = 2 * x;
        if (2 * x + 1 <= size && heap[2 * x + 1]->weight < heap[min]->weight)
            min = 2 * x + 1;
        if (heap[x]->weight < heap[min]->weight) break;
        swap(heap[x]->position, heap[min]->position);
        swap(heap[x], heap[min]);
        x = min;
    }
}

void swap(Node *heap[], long x, long y) {
    Node *temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}
