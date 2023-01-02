#include <bits/stdc++.h>
#include <climits>
using namespace std;

int randSize;

//生成随机数组
template <class T>
T* creatArr(int size, int value){ // size为数组大小上界，value为数据内数字取值范围[-value, value]
    srand(rand()); // 生成随机种子
    randSize = rand()%(size+1)+1; //初始化随机数组大小
    T *arr = new T [randSize];
    for(int i = 0; i < randSize; i++){
        arr[i] = rand()%(value+1) - rand()%(value+1); //生成[-value, vlaue]范围内的随机数
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr;
}

//拷贝数组
template<class T>
T* copyArr(T arr[], int size){
    T* newArr = new T [size];
    for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    return newArr;
}

template<class T>
void output(T arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int n = 5;
    while(n--){
        int *arr = creatArr<int>(20, 20);
        output(arr, randSize);
    }
}
