#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ============================================================
//  EJERCICIO 1 - Recorridos de Árbol Binario
//  Árbol:        10
//               /  \
//              5    15
//             / \   / \
//            2   7 12  20
// ============================================================

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

// ── Recorridos ─────────────────────────────────────────────

void preorden(Nodo* raiz) {
    if (!raiz) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (!raiz) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (!raiz) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (!raiz) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front(); cola.pop();
        cout << actual->dato << " ";
        if (actual->izquierda) cola.push(actual->izquierda);
        if (actual->derecha)   cola.push(actual->derecha);
    }
}

// ── Visualización del árbol ─────────────────────────────────

void imprimirArbol(Nodo* raiz, string prefijo = "", bool esIzquierda = true) {
    if (!raiz) return;
    cout << prefijo;
    cout << (esIzquierda ? "|-->" : "\\-->") << " ";
    cout << raiz->dato << "\n";
    string nuevoPrefijo = prefijo + (esIzquierda ? "|    " : "     ");
    imprimirArbol(raiz->izquierda, nuevoPrefijo, true);
    imprimirArbol(raiz->derecha,   nuevoPrefijo, false);
}

void imprimirArbolCompleto(Nodo* raiz) {
    if (!raiz) return;
    cout << raiz->dato << "\n";
    imprimirArbol(raiz->izquierda, "", true);
    imprimirArbol(raiz->derecha,   "", false);
}

// ── Separador visual ────────────────────────────────────────

void linea() { cout << string(40, '-') << "\n"; }

int main() {
    // Construir el árbol
    Nodo* raiz = new Nodo(10);
    raiz->izquierda            = new Nodo(5);
    raiz->derecha              = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    linea();
    cout << "         --- EJERCICIO 1 ---\n";
    linea();

    cout << "\nArbol Estructurado:\n";
    imprimirArbolCompleto(raiz);

    linea();
    cout << "Preorden:   "; preorden(raiz);   cout << "\n";
    cout << "Inorden:    "; inorden(raiz);    cout << "\n";
    cout << "Postorden:  "; postorden(raiz);  cout << "\n";
    cout << "BFS:        "; bfs(raiz);        cout << "\n";
    linea();

    return 0;
}
