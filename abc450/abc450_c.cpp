#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        string s; cin >> s;
        for (int j = 0; j < W; ++j) {
            G[i][j] = (s[j] == '#' ? 1 : 0);
        }
    }
    int d[] = {0, 1, 0, -1, 0};
    auto fill = [&](auto self, int r, int c) -> void {
        if (r < 0 || r >= H || c < 0 || c >= W || G[r][c] != 0) return;
        G[r][c] = -1;
        for (int i = 0; i < 4; ++i) self(self, r + d[i], c + d[i + 1]);
    };
    for (int i = 0; i < H; ++i) { fill(fill, i, 0); fill(fill, i, W - 1); }
    for (int j = 0; j < W; ++j) { fill(fill, 0, j); fill(fill, H - 1, j); }
    int answer = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (G[i][j] == 0) {
                answer++;
                fill(fill, i, j);
            }
        }
    }
    cout << answer << endl;
    return 0;
}