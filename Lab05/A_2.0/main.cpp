#include <iostream>

using namespace std;

const int N = 110;

int main() {
    long T;
    cin >> T;
    while (T--) {
        string text;
        long n;
        cin >> text >> n;
        long tSize = text.size();
        string pattern[N];
        for (long i = 0; i < n; i++) {
            cin >> pattern[i];
        }

        long bestSubstr[n];
        for(long i = 0; i < tSize; i++){
            long maxL = 0, index = -1;
            for(long j = 0; j < n; j++){
                int pSize = pattern[j].size();
                if(pSize <= maxL)
                    continue;
                bool flag = false;
                for(int k = 0; k < pSize; k++){
                    if(i + k > tSize - 1){
                        break;
                    }
                    if(text[i + k] == pattern[j][k] && k == pSize - 1){
                        flag = true;
                    }
                }
                if(flag && pSize > maxL){
                    maxL = pSize;
                    index = j;
                }
            }
            bestSubstr[i] = index;
        }

        long count = 0;
        long result [N][2];
        long left = -1, right = - 1;
        while(right < tSize - 1){
            long substrIndex = -1, startIndex = -1;
            long maxEndIndex = right;
            for(long i = left + 1; i <= right + 1; i++){
                if(bestSubstr[i] == -1){
                    continue;
                }
                long index = i + pattern[bestSubstr[i]].size() - 1;
                if(index > maxEndIndex){
                    maxEndIndex = index;
                    substrIndex = bestSubstr[i];
                    startIndex = i;
                }
            }
            if(maxEndIndex == right){
                count = -1;
                break;
            }
            result[count][0] = substrIndex + 1;
            result[count][1] = startIndex + 1;
            count++;
            left = startIndex;
            right = maxEndIndex;
        }
        if(count == -1){
            cout << -1;
            continue;
        }
        cout << count << endl;
        for(long i = 0; i < count; i++){
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }
    return 0;
}
