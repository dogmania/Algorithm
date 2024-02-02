#include <bits/stdc++.h>

using namespace std;

int measure(int, int);

vector<int> solution(int n, int m) {
    vector<int> answer;
    // vector<int> v;
    // int n1 = n;
    // int m1 = m;
    int q = 1;
    // int i = 2;
    
    q = measure(n, m);
    answer.push_back(q);
    answer.push_back(n * m / q);
    
//     if (n >= m) {
//         for (i; i <= m1; i++) {
//             if (n1 % i == 0 && m1 % i == 0) {
//                 v.push_back(i);
//                 n1 /= i;
//                 m1 /= i;
//                 i = 2;
//             }
//         }
        
//         for (int j = 0; j < v.size(); j++) {
//             q *= v[j];
//         }
        
//         answer.push_back(q);
//         answer.push_back(n1 * m1 * q);
//     } else if (n < m) {
//         i = 2;
//         for (i; i <= n1; i++) {
//             if (n1 % i == 0 && m1 % i == 0) {
//                 v.push_back(i);
//                 n1 /= i;
//                 m1 /= i;
//                 i = 2;
//             }
//         }
        
//         for (int j = 0; j < v.size(); j++) {
//             q *= v[j];
//         }
        
//         answer.push_back(q);
//         answer.push_back(n1 * m1 * q);
//     }
    
    return answer;
}

int measure(int n, int m) {
    int i = 2;
    bool b = false;
    
    for (i; i <= n; i++) {
        if (n % i == 0 && m % i == 0) {
            b = true;
            break;
        }
    }
    
    if (b) return i * measure(n / i, m / i);
    else return 1;
}