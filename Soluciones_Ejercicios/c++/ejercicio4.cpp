#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  EJERCICIO 4 - Contar la cantidad de hojas del árbol
//  Una hoja es un nodo sin hijos (izquierda == nullptr
//  Y derecha == nullptr al mismo tiempo).
// ============================================================

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

// ── Función principal del ejercicio ─────────────────────────

int contarHojas(Nodo* raiz) {
    if (!raiz) return 0;
    // Si no tiene hijos, es una hoja
    if (!raiz->izquierda && !raiz->derecha) return 1;
    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

int contarNodos(Nodo* raiz) {
    if (!raiz) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

// ── Mostrar hojas ────────────────────────────────────────────

void mostrarHojas(Nodo* raiz) {
    if (!raiz) return;
    if (!raiz->izquierda && !raiz->derecha) {
        cout << raiz->dato << " ";
        return;
    }
    mostrarHojas(raiz->izquierda);
    mostrarHojas(raiz->derecha);
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
    // Árbol del ejercicio 2 (11 nodos)
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
    cout << "         --- EJERCICIO 4 ---\n";
    cout << "       Contar hojas del arbol\n";
    linea();

    cout << "\nArbol Estructurado:\n";
    imprimirArbolCompleto(raiz);

    linea();
    cout << "Nodos totales:   " << contarNodos(raiz) << "\n";
    cout << "Cantidad de hojas: " << contarHojas(raiz) << "\n";
    cout << "Nodos hoja:      "; mostrarHojas(raiz); cout << "\n";
    linea();

    return 0;
}
