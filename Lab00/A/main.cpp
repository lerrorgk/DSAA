#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string result[n];
    for(int i = 0; i < n; i++){
        int box_l, box_w, box_h;
        cin >> box_l >> box_w >> box_h;
        int lines = (box_w + box_h) * 2 + 1;
        if(box_w <= box_h){
            for(int j = 1; j <= lines; j++){
                if(j % 2 == 1){
                    if(j < 2 * box_w){
                        for(int k = 0; k < 2 * box_w - j + 1; k++){
                            result[i].append(".");
                        }
                    }
                    for(int t = 0; t < box_l; t++){
                        result[i].append("+-");
                    }
                    if(j < 2 * box_w){
                        for(int k = 0; k < (j - 1) / 2; k++){
                            result[i].append("+.");
                        }
                    }
                    else if((j > 2 * box_w) && (j <= lines - 2 * box_w)){
                        for(int k = 0; k < box_w; k++){
                            result[i].append("+.");
                        }
                    }
                    else{
                        for(int k = 0; k < (lines - j) / 2; k++){
                            result[i].append("+.");
                        }
                    }
                    result[i].append("+");
                    if(j > lines - 2 * box_w){
                        for(int k = 0; k < 2 * box_w - (lines - j); k++){
                            result[i].append(".");
                        }
                    }
                    result[i].append("\n");
                }
                else{
                    if(j <= 2 * box_w){
                        for(int k = 0; k < 2 * box_w - j + 1; k++){
                            result[i].append(".");
                        }
                        for(int t = 0; t < box_l; t++){
                            result[i].append("/.");
                        }
                        for(int m = 0; m < j / 2; m++){
                            result[i].append("/|");
                        }
                    }
                    else{
                        for(int k = 0; k < box_l; k++){
                            result[i].append("|.");
                        }
                        if((j > 2 * box_w) && (j < lines - 2 * box_w)){
                            for(int t = 0; t < box_w; t++){
                                result[i].append("|/");
                            }
                            result[i].append("|");
                        }
                        else{
                            for(int t = 0; t < (lines - j + 1) / 2; t++){
                                result[i].append("|/");
                            }
                            for(int m = 0; m < 2 * box_w - (lines - j); m++){
                                result[i].append(".");
                            }
                        }
                    }
                    result[i].append("\n");
                }
            }
        }
        else{
            for(int j = 1; j <= lines; j++){
                if(j % 2 == 1){
                    if(j <= 2 * box_w){
                        for(int k = 0; k < 2 * box_w - j + 1; k++){
                            result[i].append(".");
                        }
                    }
                    for(int t = 0; t < box_l; t++){
                        result[i].append("+-");
                    }
                    if(j <= lines - 2 * box_w){
                        for(int k = 0; k < (j - 1) / 2; k++){
                            result[i].append("+.");
                        }
                    }
                    else if((j > lines - 2 * box_w) && (j <= 2 * box_w)){
                        for(int k = 0; k < (lines - 2 * box_w - 1) / 2; k++){
                            result[i].append("+.");
                        }
                    }
                    else{
                        for(int k = 0; k < (lines - j) / 2; k++){
                            result[i].append("+.");
                        }
                    }
                    result[i].append("+");
                    if(j > lines - 2 * box_w){
                        for(int k = 0; k < 2 * box_w - (lines - j); k++){
                            result[i].append(".");
                        }
                    }
                    result[i].append("\n");
                }
                else{
                    if(j <= 2 * box_w){
                        for(int k = 0; k < 2 * box_w - j + 1; k++){
                            result[i].append(".");
                        }
                        for(int t = 0; t < box_l; t++){
                            result[i].append("/.");
                        }
                        if(j <= lines - 2 * box_w){
                            for(int m = 0; m < j / 2; m++){
                                result[i].append("/|");
                            }
                        }
                        else{
                            for(int m = 0; m < box_h; m++){
                                result[i].append("/|");
                            }
                            result[i].append("/");
                            for(int mm = 0; mm < j - 2 * box_h - 1; mm++){
                                result[i].append(".");
                            }
                        }
                    }
                    else{
                        for(int k = 0; k < box_l; k++){
                            result[i].append("|.");
                        }
                        if((j > 2 * box_w) && (j < lines - 2 * box_w)){
                            for(int t = 0; t < box_w; t++){
                                result[i].append("|/");
                            }
                            result[i].append("|");
                        }
                        else{
                            for(int t = 0; t < (lines - j + 1) / 2; t++){
                                result[i].append("|/");
                            }
                            for(int m = 0; m < 2 * box_w - (lines - j); m++){
                                result[i].append(".");
                            }
                        }
                    }
                    result[i].append("\n");
                }
            }
        }
    }
    for(int j = 0; j < n; j++){
        cout << result[j];
    }
    return 0;
}
