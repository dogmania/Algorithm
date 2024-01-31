#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int input_count;
    cin >> input_count;
    int n, m;
    int answer = 0;
    vector<int> result;
    
    for (int i = 0; i < input_count; i++) {
        int arr[101] = {0};
        cin >> n >> m;
        int seat[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> seat[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (seat[i][j] != -1) {
                    if (i == n - 1) {
                        if (j == m - 1) break;
                        if (seat[i][j] == seat[i][j + 1]) arr[seat[i][j]]++;
                    } else {
                        if (j == 0) {
                            if (seat[i][j] == seat[i + 1][j] || seat[i][j] == seat[i + 1][j + 1]  || seat[i][j] == seat[i][j + 1]) {
                                arr[seat[i][j]]++;
                            }
                        } else if (j == m - 1) {
                            if (seat[i][j] == seat[i + 1][j] || seat[i][j] == seat[i + 1][j - 1]) {
                                arr[seat[i][j]]++;
                            }
                        } else {
                            if (seat[i][j] == seat[i + 1][j] || seat[i][j] == seat[i + 1][j + 1]  || seat[i][j] == seat[i][j + 1] || seat[i][j] == seat[i + 1][j - 1]) {
                                arr[seat[i][j]]++;
                            }
                        }
                    }
                }
            }
        }
        
        for (int i = 1; i < 101; i++) {
            if (arr[i] != 0) answer++;
        }
    
        result.push_back(answer);
        answer = 0;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
