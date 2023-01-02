#include <iostream>

using namespace std;

const int N = 1000010;
int head, e[N], ne[N], pe[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

void insert(int a)
{
    e[idx] = a;
    ne[idx] = head;
    head = idx ++ ;
}

void sort(int left, int right) {

}

void initPe(){
    pe[head] = -1;
    int cur = head;
    while(ne[cur] != -1){
        pe[ne[cur]] = cur;
        cur = ne[cur];
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    init();
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        insert(temp);
    }
    sort();
    initPe();


    return 0;
}
