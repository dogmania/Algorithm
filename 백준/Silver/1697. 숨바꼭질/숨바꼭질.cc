#include <bits/stdc++.h>

using namespace std;

void bfs(vector<bool>& visited, int start, int end, vector<int>& answer) {
    deque<tuple<int, int>> dq;

    visited[start] = true;
    dq.push_back({start, 0});

    while(!dq.empty()) {
        tuple<int, int> y = dq.front();
        dq.pop_front();

        int current_x = get<0>(y);
        int current_answer = get<1>(y);

        if (current_x == end) answer.push_back(current_answer);

        if (current_x + 1 >= 0 && current_x + 1 <= 100000 && !visited[current_x + 1]) {  
            dq.push_back({current_x + 1, current_answer + 1});
            visited[current_x + 1] = true;
        }

        if (current_x - 1 >= 0 && current_x - 1 <= 100000 && !visited[current_x - 1]) {  
            dq.push_back({current_x - 1, current_answer + 1});
            visited[current_x - 1] = true;
        }

        if (current_x * 2 >= 0 && current_x * 2 <= 100000 && !visited[current_x * 2]) {  
            dq.push_back({current_x * 2, current_answer + 1});
            visited[current_x * 2] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    vector<int> answer;
    cin >> n >> k;

    vector<bool> visited(100001, false);

    bfs(visited, n, k, answer);
    cout << *min_element(answer.begin(), answer.end()) << '\n';
}