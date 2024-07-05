#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int>& arr, long long budget, int n) {
    long long start, end;
    int answer = 0;
    
    start = 0;
    end = arr.back();
    
    while(start <= end) {
        long long mid = (start + end) / 2;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] <= mid) sum += arr[i];
            else sum += mid;
        }

        if (sum <= budget) {
            start = mid + 1;
            answer = mid;
        } else {
            end = mid - 1;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0;
    int answer = 0;
    long long budget;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cin >> budget;

    sort(arr.begin(), arr.end());

    if (sum <= budget) answer = arr.back();
    else answer = binary_search(arr, budget, n);

    cout << answer << '\n';    
}