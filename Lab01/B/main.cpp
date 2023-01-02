#include <iostream>
using namespace std;

int main() {
    int N, targe, size = 0;
    cin >> N >> targe;
    long long nums[N];
    long long count[N];
    for(int i = 0; i < N; i++){
        long long temp;
        cin >> temp;
        if(size == 0 || temp != nums[size - 1]){
            nums[size] = temp;
            count[size] = 1;
            size++;
        }
        else if(temp == nums[size - 1]){
            count[size - 1]++;
        }
    }
    long long result = 0;
    for(int k = 0; k < size; k++){
        int left;
        int right = size - 1;
        if(count[k] >= 2)
            left = k;
        else
            left = k + 1;
        while(right >= left){
            if (nums[k] + nums[left] + nums[right] > targe) right--;
            else if (nums[k] + nums[left] + nums[right] < targe) left++;
            else{
                if(k == left && right == left){
                    result += (count[k] * (count[k] - 1) * (count[k] - 2)) / 6;
                }
                else if(k == left && right != left){
                    result += (count[k] * (count[k] - 1)) / 2 * count[left];
                }
                else if(k != left && right == left){
                    result += (count[left] * (count[left] - 1)) / 2 * count[k];
                } else{
                    result +=  count[k] * count[left] * count[right];
                }
                right--;
                left++;
            }
        }
    }

    cout << result;
    return 0;
}
