struct Nodo
{
    int info;
    Nodo *ant;
    Nodo *prox;
};

void inserirNo(Nodo **lista, int valor)
{
    Nodo *aux, *novo = new Nodo();
    if (novo == nullptr)
        return;

    novo->info = valor;
    novo->ant = nullptr;

    if (*lista != nullptr)
    {
        novo->prox = *lista;
        (*lista)->ant = novo;
    }
    else
    {
        novo->prox = nullptr;
    }

    *lista = novo;
}

int main()
{
}