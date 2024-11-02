#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    unsigned long long answer = 0;
    unsigned long long zero = 1;
    unsigned long long one = 0;
    cin >> n;

    if (n == 1 || n == 2) answer = 1;
    else {
        for (int i = 0; i < n - 2; i++) {
            unsigned long long newZero = zero + one;
            unsigned long long newOne = zero;

            zero = newZero;
            one = newOne;
        }
    }

    answer = zero + one;

    cout << answer << '\n';
}