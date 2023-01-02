#include <iostream>

using namespace std;

int binarySearch(int num);

const int N = 1000010;
int qData[N] = {0}, qIndex[N]= {0};
int hh = 0, tt = -1;

int main() {
    int n, sum = 0;
    cin >> n;
    int nums[n];
    int data[n + 1];
    data[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
        data[i + 1] = sum;
    }

    for(int i = 0; i <= n; i++){
        while(hh <= tt && data[i] >= qData[tt]){
            tt--;
        }
        qData[++tt] = data[i];
        qIndex[tt] = i;
    }

//    for(int i = hh; i <= tt; i++){
//        cout << qData[i] << " " << qIndex[i] << endl;
//    }
    int max = 0;
    for(int i = 0; i <= n; i++){
        int temp = binarySearch(data[i]);
        max = temp - i > max ? temp - i: max;
    }
    cout << max;
    return 0;
}

int binarySearch(int num){
    int left = hh;
    int right = tt;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(qData[middle] <= num)
            right = middle;
        else
            left = middle;
    }
    if(qData[left] > num){
        if(qData[right] > num)
            return qIndex[right];
        return qIndex[left];
    }
    return -1;
}
