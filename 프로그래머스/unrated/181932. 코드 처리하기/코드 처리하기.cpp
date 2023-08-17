#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    string ret = "";
    bool mode = 0;
    
    for (int i = 0; i < code.length(); i++) {
        if (mode == 0 && i % 2 == 0 && code[i] != '1') 
            ret.push_back(code[i]);
        else if (mode == 1 && i % 2 == 1 && code[i] != '1') 
            ret.push_back(code[i]);
        else if (code[i] == '1') mode = !mode;
    }
    
    return answer = (ret == "") ? "EMPTY" : ret;
}