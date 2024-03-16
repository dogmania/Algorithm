#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

class Person {
public:
    int age;
    int order;
    string name;

    Person(int age, int order, string name) {
        this->age = age;
        this->order = order;
        this->name = name;
    }
};

bool cmp(Person p1, Person p2) {
    if (p1.age == p2.age) return p1.order <= p2.order;
    else return p1.age <= p2.age;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int age;
    int order = 1;
    string name;
    vector<Person> p;
    int n;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        p.push_back(Person(age, order, name));
        order++;
    }

    sort(p.begin(), p.end(), cmp);

    for (int i = 0; i < p.size(); i++) {
        cout << p[i].age << ' ' << p[i].name << '\n';
    }
}