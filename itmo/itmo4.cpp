//  
// 24.02.2024

#include <iostream>
#include <vector>
using namespace std;

#define int long long

int arr[15][15] = {
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
};

vector<pair<int, int>> order;

bool border(int x, int y) {
    return x < 0 || x >= 15 || y < 0 || y >= 15;
}

void fill(int x, int y) {
    if (border(x, y)) {
        return;
    }
    if (!arr[x][y]) {
        arr[x][y] = 1;
        order.emplace_back(x, y);
        fill(x + 1, y);
        fill(x, y - 1);
        fill(x - 1, y);
        fill(x, y + 1);
    }
}

signed main() {
    fill(7, 7);

    int c = 0;
    for (int i = 1; i < order.size(); ++i) {
        if (abs(order[i - 1].first - order[i].first) + abs(order[i - 1].second - order[i].second) > 1) {
            ++c;
        }
    }
    cout << c << "\n\n";

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}