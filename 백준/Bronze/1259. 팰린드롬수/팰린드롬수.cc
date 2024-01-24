#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int num = 0;
    string input = "";
    bool is_same = true;

    while(1) {
        cin >> num;

        if (num == 0) {
            cout << endl;
            break;
        } 

        input = to_string(num);
        is_same = true;

        for (int i = 0; i < input.length() / 2; i++) {
            if (input[i] != input[input.length() - 1 - i]){
                is_same = false;
                break;
            }
        }
        if (is_same) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}