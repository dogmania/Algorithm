#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double count = 0.0;
    double sum = 0.0;
    map<string, double> mp = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}
    };

    for (int i = 0; i < 20; i++) {
        string s, grade;
        double score;

        cin >> s >> score >> grade;

        if (grade == "P") continue;

        sum += score * mp[grade];
        count += score;
    }

    cout << sum / count << '\n';
}