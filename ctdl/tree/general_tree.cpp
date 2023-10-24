#include "treenode.cpp"
#ifndef __generaltree__cpp__
#define __generaltree__cpp__
using namespace std;
template <class T>
class GeneralTree
{
    TreeNode<T> *root;
    int num;
public:
    GeneralTree(T rootdata)
    {
        root = new TreeNode(rootdata);
        num = 1;
    }
    void addChild(TreeNode<T>* parent, TreeNode<T>* child) {
        child->setParent(parent);
        parent->getChild().push_back(child);
        
    }
    TreeNode<T>* getroot()
    {
        return root;
    }

    int size()
    {
        return num;
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    // kiểm tra xem một nút có phải là nút nội bộ hay không
    bool isInternal(TreeNode<T> *node)
    {
        return !node->getChild().empty();
    }

    // kiểm tra xem một nút có phải là nút lá hay không
    bool isExternal(TreeNode<T> *node)
    {
        return node->getChild().empty();
    }

    bool isRoot(TreeNode<T> *node)
    {
        return node->getParent() == NULL;
    }

    void preOrder(TreeNode<T> *node)
    {
        if (node == NULL)
            return;
        cout << node->getdata() << " ";
        for (TreeNode<T> *child : node->getChild())
        {
            preOrder(child);
        }
    }

    void inOrder(TreeNode<T>* node)
    {
        if (node == NULL)
            return;
        auto it = node->getChild().begin();
        if (it != node->getChild().end())
        {
            inOrder(*it); // Duyệt qua nút con đầu tiên
            ++it;
        }
        cout << node->getdata() << " "; // Xử lý nút hiện tại
        while (it != node->getChild().end())
        {
            inOrder(*it);
            ++it;
        }
    }

    void postOrder(TreeNode<T> *node)
    {
        if (node == NULL)
            return;
        for (TreeNode<T> *child : node->getChild())
        {
            postOrder(child);
        }
        cout << node->getdata() << " ";
    }
    // void insert(TreeNode<T> *node)
    // {
    //     this->root().
    // }
};
#endif
