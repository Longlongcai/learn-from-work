#include<iostream>
using namespace std;

typedef struct BiTNode
{
    int value;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree *T)
{
    int num;
    cin >> num;
    if(num == -1)
    {
        *T = NULL;
    }
    else
    {
        *T = new BiTNode;
        (*T)->value = num;
        cout << "now is the left child." << num << endl;
        (void)CreateBiTree(&((*T)->lchild));
        cout << "below is the right child." << endl;
        (void)CreateBiTree(&((*T)->rchild));
    }

    return 1;
}

/*
void preorder(BiTree T)
{
    if(T == NULL)
        return;
    cout << T->value << endl;
    preorder(T->lchild);
    preorder(T->rchild);
}
*/

/*
void NRpreorder(BiTree T)
{
    BiTree s[10],p;
    int top;

    if(!T)
        return;

    top = 0;
    p = T;

    while(!((p==NULL)&&(top==0)))
    {
        while(p)
        {
            cout << p->value << endl;
            if(top < 10)
            {
                s[top] = p;
                top++;
            }
            else
            {
                cout << "overflow." << endl;
                return;
            }
            p = p->lchild;
        }

        if(top <= 0) return;
        else
        {
            top--;
            p = s[top];
            p = p->rchild;
        }
    }
}
*/

void levelorder(BiTree T)
{
    BiTree q[10];
    int front, rear;
    if (!T)
        return;
    front = -1;
    rear = 0;
    q[rear] = T;

    while(front != rear)
    {
        front++;
        cout << q[front]->value << endl;
        if(q[front]->lchild != NULL)
        {
            rear++;
            q[rear] = q[front]->lchild;
        }
        if(q[front]->rchild != NULL)
        {
            rear++;
            q[rear] = q[front]->rchild;
        }
    }
}

void destroy(BiTree *T)
{
    if(*T)
    {
        destroy(&((*T)->lchild));
        destroy(&((*T)->rchild));
        delete (*T);
        (*T) = NULL;
    }
}

int main()
{
    BiTree T;
    if(!CreateBiTree(&T))
    {
        cout << "create bitree faied." << endl;
        return -1;
    }

    levelorder(T);

    destroy(&T);

    return 0;
}
