#include <iostream>
#include <stack>

using namespace std;

string toBin(long long n) {
    string s = "";
    while (n > 0) {
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    return s;
}

int main() {
    int q; cin >> q;
    while(q--) {
        long long n; cin >> n;
        string s = toBin(n);
        stack <char> st;
        for(long long i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == '1' && s[i] == '0') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        if (!st.empty()) {
            cout << "NO\n";
        }
        else 
            cout << "YES\n";
    }
}