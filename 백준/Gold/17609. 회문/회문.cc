#include <bits/stdc++.h>

using namespace std;

int checkPalindrome(string s, int left, int right, int count) {

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (count == 1) return 2;

            int result1 = checkPalindrome(s, left + 1, right, count + 1);
            int result2 = checkPalindrome(s, left, right - 1, count + 1);

            return min(result1, result2);
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    vector<int> answer;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        answer.push_back(checkPalindrome(s, 0, s.length() - 1, 0));
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}