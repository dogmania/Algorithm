#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    vector<int> temp;
    int num = 0;
    int i = 0;
    int cur_size = 0;
    
    while (1) {
        num = 5 * pow(10, i);
        
        if (num > r) break;
        temp.push_back(num);
        
        cur_size = temp.size();
        for (int j = 0; j < cur_size - 1; j++) {
            temp.push_back(num + temp[j]);
        }
        
        i++;
    }
    
    for (int k = 0; k < temp.size(); k++) {
        if (temp[k] >= l && temp[k] <= r) answer.push_back(temp[k]);
    }
    
    if (answer.size() == 0) answer.push_back(-1);
    
    return answer;
}