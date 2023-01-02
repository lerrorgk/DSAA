#include <iostream>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int data[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            data[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        data[idx1][idx2] = 1;
        data[idx2][idx1] = 1;
    }
    for(int i = 0; i < q; i++){
        int idx1, idx2;
        cin >> idx1 >> idx2;
        if(data[idx1][idx2] == 1){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}
