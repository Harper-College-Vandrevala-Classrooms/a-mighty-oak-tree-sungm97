#include <iostream>
#include <string>

using namespace std;

class Squirrel 
{
private:
    string name;

public:
    Squirrel(string name) 
    {
        this->name = name;
    }

    string get_name() const 
    {
        return name;
    }
};

class Node {
private:
    Squirrel* squirrel;
    Node* leftChild;
    Node* rightChild;

public:
    Node(Squirrel* squirrel) : squirrel(squirrel), leftChild(nullptr), rightChild(nullptr) {}

    void set_left(Node* left) 
    {
        leftChild = left;
    }

    void set_right(Node* right) 
    {
        rightChild = right;
    }

    Node* left() const 
    {
        return leftChild;
    }

    Node* right() const 
    {
        return rightChild;
    }

    Squirrel* get_squirrel() const 
    {
        return squirrel;
    }
};

void pre_order_traversal(Node* node) 
{
    if (node == nullptr) {
        return;
    }

    cout << node->get_squirrel()->get_name() << " ";
    pre_order_traversal(node->left());
    pre_order_traversal(node->right());
}

int main() 
{
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    cout << "Pre-order traversal of the tree:" << endl;
    pre_order_traversal(&node_one);
    cout << endl;

    Node* retrieved_node_one = node_one.left();
    Node* retrieved_node_two = node_one.right();

    cout << "Right child of root: " << retrieved_node_two->get_squirrel()->get_name() << endl;
    cout << "Left child of root: " << retrieved_node_one->get_squirrel()->get_name() << endl;

    return 0;
}
