#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {
    int n;
    vector<int> v;
    int num;
    vector<int> answer;
    int count = 0;
    int i;
    int j = 0;
    int k = 0;
    int index = 0;
    
    answer.push_back(4);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = v.front();;) {
        if (i == v.back()) break;
        
        k = index;
        for (int j = i; j < i + 5; j++) {
            if (v[k] != j) count++;
            else  {
                k++;
            }
        }
        answer.push_back(count);
        count = 0;
        if (v[index + 1] - i > 4) {
            index++;
            i = v[index];
        } else {
            i++;
            if (i == v[index + 1]) index++;
        }
    }
    
    sort(answer.begin(), answer.end());
    cout << answer[0] << endl;
}
