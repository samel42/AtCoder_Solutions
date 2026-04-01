#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> dp;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        dp[A] = dp[A - 1] + 1;
        ans = max(ans, dp[A]);
    }
    cout << ans << endl;
    return 0;
}