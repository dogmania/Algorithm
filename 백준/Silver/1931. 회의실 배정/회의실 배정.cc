#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<long long> arr1, vector<long long> arr2) {
    if (arr1[1] == arr2[1]) return arr1[0] <= arr2[0];
    else return arr1[1] <= arr2[1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long endTime = 0;
    int answer = 0;

    cin >> n;

    vector<vector<long long>> arr(n, vector<long long>(2, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    sort(arr.begin(), arr.end(), cmp);

    endTime = arr[0][1];
    answer++;
    for (int i = 1; i < n; i++) {
        if (arr[i][0] >= endTime) {
            endTime = arr[i][1];
            answer++;
        }
    }

    cout << answer << '\n';
}