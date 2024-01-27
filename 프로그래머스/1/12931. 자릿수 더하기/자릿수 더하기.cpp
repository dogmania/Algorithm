#include <bits/stdc++.h>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string input = to_string(n);

    for (int i = 0; i < input.length(); i++) {
        answer += input[i] - '0';
    }

    return answer;
}