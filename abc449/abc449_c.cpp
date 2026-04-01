#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    string S;
    cin >> S;
    vector<int> counts(26,0);
	long long ans = 0;
	for (int j = 0; j < N; ++j) {
        if (j - L >= 0) {
            counts[S[j - L] - 'a']++;
        }
        if (j - R - 1 >= 0) {
            counts[S[j - R - 1] - 'a']--;
        }
        ans += counts[S[j] - 'a'];
    }
    cout << ans << endl;
}