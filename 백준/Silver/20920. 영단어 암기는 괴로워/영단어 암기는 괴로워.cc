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

class word{
public:
    string w;
    int count = 0;

    word(string w, int count) {
        this->w = w;
        this->count = count;
    }
};

bool cmp(word w1, word w2) {
    int length1 = w1.w.length();
    int length2 = w2.w.length();

    if (w1.count == w2.count) {
        if (length1 == length2) {
            return w1.w < w2.w;
        } else {
            return length1 > length2;
        }
    } else {
        return w1.count > w2.count;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    vector<word> v;
    map<string, int> mp;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        if (s.length() >= m) {
            mp[s]++;
        }
    }

    for (auto i = mp.begin(); i != mp.end(); i++) {
        word w = word(i->first, i->second);
        v.push_back(w);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto ans: v) {
        cout << ans.w << '\n';
    }
}