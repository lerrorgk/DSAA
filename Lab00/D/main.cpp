#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> switchNun (string);
vector<int> chooseQuetou(vector<int>);
vector<int> delData(vector<int>, int, int, int);
vector<int> chooseShunKe(vector<int>);
bool findResult(const vector<int>&);

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        bool result = false;
        string tempData;
        cin >> tempData;
        vector<int> data14 = switchNun(tempData);
        vector<int> quetou = chooseQuetou(data14);
        int qsize = quetou.size();
//        for(auto &&iter : data14){
//            cout << iter << " ";
//        }
//        cout << endl;
        for(int j = qsize / 2 - 1; j >= 0; j--){
            vector<int> data12 = delData(data14, quetou[2 * j], quetou[2 * j + 1], -1);
            if(findResult(data12)){
                result = true;
                printf("Blessing of Heaven\n");
                break;
            }
        }
        if(!result){
            printf("Bad luck\n");
        }
    }
    return 0;
}

bool findResult(const vector<int>& data){
    vector<int> shunkeNum = chooseShunKe(data);
    int ssize = shunkeNum.size();
    int dsize = data.size();
//    for(auto &&iter : data){
//        cout << iter << " ";
//    }
//    cout << endl;
    if(ssize < dsize){
        return false;
    }
    else if((dsize == 3) && (!ssize)){
        return true;
    }
    else if(ssize == dsize){
        sort(shunkeNum.begin(),shunkeNum.end());
        for(int k = 0; k < ssize; k++){
            if(data[k] != shunkeNum[k]){
                return false;
            }
        }
        return true;
    }
    else{
        for(int k = 0; k < (ssize / 3); k++){
            findResult(delData(data, shunkeNum[3 * k], shunkeNum[3 * k + 1], shunkeNum[3 * k + 2]));
        }
    }
}
vector<int> switchNun (string s){
    vector<int> result;
    for(int i = 0; i < 14; i++){
        string temp1 = s.substr(2 * i + 1,1);
        string temp2 = s.substr(2 * i,1);
        int temp3 = atoi(temp2.c_str());
        if(temp1 == "b"){
            result.push_back(10 + temp3);
        }
        else if(temp1 == "s"){
            result.push_back(20 + temp3);
        }
        else if(temp1 == "w"){
            result.push_back(30 + temp3);
        }
        else{
            result.push_back(40 + temp3);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

vector<int> chooseQuetou(vector<int> data0){
    vector<int> result;
    int ie = data0.size();
    for(int i = 0; i < ie; i++){
        if(data0[i] == data0[i + 1]){
            result.push_back(data0[i]);
            result.push_back(data0[i + 1]);
        }
        while(data0[i] == data0[i + 1]){
            i++;
        }
    }
    return result;
}

vector<int> delData(vector<int>nums, int num1, int num2, int num3){
    for(auto iter = nums.begin();iter != nums.end();iter++) {
        if (*iter == num1) {
            nums.erase(iter);
            break;
        }
    }
    for(auto iter = nums.begin();iter != nums.end();iter++) {
        if (*iter == num2) {
            nums.erase(iter);
            break;
        }
    }
    if(num3 != -1){
        for(auto iter = nums.begin();iter != nums.end();iter++) {
            if (*iter == num3) {
                nums.erase(iter);
                break;
            }
        }
    }
    return nums;
}

vector<int> chooseShunKe(vector<int> data1){
    vector<int> result;
    int ie = data1.size();
    for (int j = 0; j + 2 < ie; j++){
        if((data1[j] == data1[j + 1]) && (data1[j] == data1[j + 2])){
            result.push_back(data1[j]);
            result.push_back(data1[j + 1]);
            result.push_back(data1[j + 2]);
            j = j + 2;
        }
    }
    for (int i = 0; (i + 2 < ie) && (data1[i + 2] < 40); i++){
        for(int j = i + 1; j + 1 < ie; j++){
            if(data1[j] > data1[i] + 1) break;
            else if(data1[j] == data1[i] + 1){
                for(int k = j + 1; k < ie; k++){
                    if(data1[k] > data1[j] + 1) break;
                    else if(data1[k] == data1[j] + 1){
                        result.push_back(data1[i]);
                        result.push_back(data1[j]);
                        result.push_back(data1[k]);
                    }
                }
            }
        }
    }
//    for(int i = 1; (i + 1 < ie) && (data1[i + 1] < 40); i++){
//        int left = i - 1;
//        int right = i + 1;
//        while((left - 1 >= 0) && (data1[left] == data1[i])){
//            left--;
//        }
//        while((right + 1 < ie) && (data1[right] == data1[i])){
//            right++;
//        }
//        if((data1[left] == data1[i] - 1) && (data1[right] == data1[i] + 1)){
//            result.push_back(data1[left]);
//            result.push_back(data1[i]);
//            result.push_back(data1[right]);
//        }
//    }
    return result;
}
