#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        vector<int> v1(n, 0);
        vector<int> v2(n, 0);
        int num1 = arr1[i];
        int num2 = arr2[i];
        int index = n - 1;
        string s = "";
        
        while (num1 > 0) {
            v1[index] = num1 % 2;
            num1 /= 2;
            index--;
        }
        
        index = n - 1;
        
        while (num2 > 0) {
            v2[index] = num2 % 2;
            num2 /= 2;
            index--;
        }
        
        for (int i = 0; i < n; i++) {
            if (v1[i] || v2[i]) {
                s.push_back('#');
            } else {
                s.push_back(' ');
            }
        }
        
        answer.push_back(s);
    }
    
    return answer;
}