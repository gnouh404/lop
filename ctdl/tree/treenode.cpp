#include <bits/stdc++.h>
#ifndef __treenode__cpp__
#define __treenode__cpp__
using namespace std;
template <class T>
class TreeNode
{
    T data;
    TreeNode *Parent;
    list<TreeNode*> children;

public:
    TreeNode() {}
    TreeNode(T data, TreeNode<T> *N = NULL)
    {
        this->data = data;
        Parent = N;
    }
    TreeNode<T> *&getParent()
    {
        return Parent;
    }
    void setParent(TreeNode<T> *Parent)
    {
        this->Parent = Parent;
    }
    TreeNode *getChild(int index)
    {
        if (index < 0 || index >= children.size())
        {
            return NULL;
        }
        auto it = children.begin();
        // sử dụng hàm advance() để di chuyển iterator đến vị trí index
        advance(it, index);
        return *it;
    }
    list<TreeNode *> getChild()
    {
        return children;
    }
    T &getdata()
    {
        return data;
    }
    void setdata(T data)
    {
        this->data = data;
    }
    int size()
    {
        int size = 1; // Tính cả nút hiện tại
        for (TreeNode *child : children)
        {
            size += child->size();
        }
        return size;
    }
    
};
// class GeneralTree
// {
//     TreeNode<T> *root;

// public:
//     GeneralTree(T rootdata)
//     {
//         root = new TreeNode(rootdata);
//     }

//     TreeNode *root()
//     {
//         return root;
//     }

//     int size()
//     {
//         return root->size();
//     }

//     bool isEmpty()
//     {
//         return root == NULL;
//     }

//     // kiểm tra xem một nút có phải là nút nội bộ hay không
//     bool isInternal(TreeNode<T> *node)
//     {
//         return !node->getChild().empty();
//     }

//     // kiểm tra xem một nút có phải là nút lá hay không
//     bool isExternal(TreeNode<T> *node)
//     {
//         return node->getChild().empty();
//     }

//     bool isRoot(TreeNode<T> *node)
//     {
//         return node->getParent() == NULL;
//     }

//     void preOrder(TreeNode<T> *node)
//     {
//         if (node == NULL)
//             return;
//         cout << node->getdata() << " ";
//         for (TreeNode *child : node->getChild())
//         {
//             preOrder(child);
//         }
//     }

//     void inOrder(TreeNode<T> *node)
//     {
//         if (node == NULL)
//             return;
//         auto it = node->getChild().begin();
//         if (it != node->getChild().end())
//         {
//             inOrder(*it); // Duyệt qua nút con đầu tiên
//             ++it;
//         }
//         cout << node->getdata() << " "; // Xử lý nút hiện tại
//         while (it != node->getChild().end())
//         {
//             inOrder(*it);
//             ++it;
//         }
//     }

//     void postOrder(TreeNode<T> *node)
//     {
//         if (node == NULL)
//             return;
//         for (TreeNode *child : node->getChild())
//         {
//             postOrder(child);
//         }
//         cout << node->getdata() << " ";
//     }
//     void insert(TreeNode<T> *node)
//     {
//         this->root
//     }
// };
#endif