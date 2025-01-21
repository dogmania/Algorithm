#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    int answer = 0;

    cin >> h >> w;

    vector<int> block(w, 0);

    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }

    int left = 0;
    int right = w - 1;
    int lMax = 0, rMax = 0;

    while(left < right) {
        if (block[left] <= block[right]) {
            if (block[left] > lMax) {
                lMax = block[left];
            } else {
                answer += lMax - block[left];
            }
            left++;
        } else {
            if (block[right] > rMax) {
                rMax = block[right];
            } else {
                answer += rMax - block[right];
            }
            right--;
        }
    }

    cout << answer << '\n';
}