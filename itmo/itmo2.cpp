//  
// 24.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    int tr[8][8] = {
            {5, 5, 5, 5, 5, 5, 5, 5},
            {5, 2, 3, 7, 4, 0, 1, 6},
            {5, 3, 4, 1, 5, 3, 4, 1},
            {5, 7, 1, 2, 4, 6, 3, 0},
            {5, 4, 5, 4, 5, 4, 5, 4},
            {5, 0, 3, 6, 4, 2, 1, 7},
            {5, 1, 4, 3, 5, 1, 4, 3},
            {5, 6, 1, 0, 4, 7, 3, 2},
    };
    int mas[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            mas[i][j] = 0;
        }
    }

    cout << "START\n";
    for (int startN = 0; startN < 50000000; ++startN) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                mas[i][j] = 0;
            }
        }

        int M = 8143989;

        int N = startN;

        while (M > 0) {
            int i = 0;
            while (i < 8) {
                int j = 0;
                while (j < 8) {
                    if ((i * j) % 8 == M % 8) {
                        mas[i][j] = N % 8;
                    }
                    ++j;
                }
                ++i;
            }
            N /= 8;
            M /= 8;
        }

        bool flag = true;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (tr[i][j] != mas[i][j]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            cout << "DONE: " << startN << '\n';
            break;
        }
    }


    return 0;
}
