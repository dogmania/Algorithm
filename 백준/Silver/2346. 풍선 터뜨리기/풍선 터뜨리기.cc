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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int index = 0;
    int next = 0;
    cin >> n;
    deque<int> num(n, 0);
    vector<bool> p(n, false);
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    answer.push_back(1);
    p[0] = true;
    n--;
    next = num[0];

    while(n > 0) {
        int count = 0;
        
        if (next > 0) {
            while(1) {

                if (!p[index]) {
                    count++;
                }

                if (count == next) break;

                index++;

                if (index >= num.size()) index = 0;
            }

            answer.push_back(index + 1);
            p[index] = true;
            next = num[index];

        } else if (next < 0) {
            while (1) {

                if (!p[index]) {
                    count--;
                }

                if (count == next) break;

                index--;

                if (index < 0) index = num.size() - 1;
            }

            answer.push_back(index + 1);
            p[index] = true;
            next = num[index];
            
        }

        n--;
    }

    for (auto ans: answer) {
        cout << ans << ' ';
    }

    cout << '\n';
}