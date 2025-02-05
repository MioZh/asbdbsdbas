#include <iostream>
using namespace std;


struct Node{
    int data;
    Node*next;
    Node(int x){
        data = x;
        next=NULL;
    }
};

struct LinkedList{
    Node*head = NULL;
    Node*tail = NULL;
    void push_front(int val){
        Node*node = new Node(val);
        if (head == NULL){
            head = tail =  node;
        }
        else{
           tail -> next = node;
           tail = node;
        }
    }
    
    void check(int a, int n){
        Node*cur = head;
        int find = 99999, pos;
        for(int i=0; i<n; i++){
            if(find > abs(a - cur -> data)){
                find = abs(a - cur -> data);
                pos = i;
            }
            cur = cur -> next;
        }

        cout << pos;

    }

    
};

int main(){
    LinkedList ll;
    int n; cin>>n;
    for (int i=0; i<n; i++){ 
        int a; cin>>a;
        ll.push_front(a);
    }
    int num; cin >> num;
    ll.check(num, n);
}