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
void printInOrderTree(No *ptr);
void printPreOrderTree(No *ptr);
void printPostOrderTree(No *ptr);
void removeNoTree(Tree *t, int id);
No* searchNoTree(Tree *t, int id);
int heightTree(No *ptr);

void updateFB(No *ptr);
void verificar(No *ptr);

void rotacaoDireita(Tree *t, No *ptr);
