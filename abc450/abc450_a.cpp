#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >>N;
    for (int i = N;i >= 1;i--){
        cout << i;
        if (i != 1){
            cout << ",";
        }
    }
    return 0;
}