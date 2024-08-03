#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    queue<int> people;
    vector<int> answer;

    for (int i = 1; i <= n; i++) {
        people.push(i);
    }

    while (!people.empty()) {
        for (int i = 1; i < k; i++) {
            people.push(people.front());
            people.pop();
        }
        answer.push_back(people.front());
        people.pop();
    }

    answer.push_back(people.back());

    cout << '<';
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i != n - 1) cout << ", ";
    }
    cout << '>' << '\n';
}