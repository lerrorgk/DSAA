#include <iostream>
using namespace std;

int main() {
    freopen("/home/lerrorgk/桌面/02.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    while(n--){
        int nums[m];
        int result = 0;
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
        }
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m - 1 - j; k++){
                if(nums[k] > nums[k + 1]){
                    int temp = nums[k];
                    nums[k] = nums[k + 1];
                    nums[k + 1] = temp;
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
