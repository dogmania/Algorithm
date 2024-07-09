#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0]) return v1[1] <= v2[1];
    else return v1[0] <= v2[0];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int answer = 1;

        vector<vector<int>> rank(m, vector<int>(2, 0));

        for (int j = 0; j < m; j++) {
            cin >> rank[j][0] >> rank[j][1];
        }

        sort(rank.begin(), rank.end(), cmp);

        int minValue = rank[0][1];
        for (int j = 0; j < m; j++) {
            if (rank[j][1] < minValue) {
                answer++;
                minValue = rank[j][1];
            }
        }

        cout << answer << '\n';
    }
}