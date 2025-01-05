#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    deque<long long> q;
    vector<long long> arr;

    for (int i = 0; i < 10; i++) {
        q.push_back(i);
        arr.push_back(i);
    }

    while(!q.empty()) {
        long long num = q.front();
        int last = num % 10;
        q.pop_front();

        for (int i = 0; i < last; i++) {
            long long newNum = num * 10 + i;

            if (newNum > 9876543210) break;

            q.push_back(newNum);
            arr.push_back(newNum);
        }
    }

    if (n >= arr.size()) {
        cout << -1 << '\n';
    } else {
        cout << arr[n] << '\n';
    }
}