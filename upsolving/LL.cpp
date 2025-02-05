#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;

    Node(int x) {
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *add_front(Node *head, int x) {
    Node *n_head = new Node(x);
    n_head->next = head;
    head->prev = n_head;
    head = n_head;
    return head;
}

Node *add_back(Node *tail, int x) {
    Node *n_tail = new Node(x);
    n_tail->prev = tail;
    tail->next = n_tail;
    tail = tail->next;
    return tail;
}

void print_front(Node *head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

void print_back(Node *tail) {
    while(tail != NULL) {
        cout << tail->val << " ";
        tail = tail->prev;
    }
}

int main() {
    int q; cin >> q;
    int reverse_cnt = 0;
    Node *head = NULL;
    Node *current = NULL;
    while(q--) {
        int n; cin >> n;
        if (n == 2) {
            reverse_cnt++;
        }
        if (n == 1) {
            int x; cin >> x;
            if (head == NULL) {
                head = new Node(x);
                current = head;
            }
            else {
                if (reverse_cnt % 2 == 0) {
                    current = add_back(current, x);
                }
                else {
                    head = add_front(head, x);
                }
            }
        }
    }
    reverse_cnt % 2 == 0 ? print_front(head) : print_back(current);
}