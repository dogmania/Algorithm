#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long num1 = num;
    
    if (num1 != 1) {
        for (int i = 1; i < 501; i++) {
            if (num1 % 2 == 0) num1 = num1 / 2L;
            else num1 = num1 * 3L + 1L;

            if (num1 == 1) {
                answer = i;
                break;
            }
        }
    }
    
    if (num1 != 1) answer = -1;
    
    return answer;
}