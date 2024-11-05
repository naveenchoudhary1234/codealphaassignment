/// Binry serach Tree
// left subtree m sare element chote hne root element s 
// right subtree m msare element bde honge root elemnt s
#include <iostream>
#include <queue>
using namespace std;

/// Creation of binary tree
// inorder of a BST is always sorted
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertintoroot(Node* root, int data) {
    /// For the first node
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Else, insert recursively
    if (data > root->data) {
        root->right = insertintoroot(root->right, data);
    } else {
        root->left = insertintoroot(root->left, data);
    }
    return root;
}

Node* createBST(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertintoroot(root, data);
        cin >> data; // yha ye new value deta rhega jb tk data not equal to -1 nhi hojata hain
    }
    return root;
}
Node*bstfrominorder(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int elem=inorder[mid];
    Node*root=new Node(elem);
    root->left=bstfrominorder(inorder,s,mid-1);
    root->right=bstfrominorder(inorder,mid+1,e);
    return root;
}

void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node*root){
    if(root==NULL) return;
    // nlr
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node*root){
    if(root==NULL) return;
    // lnr
    inorder(root->left);
    cout<<root->data<<" ";

    inorder(root->right);
}
void postorder(Node*root){
    if(root==NULL) return;
    // lrn
    postorder(root->left);

    postorder(root->right);
    cout<<root->data<<" ";
}


Node* minvalue(Node*root){
    if(root==NULL){
       cout<<"no min";
       return NULL;
    } 
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


Node* maxvalue(Node*root){
    if(root==NULL){
       cout<<"no max";
       return NULL;
    } 
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

bool searchinBST(Node*root,int target){
    if(root==NULL){
        return false;
    }
    
    if(root->data==target){
        return true;
    }
    bool leftans=false;
    bool rightans=false;
    
    if(target>root->data){
        rightans=searchinBST(root->right,target);
    }
    else{
        leftans=searchinBST(root->left,target);
    }
    return leftans||rightans;
}
Node*deletefromBST(Node*root,int target){
    // target ko dhundo
    // aur delete kro
    if(root==NULL) return NULL;
    if(target==root->data){
        // ab delete krenge
        // 4 cases
        
        // case1
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        // left non null right null
        if(root->left!=NULL && root->right==NULL){
            Node*childsubtree=root->left;
            delete root;
            return childsubtree;
        }
        
        // case 3 left null right non null
        if(root->left==NULL && root->right!=NULL){
            Node*childsubtree=root->right;
            delete root;
            return childsubtree;
        }
        
        /// case 4 when both are not null
        if(root->left!=NULL && root->right!=NULL){
            // step1 find the max element from left subtree
           Node*maxl= maxvalue(root->left);
           /// replacement
           root->data=maxl->data;
           
           // delete actual maxi node
           root->left=deletefromBST(root->left,maxl->data);  // imp step
           return root;
        }
        
    }
    else if(target>root->data){
        // right m jao
       root->right= deletefromBST(root->right,target);
    }
    else{
       root->left= deletefromBST(root->left,target);
    }
    return root;
}
Node*bstfrominorder(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int elem=inorder[mid];
    Node*root=new Node(elem);
    root->left=bstfrominorder(inorder,s,mid-1);
    root->right=bstfrominorder(inorder,mid+1,e);
    return root;
}

int main() {
    Node* root = NULL;
    createBST(root);

    levelorder(root);
    cout<<"inorder:";
    inorder(root);
    cout<<endl;
    
    cout<<"preorder:";
    preorder(root);
    cout<<endl;
    
    cout<<"postorder:";
    postorder(root);
    cout<<endl;
    
    
    Node*minimumvalue=minvalue(root);
    if(minimumvalue==NULL){
        cout<<"no vlaue";
    }
    else{
        cout<<minimumvalue->data;
    }
    
    Node*maximumvalue=maxvalue(root);
    if(maximumvalue==NULL){
        cout<<"np such vaue";
    }
    else{
        cout<<maximumvalue->data;
    }
    
    int target;
    cin>>target;
    while(target!=-1){
        bool ans=searchinBST(root,target);
        if(ans==true){
            cout<<"found";
        }
        else{
            cout<<"not found";
        }
        
        cin>>target;
    }


    int target;
    cin>>target;
    
    while(target!=-1){
        root=deletefromBST(root,target);
        levelorder(root);
        cin>>target;
    }

    return 0;
}
