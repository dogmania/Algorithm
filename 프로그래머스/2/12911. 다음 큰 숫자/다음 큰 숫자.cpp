#include <bits/stdc++.h>

using namespace std;

int binary(int);

int solution(int n) {
    int num = n + 1;
    int count = 0;
    
    count = binary(n);
    
    while(1) {
        if (binary(num) == count) break;
        else num++;
    }
    
    return num;
}

int binary(int n) {
    int c = 0;
    
    while(n > 0) {
        if (n % 2 == 1) c++;
        n /= 2;
    }
    
    return c;
}