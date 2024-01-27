#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long i = 0;
    
    while (i * i <= n) {
        if (i * i == n) answer = (i + 1) * (i + 1);
        i++;
    }
    
    return answer == 0 ? -1 : answer;
}