#include <bits/stdc++.h>

using namespace std;

int n;

bool binary_search(vector<int>& number, int targetIndex) {
    int start = 0;
    int end = n - 1;
    int target = number[targetIndex];

    while (start < end) {
        long long sum = number[start] + number[end];
        if (sum == target && start != targetIndex && end != targetIndex) return true;
        else if (sum < target) {
            start++;
        } else {
            end--;
        }

        if (start == targetIndex) start++;
        if (end == targetIndex) end--;
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    cin >> n;
    vector<int> number(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    sort(number.begin(), number.end());

    for (int i = 0; i < n; i++) {
        bool isGood = binary_search(number, i);
        if (isGood) answer++;
    }

    cout << answer << '\n';
}