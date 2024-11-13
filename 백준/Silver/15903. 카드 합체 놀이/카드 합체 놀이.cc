#include <bits/stdc++.h>

#define ULL unsigned long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    ULL answer = 0;
    cin >> n >> m;
    priority_queue<ULL> num;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        num.push(-number);
    }

    for (int i = 0; i < m; i++) {
        ULL num1 = -num.top();
        num.pop();
        ULL num2 = -num.top();
        num.pop();

        ULL result = num1 + num2;
        num.push(-result);
        num.push(-result);
    }

    while(!num.empty()) {
        answer += -num.top();
        num.pop();
    }

    cout << answer << '\n';
}