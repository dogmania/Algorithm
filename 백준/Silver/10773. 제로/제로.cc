#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    cin >> k;
    stack<int> st;
    int num;
    int size = 0;
    
    for (int i = 0; i < k; i++) {
        cin >> num;
        if (num == 0) {
            st.pop();
        } else {
            st.push(num);
        }
    }
    
    num = 0;
    size = st.size();
    for (int i = 0; i < size; i++) {
        num += st.top();
        st.pop();
    }
    
    cout << num << '\n';
}