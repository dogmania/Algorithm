#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p;
    int start = 0, end = 0;
    int answer = 0;
    string dna;
    map<char, int> count;
    map<char, int> curCount;

    cin >> s >> p;
    cin >> dna;

    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;

        switch (i) {
            case 0: 
                count['A'] = temp;
                break;
            case 1:
                count['C'] = temp;
                break;
            case 2:
                count['G'] = temp;
                break;
            case 3:
                count['T'] = temp;
                break;
            default: 
                break;
        }
    }

    end = p - 1;

    for (int i = start; i <= end; i++) {
        curCount[dna[i]]++;
    }

    while (end < s) {
        if (curCount['A'] >= count['A'] && curCount['C'] >= count['C'] && curCount['G'] >= count['G'] && curCount['T'] >= count['T']) answer++;

        start++;
        end++;

        curCount[dna[start - 1]]--;
        curCount[dna[end]]++;
    }

    cout << answer << '\n';
}