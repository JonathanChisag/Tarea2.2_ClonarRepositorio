#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ============================================================
//  EJERCICIO 2 - Árbol Modificado (agregando 1, 3, 18, 25)
//  Árbol:           10
//                 /    \
//                5      15
//               / \    /  \
//              2   7  12   20
//             / \         /  \
//            1   3       18   25
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
    cout << prefijo << (esIzquierda ? "|-->" : "\\-->") << " " << raiz->dato << "\n";
    string nuevo = prefijo + (esIzquierda ? "|    " : "     ");
    imprimirArbol(raiz->izquierda, nuevo, true);
    imprimirArbol(raiz->derecha,   nuevo, false);
}

void imprimirArbolCompleto(Nodo* raiz) {
    if (!raiz) return;
    cout << raiz->dato << "\n";
    imprimirArbol(raiz->izquierda, "", true);
    imprimirArbol(raiz->derecha,   "", false);
}

void linea() { cout << string(40, '-') << "\n"; }

int main() {
    // Árbol base
    Nodo* raiz = new Nodo(10);
    raiz->izquierda            = new Nodo(5);
    raiz->derecha              = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    // Nodos nuevos: 1, 3, 18, 25
    raiz->izquierda->izquierda->izquierda = new Nodo(1);
    raiz->izquierda->izquierda->derecha   = new Nodo(3);
    raiz->derecha->derecha->izquierda     = new Nodo(18);
    raiz->derecha->derecha->derecha       = new Nodo(25);

    linea();
    cout << "      --- EJERCICIO 2 (Modificado) ---\n";
    cout << "   Nodos agregados: 1, 3, 18 y 25\n";
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
