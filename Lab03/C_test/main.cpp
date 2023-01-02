#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ofstream mycout("/home/lerrorgk/桌面/02.txt");

typedef struct element{
    int data;
    element *prev;
    element *next;
}*ele;

void Init(ele &elements){
    elements = new element;
    elements->next = NULL;
    elements->prev = NULL;
}


void sort(ele as[], int left, int right, ele *tp);
void mergeSort(ele as[], int left, int right, int mid, ele *tp);
int main(){
    int n;
    scanf("%d", &n);
    ele arrA[n];
    for (int i = 0; i < n; i++)
    {
        ele tpA = new element;
        int tpData;
        scanf("%d", &tpData);
        tpA->data = tpData;
        arrA[i] = tpA;
    }
    ele arrB[n];
    for (int i = 0; i < n; i++)
    {
        arrB[i] = arrA[i];
    }
    ele arrTp[n];
    sort(arrB, 0, n-1, arrTp);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            arrTp[i]->next = arrTp[i+1];
            arrTp[i]->prev = NULL;
        }
        else if(i == n-1)
        {
            arrTp[i]->prev = arrTp[i-1];
            arrTp[i]->next = NULL;
        }
        else
        {
            arrTp[i]->next = arrTp[i+1];
            arrTp[i]->prev = arrTp[i-1];
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        if (arrA[i]->next != NULL && arrA[i]->prev != NULL)
        {
            int temp = (abs(arrA[i]->data - arrA[i]->next->data) < abs(arrA[i]->data - arrA[i]->prev->data)) ? abs(arrA[i]->data - arrA[i]->next->data) : abs(arrA[i]->data - arrA[i]->prev->data);
            printf("%d ", temp);
            mycout << temp << " ";
            arrA[i]->prev->next = arrA[i]->next;
            arrA[i]->next->prev = arrA[i]->prev;
        }
        else if (arrA[i]->next == NULL && arrA[i]->prev != NULL)
        {
            printf("%d ", abs(arrA[i]->data - arrA[i]->prev->data));
            mycout << abs(arrA[i]->data - arrA[i]->prev->data) << " ";
            arrA[i]->prev->next = NULL;
            arrA[i]->prev = NULL;
        }
        else
        {
            printf("%d ", abs(arrA[i]->data - arrA[i]->next->data));
            mycout << abs(arrA[i]->data - arrA[i]->next->data) << " ";
            arrA[i]->next->prev = NULL;
            arrA[i]->next = NULL;
        }
    }

}

void sort(ele as[], int left, int right, ele *tp){
    int mid = (left+right)/2;
    if (left < right)
    {
        sort(as, left, mid, tp);
        sort(as, mid+1, right, tp);
        mergeSort(as, left, right, mid, tp);
    }
}
void mergeSort(ele as[], int left, int right, int mid, ele *tp){
    int l = left;
    int r = mid + 1;
    int t = 0;
    while (l <= mid && r <= right)
    {
        if (as[l]->data > as[r]->data)
        {
            tp[t++] = as[r++];
        }else
        {
            tp[t++] = as[l++];
        }
    }
    while (l <= mid)
    {
        tp[t++] = as[l++];
    }
    while (r <= right)
    {
        tp[t++] = as[r++];
    }
    for (int i = left, j = 0; i <= right; i++, j++)
    {
        as[i] = tp[j];
    }

}
