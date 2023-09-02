#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int index = 0;
    map<string, int> m;
    
    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }
    
    for (auto& c: callings) {
        if (m.find(c) != m.end()) {
            index = m[c];
            m[c] -= 1;
            m[players[index - 1]] += 1;
            swap(players[index], players[index - 1]);
        } else {
            index = find(players.begin(), players.end(), c) - players.begin();
            m[c] -= 1;
            m[players[index - 1]] += 1;
            swap(players[index], players[index - 1]);
        }
    }
    
    return players;
}