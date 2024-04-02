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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int primeNum[30001];
    vector<int> num1(2, 0);
    vector<int> num2(2, 0);
    vector<int> answer(2, 0);

    cin >> num1[0] >> num1[1];
    cin >> num2[0] >> num2[1];

    answer[1] = num1[1] * num2[1];
    answer[0] = (num1[0] * num2[1]) + (num1[1] * num2[0]);

    int num = gcd(answer[0], answer[1]);

    answer[0] /= num;
    answer[1] /= num;

    cout << answer[0] << ' ' << answer[1] << '\n';
}