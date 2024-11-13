#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int flag = 0;
    int answer = 0;
    cin >> n >> k;
    vector<int> sensor(n, 0);
    vector<int> distance(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> sensor[i];
    }

    sort(sensor.begin(), sensor.end());

    for (int i = 0; i < n - 1; i++) {
        int d = sensor[i + 1] - sensor[i];
        distance.push_back(d);
    }

    sort(distance.rbegin(), distance.rend());

    for (auto d: distance) {
        flag++;
        if (flag <= k - 1) continue;

        answer += d;
    }

    cout << answer << '\n';
}