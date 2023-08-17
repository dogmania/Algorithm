#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string cur_bab = "";
    
    for (int i = 0; i < babbling.size(); i++) {
        cur_bab = babbling[i];
        
        while (cur_bab.length() >= 2) {
            if (cur_bab.length() >= 3) {
                if ((cur_bab[0] == 'a' && cur_bab[1] == 'y' && cur_bab[2] == 'a') || (cur_bab[0] == 'w' && cur_bab[1] == 'o' && cur_bab[2] == 'o')) {
                    cur_bab.erase(0, 3);
                } else if ((cur_bab[0] == 'y' && cur_bab[1] == 'e') || (cur_bab[0] == 'm' && cur_bab[1] == 'a')) {
                    cur_bab.erase(0, 2);
                } else break;
            } else if (cur_bab.length() == 2) {
                if ((cur_bab[0] == 'y' && cur_bab[1] == 'e') || (cur_bab[0] == 'm' && cur_bab[1] == 'a')) {
                    cur_bab.erase(0, 2);
                } else break;
            }
        }
        
        if (cur_bab == "") answer += 1;
    }
    
    return answer;
}