#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index, count;
    cin >> index >> count;
    long long answer = 0;

    if (count != 0) {
        while(count > 0) {
            if (count > 1) {
                if (index == 1 || index == 5) {
                    count--;
                } else count -= 2;

                answer += 8;
                
                if (count == 0) answer += index - 1;
            } else {
                answer += 5;
                count -= 1;

                if (index == 3) answer += 1;
                else if (index == 2) answer += 2;
                else if (index == 1) answer += 3;
                else if (index == 5) answer += 7;
            }
        }
    } else {
        answer += index - 1;
    }

    cout << answer << '\n';
}