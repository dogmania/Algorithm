#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int n, int sum) {
    if (n == numbers.size()) {
        if (sum == target) answer++;
    } else if (n <= numbers.size() - 1) {
        dfs(numbers, target, n + 1, sum + numbers[n]);
        dfs(numbers, target, n + 1, sum - numbers[n]);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}