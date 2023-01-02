#include <iostream>
#include <algorithm>
using namespace std;

bool check(int* data, int size, int max, int m);
int main() {
    int L, n, m;
    while(cin >> L >> n >> m){
        int data[n + 1];
        int A[n + 2];
        A[0] = 0;
        A[n + 1] = L;
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        sort(A, A + n + 2);
        int left = -1, right = 1e9;
        for(int i = 1; i <= n + 1; i++){
            data[i - 1] = A[i] - A[i - 1];
            if(data[i - 1] > left) left = data[i - 1];
        }
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(check(data, n + 1, mid, m)) right = mid;
            else left = mid;
        }
        if(check(data, n + 1, left, m)) cout << left << endl;
        else cout << right << endl;
    }
    return 0;
}

bool check(int* data, int size, int max, int m){
    int count = 1;
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(data[i] > max) return false;
        if(sum + data[i] <= max){
            sum += data[i];
        } else{
            count++;
            sum = data[i];
        }
    }
    if(count > m) return false;
    else return true;
}
