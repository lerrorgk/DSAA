#include <iostream>

using namespace std;


int main() {
    string s;
    cin >> s;

    int result[s.size()][26];
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            result[i][j] = 0;
        }
    }
    result[0][s[0] - 'a'] = 1;

    int X = 0;
    for (int j = 1; j < s.size(); j++) {
        for (int c = 'a'; c <= 'z'; c++) {
            if (s[j] == c)
                result[j][c - 'a'] = j + 1;
            else
                result[j][c - 'a'] = result[X][c - 'a'];
        }
        X = result[X][s[j] - 'a'];
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
