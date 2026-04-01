#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >>N;
    vector<vector<long long>> C(N + 1, vector<long long>(N + 1));
    for (int i = 1; i <= N - 1; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            cin >> C[i][j];
        }
    }
    for (int a = 1; a <= N - 2; ++a) {
        for (int b = a + 1; b <= N - 1; ++b) {
            for (int c = b + 1; c <= N; ++c) {
                if (C[a][c] > C[a][b] + C[b][c]) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}