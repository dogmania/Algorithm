#include <bits/stdc++.h>

using namespace std;

long long binary_search(vector<long long> line, int n) {
    long long start = 1;
    long long  end = line.back();
    int answer = 0;

    while(start <= end) {
        long long count = 0;
        long long mid = (start + end) / 2;

        for (auto l: line) {
            if (l >= mid) {
                count += l / mid;
            }
        }

        if (count >= n && mid > answer) {
            answer = mid;
            start = mid + 1;
        }
        else if (count < n) {
            end = mid - 1;
        } else if (count > n) {
            start = mid + 1;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k, n;
    cin >> k >> n;

    vector<long long> line(k, 0);

    for (int i = 0; i < k; i++) {
        cin >> line[i];
    }

    sort(line.begin(), line.end());

    long long answer = binary_search(line, n);

    cout << answer << '\n';
}