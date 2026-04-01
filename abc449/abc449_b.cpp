#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W,Q;
    cin >> H >> W >> Q;
    for (int i = 0; i < Q; i++){
        int A,B;
        cin >> A >> B;
        if (A == 1){
            cout << W*B << endl;
            H = H - B;
        }
        if (A == 2){
            cout << H*B << endl;
            W = W- B;
        }
    }
}