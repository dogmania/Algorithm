#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int x;
    cin >> x;
    int numerator = 1;
    int denominator = 1;
    int num = 1;

    if (x == 1) {
        cout << numerator << '/' << denominator << endl;
    } else {
        denominator++;
        num++;
        while(x != num) {
            if (numerator == 1 && denominator != 1) {
                if (num == x) break;

                if (denominator != 2) {
                    denominator++;
                    num++;
                }
                while(denominator != 1) {
                    if (num == x) break;
                    num++;
                    denominator--;
                    numerator++;
                }
            } 

            if (denominator == 1 && numerator != 1) {
                if (num == x) break;
                numerator++;
                num++;
                while(numerator != 1) {
                    if (num == x) break;
                    numerator--;
                    denominator++;
                    num++;
                }
            }
        }
        cout << numerator << '/' << denominator << endl;
    }
}