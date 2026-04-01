#include <bits/stdc++.h>
using namespace std;

int main() {
    int N , X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        if (A_i < X) {
                X = A_i;
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
    }
    return 0;
}