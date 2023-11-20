#include <iostream>
#include <queue>
using namespace std;
class AVL
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(0) {}
    };

    Node *root;

public:
    AVL() : root(nullptr) {}
    ~AVL()
    {
        clear(root);
    }

    void Insert(int value)
    {
        root = insert(root, value);
    }

    void inorderTraversal()
    {
        inorder(root);
        cout << endl;
    }

    int calBalanceFactor(){
        return getBalanceFactor(root);
    }

private:

    int getBalanceFactor(Node *node){
        if (node == NULL)
            return 0;
        return cal_height(node->left)-cal_height(node->right);
    }

    int cal_height(Node *node){
        if (node == nullptr)
            return -1;
        int leftHeight = cal_height(node->left);
        int rightHeight = cal_height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    Node *rightRotate(Node *node_y){

        Node *node_x = node_y->left;
        Node *T = node_x->right;

        node_x->right = node_y;
        node_y->left = T;

        node_y->height = max(cal_height(node_y->left),cal_height(node_y->right)) + 1;
        node_x->height = max(cal_height(node_x->left),cal_height(node_x->right)) + 1;
        return node_x;
    }

    Node *leftRotate(Node *node_x){

        Node *node_y = node_x->right;
        Node *T = node_y->left;

        node_y->left = node_x;
        node_x->right = T;

        node_x->height = max(cal_height(node_x->left),cal_height(node_x->right)) + 1;
        node_y->height = max(cal_height(node_y->left),cal_height(node_y->right)) + 1;
        return node_y;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        node->height = 1 + max(cal_height(node->left),cal_height(node->right));
        int nodeBalance=getBalanceFactor(node);

        if (nodeBalance > 1 && value < node->left->data)    //LL Rotation
            return rightRotate(node);

        if (nodeBalance < -1 && value > node->right->data)  //RR Rotation
            return leftRotate(node);
        
        if (nodeBalance < -1 && value < node->right->data)  //RL Rotation
        { 
            node->right = rightRotate(node->right); 
            return leftRotate(node); 
        }
        
        return node;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void clear(Node *node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

int main()
{
    AVL tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.inorderTraversal();
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(10);
    tree.inorderTraversal();
    tree.Insert(8);
    tree.Insert(7);
    tree.Insert(9);
    tree.inorderTraversal();

    return 0;
}