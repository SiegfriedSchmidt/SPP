//
// 05.03.2024

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<pair<string, string>> codes;
    ifstream in("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/tests/e2.txt");

    int t;
    in >> t;
    for (int i = 0; i < t * 2; ++i) {
        string s1, s2;
        in >> s1 >> s2;
        codes.emplace_back(s1, s2);
    }
    in.close();

    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/mosh-E-solution.txt", "r", stdin);

    int n = 10;

    for (int idx = 0; idx < t; ++idx) {
        map<string, char> table;
        for (int i = 0; i < n; ++i) {
            char c;
            string s;
            cin >> c >> s;
            table[s] = c;
        }

        string result;
        string buffer;
        for (char c : codes[idx].second) {
            buffer += c;
            int code_idx = -1;
            for (int i = 0; i < n; ++i) {
                if (table.contains(buffer)) {
                    code_idx = i;
                    break;
                }
            }
            if (code_idx != -1) {
                result += table[buffer];
                buffer.clear();
            }
        }

        if (result == codes[idx].first) {
            cout << "TRUE\n";
        } else {
            cout << "FALSE\n";
        }
    }

    return 0;
}
