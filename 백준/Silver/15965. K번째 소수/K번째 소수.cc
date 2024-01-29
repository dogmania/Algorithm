#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;
    int num = 11;
    vector<int> v;
    bool p = true;
    
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    
    if (k >= 5) {
        while (1) {
            for (int i = 0; i < v.size(); i++) {
                if (num % v[i] == 0) {
                    p = false;
                    break;
                }
                
                if (v[i] > sqrt(num)) break;
            }
            
            if (p) v.push_back(num);
                        
            if (v.size() == k) break;
            
            switch(num % 10) {
                case 1:
                    num += 2;
                    break;
                case 3:
                    num += 4;
                    break;
                case 7:
                    num += 2;
                    break;
                case 9:
                    num += 2;
                    break;
            }
            p = true;
        }
    }
    
    cout << v[k - 1] << endl;
}
