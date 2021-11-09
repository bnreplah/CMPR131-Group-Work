// Name: prof Q
// Date: 11-3-2021
// Description: binary tree node for growing a tree

#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class Item>
class binary_tree_node
{
private:
    /// Any C++ data type
    Item data;
    // Left child node
    binary_tree_node* left;
    // Right child node
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data = init_data;
        left = init_left;
        right = init_right;
    }

    /// Precondition: Tree object must be initialized and must have data stored in the node
    /// Postcondition: Will return the data with in the node
    Item& getData()
    {
        return data;
    }

    /// Precondition: Tree object must be initialized and must have left child
    /// Postcondition: returns the reference to the left child pointer node
    binary_tree_node*& getLeft()
    {
        return left;
    }

    /// Precondition: Tree object must be initialized and must have right child
    /// Postcondition: returns the reference to the right child pointer node
    binary_tree_node*& getRight()
    {
        return right;
    }

    /// Precondition: Tree object must be initialized and node must be initialized
    /// Postcondition: Will store the new data in the node
    void setData(const Item& new_data)
    {
        data = new_data;
    }

    /// Precondition: Tree object must be initialized 
    /// Postcondition: Will place a left node to the parent node
    void setLeft(binary_tree_node* new_left)
    {
        left = new_left;
    }

    /// Precondition: Tree object must be initialized 
    /// Postcondition: Will place a right node to the parent node
    void setRight(binary_tree_node* new_right)
    {
        right = new_right;
    }

    /// Const
    /// Precondition: Tree object must be initialized and must have data stored in the node
    /// Postcondition: Will return the data with in the node
    const Item& getData() const
    {
        return data;
    }

    /// Const
    /// Precondition: Tree object must be initialized and must have left child
    /// Postcondition: returns the reference to the left child pointer node
    const binary_tree_node* getLeft() const
    {
        return left;
    }

    /// Const
    /// Precondition: Tree object must be initialized and must have right child
    /// Postcondition: returns the reference to the right child pointer node
    const binary_tree_node* getRight() const
    {
        return right;
    }

    /// Const
    /// Precondition: Tree object must be initialized
    /// Postcondition: If the child nodes left and right are null, then will return true, else will return false
    bool isLeaf() const
    {
        return (left == NULL && right == NULL);
    }

};

/// Precondition: Tree object must be initialized
/// Postcondition: Using recursion will delete all the nodes from the Tree object
template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
    if (leaf == NULL)
        return;

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;

}

/// Precondition: Tree object must be initialized
/// Postcondition: Will output the all the nodes of the tree object and graphically showing how they are connected
template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196)); // will print └
                else
                    cout << char(195) << string(3, char(196)); // will print ├
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196)); // will print └
                else
                    cout << char(195) << string(3, char(196)); // will print ├
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        
        // Recursion is applied
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false,true);
    }
}