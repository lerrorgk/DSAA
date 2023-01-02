#include <iostream>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
unordered_set <ull> dataS1;
unordered_set <ull> dataS2;
bool isPalindrome(string s1, string s2, int length);
void getHash(string s, int length, ull* arr);
void checkHash(string s, int length, const ull* arr, bool isS1);

int main() {
    string strA, strB;
    cin >> strA >>strB;
    int result = -1;
    int minL = strA.size() < strB.size() ? strA.size() : strB.size();

    int left = 0, right = minL;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(isPalindrome(strA, strB, 2 * middle)){
            left = middle;
        } else{
            right = middle;
        }
    }
    if(isPalindrome(strA, strB, 2 * left) && !isPalindrome(strA, strB, 2 * right)) {
        result = 2 * left > result ?  2 * left : result;
    }


    left = 0, right = minL;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(isPalindrome(strA, strB, 2 * middle + 1)){
            left = middle;
        } else{
            right = middle;
        }
    }
    if(isPalindrome(strA, strB, 2 * left + 1) && !isPalindrome(strA, strB, 2 * right + 1)) {
        result = 2 * left + 1 > result ?  2 * left + 1: result;
    }
    cout << result;
    return 0;
}

bool isPalindrome(string s1, string s2, int length){
    if(length > s1.size() || length > s2.size() || length <= 0){
        return false;
    }

    ull s1Hash[s1.size()];
    for(int i = 0; i < s1.size(); i++){
        s1Hash[i] = 0;
    }
    getHash(s1, length, s1Hash);
    for(int i = 0, j = s1.size() - 1; i < s1.size() / 2; i++, j--){
        swap(s1[i], s1[j]);
    }
    checkHash(s1, length, s1Hash, true);

    ull s2Hash[s2.size()];
    for(int i = 0; i < s2.size(); i++){
        s2Hash[i] = 0;
    }
    getHash(s2, length, s2Hash);
    for(int i = 0, j = s2.size() - 1; i < s2.size() / 2; i++, j--){
        swap(s2[i], s2[j]);
    }
    checkHash(s2, length, s2Hash, false);

    for (auto & it : dataS1){
        if(dataS2.find(it) != dataS2.end()){
            dataS1.clear();
            dataS2.clear();
            return true;
        }
    }
    dataS1.clear();
    dataS2.clear();
    return false;
}

void getHash(string s, int length, ull* arr){
    int R = 131;
    ull RL = 1;
    for(int i = 1; i <= length - 1; i++){
        RL = RL * R;
    }
    ull windowHash = 0;
    int left = 0, right = 0;
    while(right < s.size()){
        windowHash = windowHash * R + s[right];
        right++;
        if(right - left == length){
            arr[left] = windowHash;
            windowHash = (windowHash - s[left] * RL);
            left++;
        }
    }
}

void checkHash(string s, int length, const ull* arr, bool isS1){
    int R = 131;
    ull RL = 1;
    for(int i = 1; i <= length - 1; i++){
        RL = RL * R;
    }
    ull windowHash = 0;
    int left = 0, right = 0;
    while(right < s.size()){
        windowHash = windowHash * R + s[right];
        right++;
        if(right - left == length){
            if(arr[s.size() - right] == windowHash){
                if(isS1){
                    dataS1.insert(windowHash);
                } else{
                    dataS2.insert(windowHash);
                }
            }
            windowHash = (windowHash - s[left] * RL);
            left++;
        }
    }
}
