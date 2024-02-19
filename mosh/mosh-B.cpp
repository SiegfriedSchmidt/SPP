//
// 18.02.2024
#include <iostream>
#include <random>
#include <unordered_set>
#include <chrono>

using namespace std;

#define int long long
int n = 70000;
int k = 6;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
unordered_set<string> table;

string generate() {
    string s;
    for (int i = 0; i < k; ++i) {
        int r = rnd() % 16;
        if (r < 10) {
            s += char('0' + r);
        } else {
            s += char('a' + r % 10);
        }
    }

    return s;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    freopen("/Users/matvei/Developer/Projects/SPP/mosh/output.txt", "w", stdout);

    for (int i = 0; i < n; ++i) {
        bool un_correct = true;
        string s;
        while (un_correct) {
            s = generate();
            for (int j = 0; j < k; ++j) {
                string slice = s.substr(0, j) + s.substr(j + 1, k - j);
                un_correct = table.contains(slice);
                if (un_correct) {
                    break;
                }
            }
        }
        cout << s << '\n';
        for (int j = 0; j < k; ++j) {
            string slice = s.substr(0, j) + s.substr(j + 1, k - j);
            table.insert(slice);
        }
    }
}
