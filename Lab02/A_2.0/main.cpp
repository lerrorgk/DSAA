#include <iostream>
#include <cstdlib>

using namespace std;

void quickSort(long *nums, long, long);
long getPivot(long *nums, long, long);

int main() {
    long N;
    cin >> N;
    long nums[N];
    long sum = 0;
    for (long i = 0; i < N; i++) {
        cin >> nums[i];
    }
    quickSort(nums, 0, N - 1);
//    for (long it = 0; it < N; it++) {
//        cout << nums[it] << " ";
//    }
    for (long j = 0; j < N / 2; j++) {
        sum += nums[j] * nums[N - 1 - j];
    }
    cout << sum;
    return 0;
}

long getPivot(long a[], long left, long right) {
    long pivot;
    if (left < right) {
        long low = left, high = right, key = a[left];
        while (low < high) {
            while (a[high] >= key && low < high) {
                high--;
            }
            a[low] = a[high];
            while (a[low] <= a[high] && low < high) {
                low++;
            }
            a[high] = a[low];
        }
        pivot = low;
        a[pivot] = key;
    }
    return pivot;
}

void quickSort(long a[], long left, long right) {
    if (left < right) {
        srand(unsigned(time(NULL)));
        long randNum = rand() % (right - left + 1) + left;
        swap(a[left], a[randNum]);
        long pivot = getPivot(a, left, right);
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}
