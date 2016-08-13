#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeBode
{
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


struct BinaryTreeNode* Construct(const vector<int> &preArr, const vector<int> &inArr)
{
    return NULL;
}

void InOrderBinaryTree(BinaryTreeNode * root)
{
    if(root == NULL)
        return;
    InOrderBinaryTree(root->m_pLeft);
    cout<<root->m_nValue<<"  ";
    InOrderBinaryTree(root->m_pRight);
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
    for(int i = 0; i < size; i++)
    {
        cin>>inArr[i];
    }

    BinaryTreeNode* ret = eConstruct (preArr , inArr);
    InOrderBinaryTree (ret);

    return 0;
}
