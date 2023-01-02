#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int queue[n], start = 0, end = -1;
    while (n--){
        char op;
        int x;
        cin >> op >> x;
        if(op == 'E'){
            queue[++end] = x;
        } else{
            start += x;
            printf("%d\n", queue[start]);
        }
    }
    return 0;
}
