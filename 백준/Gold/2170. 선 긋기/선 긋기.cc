#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    int first;
    int second;

    Point(int first, int second) {
        this->first = first;
        this->second = second;
    }
};

bool sortAsc(Point point1, Point point2) {
    if (point1.first == point2.first) {
        return point1.second < point2.second;
    } else {
        return point1.first < point2.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<Point> point;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        point.push_back(Point(first, second));
    }

    sort(point.begin(), point.end(), sortAsc);

    int start = point.front().first;
    int end = point.front().second;

    for (int i = 1; i < n; i++) {
        if (point[i].first > end) {
            answer += end - start;
            start = point[i].first;
            end = point[i].second;
            continue;
        }

        if (point[i].second > end) {
            end = point[i].second;
        }
    }

    answer += end - start;

    cout << answer << '\n';
}