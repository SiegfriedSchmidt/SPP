//  
// 15.04.2024

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mp make_pair

map<pair<int, int>, int> mpos;
pair<int, pair<int, int>> dirs[] = {
        {4, {-1, 0}},
        {1, {-1, -1}},
        {2, {0,  -1}},
        {3, {1,  -1}},
        {4, {1,  0}},
        {1, {1,  1}},
        {2, {0,  1}},
        {3, {-1, 1}}
};

bool check_win(int x1, int y1, int player) {
    int dirs_cnt[5] = {0, 0, 0, 0};
    for (auto [diag, d]: dirs) {
        int x = x1, y = y1;
        for (int i = 0; i < 4; ++i) {
            x += d.first;
            y += d.second;
            if (mpos[{x, y}] == player) {
                ++dirs_cnt[diag - 1];
            } else {
                break;
            }
        }
    }
    for (auto cnt: dirs_cnt) {
        if (cnt >= 4) {
            return true;
        }
    }
    return false;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int win_idx = -1;
    int winner = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        // X - 1, O - 2
        mpos[{x, y}] = i % 2 + 1;
        if (winner == 0 && check_win(x, y, i % 2 + 1)) {
            win_idx = i;
            winner = i % 2 + 1;
        }
    }

    if (winner == 0) {
        cout << "Draw";
    } else if (win_idx < n - 1) {
        cout << "Inattention";
    } else {
        cout << (winner == 1 ? "First" : "Second");
    }

    return 0;
}
