#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> num(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    int answer = 1;
    int flag = 0; 

    for (int i = flag + 1; i < n; i++) {
        if (num[i] >= num[flag] * 2) {
            answer++;
            flag = i; 
        }
    }

    cout << answer << '\n';
}