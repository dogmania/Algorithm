#include <bits/stdc++.h>

using namespace std;

vector<string> wheels(5, "");

void rotatePositive(int wheelNum) {
    char temp = wheels[wheelNum].back();
    wheels[wheelNum].pop_back();
    wheels[wheelNum].insert(wheels[wheelNum].begin(), temp);
}

void rotateNegative(int wheelNum) {
    char temp = wheels[wheelNum].front();
    wheels[wheelNum].erase(wheels[wheelNum].begin());
    wheels[wheelNum].push_back(temp);
}

void spreadUpward(int wheelNum, int direction) {
    if (wheelNum > 1 && wheels[wheelNum][6] != wheels[wheelNum - 1][2]) {
        spreadUpward(wheelNum - 1, direction * -1);
        if (direction == 1) rotateNegative(wheelNum - 1);
        else rotatePositive(wheelNum - 1);
    }
}

void spreadDownward(int wheelNum, int direction) {
    if (wheelNum < 4 && wheels[wheelNum][2] != wheels[wheelNum + 1][6]) {
        spreadDownward(wheelNum + 1, direction * -1);
        if (direction == 1) rotateNegative(wheelNum + 1);
        else rotatePositive(wheelNum + 1);
    }
}

void rotate(int wheelNum, int direction) {
    spreadUpward(wheelNum, direction);
    spreadDownward(wheelNum, direction);

    if (direction == 1) rotatePositive(wheelNum);
    else rotateNegative(wheelNum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0, count;

    for (int i = 1; i < 5; i++) {
        cin >> wheels[i];
    }

    cin >> count;

    for (int i = 0; i < count; i++) {
        int wheelNum, direction;
        cin >> wheelNum >> direction;
        rotate(wheelNum, direction);
    }

    for (int i = 1; i < 5; i++) {
        answer += (wheels[i][0] - '0') << (i - 1);
    }

    cout << answer << '\n';
}