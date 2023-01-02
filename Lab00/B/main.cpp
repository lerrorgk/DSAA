#include <iostream>
using namespace std;

int main()
{
    string player;
    string oplayer[5];
    string result = "Fold";
    cin >> player;
    string rank = player.substr(0,1);
    string suit = player.substr(1,1);
    for(int i = 0; i < 5; i++){
        cin >> oplayer[i];
        string temp1 = oplayer[i].substr(0,1);
        string temp2 = oplayer[i].substr(1,1);
        if((temp1 == rank) || (temp2 == suit)){
            result = "All in";
        }
    }
    cout << result;
    return 0;
}

