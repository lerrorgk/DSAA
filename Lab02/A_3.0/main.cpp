#include <iostream>

using namespace std;

void MergeSort(long *, long, long);

int main() {
    long N;
    cin >> N;
    long nums[N];
    long sum = 0;
    for (long i = 0; i < N; i++) {
        cin >> nums[i];
    }
    MergeSort(nums, 0, N - 1);
    for (long j = 0; j < N / 2; j++) {
        sum += nums[j] * nums[N - 1 - j];
    }
    cout << sum;
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
