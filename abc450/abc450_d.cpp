#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> A(N ,0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] = A[i] % K;
    }
    sort(A.begin(), A.end()); 
    int output = A[N-1] - A[0];
    for (int i = 0; i < N - 1; ++i) {
        long long diff = (A[i] + K) - A[i+1];
        if (diff < output) {
            output = diff;
        }
    }
    cout << output << endl;
    return 0;
}