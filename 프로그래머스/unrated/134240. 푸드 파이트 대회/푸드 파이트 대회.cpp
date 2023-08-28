#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int cur_size = 0;
    
    for (int i = 1; i < food.size(); i++) {
        if (food[i] >= 2) {
            for (int j = 0; j < food[i] / 2; j++) {
                answer.push_back(i + '0');
            }
        }
    }
    
    cur_size = answer.size();
    answer.push_back(0 + '0');
    
    for (int i = cur_size - 1; i >= 0; i--) {
        answer.push_back(answer[i]);
    }
    
    return answer;
}