#include <iostream>
#include <cmath>

using namespace std;

void mergeSort(long *, long, long);
void getIncome(long *, long, long);
long getChangedNum(long, long, long);
bool chooseMax(long *, long, long);
bool chooseMin(long *, long, long);

long count = 0;

int main() {
    long n, m, k;
    cin >> n >> m >> k;
    long data[n], income[9 * n];
    long sum = 0;
    for(long i = 0; i < n; i++){
        cin >> data[i];
        sum += data[i];
        getIncome(income, data[i], k);
    }
    mergeSort(income, 0 , count - 1);
    long size = count < m ? count : m;
    long result = sum;
    long countI = 0;
    for(long j = count - 1; j >= count - size ; j--){
        if(income[j] > k){
            result += income[j];
            countI++;
        }
        else
            break;
    }
    cout << result - k * countI;
    return 0;
}

void getIncome(long income[], long data, long k){
    long length;
    if(data > 0)
        length = (long)(log10(data)+1);
    else if(data < 0)
        length = (long)(log10(-1 *data)+1);
    else
        return;
    for(long i = 0; i < length; i++){
        long newNum = getChangedNum(data, i, length);
        long incomeNum = newNum - data;
        if(incomeNum > 0)
            income[count++] = incomeNum;
        else
            continue;
        data = newNum;
    }
}

long getChangedNum(long old, long left, long length){
    long oldNum[length];
    long result = 0;
    long oldCopy = old;
    if(old > 0){
        for(long i = 0; i < length; i++){
            oldNum[length - 1 - i] = old % 10;
            old /= 10;
        }
        if(!chooseMax(oldNum, left, length - 1))
            return oldCopy;
        else{
            for(long j = 0; j < length; j++){
                result += oldNum[j] * (long)pow(10, length - 1 - j);
            }
            return result;
        }
    } else{
        old = -1 * old;
        for(long i = 0; i < length; i++){
            oldNum[length - 1 - i] = old % 10;
            old /= 10;
        }
        if(!chooseMin(oldNum, left, length - 1))
            return oldCopy;
        else{
            for(long j = 0; j < length; j++){
                result += oldNum[j] * (long)pow(10, length - 1 - j);
            }
            result = -1 * result;
            return result;
        }
    }
}

bool chooseMax(long nums[], long left, long right){
    if(left == right)
        return false;
    long max = left;
    for(long i = left + 1; i <= right; i++){
        if(nums[i] > nums[max])
            max = i;
    }
    if(max == left)
        return false;
    else{
        long temp = nums[max];
        nums[max] = nums[left];
        nums[left] = temp;
        return true;
    }
}

bool chooseMin(long nums[], long left, long right){
    if(left == right)
        return false;
    long min = left;
    for(long i = left + 1; i <= right; i++){
        if(nums[i] < nums[min])
            min = i;
    }
    if(min == left)
        return false;
    else{
        long temp = nums[min];
        nums[min] = nums[left];
        nums[left] = temp;
        return true;
    }
}

void mergeSort(long nums[], long left, long right) {
    if (left >= right)
        return;
    long middle =  left + (right - left) / 2;

    mergeSort(nums, left, middle);
    mergeSort(nums, middle + 1, right);

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
