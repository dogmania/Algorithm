#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int first = 1;
    int last = n;

    for (int i = 0;; i++) {
        if (n == pow(2, i)) {
            answer = i;
            break;
        }
    }
    
    if (a < b) {
        while(first < last) {
            int mid = (first + last) / 2;

            if (a <= mid && b > mid) break;
            else if (a > mid) {
                answer--;
                first = mid + 1;
            } else {
                last = mid - 1;
                answer--;
            }
        }
    } else {
        while(first < last) {
            int mid = (first + last) / 2;

            if (b <= mid && a > mid) break;
            else if (b > mid) {
                answer--;
                first = mid + 1;
            } else {
                last = mid - 1;
                answer--;
            }
        
        }
    }

    return answer;
}