#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < q; ++i) {
        int t;
        long long h;
        cin >> t >> h;
        if (t == 1) {
            pq.push(h);
        }
        else if (t == 2) {
            while (!pq.empty() && pq.top() <= h) {
                pq.pop();
            }
        }
        cout << pq.size() << endl;
    }
}
