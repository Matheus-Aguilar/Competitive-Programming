#include<bits/stdc++.h>

using namespace std;

struct Node{
    int v;
    Node * left, * right;
    Node(int v_): v(v_), left(NULL), right(NULL){}    
};

void add(Node *&root, int e){
    if(root == NULL)
        root = new Node(e);
    else if(root->v > e)
        add(root->left, e);
    else
        add(root->right, e);
}

void preOrder(Node *root){
    if(root == NULL) return;
    cout << " " << root->v;
    preOrder(root->left);
    preOrder(root->right);
}


void posOrder(Node *root){
    if(root == NULL) return;
    posOrder(root->left);
    posOrder(root->right);
    cout << " " << root->v;
}


void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << " " << root->v;
    inOrder(root->right);
}

int main(){
    int c, i = 0;
    cin >> c;
    while(i++ != c){
        cout << "Case " << i << ":\n";

        int n, e;
        cin >> n >> e;

        Node *root = new Node(e);

        while(--n){
            scanf("%d", &e);
            add(root, e);
        }

        cout << "Pre.:"; preOrder(root); cout << "\n";
        cout << "In..:"; inOrder(root); cout<< "\n";
        cout << "Post:"; posOrder(root); cout << "\n\n";
    }
}