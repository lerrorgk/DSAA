#include <iostream>
#include <algorithm>
using namespace std;
bool compare(long x, long y){
    return x > y;
}
int main() {
    long n;
    cin >> n;
    long degrees[n + 1];
    long sumAi[n + 1];
    sumAi[0] = 0;
    bool b1 = true;
    bool b2 = true;
    bool b3 = true;
    bool b4 = true;
    for(long i = 1; i <= n; i++){
        cin >> degrees[i];
        if(degrees[i] <= 0) b4 = false;
    }

    sort(degrees + 1, degrees + n + 1, compare);
    for(long i = 1; i <= n; i++){
        sumAi[i] = sumAi[i - 1] + degrees[i];
    }

    if(sumAi[n] % 2 != 0) b1 = false;
    if(sumAi[n] != 2 * n - 2) b3 = false;

    long k = n;
    for(long i = 1; i <= n; i++){
        long sumNeed = sumAi[i];
        long sumSupply = 0;
        while(k > 0 && degrees[k] < i) k--;
        sumSupply += i * (i - 1);
        if(k > i){
            sumSupply += (k - i) * i;
            sumSupply += sumAi[n] - sumAi[k];
        } else{
            sumSupply += sumAi[n] - sumAi[i];
        }
        if(sumSupply < sumNeed) b2 = false;
//        cout << sumSupply << " " << sumNeed << endl;
    }
//    cout << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
    if(b1) cout << "YES" << endl;
    else cout << "NO" << endl;
    if(b1 && b2) cout << "YES" << endl;
    else cout << "NO" << endl;
    if(b1 && b2 && b3 && b4) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
