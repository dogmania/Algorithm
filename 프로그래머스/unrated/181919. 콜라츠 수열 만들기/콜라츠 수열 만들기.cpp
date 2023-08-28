#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    answer.push_back(n);
    
    while (n != 1) {
        if (n % 2) {
            n = n * 3 + 1;
            answer.push_back(n);
        } else {
            n /= 2;
            answer.push_back(n);
        }
    }
    
    return answer;
}