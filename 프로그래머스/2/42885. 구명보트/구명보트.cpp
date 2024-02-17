#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    int first = 0;
    int last = people.size() - 1;
    
    sort(people.rbegin(), people.rend());
    
    while(first <= last) {
        if (sum + people[first] <= limit) {
            sum += people[first];
            first++;
        } 
        
        if (sum + people[last] <= limit) {
            sum += people[last];
            last--;
        } 
        
        sum = 0;
        answer++;
    }
    
    return answer;
}