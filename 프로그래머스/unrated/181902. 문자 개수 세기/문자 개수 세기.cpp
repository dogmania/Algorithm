#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    int index = 0;

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] < 97 ) {
            index = my_string[i] - 65;
            answer[index]++;
        } else {
            index = my_string[i] - 71;
            answer[index]++;
        }
    }
    
    return answer;
}