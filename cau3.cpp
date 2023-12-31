#include <iostream>
#include <stack>
using namespace std;

string encodeString(const string& s) {
    if (s.empty()) return "";

    stack<pair<char, int>> stk;
    string result = "";

    for (char c : s) {
        if (stk.empty() || stk.top().first != c) {
            stk.push({c, 1});
        } else {
            stk.top().second++;
        }
    }

    while (!stk.empty()) {
        result = stk.top().first + to_string(stk.top().second) + result;
        stk.pop();
    }

    return result;
}


int main() {
    string s;
    cin >> s;
    cout << encodeString(s) << endl;
    return 0;
}
