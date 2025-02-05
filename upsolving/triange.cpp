#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int checklengthright(Node *root) {
    if (root->right != NULL)
        return 1 + checklengthright(root->right);
    else return 0;
}

int checklengthleft(Node *root) {
    if (root->left != NULL)
        return 1 + checklengthleft(root->left);
    else return 0;
}

int dfs (Node *root, int cnt, vector <int>& v) {
    if (root == NULL)
		return 0;
	int deep = min(checklengthleft(root), checklengthright(root));
    while (deep >= 1)
	    v[deep--]++;
	
    // if (root->left != NULL && root->right != NULL) {
    //     v[++cnt]++;
    //     cnt = dfs(root->left, cnt, v);
    //     cnt = dfs(root->right, cnt, v);
    // }
	cnt = dfs(root->left, cnt + 1, v);
	cnt = dfs(root->right, cnt + 1, v);
    return cnt;
}

int main () {
    int n; cin >> n;
    Node *root = NULL;
    Node *current = root;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (root == NULL) {
            root = add(root, x);
        }
        else {
            add(root, x);
        }
    }
    // cout << checklengthleft(root) << " ";
    // cout << checklengthright(root) << "\n";
    vector <int> v(100000);
    dfs(root, 0, v);
    for (int i = 1; i < n; i++) {
        cout << v[i] << " ";
    }
}