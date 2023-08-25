#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    for (int i = 0; i < numLog.size() - 1; i++) {
        switch (numLog[i + 1] - numLog[i]) {
            case 1: answer.push_back('w'); 
                break;
            case -1: answer.push_back('s');
                break;
            case 10: answer.push_back('d');
                break;
            case -10: answer.push_back('a');
                break;
        }
    }
    
    return answer;
}