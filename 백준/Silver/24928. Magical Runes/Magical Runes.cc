#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define ull unsigned long long

int main () {
    string s = "";
    ull n;
    cin >> s >> n;
    unsigned long length = s.length();
    int sum = 0;
    int arr[length];
    long long count = 0;
    
    if (s[0] == 'A') {
        arr[0] = 2;
        sum += 2;
    }
    else {
        arr[0] = 1;
        sum += 1;
    }
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'B') {
            arr[i] = sum;
        } else {
            sum += pow(2, i);
            arr[i] = sum;
        }
    }
    
    for(int i = 0; i < s.length(); i++) {
        count = arr[i];
        if (n >= count) {
            if (((n - count) / (1ULL << i)) % 2 == 1) {
                s[i] = 'B';
            } else s[i] = 'A';
        } else {
            if (((count - n - 1) / (1ULL << i)) % 2 == 1) s[i] = 'A';
            else s[i] = 'B';
        }
    }
    
    cout << s << endl;
}
