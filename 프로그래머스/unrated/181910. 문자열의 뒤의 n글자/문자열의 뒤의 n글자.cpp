#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int start = my_string.length() - n;
    
    return answer += my_string.substr(start, n);
}