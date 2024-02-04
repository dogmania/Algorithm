#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {
    string s;
    cin >> s;
    vector<string> answer;
    
    for (int i = s.length() - 1; i >= 0; i--) {
        answer.push_back(s.substr(i));
    }
    
    sort(answer.begin(), answer.end());
    
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}
