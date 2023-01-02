#include <iostream>
using namespace std;

bool check(const double [], int, int, double);
int main() {
    double M_PI = 3.14159265358979323846;
    int n, m;
    cin >> n >> m;
    double data[m];
    double max = 0.0;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        data[i] = M_PI * temp * temp;
        max = data[i] > max ? data[i] : max;
    }

    double left = 0.0;
    double right = max;
    while(right - left > 0.0000001){
        double  middle = left + (right - left) / 2;
        if(check(data, m, n, middle)){
            left = middle;
        } else{
            right = middle;
        }
    }

    printf("%f", left + (right - left) / 2);
    return 0;
}

bool check(const double data[], int m, int n, double area){
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum += (int)(data[i] / area);
    }
    if(sum >= n){
        return true;
    }
    return false;
}
