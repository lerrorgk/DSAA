#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <climits>

int main() {
        int N;
        scanf("%d", &N);
        int a[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }
        int index = -1;
        for (int xx = 0; xx < N - 1; xx++) {
            index = -1;
            int min = INT_MAX;
            for (int i = 0; i < N; i++) {
                if (a[i] != -1 && a[i] < min) {
                    min = a[i];
                    index = i;
                }
            }
            int left = index - 1;
            while (left != -1) {
                if (a[left] == -1) {
                    left--;
                } else break;
            }
            int right = index + 1;
            while (right != N) {
                if (a[right] == -1) {
                    right++;
                } else break;
            }
            if (left != -1 && (right == N || (a[index] ^ a[left]) >= (a[index] ^ a[right]))) {
                a[index] = (a[index] ^
                            a[left]) + 1;
                a[left] = -1;
            } else {
                a[index] = (a[index] ^ a[right]) + 1;
                a[right] = -1;
            }
        }
        printf("%d", a[index]);
    return 0;
}
