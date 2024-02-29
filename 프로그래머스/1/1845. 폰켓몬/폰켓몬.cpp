#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size() / 2;
    map<int, int> m;
    
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }
    
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second != 0) {
            answer++;
            (i->second)--;
        }
        if (answer == n) break;
    }
    
    return answer;
}