//  
// 14.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define mp make_pair

typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2 * 1e5 + 1;
const int MAXK = 1e5 + 1;
const int INF = 1e9 + 7;

map<int, ordered_set> map_horiz;
map<int, ordered_set> map_vert;

map<int, map<int, int>> ship_horiz;
map<int, map<int, int>> ship_vert;

set<int> shoot[MAXK];
pair<int, int> sizes[MAXK];

set<pair<int, int>> all_shoots;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            map_vert[y1].insert(max(x1, x2));
            ship_vert[y1][max(x1, x2)] = i;
            sizes[i] = {x1, x2};
        } else if (x1 == x2) {
            map_horiz[x1].insert(max(y1, y2));
            ship_horiz[x1][max(y1, y2)] = i;
            sizes[i] = {y1, y2};
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (all_shoots.contains(mp(x, y))) {
            cout << "REPEAT\n";
            continue;
        }

        all_shoots.insert({x, y});

        if (map_horiz.contains(x)) {
            int idx = map_horiz[x].order_of_key(y);
            if (idx != map_horiz[x].size()) {
                int el = *map_horiz[x].find_by_order(idx);
                int ship_idx = ship_horiz[x][el];
                auto [l, r] = sizes[ship_idx];
                if (y >= l && y <= r) {
                    if (!shoot[ship_idx].contains(y)) {
                        shoot[ship_idx].insert(y);
                        if (shoot[ship_idx].size() == r - l + 1) {
                            cout << "SINK\n";
                        } else {
                            cout << "HIT\n";
                        }
                        continue;
                    }
                }
            }
        }

        if (map_vert.contains(y)) {
            int idx = map_vert[y].order_of_key(x);
            if (idx == map_vert[y].size()) {
                cout << "MISS\n";
                continue;
            }
            int el = *map_vert[y].find_by_order(idx);
            int ship_idx = ship_vert[y][el];
            auto [l, r] = sizes[ship_idx];
            if (x >= l && x <= r) {
                if (!shoot[ship_idx].contains(x)) {
                    shoot[ship_idx].insert(x);
                    if (shoot[ship_idx].size() == r - l + 1) {
                        cout << "SINK\n";
                    } else {
                        cout << "HIT\n";
                    }
                    continue;
                }
            }
        }
        cout << "MISS\n";
    }



    return 0;
}

