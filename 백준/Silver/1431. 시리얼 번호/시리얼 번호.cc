#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

class serialNum {
public:
    string num;
    int sum = 0;

    serialNum(string num) {
        this->num = num;
    }

    int calSum() {
        for (int i = 0; i < num.length(); i++) {
            if (num[i] >= 65 && num[i] <= 90) continue;
            else {
                sum += num[i] - '0';
            }
        }

        return sum;
    }
};

bool cmp(serialNum num1, serialNum num2) {
    int length1 = num1.num.length();
    int length2 = num2.num.length();
    int sum1 = num1.calSum();
    int sum2 = num2.calSum();

    if (length1 == length2) {
        if (sum1 == sum2) {
            return num1.num < num2.num;
        } else {
            return sum1 < sum2;
        }
    } else {
        return length1 < length2;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<serialNum> v;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(serialNum(s));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i].num << '\n';
    }
}