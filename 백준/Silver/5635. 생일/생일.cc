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
    string name;
    int day;
    int month;
    int year;

    Person(string name, int day, int month, int year) {
        this->name = name;
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

bool cmp(Person p1, Person p2) {
    if (p1.year == p2.year) {
        if (p1.month == p2.month) {
            return p1.day > p2.day;
        } else {
            return p1.month > p2.month;
        }
    } else {
        return p1.year > p2.year;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<Person> p;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int day;
        int month;
        int year;

        cin >> name >> day >> month >> year;

        p.push_back(Person(name, day, month, year));
    }

    sort(p.begin(), p.end(), cmp);

    if (n == 1) {
        cout << p[0].name << '\n';
    } else {
        cout << p[0].name << '\n';
        cout << p[n - 1].name << '\n';
    }
}