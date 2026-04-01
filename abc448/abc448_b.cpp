#include <bits/stdc++.h>
using namespace std;

int main() {
    int N , M;
    cin >> N >> M;
    long long output = 0;
    vector<long long> P(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> P[i];
    }
    vector<long long> D(M + 1, 0);
    for (int i = 0; i < N; ++i) {
        int a;
        long long b;
        cin >> a >> b;
        if (a >= 1 && a <= M) {
            D[a] += b;
        }
    }
    for (int j = 1; j <= M; ++j) {
        output += min(P[j], D[j]);
    }
    cout << output << endl;
    return 0;
}