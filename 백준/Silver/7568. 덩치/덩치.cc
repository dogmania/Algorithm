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

class Person {
public:
    int w;
    int h;

    Person(int w, int h) {
        this->w = w;
        this->h = h;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<Person> v;
    vector<int> answer(n);

    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;

        Person p(w, h);
        v.push_back(p);
    }

    for (int i = 0; i < n; i++) {
        int rank = 1;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            else {
                if (v[i].w < v[j].w && v[i].h < v[j].h) {
                    rank++;
                }
            }
        }

        answer[i] = rank;
    }

    for (auto ans: answer) {
        cout << ans << ' ';
    }
}