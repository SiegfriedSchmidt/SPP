// 
// 07.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<string, vector<double>> comps;
        for (int i = 0; i < m; ++i) {
            string name;
            cin >> name;
            for (int j = 0; j < n; ++j) {
                int cost;
                cin >> cost;
                comps[name].emplace_back(cost);
            }
        }

        double ans = 0;
        double profit = 0;
        map<string, pair<double, double>> comp_count;
        for (int i = 0; i < k; ++i) {
            int day;
            string type;
            cin >> day >> type;
            --day;

            if (type == "buy") {
                double count;
                string name;

                cin >> count >> name;
                comp_count[name].first += count;
                comp_count[name].second += (count * comps[name][day]) * 1.01;
            } else {
                string name;
                cin >> name;
                profit += (comp_count[name].first * comps[name][day]) * 0.99 - comp_count[name].second;
                comp_count[name] = {0, 0};
                ans = min(ans, profit);
            }
        }
        cout << setprecision(8) << ans << '\n';
    }

    return 0;
}

/*
4
3 1 3
comp 300 400 500
1 buy 10 comp
2 buy 5 comp
3 sell comp
3 2 4
gazp 100 111 300
yndx 1000 1100 1111
1 buy 10 gazp
2 buy 1 yndx
3 sell yndx
3 sell gazp
3 1 3
comp 300 400 200
1 buy 10 comp
2 buy 5 comp
3 sell comp
2 2 3
bdn 100 100
nik 1 100
1 buy 300 bdn
1 buy 10 nik
2 sell nik

 */