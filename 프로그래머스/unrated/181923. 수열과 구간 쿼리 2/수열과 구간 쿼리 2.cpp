#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    vector<int> temp;
    
    for (auto q: queries) {
        for (int i = q[0]; i <= q[1]; i++) {
            if (arr[i] > q[2]) temp.push_back(arr[i]);
        }
        if (temp.size() == 0) answer.push_back(-1);
        else answer.push_back(*min_element(temp.begin(), temp.end()));
        temp.clear();
    }
    
    return answer;
}