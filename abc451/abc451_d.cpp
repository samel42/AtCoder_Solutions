#include <bits/stdc++.h>
using namespace std;
vector<long long> p2_val;
vector<long long> p2_mult;
vector<long long> ans;
void dfs(long long current_val) {
    if (current_val > 0) {
        ans.push_back(current_val);
    }
    for (size_t i = 0; i < p2_val.size(); ++i) {
        if (current_val == 0) {
            dfs(p2_val[i]);
        } else {
            if (1000000000 / p2_mult[i] < current_val) {
                break;
            }
            long long nxt = current_val * p2_mult[i] + p2_val[i];
            if (nxt <= 1000000000) {
                dfs(nxt);
            }
        }
    }
}
int main() {
    long long n;
    cin >> n; 
    long long v = 1;
    while (v <= 1000000000) {
        p2_val.push_back(v);
        long long mult = 1;
        long long temp = v;
        while (temp > 0) {
            mult *= 10;
            temp /= 10;
        }
        p2_mult.push_back(mult);
        v *= 2;
    }
    ans.reserve(3000000);
    dfs(0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if (n - 1 >= 0 && n - 1 < ans.size()) {
        cout << ans[n - 1] << endl;
    }
}