#include <iostream>
#include <climits>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int data[n];
        int minVal[n];
        for(int i = 0; i < n; i++){
            cin >> data[i];
        }
        int min = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            if(data[i] < min) min = data[i];
            minVal[i] = min;
        }
        int result = INT_MIN;
        for(int i = 0; i < n - 1; i++){
            int temp = data[i] - minVal[i + 1];
            if(temp > result) result = temp;
        }
        cout << result << endl;
    }
    return 0;
}
