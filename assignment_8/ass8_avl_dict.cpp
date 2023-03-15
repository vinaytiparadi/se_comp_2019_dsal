#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string word, meaning;
    int ht;
    Node *left;
    Node *right;
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    void create();
    void display(Node *);
    void displayAscending(Node *);
    void displayPre(Node *);
    void displayDescending(Node *);

    void recursivePreorder(Node *);

    int search(Node *, string);
    int update(Node *, string);
    Node *deleteNode(Node *, string);
    Node *insert(Node *, string, string);
    int balanceFactor(Node *);
    int height(Node *);
    Node *LL(Node *);
    Node *RR(Node *);
    Node *LR(Node *);
    Node *RL(Node *);
    Node *rotateLeft(Node *);
    Node *rotateRight(Node *);
};

void AVL::create(){
    char ch;

    do
    {
        Node * temp = new Node;
        cout << "\nEnter Keyword: ";
        cin >> temp->word;
        cout << "\nEnter Meaning: ";
        cin >> temp->meaning;

        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp->word, temp->meaning);
        }
        cout<<"\nDo you want to continue? (Y/N) ";
        cin>>ch;
    } while (ch == 'Y' || ch == 'y');
}

void AVL :: recursivePreorder(Node *root){
    if(root!=NULL){
        cout<<root->word<<" ";
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}

void AVL :: display(Node *root){
     char ch;
    int op;

    do
    {
        cout<<"\n^^^^^^Display Operations ^^^^^^";
        cout<<"\n1 . Ascending order \n2 . Descending order";
        cout<<"\nEnter your choice: ";
        cin>>op;

        switch (op)
        {
        case 1:
            displayAscending(root);
            break;
        case 2:
            displayDescending(root);
            break;
        default:
            cout<<"Invalid option.";
            break;
        }
        cout<<"\nDo you want to continue? (Y/N) ";
        cin>>ch;
    } while (ch=='y' || ch=='Y');
}

void AVL::displayAscending(Node *root){
    if (root != NULL){
        displayAscending(root->left);
        cout << "\n Key Word: " << root->word;
        cout << "\t Meaning: " << root->meaning;
        displayAscending(root->right);
    }
}
void AVL::displayPre(Node *root){
    if (root != NULL){
        cout << "\n Key Word: " << root->word;
        cout << "\t Meaning: " << root->meaning;
        displayPre(root->left);
        displayPre(root->right);
    }
}

void AVL :: displayDescending(Node *root){
    if(root !=NULL){
        displayDescending(root->right);
        cout << "\n Key Word: " << root->word;
        cout << "\t Meaning: " << root->meaning;
        displayDescending(root->left);
    }
}


int AVL ::height(Node *temp)
{
    int LH = 0, RH = 0;
    if (temp == NULL)
    {
        return 0;
    }
    LH = (temp->left == NULL) ? 0 : 1 + (temp->left->ht);
    LH = (temp->right == NULL) ? 0 : 1 + (temp->right->ht);

    return max(LH, RH);
}

int AVL ::balanceFactor(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return (height(root->left) - height(root->right));
    }
}

Node *AVL ::LL(Node *T)
{
    T = rotateRight(T);
    return T;
}

Node *AVL ::RR(Node *T)
{
    T = rotateLeft(T);
    return T;
}

Node *AVL ::LR(Node *T)
{
    T->left = rotateLeft(T->left);
    T = rotateRight(T);
    return T;
}

Node *AVL ::RL(Node *T)
{
    T->right = rotateRight(T->right);
    T = rotateLeft(T);
    return T;
}

Node *AVL ::rotateLeft(Node *parent)
{
    Node *temp;
    temp = parent->right;
    temp->left = parent;
    parent->ht = height(parent);
    temp->ht = height(temp);
    return temp;
}

Node *AVL ::rotateRight(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = NULL;
    temp->right = parent;
    parent->ht = height(parent);
    temp->ht = height(temp);
    return temp;
}

Node *AVL ::insert(Node *root, string w, string m)
{
    if (root == NULL)
    {
        Node *temp = new Node;
        temp->word = w;
        temp->meaning = m;
        temp->left = NULL;
        temp->right = NULL;
        temp->ht = 1;
        root = temp;
    }
    else if (w.compare(root->word) < 0)
    {
        root->left = insert(root->left, w, m);
        if (balanceFactor(root) == 2)
        {
            root = ( w.compare(root->left->word) <0)  ? LL(root) : LR(root);
        }
    }
    else
    {
        root->right = insert(root->right,w,m);
        if(balanceFactor(root)==2){
            root=( w.compare(root->right->word) > 0 ) ? RR(root) : RL(root);
        }
    }

    root->ht = height(root);
    return root;
}

int AVL ::search(Node *root, string w){
    int c = 0;
    while (root != NULL){
        c++;

        if(w.compare(root->word)==0){
            cout << "\nNo of Comparisons:" << c;
            return 1;
        }
        if(w.compare(root->word)<0){
            root = root->left;
        }
        if(w.compare(root->word)>0){
            root = root->right;
        }
    }
    return -1;
}


int AVL ::update(Node *root, string w){
    while (root != NULL){
        if (w.compare(root->word)==0){
            cout << "\nEnter New Meaning of Keyword " << root->word<< " ";
            cin >> root->meaning;
            return 1;
        }
        if (w.compare(root->word) < 0)
            root = root->left;
        if (w.compare(root->word) > 0)
            root = root->right;
    }
    return -1;
}

Node * AVL::deleteNode(Node *temp, string w){
    if(temp==NULL) return NULL;
    else{

        if(w.compare(temp->word)>0){
            temp->right=deleteNode(temp->right, w);
            if(balanceFactor(temp)==2){
                temp = ( balanceFactor(temp->left) >=0 ) ? LL(temp) : LR(temp);
            }
        }

        else{
            if(w.compare(temp->word)<0){
                temp->left =deleteNode(temp->left,w);
                if( balanceFactor(temp) == -2){
                    temp = (balanceFactor(temp->right)<=0) ? RR(temp) : RL(temp);
                }
            }
            else{
                if(temp->right !=NULL){
                    Node *temp1;
                    temp1 = temp->right;
                    
                    while(temp1->left != NULL)
                        temp1 = temp1->left;
                    
                    temp->word = temp1->word;
                    temp->right = deleteNode(temp->right, temp1->word);

                    if(balanceFactor(temp)==2)
                        temp = (balanceFactor(temp->left)>= 0) ? LL(temp) : LR(temp);

                }
                else{
                    return temp->left;
                }
            }
        }

    }

    temp->ht =height(temp);
    return temp;
}

int main()
{
    
    int ch;
    char op;
    AVL d;
    d.root = NULL;

    do
    {
        cout << "\n^^^^^^^^^^^^^ MENU ^^^^^^^^^^^^^\n1 . Create\n2 . Display\n3 . Search\n4 . Update\n5 . Delete\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL){
                cout << "\nDictionary is Empty.";
            }
            else{
                d.display(d.root);
            }
            break;
        case 3:
            if (d.root == NULL){
                cout << "\nDictionary is Empty.";
            }
            else{
                cout << "\nEnter the Keyword that you want to search: ";
                string k;
                cin >> k;

                if (d.search(d.root, k) == 1)
                    cout << "\nKeyword Found";
                else if(d.search(d.root, k) == -1)
                    cout << "\nKeyword Not Found";
            }
            break;
        case 4:
            if (d.root == NULL){
                cout << "\nDictionary is Empty.";
            }
            else{
                cout << "\nEnter the Keyword whose meaning you want to update: ";
                string k;
                cin >> k;
                if (d.update(d.root, k) == 1)
                    cout << "\nMeaning Updated";
                else
                    cout << "\nKeyword Not Found";
            }
            break;
        case 5:
            if (d.root == NULL){
                cout << "\nDictionary is Empty.";
            }
            else
            {
                cout << "\nEnter Keyword which you want to delete: ";
                string k;
                cin >> k;
                if (d.root == NULL){
                    cout << "\nKeyword not found.";
                }
                else{
                    d.root = d.deleteNode(d.root, k);
                }
            }
            break;
        case 6: 
            d.displayPre(d.root);
            break;
        default:
            break;
        }
    cout<<"\nDo you want to visit main menu? (Y/N) ";
    cin>>op;
    } while (op == 'y' || op=='Y');

    return 0;
}