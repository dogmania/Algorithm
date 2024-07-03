#include <bits/stdc++.h>

using namespace std;

void dfs(long long start, long long end, int count, vector<int>& answer) {
    if (start == end) answer.push_back(count);

    if (start * 2 <= 1000000000 && start * 2 <= end) dfs(start * 2, end, count + 1, answer);
    if (start * 10 + 1 <= 1000000000 && start * 10 + 1 <= end) dfs(start * 10 + 1, end, count + 1, answer);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;
    vector<int> answer;

    dfs(A, B, 1, answer);

    if (answer.size() == 0) cout << -1 << '\n';
    else cout << *min_element(answer.begin(), answer.end()) << '\n';
}