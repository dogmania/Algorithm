#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> num(n, 0);
    vector<int> fMax;
    map<int, int> mp;
    int sum = 0;
    double avg = 0.0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        num[i] = temp;
        mp[temp]++;
        sum += temp;
    }

    sort(num.begin(), num.end());

    int max = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (max < it->second) max = it->second;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == max) fMax.push_back(it->first);
    }

    sort(fMax.begin(), fMax.end());

    avg = static_cast<double>(sum) / n;

    cout << int(round(avg)) << '\n';
    cout << num[n / 2] << '\n';
    if (fMax.size() > 1) cout << fMax[1] << '\n';
    else cout << fMax.front() << '\n';
    cout << num.back() - num.front() << '\n';
}