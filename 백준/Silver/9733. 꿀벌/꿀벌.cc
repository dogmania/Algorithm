#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int main(void) {
    string s, word;
    unordered_map<string, int> m = {
        {"Re", 0}, {"Pt", 0}, {"Cc", 0}, {"Ea", 0}, {"Tb", 0}, {"Cm", 0}, {"Ex", 0}
    };
    double count = 0;
    
    while (getline(cin, s)) {
        if (s.empty()) break;
        
        stringstream ss(s);
        
        while(ss >> word) {
            m[word]++;
            count++;
        }
    }
    
    printf("Re %d %.2f\n", m["Re"], m["Re"] / count);
    printf("Pt %d %.2f\n", m["Pt"], m["Pt"] / count);
    printf("Cc %d %.2f\n", m["Cc"], m["Cc"] / count);
    printf("Ea %d %.2f\n", m["Ea"], m["Ea"] / count);
    printf("Tb %d %.2f\n", m["Tb"], m["Tb"] / count);
    printf("Cm %d %.2f\n", m["Cm"], m["Cm"] / count);
    printf("Ex %d %.2f\n", m["Ex"], m["Ex"] / count);
    printf("Total %.0f %.2f\n", count, 1.00);
}