#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    int first;
    int second;
    bool included;

    Point(int first, int second, bool included) {
        this->first = first;
        this->second = second;
        this->included = included;
    }
};

bool sortAsc(Point point1, Point point2) {
    if (point1.first == point2.first) {
        return point1.second < point2.second;
    } else return point1.first < point2.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;
    vector<Point> point;

    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        point.push_back(Point(first, second, false));
    }

    sort(point.begin(), point.end(), sortAsc);

    for (int i = 0; i < n; i++) {
        if (point[i].included) continue;
        int count = 0;

        for (int j = i + 1; j < n; j++) {
            if (point[i].first <= point[j].first && point[i].second >= point[j].second) {
                count++;
                point[j].included = true;
            }
        }

        answer = max(count, answer);
    }

    cout << answer << '\n';
}