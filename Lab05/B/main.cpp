#include <iostream>
#include <string>
using namespace std;

string getPalindromeFrom (string s, int left, int right);
bool isInB(string s, string p);
int main() {
    int result = 0;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        string oddPalindrome = getPalindromeFrom(a, i, i);
        while(!oddPalindrome.empty()){
            if(isInB(b, oddPalindrome)){
                if(oddPalindrome.size() > result)
                    result = oddPalindrome.size();
                break;
            }
            oddPalindrome = oddPalindrome.substr(1, oddPalindrome.size() - 2);
        }

        string evenPalindrome = getPalindromeFrom(a, i, i + 1);
        while(!evenPalindrome.empty()){
            if(isInB(b, evenPalindrome)){
                if(evenPalindrome.size() > result)
                    result = evenPalindrome.size();
                break;
            }
            evenPalindrome = evenPalindrome.substr(1, evenPalindrome.size() - 2);
        }
    }
    cout << result;
    return 0;
}

string getPalindromeFrom (string s, int left, int right){
    while (left >= 0 && right < s.size()){
        if(s[left] != s[right])
            break;
        left--;
        right++;
    }
    if(left + 1 == right)
        return "";
    return s.substr(left + 1, right);
}

bool isInB(string s, string p) {
    int n = s.size(), m = p.size();
    int ne[m];
    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i++) {
        while (j >= 0 && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 0, j = -1; i <= n; i++) {
        while (j >= 0 && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m - 1) {
            return true;
        }
    }
    return false;
}
