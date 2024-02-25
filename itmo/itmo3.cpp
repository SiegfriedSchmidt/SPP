//  
// 24.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

bool f1(int A, int B, int C, int D) {
    return ((!B <= !A) <= !B) || (!A <= !C) && !C || !(A <= !D);
}

signed main() {
    vector<int> a(10, 0);
    for (int A = 0; A < 2; ++A) {
        for (int B = 0; B < 2; ++B) {
            for (int C = 0; C < 2; ++C) {
                for (int D = 0; D < 2; ++D) {
                    if (!f1(A, B, C, D)) {
                        int v1 = (A && B) == (C && D);
                        int v2 = (A <= B) == (C <= D);
                        int v3 = A == (B && C && D);
                        int v4 = (A && C) == (B && D);
                        int v5 = (A <= C) == (B <= D);
                        int v6 = B == (A && C && D);
                        int v7 = (B && C) == (A && D);
                        int v8 = C == (A && B && D);
                        int v9 = D == (A && B && C);
                        int v10 = (D <= C) == (A <= B);
                        a[0] += v1;
                        a[1] += v2;
                        a[2] += v3;
                        a[3] += v4;
                        a[4] += v5;
                        a[5] += v6;
                        a[6] += v7;
                        a[7] += v8;
                        a[8] += v9;
                        a[9] += v10;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (a[i] == 0 || a[i] == 3) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}