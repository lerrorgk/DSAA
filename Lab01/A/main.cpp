#include <iostream>

using namespace std;

int findLeft(const int[], int, int);

int findRight(const int[], int, int);

int main() {
    int N, Q;
    cin >> N >> Q;
    int nums[N];
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int j = 0; j < Q; j++) {
        int left, right;
        int min, max;
        cin >> min >> max;

        if (min == max) {
            cout << "NO" << endl;
            continue;
        }

        if (nums[N - 1] <= min) {
            cout << "NO" << endl;
            continue;
        } else if (nums[0] > min) {
            left = 0;
        } else {
            left = findLeft(nums, N, min);
        }


        if (nums[0] >= max) {
            cout << "NO" << endl;
            continue;
        } else if (nums[N - 1] < max) {
            right = N - 1;
        } else {
            right = findRight(nums, N, max);
        }

        if (left == right) {
            if (nums[left] <= min && nums[right] >= max) {
                cout << "NO" << endl;
                continue;
            }
        }
        int result = right - left + 1;
        if (result > 0) {
            cout << "YES " << result << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


int findLeft(const int nums[], int size, int min) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] > min){
            if(nums[mid - 1] <= min)
                return mid;
            else
                right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return  -1;
}

int findRight(const int nums[], int size, int max) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] < max){
            if(nums[mid + 1] >= max)
                return mid;
            else
                left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return  -1;
}
