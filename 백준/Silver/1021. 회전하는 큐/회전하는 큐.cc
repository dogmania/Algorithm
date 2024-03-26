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

int answer = 0;

void popFront(deque<int>& dq) {
    int temp = dq.front();
    dq.push_back(temp);
    dq.pop_front();
    answer++;
}

void popBack(deque<int>& dq) {
    int temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
    answer++;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    vector<int> num(m);
    int index = 0;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }

    while(index != m) {
        for (int i = 0; i < dq.size(); i++) {
            if (num[index] == dq[i]) {
                if (i <= dq.size() / 2) {
                    while(dq.front() != num[index]) {
                        popFront(dq);
                    }
                    dq.pop_front();
                } else {
                    while(dq.front() != num[index]) {
                        popBack(dq);
                    }
                    dq.pop_front();
                }
            }
        }

        index++;
    }

    cout << answer << '\n';
}