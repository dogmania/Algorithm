#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    
    return answer / arr.size();
}