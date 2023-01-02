#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next, *pre;
    ListNode() : val(0), next(nullptr), pre(nullptr) {}
    ListNode(int x, int y) : val(x), next(nullptr), pre(nullptr) {}
};

void mergeSort(ListNode *nums[], int left, int right);



int main() {
    int n;
    scanf("%d", &n);
    ListNode *arrA[n];
    ListNode *arrB[n];
    for(int i = 0; i < n; i++){
        int temp = 0;
        scanf("%d", &temp);
        ListNode *newNode = new ListNode(temp, i);
        arrA[i] = newNode;
        arrB[i] = newNode;
    }

    mergeSort(arrB, 0, n - 1);

    ListNode *dHead = new ListNode();
    ListNode *cur = dHead;
    for(int i = 0; i < n; i++){
        cur->next = arrB[i];
        cur->next->pre = cur;
        cur = cur->next;
    }

    arrB[0]->pre = nullptr;
    arrB[n-1]->next = nullptr;
    for(int j = 0; j < n - 1; j++){
        int min = 0, max = 0, num = arrA[j]->val, result = 0;
        if(arrA[j]->pre != nullptr)
            min = arrA[j]->pre->val;
        if(arrA[j]->next != nullptr)
            max = arrA[j]->next->val;
        if(arrA[j]->pre == nullptr){
            arrA[j]->next->pre = nullptr;
        } else if(arrA[j]->next == nullptr){
            arrA[j]->pre->next = nullptr;
        } else{
            arrA[j]->pre->next = arrA[j]->next;
            arrA[j]->next->pre = arrA[j]->pre;
        }
        if(max == 0 && min > 0)
            result = num - min;
        else if(min == 0 && max > 0)
            result = max - num;
        else
            result = (max - num <= num - min) ? max - num : num - min;
        printf("%d ", result);
    }
}

void mergeSort(ListNode *nums[], int left, int right) {
    if (left >= right)
        return;
    int middle =  left + (right - left) / 2;

    mergeSort(nums, left, middle);
    mergeSort(nums, middle + 1, right);

    int n = right - left + 1, i = 0, l = left, r = middle + 1;
    ListNode *temp[n];
    while (l <= middle && r <= right){
        if(nums[l]->val <= nums[r]->val){
            temp[i] = nums[l];
            i++, l++;
        } else{
            temp[i] = nums[r];
            i++, r++;
        }
    }
    while (l <= middle)
        temp[i++] = nums[l++];
    while (r <= right)
        temp[i++] = nums[r++];
    for (int j = 0; j < n; ++j)
        nums[left + j] = temp[j];
}
