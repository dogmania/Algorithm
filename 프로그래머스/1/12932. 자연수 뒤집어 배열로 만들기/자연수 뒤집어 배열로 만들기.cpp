#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string a = to_string(n);
    int temp = 0;
    
    for (long long i = a.length() - 1; i >= 0; i--) {
        temp = a[i] - '0';
        answer.push_back(temp);
    }
    
    return answer;
}