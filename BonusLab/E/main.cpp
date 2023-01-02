#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string p;
        cin >> p;
        int m = p.size();
        int ne[m];
        ne[0] = -1;
        for (int i = 1, j = -1; i < m; i++) {
            while (j >= 0 && p[i] != p[j + 1])
                j = ne[j];
            if (p[i] == p[j + 1])
                j++;
            ne[i] = j;
        }
        int cir = m - 1 - ne[m - 1];
        int result = (cir - (m % cir)) % cir;
        if(ne[m - 1] == -1) cout << m << endl;
        else cout << result << endl;
    }
    return 0;
}
