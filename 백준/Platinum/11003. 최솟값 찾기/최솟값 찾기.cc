#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    int start = 0, end = 0;

    cin >> n >> l;

    vector<int> A(n + 1, 0);
    vector<int> D;
    deque<int> index;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    start = 1 - l + 1;
    end = 1;
    D.push_back(A[end]);

    index.push_back(end);

    while(end < n) {
        start++;
        end++;

        while(!index.empty() && A[index.back()] >= A[end]) {
            index.pop_back();
        }

        index.push_back(end);

        if (index.front() < start) index.pop_front();

        D.push_back(A[index.front()]);
    }

    for (auto ans: D) {
        cout << ans << ' ';
    }

    cout << '\n';
}