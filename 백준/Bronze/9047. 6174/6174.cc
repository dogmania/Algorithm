#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int input_count;
    cin >> input_count;
    vector<string> v;
    int max;
    int min;
    string num;
    int count = 0;
    
    for (int i = 0; i < input_count; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    for (int i = 0; i < v.size(); i++) {
        num = v[i];
        count = 0;
        while (num != "6174") {
            sort(num.begin(), num.end());
            min = (num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + num[3] - '0';
            max = (num[3] - '0') * 1000 + (num[2] - '0') * 100 + (num[1] - '0') * 10 + num[0] - '0';
            num = to_string(max - min);
            count++;
        }
        cout << count << endl;
    }
}
