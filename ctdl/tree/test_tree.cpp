#include "general_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    GeneralTree<int> tree(1);

    TreeNode<int>* node2 = new TreeNode(2);
    TreeNode<int>* node3= new TreeNode(3);
    TreeNode<int>* node4=new TreeNode(4);
    TreeNode<int>* node5=new TreeNode(5);

    tree.addChild(tree.getroot(), node2);
    tree.addChild(tree.getroot(), node3);
    tree.addChild(node2, node4);
    tree.addChild(node2, node5);
    
    tree.size();
    

}