#include <iostream>

using namespace std;

int main() {
    long n, k, q;
    scanf("%ld%ld%ld", &n, &k, &q);
    long nums[n], que[n], result[n - k + 1];
    long head = 0, tail = -1;
    for (long i = 0; i < n; i++) {
        scanf("%ld", &nums[i]);
    }
    long question[q];
    for(long i = 0; i < q; i++){
        scanf("%ld", &question[i]);
    }


    for (long i = 0; i < n; i++) {
        if(head <= tail && que[head] < i - k + 1)
            head++;
        while(head <= tail && nums[i] >= nums[que[tail]])
            tail--;
        que[++tail] = i;
        if(i >= k - 1)
            result[i - k + 1] = nums[que[head]];
    }

//    for(long j = 0; j < n - k + 1; j++){
//        printf("%d ", result[j]);
//    }
//    printf("\n");

    for(long i = 0; i < q; i++){
        printf("%ld\n", result[question[i] - 1]);
    }
    return 0;
}
