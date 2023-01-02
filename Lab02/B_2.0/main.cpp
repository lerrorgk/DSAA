#include <iostream>
#include <climits>
using namespace std;

void mergeCount(long *, long, long);

long count = 0;

int main() {
    long n;
    cin >> n;
    while(n--){
        long m;
        cin >> m;
        long nums[m];
        for (long i = 0; i < m; i++) {
            cin >> nums[i];
        }
        count = 0;
        mergeCount(nums, 0, m - 1);
        cout << count << endl;
    }
    return 0;
}

void mergeCount(long nums[], long left, long right) {
    if (left >= right)
        return;
    long middle =  left + (right - left) / 2;

    mergeCount(nums, left, middle);
    mergeCount(nums, middle + 1, right);

    long n = right - left + 1, i = 0, l = left, r = middle + 1;
    long temp[n];
    while (l <= middle && r <= right){
        if(nums[l] <= nums[r])
            temp[i++] = nums[l++];
        else{
            count += middle - l + 1;
            temp[i++] = nums[r++];
        }
    }
    while (l <= middle)
        temp[i++] = nums[l++];
    while (r <= right)
        temp[i++] = nums[r++];
    for (long j = 0; j < n; ++j)
        nums[left + j] = temp[j];
}
