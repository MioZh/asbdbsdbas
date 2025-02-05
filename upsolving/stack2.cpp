#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <int> st;
    stack <int> stMax;
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        if (s == "add") {
            int n; cin >> n;
            if (n > stMax.top() || st.empty())
                stMax.push(n);
            else
                stMax.push(stMax.top());
            st.push(n);
        }
        else if (s == "delete") {
            if (!st.empty()) {
                st.pop();
                stMax.pop();
            }
        }
        else if (s == "getcur") {
            if (!st.empty())
                cout << st.top() << "\n";
            else
                cout << "error\n";
        }
        else if (s == "getmax") {
            if (!st.empty())
                cout << stMax.top() << "\n";
            else
                cout << "error\n";
        }
    }
}
