#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct leaf_t
{
    int key = -1;
    leaf_t* father = NULL;
    leaf_t* left = NULL;
    leaf_t* right = NULL;
};


int main()
{
    leaf_t* root = new leaf_t;
    leaf_t* root_father = new leaf_t;
    char option = 'a';
    int number;
    
    while (option != 'q')
    {
        scanf("%c", &option);
        leaf_t* current_leaf = root;
        leaf_t* leaf_to_add = new leaf_t;
        leaf_t* consequent = new leaf_t;
        leaf_t* father = new leaf_t;
        switch (option)
        {
        case '+':
        {
            cin >> number;
            leaf_to_add->key = number;
            while (true)
            {
                if (root->key == -1)
                {
                    current_leaf->key = number;
                    root_father->right = root;
                    root->father = root_father;
                    break;
                }
                else if (number > current_leaf->key)
                {
                    if (current_leaf->right != NULL)
                    {
                        current_leaf = current_leaf->right;
                    }
                    else
                    {
                        leaf_to_add->father = current_leaf;
                        current_leaf->right = leaf_to_add;
                        break;
                    }
                }
                else if (number < current_leaf->key)
                {
                    if (current_leaf->left != NULL)
                    {
                        current_leaf = current_leaf->left;
                    }
                    else
                    {
                        leaf_to_add->father = current_leaf;
                        current_leaf->left = leaf_to_add;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        break;

        case '-':
        {
            cin >> number;
            while (true)
            {
                if (number > current_leaf->key)
                {
                    if (current_leaf->right != NULL)
                    {
                        current_leaf = current_leaf->right;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (number < current_leaf->key)
                {
                    if (current_leaf->left != NULL)
                    {
                        current_leaf = current_leaf->left;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (number == current_leaf->key)
                {
                    if (current_leaf->right != NULL && current_leaf->left != NULL)
                    {
                        consequent = current_leaf->right;
                        while (consequent->left != NULL)
                        {
                            consequent = consequent->left;
                        }
                        consequent = consequent->father;
                        if (current_leaf == consequent)
                        {
                            current_leaf->key = current_leaf->right->key;
                            delete current_leaf->right;
                            current_leaf->right = NULL;
                        }
                        else
                        {
                            current_leaf->key = consequent->left->key;
                            delete consequent->left;
                            consequent->left = NULL;
                        }

                    }
                    else if (current_leaf->right == NULL && current_leaf->left != NULL)
                    {
                        current_leaf->left->father = current_leaf->father;
                        if (current_leaf->father->right == current_leaf)
                        {
                            if (current_leaf->right == NULL && current_leaf->left != NULL)
                                current_leaf->father->right = current_leaf->left;
                            else if (current_leaf->right != NULL)
                                current_leaf->father->right = current_leaf->right;

                            if (current_leaf == root)
                                root = current_leaf->right;
                        }
                        else if (current_leaf->father->left == current_leaf)
                        {
                            if (current_leaf->left == NULL && current_leaf->right != NULL)
                                current_leaf->father->left = current_leaf->right;
                            else if (current_leaf->left != NULL)
                                current_leaf->father->left = current_leaf->left;

                            if (current_leaf == root)
                                root = current_leaf->left;
                        }
                        delete current_leaf;
                    }
                    else if(current_leaf->right != NULL && current_leaf->left == NULL)
                    {
                        current_leaf->right->father = current_leaf->father;
                        if (current_leaf->father->right == current_leaf)
                        {
                            if (current_leaf->right == NULL && current_leaf->left != NULL)
                                current_leaf->father->right = current_leaf->left;
                            else if(current_leaf->right != NULL)
                                current_leaf->father->right = current_leaf->right;
                            
                            if (current_leaf == root)
                                root = current_leaf->right;
                        }
                        else if (current_leaf->father->left == current_leaf)
                        {
                            if (current_leaf->left == NULL && current_leaf->right != NULL)
                                current_leaf->father->left = current_leaf->right;
                            else if (current_leaf->left != NULL)
                                current_leaf->father->left = current_leaf->left;

                            if (current_leaf == root)
                                root = current_leaf->left;
                        }
                        delete current_leaf;
                    }
                    else if (current_leaf->right == NULL && current_leaf->left == NULL)
                    {
                        if (current_leaf->father->right == current_leaf)
                        {
                            current_leaf = current_leaf->father;
                            delete current_leaf->right;
                            current_leaf->right = NULL;
                        }
                        else if (current_leaf->father->left == current_leaf)
                        {
                            current_leaf = current_leaf->father;
                            delete current_leaf->left;
                            current_leaf->left = NULL;
                        }
                    }
                    break;
                }
            }
        }
        break;

        case 'm':
        {
            while (true)
            {
                if(current_leaf->left == NULL)
                {
                    cout << current_leaf->key << endl;
                    break;
                }
                else
                {
                    current_leaf = current_leaf->left;
                }
            }
        }
        break;

        case 'M':
        {
            while (true)
            {
                if (current_leaf->right == NULL)
                {
                    cout << current_leaf->key << endl;
                    break;
                }
                else
                {
                    current_leaf = current_leaf->right;
                }
            }
        }
        break;

        case '?':
        {
            cin >> number;
            while (true)
            {
                if (number > current_leaf->key)
                {
                    if (current_leaf->right != NULL)
                    {
                        current_leaf = current_leaf->right;
                    }
                    else
                    {
                        cout << "0" << endl;
                        break;
                    }
                }
                else if (number < current_leaf->key)
                {
                    if (current_leaf->left != NULL)
                    {
                        current_leaf = current_leaf->left;
                    }
                    else
                    {
                        cout << "0" << endl;
                        break;
                    }
                }
                else if (number == current_leaf->key)
                {
                    cout << "1" << endl;
                    break;
                }
            }
        }
        break;

        default:
            break;
        }
        leaf_to_add = NULL;
        consequent = NULL;
        father = NULL;
    }
    
    leaf_t* current_leaf = root;
    leaf_t* to_delete = NULL;
    while (root_father->right != NULL)
    {
        if (current_leaf->right != NULL)
        {
            current_leaf = current_leaf->right;
            continue;
        }

        if (current_leaf->left != NULL)
        {
            current_leaf = current_leaf->left;
            continue;
        }

        to_delete = current_leaf;
        current_leaf = current_leaf->father;
        if (current_leaf->right == to_delete)
            current_leaf->right = NULL;
        else if(current_leaf->left == to_delete)
            current_leaf->left = NULL;

        delete to_delete;
    }
    delete root_father;
}

