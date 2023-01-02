#include <iostream>
using namespace std;

void swap(int &,int &);

int main() {
    int N;
    cin >> N;
    int nums[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for(int j = 0; j < N / 2; j++){
        int max = nums[j];
        int min = nums[j];
        int max_i = 0, min_i = 0;
        for(int k = N - 1 - j; k > j; k--){
            if(nums[k] > max){
                max = nums[k];
                max_i = k;
            }
            if(nums[k] < min){
                min = nums[k];
                min_i = k;
            }
        }
        sum += max * min;
        swap(nums[j], nums[min_i]);
        swap(nums[N - 1 - j], nums[max_i]);
    }
    cout << sum;
    return 0;
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

