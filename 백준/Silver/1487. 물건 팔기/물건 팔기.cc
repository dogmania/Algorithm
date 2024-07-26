#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> input;
    
    for(int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        
        input.push_back({p, d});
    }
    
    sort(input.begin(), input.end());
    
    int maxCost = 0;
    int maxProfit = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            int curProfit = input[i].first - input[j].second;
            if(curProfit > 0) sum += curProfit;
        }
        if(maxProfit < sum) {
            maxProfit = sum;
            maxCost = input[i].first;
        }
    }
    
    cout << maxCost;
}