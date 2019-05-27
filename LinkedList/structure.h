typedef struct no No;
struct no{
    int id;
    No *prox;
};

typedef struct list List;
struct list{
    No *inicio;
    No *fim;
};

List* initList();
No* mallocNo(int id);
void insertEndList(List *ptr, No *n);
void insertBeginList(List *ptr, No *n);
void insertOrderList(List *l, No *n);
void removeList(List *l, int id);
void printList(List *l);
void searchList(List* l, int id);
void clearList(List *ptr);