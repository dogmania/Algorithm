#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> time(n, 0);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    
    sort(time.begin(), time.end());
    
    for (int i = 0; i < time.size(); i++) {
        sum += time[i] * (n - i);
    }
    
    cout << sum << endl;
}