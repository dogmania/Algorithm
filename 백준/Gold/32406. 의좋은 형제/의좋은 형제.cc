#include <bits/stdc++.h>

using namespace std;

int n;

int calculateTopAndBottom(vector<int> b1, vector<int> b2) {
    int resultA = b1.back();
    int resultB = b2.back();

    for (int i = 0; i < n - 2; i++) {
        if (b1[i] >= b2[i]) {
            resultA += b1[i];
            resultB += b2[i];
        } else {
            resultA += b2[i];
            resultB += b1[i];
        }
    }

    resultA += b2[n - 2];
    resultB += b1[n - 2];

    return abs(resultA - resultB);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> b1(n, 0);
    vector<int> b2(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> b1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b2[i];
    }

    if (n == 2) {
        b2[1] += b1[0];
        b1[1] += b2[0];

        cout << max(b1[1] - b2[1], b2[1] - b1[1]) << '\n';

        return 0;
    }

    int result1 = calculateTopAndBottom(b1, b2);
    int result2 = calculateTopAndBottom(b2, b1);

    cout << max(result1, result2) << '\n';
}