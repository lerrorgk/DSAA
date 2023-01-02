#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    long st[1000000];
    int index = 0;
    for (char i : s) {
        if (i == '(') {
            st[++index] = 0;
        } else {
            long sum = st[index];
            index--;
            long max = 2 * sum > 1 ? 2 * sum : 1;
            st[index] = (st[index] + max) % 514329;
        }
    }
    cout << st[index] % 514329;
    return 0;
}
