typedef struct no No;
struct no{
    int id;
    No *right;
    No *left;
};

typedef struct tree Tree;
struct tree{
    No *root;
};

Tree* initTree();
No* mallocNo(int id);
void insertTree(Tree *t, No *n);
void printInOrderTree(No *ptr);
void printPreOrderTree(No *ptr);
void printPostOrderTree(No *ptr);
void removeNoTree(Tree *t, int id);
void searchNoTree(Tree *t, int id);
