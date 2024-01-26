#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int input_count;
    cin >> input_count;
    string word[input_count];
    int answer = 0;
    bool is_exist = false;
    
    for (int i = 0; i < input_count; i++) {
        cin >> word[i];
    }

    for (auto& w: word) {
        is_exist = false;
        for (int i = 0; i < w.length(); i++) {
            if (i >= 2) {
                for (int j = 0; j <= i - 2; j++) {
                    if (w[j] == w[i]) {
                        if (w[i - 1] != w[i]) {
                            is_exist = true;
                            break;
                        }
                    }
                }
                
                if (is_exist) break;
            }
        }
        if (!is_exist) answer++;
    }
    
    cout << answer << endl;
}
