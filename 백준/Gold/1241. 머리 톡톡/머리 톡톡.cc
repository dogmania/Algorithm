#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int maxNum = 0;
    cin >> n;
    vector<int> num(n, 0);
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        maxNum = max(maxNum, num[i]);
    }

    vector<int> numCount(maxNum + 1, 0);

    for (int i = 0; i < n; i++) {
        numCount[num[i]]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= num[i]; j++) {
            if (num[i] % j == 0) {
                if (num[i] / j != j) answer[i] += numCount[j] + numCount[num[i] / j];
				else answer[i] += numCount[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] - 1 << '\n';
    }
}