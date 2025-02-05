#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node (int x) {
        this->val = x;
        this->next = NULL;
    }
};

struct stack {
    Node *top;

    void add(int x) {
        Node *tmp = new Node(x);
        if (top == NULL) {
            top = tmp;
        }
        else {
            tmp->next = top;
            top = tmp;
        }
    }

    void del() {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }

    int getcur() {
        return top->val;
    }

    int getmax() {
        Node *cur = top;
        int max = INT32_MIN;
        while(cur != NULL) {
            if (cur->val > max) {
                max = cur->val;
            }
            cur = cur->next;
        }
        return max;
    }

    bool empty() {
        return top == NULL;
    }

    stack () {
        this->top = NULL;
    }
};

int main() {
    int q; cin >> q;
    stack st = stack();
    stack stMax = stack();
    while (q--) {
        string s; cin >> s;
        if (s == "add") {
            int n; cin >> n;
            if (st.empty())
                stMax.add(n);
            else {
                if (n > stMax.top->val)
                    stMax.add(n);
                else
                    stMax.add(stMax.top->val);
            }
            st.add(n);
        }
        else if (s == "delete") {
            if (!st.empty()) {
                st.del();
                stMax.del();
            }
        }
        else if (s == "getcur") {
            if (!st.empty())
                cout << st.getcur() << "\n";
            else
                cout << "error\n";
        }
        else if (s == "getmax") {
            if (!st.empty())
                cout << stMax.getcur() << "\n";
            else
                cout << "error\n";
        }
    }
}