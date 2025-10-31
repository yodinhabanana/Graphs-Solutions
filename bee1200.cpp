#include <iostream>
using namespace std;

struct nodes {
    char elemento;
    nodes *proxEsquerda;
    nodes *proxDireita;
    nodes(char val) : elemento(val), proxEsquerda(nullptr), proxDireita(nullptr) {}
};

class BST {
public:
    nodes* raiz;
    BST() : raiz(nullptr) {}

    nodes* BST_Insert(char element, nodes* node) {
        if (node == nullptr) return new nodes(element);
        if (element > node->elemento)
            node->proxDireita = BST_Insert(element, node->proxDireita);
        else if (element < node->elemento)
            node->proxEsquerda = BST_Insert(element, node->proxEsquerda);
        return node;
    }

    nodes* BST_Search(char elementoBusca, nodes* atual) {
        if (atual == nullptr) return nullptr;
        if (elementoBusca > atual->elemento)
            return BST_Search(elementoBusca, atual->proxDireita);
        else if (elementoBusca < atual->elemento)
            return BST_Search(elementoBusca, atual->proxEsquerda);
        else
            return atual;
    }

    // para imprimir sem espaço extra no fim
    void inorder(nodes* node, bool &first) {
        if (node != nullptr) {
            inorder(node->proxEsquerda, first);
            if (!first) cout << " ";
            cout << node->elemento;
            first = false;
            inorder(node->proxDireita, first);
        }
    }

    void preOrdem(nodes* node, bool &first) {
        if (node != nullptr) {
            if (!first) cout << " ";
            cout << node->elemento;
            first = false;
            preOrdem(node->proxEsquerda, first);
            preOrdem(node->proxDireita, first);
        }
    }

    void posOrdem(nodes* node, bool &first) {
        if (node != nullptr) {
            posOrdem(node->proxEsquerda, first);
            posOrdem(node->proxDireita, first);
            if (!first) cout << " ";
            cout << node->elemento;
            first = false;
        }
    }
};

bool igual(const char a[], const char b[]) {
    int i = 0;
    while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0') i++;
    return a[i] == '\0' && b[i] == '\0';
}

int main() {
    char comando[20];
    char objeto;
    BST arvoreDeBusca;

    while (cin >> comando) {
        if (igual(comando, "I")) {
            cin >> objeto;
            arvoreDeBusca.raiz = arvoreDeBusca.BST_Insert(objeto, arvoreDeBusca.raiz);
        } 
        else if (igual(comando, "PREFIXA")) {
            bool first = true;
            arvoreDeBusca.preOrdem(arvoreDeBusca.raiz, first);
            cout << "\n";
        } 
        else if (igual(comando, "INFIXA")) {
            bool first = true;
            arvoreDeBusca.inorder(arvoreDeBusca.raiz, first);
            cout << "\n";
        } 
        else if (igual(comando, "POSFIXA")) {
            bool first = true;
            arvoreDeBusca.posOrdem(arvoreDeBusca.raiz, first);
            cout << "\n";
        } 
        else if (igual(comando, "P")) {
            cin >> objeto;
            nodes* r = arvoreDeBusca.BST_Search(objeto, arvoreDeBusca.raiz);
            if (r != nullptr) cout << objeto << " existe\n";
            else cout << objeto << " nao existe\n";
        }
    }

    return 0;
}
