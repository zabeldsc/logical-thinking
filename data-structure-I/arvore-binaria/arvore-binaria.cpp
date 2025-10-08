#include <iostream>

using namespace std;

typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

Arvore *inserir(Arvore *raiz, int valor)
{
    if (raiz == nullptr)
    {
        Arvore *novo = new Arvore();
        novo->info = valor;
        novo->dir = nullptr;
        novo->esq = nullptr;
        return novo;
    }
    else
    {
        if (valor < raiz->info)
        {
            raiz->esq = inserir(raiz->esq, valor);
        }
        else if (valor > raiz->info)
        {
            raiz->dir = inserir(raiz->dir, valor);
        }

        return raiz;
    }
}

void remover(Arvore *raiz, int valor)
{
}

void imprimir(Arvore *raiz)
{
    if (raiz == nullptr)
        return;

    imprimir(raiz->esq);
    cout << raiz->info << std::endl;
    imprimir(raiz->dir);
}

int main()
{
    Arvore *raiz = nullptr;
    int opcao;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Buscar\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int valor;
            cout << "Digite o valor para inserir: ";
            cin >> valor;
            raiz = inserir(raiz, valor);
            break;
        }

        case 2:
        {
            int valor, ant;
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            cout << "Digite o valor para remover: ";
            cin >> ant;
            remover(raiz, valor);
            break;
        }

        case 3:
        {
            // int valor;
            // cout << "Digite o valor para inserir no fim: ";
            // cin >> valor;
            // inserirFim(&lista, valor);
            // break;
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
            imprimir(raiz);
        }

    } while (opcao != 0);

    return 0;
}