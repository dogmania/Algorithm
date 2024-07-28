#include <bits/stdc++.h>

#define SK "SK"
#define CY "CY"

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string answer = CY;

    while(1) {
        if (n - 3 >= 0) {
            n -= 3;
            if (answer == CY) answer = SK;
            else answer = CY;
        } else {
            n--;
            if (answer == CY) answer = SK;
            else answer = CY;
        }

        if (n == 0) {
            cout << answer << '\n';
            return 0;
        }
    }
}