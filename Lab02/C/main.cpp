#include <iostream>

using namespace std;

void MergeSort(long *, long, long);

int main() {
    long N;
    cin >> N;
    long nums[N];
    long result[N], resultK;
    for (long i = 0; i < N; i++) {
        scanf("%ld", &nums[i]);
    }
    MergeSort(nums, 0, N - 1);
    resultK = nums[N / 3];
    for(long j = 0; j < N / 3; j++){
        result[3 * j] = nums[j];
    }
    for(long k = N / 3; k + 1 < N; k += 2){
        long index = (k - N / 3) / 2 * 3 + 1;
        result[index] = nums[k];
        result[index + 1] = nums[k + 1];
    }
    result[N - 2] = nums[N - 2];
    result[N - 1] = nums[N - 1];
    printf("%ld\n", resultK);
    for (long i = 0; i < N; i++) {
        printf("%ld ", result[i]);
    }
    return 0;
}

void MergeSort(long nums[], long left, long right) {
    if (left >= right)
        return;
    long middle =  left + (right - left) / 2;

    MergeSort(nums, left, middle);
    MergeSort(nums, middle + 1, right);

    long n = right - left + 1, i = 0, l = left, r = middle + 1;
    long temp[n];
    while (l <= middle && r <= right)
        temp[i++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
    while (l <= middle)
        temp[i++] = nums[l++];
    while (r <= right)
        temp[i++] = nums[r++];
    for (long j = 0; j < n; ++j)
        nums[left + j] = temp[j];
}
