#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s;
        cin >> m;
        deque<int> num;
        vector<int> answer;
        bool isError = false;
        bool isReverse = false;

        string arr;
        cin >> arr;

        if (arr.length() != 2) {
            string number = "";
            for (int j = 0; j < arr.length(); j++) {
                if (arr[j] != '[' && arr[j] != ']' && arr[j] != ',') number.push_back(arr[j]);
                else {
                    if (number.length() > 0) {
                        num.push_back(stoi(number));
                        number = "";
                    }
                }
            }
        }

        int length = s.length();
        for (int j = 0; j < length; j++) {
            switch(s[j]) {
                case 'R':
                    isReverse = !isReverse;
                    break;
                case 'D':
                    if (num.empty()) {
                        cout << "error";
                        isError = true;
                    } else {
                        if (isReverse) num.pop_back();
                        else num.pop_front();
                    }
                    break;
                default: 
                    break;
            }

            if(isError) break;
        }

        if (!isError) {
            cout << '[';
            if (isReverse) {
                for (int j = num.size() - 1; j >= 0; j--) {
                    cout << num[j];
                    if (j != 0) cout << ',';
                }
            } else {
                for (int j = 0; j < num.size(); j++) {
                    cout << num[j];
                    if (j != num.size() - 1) cout << ',';
                }
            }
            cout << ']';
        }

        cout << '\n';
    }
}