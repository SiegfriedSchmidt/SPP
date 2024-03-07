//
// 07.03.2024


#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define int long long

struct Vertex {
    map<string, set<string>> commit;
};

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        cout << "Test case " << test_case + 1 << '\n';

        int n;
        cin >> n;

        vector<pair<string, string>> add;
        map<string, int> branch;
        vector<Vertex> graph(2);

        int head = 1;
        string cur_branch = "main";
        branch[cur_branch] = head;

        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;

            if (type == "add") {
                string file, hash;
                cin >> file >> hash;
                add.emplace_back(file, hash);

                cout << "OK " << head << '\n';
            } else if (type == "commit") {
                if (add.empty()) {
                    cout << "ERROR: no changes\n";
                    continue;
                }

                Vertex new_vertex = graph[head];
                for (auto [file, hash]: add) {
                    new_vertex.commit[file].insert(hash);
                }
                add.clear();

                graph.emplace_back(new_vertex);
                head = (int) graph.size() - 1;
                branch[cur_branch] = head;

                cout << "OK " << head << '\n';
            } else if (type == "reset") {
                int reset_head;
                cin >> reset_head;

                if (!add.empty()) {
                    cout << "ERROR: uncommitted changes\n";
                    continue;
                }

                head = reset_head;
                branch[cur_branch] = head;

                cout << "OK " << head << '\n';
            } else if (type == "checkout") {
                string checkout_branch;
                cin >> checkout_branch;

                if (!add.empty()) {
                    cout << "ERROR: uncommitted changes\n";
                    continue;
                }

                cur_branch = checkout_branch;
                if (branch.contains(checkout_branch)) {
                    head = branch[cur_branch];
                } else {
                    branch[cur_branch] = head;
                }

                cout << "OK " << head << '\n';
            } else if (type == "merge") {
                string merge_branch;
                cin >> merge_branch;

                if (!add.empty()) {
                    cout << "ERROR: uncommitted changes\n";
                    continue;
                }

                bool conflicts = false;
                for (auto [file, set_hash]: graph[head].commit) {
                    if (graph[branch[merge_branch]].commit.contains(file)) {
                        bool diff_cur_to_merge = false;
                        for (const auto &hash: set_hash) {
                            if (!graph[branch[merge_branch]].commit[file].contains(hash)) {
                                diff_cur_to_merge = true;
                                break;
                            }
                        }

                        bool diff_merge_to_cur = false;
                        for (const auto &hash: graph[branch[merge_branch]].commit[file]) {
                            if (!set_hash.contains(hash)) {
                                diff_merge_to_cur = true;
                                break;
                            }
                        }

                        if (diff_cur_to_merge && diff_merge_to_cur) {
                            conflicts = true;
                            break;
                        }
                    }
                }

                if (conflicts) {
                    cout << "ERROR: conflicts detected\n";
                    continue;
                }

                Vertex new_vertex = graph[head];
                for (auto [file, set_hash]: graph[branch[merge_branch]].commit) {
                    for (const auto &hash: set_hash) {
                        new_vertex.commit[file].insert(hash);
                    }
                }

                graph.emplace_back(new_vertex);
                head = (int) graph.size() - 1;
                branch[cur_branch] = head;

                cout << "OK " << head << '\n';
            }
        }
    }

    return 0;
}