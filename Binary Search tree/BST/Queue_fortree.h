#ifndef queyeu
#define queyeu
#define max 40

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int front;
int rear;

struct node *Insert(struct node *a,int b);
int Search(struct node *d,int s);
int findmax(struct node *c);
int findmin(struct node *b);
struct node *getnode(int c);
int recfindmin(struct node *j); //recursive method(rec).
int recfindmax(struct node *h);
int maxv(int a,int b);
int findheight(struct node *g);
void levelOrder(struct node *t);
void preorder(struct node *i);
void inorder(struct node *l);
void postorder(struct node *q);
int isBStree(struct node *rt);

struct node *A[max];
int isempty();
int isfull();
void enqueue(struct node *a);
struct node *dequeue();
struct node *fron();
#endif