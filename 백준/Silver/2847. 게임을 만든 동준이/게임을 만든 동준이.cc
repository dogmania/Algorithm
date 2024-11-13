#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int answer = 0;
    vector<int> score(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    for (int i = n - 1; i > 0; i--) {
        while(score[i] <= score[i - 1]) {
            score[i - 1] -= 1;
            answer++;
        }
    }

    cout << answer << '\n';
}