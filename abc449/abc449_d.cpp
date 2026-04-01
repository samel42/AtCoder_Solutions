#include <bits/stdc++.h>
using namespace std;

int count_evens(int l, int r) {
    if (l > r) return 0;
    int pl = 2000000; 
    l += pl;
    r += pl;
    return (r / 2) - ((l - 1) / 2);
}

int main() {
    int L,R,D,U;
    cin >> L >> R >> D >> U;
    long long total_black = 0;
    for (int now = U; now >= D; now--){
        int Y = abs(now);
        int left_l = L;
        int left_r = min(R, -Y - 1);
        total_black += count_evens(left_l, left_r);
        int mid_l = max(L, -Y);
        int mid_r = min(R, Y);
        if (mid_l <= mid_r) {
            if (Y % 2 == 0) {
                total_black += (mid_r - mid_l + 1);
            }
        }
        int right_l = max(L, Y + 1);
        int right_r = R;
        total_black += count_evens(right_l, right_r);
    }
    cout << total_black << "\n";
    return 0;
}