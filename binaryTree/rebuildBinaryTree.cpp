#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

typedef struct BinaryTreeNode
{
    int             _data;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;

    BinaryTreeNode(int data)
        :_data(data)
         ,_left(NULL)
         ,_right(NULL)
    {}
}BinaryTreeNode;



void InOrderBinaryTree(BinaryTreeNode * root)
{
    if(root == NULL)
        return;
    InOrderBinaryTree(root->_left);
    cout<<root->_data<<"  ";
    InOrderBinaryTree(root->_right);
}


void PreOrderBinaryTree(BinaryTreeNode * root)
{
    if(root == NULL)
        return;
    cout<<root->_data<<"  ";
    PreOrderBinaryTree(root->_left);
    PreOrderBinaryTree(root->_right);
}




void rebuild(BinaryTreeNode* &root, const vector<int> &preArr, const vector<int> &inArr)
{
    if(preArr.size() == 0)
        return;
    root = new BinaryTreeNode(preArr[0]);

    vector<int>::const_iterator it = find(inArr.begin(), inArr.end(), preArr[0]);
    assert(it != inArr.end());
    vector<int> inArr_L(inArr.begin(), it);
    vector<int> inArr_R(it+1, inArr.end());

    vector<int>::const_iterator it1 = preArr.begin()+1;
    vector<int> preArr_L(it1,it1+inArr_L.size());
    vector<int> preArr_R(it1+inArr_L.size(), preArr.end());

    rebuild(root->_left, preArr_L, inArr_L);
    rebuild(root->_right, preArr_R, inArr_R);

}


int main()
{
    int size = 0;
    cout<<"Please enter size:  ";
    cin>>size;
    vector<int> preArr(size);
    vector<int> inArr(size);

    cout<<"Please enter preOrder :";
    for(int i = 0; i < size; i++)
    {
        cin>>preArr[i];
    }

    cout<<"Please enter inOrder :";
    for(int i = 0; i < size;i++)
    {
        cin>>inArr[i];
    }



    BinaryTreeNode* root = NULL;
    rebuild(root, preArr , inArr);

    cout<<"preOrder: ";
    PreOrderBinaryTree(root);
    cout<<endl<<"inOrder:  ";
    InOrderBinaryTree (root);

    return 0;
}
