#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
int main() {
    long long K, M;
    if (!(cin >> K >> M)) return 0; 
    long long P = 10007;
    long long MOD = M * P;
    long long MOD9 = MOD * 9; 
    long long N_mod = 0;
    for (int i = 0; i < K; i++) {
        long long c, l;
        cin >> c >> l;
        long long T = pow_mod(10, l, MOD9);
        long long R = (T - 1) / 9;
        long long shift = T % MOD;
        N_mod = (N_mod * shift + c * R) % MOD;
    }
    long long ans = (N_mod / M) % P;
    cout << ans << "\n";
    return 0;
}