#include <iostream>

using namespace std;
int count = 0;
struct Node{
    string val;
    int cnt, cnt2;
    Node* next;
    Node* prev;
    Node(string val){
        this -> val = val;
        next = NULL;
        prev = NULL;
        cnt = 1;
        cnt2 = 0;
    }
};

struct LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void push(string val){
        Node* NewNode = new Node(val);
        if(head == NULL){
            head = tail = NewNode;
            count++;
        }
        else{
            if(tail -> val == val){
                tail -> cnt++;
            }
            else{
                if(NewNode -> cnt > 1){
                    NewNode -> cnt2++;
                    count--;
                }
                else{
                    tail -> next = NewNode;
                    NewNode -> prev = tail;
                    tail = NewNode;
                    count++;
                }
            }
        }
    }
    
    void print(){
        Node * cur = tail;
        while(cur != NULL){
            if(cur -> cnt2 == 0){
                cout << cur -> val << endl;
            }
            cur = cur->prev;
        }
    }
};

int main(){
    int n; cin >> n;
    LinkedList ll;
    while(n--){
        string s; cin >> s;
        if(s != "" && s != " "){
            ll.push(s);
        }
    }

    cout << "All in all: " << count << "\nStudents:\n";
    ll.print();
}