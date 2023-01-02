#include <iostream>

using namespace std;

bool delShunKe(int[]);
int main() {
    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
        int data[40] = {0};
        bool result = false;
        string tempData;
        cin >> tempData;
        for(int j = 0; j < 14; j++){
            string temp1 = tempData.substr(2 * j + 1,1);
            string temp2 = tempData.substr(2 * j,1);
            int temp3 = atoi(temp2.c_str());
            if(temp1 == "b"){
                data[temp3]++;
            }
            else if(temp1 == "s"){
                data[10 + temp3]++;
            }
            else if(temp1 == "w"){
                data[20 + temp3]++;
            }
            else{
                data[30 + temp3]++;
            }
        }
        
        for(int k = 1; k < 40; k++){
            if(data[k] >= 2){
                data[k] -= 2;
                if(!delShunKe(data)){
                    data[k] += 2;
                    continue;
                } else{
                    result = true;
                    break;
                }
            }
        }

        if(result){
            printf("Blessing of Heaven\n");
        } else{
            printf("Bad luck\n");
        }

    }
    return 0;
}

bool delShunKe(int data[]){
    int sum = 0;
    for(int k = 1; k < 40; k++){
        sum += data[k];
        if(k + 2 < 30){
            if(data[k] > 0 && data[k + 1] >0 && data[k + 2] > 0){
                data[k] -= 1;
                data[k + 1] -= 1;
                data[k + 2] -= 1;
                if(!delShunKe(data)){
                    data[k] += 1;
                    data[k + 1] += 1;
                    data[k + 2] += 1;
                    continue;
                } else{
                    return true;
                }
            }
        }
        if(data[k] > 2){
            data[k] -= 3;
            if(!delShunKe(data)){
                data[k] += 3;
                continue;
            } else{
                return true;
            }
        }
    }
    return sum == 0;
}
