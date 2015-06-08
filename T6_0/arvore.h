struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

void insere_arvore(Arv* a, int n);
int arv_vazia(Arv* a);
void em_ordem(Arv *a);
void pos_ordem(Arv *a);
void pre_ordem(Arv *a);
Arv* libera(Arv* a);
