#include <bits/stdc++.h>
using namespace std;

struct A {
    int value;
    int id;

    bool operator<(const A& other) const {
        return value < other.value;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<A> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i].value;
        A[i].id = i + 1;
    }
    sort(A.begin(), A.end());
    for (int j = 0; j < Q; j++){
        int K;
        cin >> K;
        vector<int> B(K);
        for (int k = 0; k < K; k++) {
            cin >> B[k];
        }
        for (int m = 0; m < N; m++) {
            bool is = false;
            for (int k = 0; k < K; k++) {
                if (A[m].id == B[k]) {
                    is = true;
                    break;
                }
            }
            if (!is) {
                cout << A[m].value << "\n";
                break;
            }
        }
    }
    return 0;
}