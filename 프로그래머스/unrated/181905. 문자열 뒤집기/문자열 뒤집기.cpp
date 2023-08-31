#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    string rev = my_string.substr(s, e - s + 1);
    
    reverse(rev.begin(), rev.end());
    
    for (int i = s; i <= e; i++) {
        my_string[i] = rev[i - s];
    }
    
    return answer = my_string;
}