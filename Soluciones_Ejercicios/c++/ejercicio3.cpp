#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  EJERCICIO 3 - Contar la cantidad total de nodos del árbol
// ============================================================

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

// ── Función principal del ejercicio ─────────────────────────

int contarNodos(Nodo* raiz) {
    if (!raiz) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
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
    // Árbol del ejercicio 2 (con los 4 nodos adicionales)
    Nodo* raiz = new Nodo(10);
    raiz->izquierda            = new Nodo(5);
    raiz->derecha              = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);
    raiz->izquierda->izquierda->izquierda = new Nodo(1);
    raiz->izquierda->izquierda->derecha   = new Nodo(3);
    raiz->derecha->derecha->izquierda     = new Nodo(18);
    raiz->derecha->derecha->derecha       = new Nodo(25);

    linea();
    cout << "         --- EJERCICIO 3 ---\n";
    cout << "    Contar total de nodos del arbol\n";
    linea();

    cout << "\nArbol Estructurado:\n";
    imprimirArbolCompleto(raiz);

    linea();
    int total = contarNodos(raiz);
    cout << "La cantidad total de nodos es: " << total << "\n";
    linea();

    return 0;
}
