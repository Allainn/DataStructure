typedef struct no No;
struct no{
    int id;
    No *father;
    No *right;
    No *left;
    int fb;
};

typedef struct tree Tree;
struct tree{
    No *root;
};

Tree* initTree();
No* mallocNo(int id);
void insertTree(Tree *t, No *n);
void printInOrderTree(No *ptr, int i);
void printPreOrderTree(No *ptr);
void printPostOrderTree(No *ptr);
void removeNoTree(Tree *t, int id);
No* searchNoTree(Tree *t, int id);
int heightTree(No *ptr);
void clear(No *ptr);

void updateFB(Tree *t, No *ptr);
void verificar(No *ptr);

void rightRotation(Tree *t, No *ptr);
void leftRotation(Tree *t, No *ptr);
