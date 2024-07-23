#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    deque<int> number;

    for (int i = 1; i < n + 1; i++) {
        number.push_back(i);
    }

    while(!number.empty()) {
        int num = number.front();
        number.pop_front();

        cout << num << ' ';

        if (number.empty()) break;

        num = number.front();
        number.pop_front();
        number.push_back(num);
    }

    cout << '\n';
}