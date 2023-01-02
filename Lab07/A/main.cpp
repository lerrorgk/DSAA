#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int A[N];
    int B[M];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &B[i]);
    }

    int result[N * M];
    int k = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            result[k++] = A[i] * B[j];
        }
    }
    sort(result, result + N * M);
    for(int i = 0; i < K; i++){
        cout << result[i] << " ";
    }
    return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void up(int *heap, int x);
//void down(int *heap, int x, int size);
//int main() {
//    int N, M, K;
//    scanf("%d %d %d", &N, &M, &K);
//    int A[N];
//    int B[M];
//    for(int i = 0; i < N; i++){
//        scanf("%d", &A[i]);
//    }
//    for(int i = 0; i < M; i++){
//        scanf("%d", &B[i]);
//    }
//
//    sort(A, A + N);
//    sort(B, B + M);
//    int length = 0;
//    for(; length * length < K; length++);
//    int count = 0;
//    int heap[K + 1];
//    int tt = 0;
//    for(int i = 0; i < N; i++){
//        for(int j = 0; j < M; j++){
//            int x = A[i] * B[j];
//            if(x > A[min(length, N)] * B[min(length, M)])
//                continue;
//            count++;
//            if(count <= K){
//                tt++;
//                heap[tt] = x;
//                up(heap, tt);
//            } else{
//                if(A[i] * B[j] < heap[1]){
//                    heap[1] = x;
//                    down(heap, 1, tt);
//                }
//            }
//        }
//    }
//    for(int i = K; i > 1; i--){
//        swap(heap[1], heap[i]);
//        down(heap, 1, i - 1);
//    }
//    for(int i = 1; i <= K; i++){
//        printf("%d ", heap[i]);
//    }
//    return 0;
//}
//
//void up(int *heap, int x){
//    while(x > 1 && heap[x] > heap[x / 2]){
//        swap(heap[x], heap[x / 2]);
//        x = x / 2;
//    }
//}
//
//void down(int *heap, int x, int size){
//    while(2 * x <= size){
//        int max = 2 * x;
//        if(2 * x + 1 <= size && heap[2 * x + 1] > max)
//            max = 2 * x + 1;
//        if(heap[x] > heap[max]) break;
//        swap(heap[x],heap[max]);
//        x = max;
//    }
//}
