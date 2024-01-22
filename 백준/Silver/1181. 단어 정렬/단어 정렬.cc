#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int input_count;
    string input_str;
    int length;
    vector<vector<string> > v(50, vector<string>(0));

    cin >> input_count;
    for (int i = 0; i < input_count; i++) {
        cin >> input_str;
        length = input_str.length();
        v[length - 1].push_back(input_str);
    }

    for (int j = 0; j < v.size(); j++) {
        sort(v[j].begin(), v[j].end());
        v[j].erase(unique(v[j].begin(), v[j].end()), v[j].end());
        for (int i = 0; i < v[j].size(); i++) {
            cout << v[j][i] << endl;
        }
    }
}