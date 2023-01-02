#include <iostream>

using namespace std;

int main() {
    int n;
    string track1, track2, data;
    cin >> n >> track1 >> track2;
    for(char & i : track2){
        if(i == 'N')
            i = 'S';
        else if(i == 'S')
            i = 'N';
        else if(i == 'E')
            i = 'W';
        else if(i == 'W')
            i = 'E';
    }
    for(int i = 0, j = track2.size() - 1; i < track2.size() / 2; i++, j--){
        swap(track2[i], track2[j]);
    }
    data = track2 + track1;
    int ne[data.size()];
    ne[0] = -1;
    for(int i = 1, j = -1;i < data.size(); i++){
        while(j >= 0 && data[i] != data[j + 1])
            j = ne[j];
        if(data[i] == data[j + 1])
            j++;
        ne[i] = j;
    }
    if(ne[data.size() - 1] == -1){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}

