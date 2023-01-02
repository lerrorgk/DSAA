#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        char stk[n + 1];
        int tt = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == ')' && tt > 0 && stk[tt] == '('){
                tt--;
                continue;
            }
            if(str[i] == ']' && tt > 0 && stk[tt] == '['){
                tt--;
                continue;
            }
            if(str[i] == '}' && tt > 0 && stk[tt] == '{') {
                tt--;
                continue;
            }
            stk[++tt] = str[i];
        }
        if(tt > 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
