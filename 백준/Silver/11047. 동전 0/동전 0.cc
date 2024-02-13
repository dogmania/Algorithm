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
    int n, price;
    cin >> n >> price;
    vector<int> coin(n, 0);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (coin[i] <= price) {
            while(price >= coin[i]) {
                price -= coin[i];
                count++;
            }
        }
        
        if (price == 0) break;
    }
    
    cout << count << endl;
}