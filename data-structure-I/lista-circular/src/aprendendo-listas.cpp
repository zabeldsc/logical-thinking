#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    struct Nodo *prox;
};

void inserirInicio(Nodo **lista, int valor)
{
    Nodo *novo = new Nodo();
    if (novo == nullptr)
        return;

    novo->info = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserirFim(Nodo **lista, int valor)
{
    Nodo *aux, *novo = new Nodo(); /* Atenção: apenas novo está sendo alocado com new! */

    if (novo == nullptr)
        return;

    novo->info = valor;
    novo->prox = nullptr;

    if (*lista == nullptr)
        *lista = novo; /* Lembre-se que lista aponta sempre para o primeiro elemento! */
    else
    {
        aux = *lista;
        while (aux->prox != nullptr)
            aux = aux->prox;

        aux->prox = novo;
    }
}

void inserirMeio(Nodo **lista, int valor, int ant)
{
    Nodo *aux, *novo = new Nodo();

    if (novo == nullptr)
        return;

    novo->info = valor;

    if (*lista == nullptr)
    {
        novo->prox = nullptr;
        *lista = novo;
    }
    else
    {
        aux = *lista;
        while (aux->info != ant && aux->prox != nullptr)
            aux = aux->prox;

        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void inserirOrdenado(Nodo **lista, int valor)
{
    Nodo *aux, *novo = new Nodo();

    if (novo == nullptr)
        return;

    novo->info = valor;

    /* Se a lista estiver vazia ou se o valor for menor do que o primeiro elemento */
    if (*lista == nullptr || valor < (*lista)->info)
    {
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        aux = *lista;
        while (aux->prox != nullptr && valor > aux->prox->info)
            aux = aux->prox;

        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void remover(Nodo **lista, int valor)
{
    if (*lista == nullptr)
        return;

    Nodo *aux, *lixo = nullptr;

    if ((*lista)->info == valor)
    {
        lixo = *lista;
        *lista = (*lista)->prox;
    }
    else
    {
        aux = *lista;

        while (aux->prox != nullptr && aux->prox->info != valor)
            aux = aux->prox;

        if (aux->prox != nullptr)
        {
            lixo = aux->prox;
            aux->prox = aux->prox->prox;
        }
    }

    delete lixo;
}

void buscar(Nodo *lista, int valor)
{
    Nodo *aux = lista;

    while (aux != nullptr && aux->info != valor)
        aux = aux->prox;

    if (aux != nullptr)
        cout << "Existe na lista\n";
    else
        cout << "Valor não existe na lista\n";
}

void juntarListas(Nodo **listaA, Nodo **listaB, Nodo **listaC)
{
    Nodo *auxAB;

    auxAB = *listaA;
    while (auxAB != nullptr)
    {
        Nodo *novo = new Nodo();
        novo->info = auxAB->info;
        novo->prox = *listaC;
        *listaC = novo;
        auxAB = auxAB->prox;
    }

    auxAB = *listaB;
    while (auxAB != nullptr)
    {
        Nodo *novo = new Nodo();
        novo->info = auxAB->info;
        novo->prox = *listaC;
        *listaC = novo;
        auxAB = auxAB->prox;
    }
}

void separarParImpar(Nodo **lista, Nodo **listaPar, Nodo **listaImpar)
{
    Nodo *aux = *lista;

    while (aux != nullptr)
    {
        Nodo *numero = new Nodo();
        numero->info = aux->info;

        if (aux->info % 2 == 0)
        {
            numero->prox = *listaPar;
            *listaPar = numero;
        }
        else
        {
            numero->prox = *listaImpar;
            *listaImpar = numero;
        }
        aux = aux->prox;
    }
}

void removerIguais(Nodo **lista, Nodo *listaComparar)
{
    while (listaComparar != nullptr)
    {
        while (*lista != nullptr && (*lista)->info == listaComparar->info)
        {
            Nodo *lixo = *lista;
            *lista = (*lista)->prox;
            delete lixo;
        }

        Nodo *aux = *lista;

        while (aux != nullptr && aux->prox != nullptr)
        {
            if (aux->prox->info == listaComparar->info)
            {
                Nodo *lixo = aux->prox;
                aux->prox = aux->prox->prox;
                delete lixo;
            }
            else
            {
                aux = aux->prox;
            }
        }
        listaComparar = listaComparar->prox;
    }
}

void imprimirLista(Nodo *lista)
{
    while (lista != nullptr)
    {
        cout << lista->info << " ";
        lista = lista->prox;
    }
}

int main()
{
    Nodo *lista = nullptr;
    int opcao;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir no início\n";
        cout << "2 - Inserir no meio\n";
        cout << "3 - Inserir no fim\n";
        cout << "4 - Inserir ordenado\n";
        cout << "5 - Remover\n";
        cout << "6 - Buscar\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int valor;
            cout << "Digite o valor para inserir no início: ";
            cin >> valor;
            inserirInicio(&lista, valor);
            break;
        }

        case 2:
        {
            int valor, ant;
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            cout << "Digite o valor anterior ao ponto de inserção: ";
            cin >> ant;
            inserirMeio(&lista, valor, ant);
            break;
        }

        case 3:
        {
            int valor;
            cout << "Digite o valor para inserir no fim: ";
            cin >> valor;
            inserirFim(&lista, valor);
            break;
        }

        case 4:
        {
            int valor;
            cout << "Digite o valor para inserir ordenado: ";
            cin >> valor;
            inserirOrdenado(&lista, valor);
            break;
        }

        case 5:
        {
            int valor;
            cout << "Digite o valor para remover: ";
            cin >> valor;
            remover(&lista, valor);
            break;
        }

        case 6:
        {
            int valor;
            cout << "Digite o valor para buscar: ";
            cin >> valor;
            buscar(lista, valor);
            break;
        }

        case 0:
            cout << "Encerrando o programa.\n";
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }

        if (opcao != 0)
        {
            cout << "\n--- Lista Atual ---\n";
            imprimirLista(lista);
        }

    } while (opcao != 0);

    return 0;
}
