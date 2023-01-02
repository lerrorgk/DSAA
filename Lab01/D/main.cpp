#include <iostream>
using namespace std;

bool checkStep(long, const long[], long, long, long, long, long, long, long);
int main() {
    long xr, yr, xc, yc;
    cin >> xr >> yr >> xc >> yc;
    long N;
    cin >> N;
    long data[N];
    long sumLR = 0, sumUD = 0;
    string s;
    cin >> s;
    for(long i = 0; i < N; i++){
        char temp = s[i];
        if(temp == 'U'){
            data[i] = 1;
            sumUD += data[i];
        }
        else if(temp == 'D'){
            data[i] = -1;
            sumUD += data[i];
        }
        else if(temp == 'L'){
            data[i] = -2;
            sumLR += data[i];
        }
        else if(temp == 'R'){
            data[i] = 2;
            sumLR += data[i];
        }
    }

    long result = -1;
    long left = 0;
    long right = 1e18;

    while(left + 1 < right){
        long mid = left + (right - left) / 2;

        if(checkStep(mid, data, N, sumUD, sumLR, xr, yr, xc, yc)){
            right = mid;
        } else{
            left = mid;
        }
    }

    if(checkStep(right, data, N, sumUD, sumLR, xr, yr, xc, yc)){
        result = right;
    }

    cout << result;
    return 0;
}

bool checkStep(long step, const long data[],long N, long sumUD, long sumLR, long xr, long yr, long xc, long yc){
    if(step == 0)
        return false;
    long count = step % N;
    long newxr = xr + (sumLR / 2) * (step / N), newyr = yr + sumUD * (step / N);
    for(long i = 0; i < count; i++){
        if(abs(data[i]) == 1){
            newyr += data[i];
        } else{
            newxr += (data[i] / 2);
        }
    }
    long distance = abs(newxr - xc) + abs(newyr - yc);
    if(distance <= step){
        return true;
    }
    return false;
}
