#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int max_p = 0;
    while ((1 << (max_p + 1)) <= N) {
        max_p++;
    }

    vector<vector<int>> minTable(N, vector<int>(max_p + 1));

    for (int i = 0; i < N; ++i) {
        minTable[i][0] = a[i];
    }

    for (int p = 1; p <= max_p; ++p) {
        for (int i = 0; i + (1 << p) <= N; ++i) {
            minTable[i][p] = min(minTable[i][p - 1], minTable[i + (1 << (p - 1))][p - 1]);
        }
    }

    vector<int> ans(Q);
    for (int k = 0; k < Q; ++k) {
        int l, r;
        cin >> l >> r;
        int len = r - l;
        if (len == 0) {
            ans[k] = 0; 
            continue;
        }
        int p = 0;
        while ((1 << (p + 1)) <= len) {
            p++;
        }
        ans[k] = min(minTable[l][p], minTable[r - (1 << p)][p]);
    }

    for (int num : ans) {
        cout << num << '\n';
    }

    return 0;
}