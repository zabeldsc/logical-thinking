#include <iostream>

using namespace std;

struct No
{
    int valor;
    No *esq;
    No *dir;
};

struct Pilha
{
    int valor;
    Pilha *ultimo;
};

No *inserir(No *raiz, int valor)
{
    if (raiz == nullptr)
    {
        No *novo = new No();
        novo->valor = valor;
        novo->esq = nullptr;
        novo->dir = nullptr;
        return novo;
    }
    else
    {
        if (valor < raiz->valor)
        {
            raiz->esq = inserir(raiz->esq, valor);
        }
        else if (valor > raiz->valor)
        {
            raiz->dir = inserir(raiz->dir, valor);
        }

        return raiz;
    }
}

void emOrdem(No *raiz)
{
    if (raiz == nullptr)
        return;

    emOrdem(raiz->esq);
    cout << raiz->valor << endl;
    emOrdem(raiz->dir);
}

bool buscar(No *raiz, int valor)
{
    if (raiz == nullptr)
        return false;

    if (valor < raiz->valor)
    {
        return buscar(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        return buscar(raiz->dir, valor);
    }
    else
    {
        return true;
    }
}

int somarNos(No *raiz)
{
    if (raiz == nullptr)
        return 0;

    int total = raiz->valor + somarNos(raiz->esq);
    total += somarNos(raiz->dir);

    return total;
}

int altura(No *raiz)
{
    if (raiz == nullptr)
        return -1;
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);

        if (esq > dir)
        {
            return esq + 1;
        }
        else
        {
            return dir + 1;
        }
    }
}

int contarFolhas(No *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
    {
        if (raiz->esq == nullptr && raiz->dir == nullptr)
            return 1;

        return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
    }
}

/* 3. Escreva uma função recursiva, em C, para gerar uma pilha contendo os nós ascendentes de
um determinado nó de uma árvore binária de pesquisa, de tal forma que no topo da pilha
encontraremos sempre o maior valor dos nós ascendentes. */

Pilha *pilhaAscendentes(No *raiz, Pilha *pilha, int valor)
{
    if (raiz == NULL)
        return nullptr;

    if (raiz->valor == valor)
        return nullptr;

    if (valor < raiz->valor)
        pilhaAscendentes(raiz->esq, pilha, valor);
    else
        pilhaAscendentes(raiz->dir, pilha, valor);

    Pilha *novo = new Pilha();
    novo->valor = raiz->valor;
    novo->ultimo = pilha;
    return pilhaAscendentes(raiz->dir, novo, valor);
}