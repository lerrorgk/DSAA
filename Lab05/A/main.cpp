#include <iostream>

using namespace std;

const int N = 110;
const int M = 11;
int data[N][M];

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            data[i][j] = 0;
        }
    }
}

void strStr(string s, string p, int index) {
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
            j = ne[j];
            data[i - m + 1][index] = 1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        string text;
        int n;
        cin >> text >> n;
        string pattern[n];
        for (int i = 0; i < n; i++) {
            cin >> pattern[i];
            strStr(text, pattern[i], i);
        }

//        for(int i = 0; i < text.size(); i++){
//            for(int j = 0; j < n; j++){
//                cout << data[i][j] << " ";
//            }
//            cout << endl;
//        }


        int processedData[text.size()][2];
        for(int i = 0; i < text.size(); i++){
            int index = -1, maxLength = -1;
            for(int j = 0; j < n; j++){
                int temp1 = data[i][j];
                int temp2 = pattern[j].size();
                if(temp1 == 1 && temp2 > maxLength){
                    maxLength = temp2;
                    index = j;
                }
                processedData[i][0] = index;
                processedData[i][1] = maxLength;
            }
        }
//        for(int i = 0; i < text.size(); i++){
//            cout << processedData[i][0] << " " << processedData[i][1] << endl;
//        }

        if(processedData[0][0] == -1){
            cout << -1;
            continue;
        }


        int count = 0;
        int result[text.size()][2];
        int left = 0, right = processedData[0][1] - 1;
        result[0][0] = processedData[0][0] + 1;
        result[0][1] = 1;
        count++;
        while(right <= text.size() - 2){
            int substrIndex = -1, startIndex = -1;
            int maxIndex = -1;
            int rightIndex = right < text.size() - 2 ? right : text.size() - 2;
            for(int i = left + 1; i <= rightIndex + 1; i++){
                int index = i + processedData[i][1] - 1;
                if(index > maxIndex){
                    maxIndex = index;
                    substrIndex = processedData[i][0] + 1;
                    startIndex = i + 1;
                }
            }
            if(substrIndex == -1){
                count = -1;
                break;
            }
            result[count][0] = substrIndex;
            result[count][1] = startIndex;
            count++;
            left = startIndex;
            right = maxIndex;
        }
        if(count == -1){
            cout << -1;
            continue;
        }
        cout << count << endl;
        for(int i = 0; i < count; i++){
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }

    return 0;
}
