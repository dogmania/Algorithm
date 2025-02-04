#include <bits/stdc++.h>

#define ULL unsigned long long

using namespace std;

ULL combination(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;

    ULL res = 1;

    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    ULL answer = 0;
    int count = 1;
    cin >> n >> m;
    vector<int> num(n, 0);
    vector<ULL> sum(n, 0);
    vector<int> rem(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sum[0] = num[0];
    rem[0] = sum[0] % m;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + num[i];
        rem[i] = sum[i] % m;
    }

    sort(rem.begin(), rem.end());

    for (int i = 0; i < n - 1; i++) {
        if (rem[i] != rem[i + 1]) {
            if (rem[i] == 0) {
                answer += combination(count + 1, 2);
            } else {
                answer += combination(count, 2);
            }

            count = 1;
        } else {
            count++;
        }
    }

    if (count != 0) {
        if (rem.back() == 0) answer += combination(n + 1, 2);
        else answer += combination(count, 2);
    }

    cout << answer << '\n';
}