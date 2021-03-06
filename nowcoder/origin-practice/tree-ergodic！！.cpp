//
// Created by 杨霖 on 2019/1/20.
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 26

typedef struct Node{
    char data;
    Node *lchild;
    Node *rchild;
}Node;
char pre[MAXSIZE], middle[MAXSIZE];
Node *BiTree;

// 建树
Node *buildTree(char *pre, char *mid, int length) {
    char rootKey = pre[0];
    Node* root = new Node;
    root->data = rootKey;
    root->lchild = root->rchild = NULL;
    if(length == 1 && pre[0] == mid[0])
        return root;

    // 核心部分，需要完全掌握
    char* rootMidOrder = mid;
    int rootIndex = 0;
    //---------------------------------------------------------------------------//
    /**
     * mid+length-1详解， 字符串加上数字功能类似于'截取字符串'从(length-1)的位置开始截取！！
     * 字符串比较在c++ 中直接使用逻辑运算符， 在c中使用 strcamp（）函数
     */
    //---------------------------------------------------------------------------//
    while(rootMidOrder[0] != rootKey)
    {
        ++rootMidOrder;
        ++rootIndex;
    }
    if(rootIndex > 0)
    {
        root->lchild = buildTree(pre+1, mid, rootIndex);
    }
    if(length-rootIndex-1 > 0)
    {
        root->rchild = buildTree(pre+rootIndex+1, rootMidOrder+1, length-rootIndex-1);
    }
    return root;
}
// 后续遍历
void backE(Node *BiTree) {
    if(BiTree) {
        backE(BiTree->lchild);
        backE(BiTree->rchild);
        printf("%c", BiTree->data);
    }
}

int main() {
    scanf("%s", pre);
    scanf("%s", middle);
    int length = strlen(pre);
    BiTree = buildTree(pre, middle, length);
    backE(BiTree);
    return 0;
}
