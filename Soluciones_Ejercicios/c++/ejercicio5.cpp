#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ============================================================
//  EJERCICIO 5 - Sistema Web representado como árbol binario
//
//              Sistema Web
//             /           \
//        Usuarios       Inventario
//         /    \          /      \
//    Registrar Buscar  Productos Reportes
//
//  Recorridos aplicados:
//   1. Preorden  → Mostrar Menú Principal (raíz primero)
//   2. Postorden → Procesar módulos internos (hojas primero)
//   3. BFS       → Mapa del sitio nivel por nivel
// ============================================================

struct Nodo {
    string nombre;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(string n) : nombre(n), izquierda(nullptr), derecha(nullptr) {}
};

// ── Recorridos ─────────────────────────────────────────────

void preorden(Nodo* raiz, string prefijo = "", bool esIzquierda = true) {
    if (!raiz) return;
    if (prefijo.empty()) {
        cout << "- " << raiz->nombre << "\n";
    } else {
        cout << prefijo << (esIzquierda ? "  - " : "  - ") << raiz->nombre << "\n";
    }
    string nuevo = prefijo + "  ";
    preorden(raiz->izquierda, nuevo, true);
    preorden(raiz->derecha,   nuevo, false);
}

void postorden(Nodo* raiz) {
    if (!raiz) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << "Cargando dependencias de: [" << raiz->nombre << "]\n";
}

void bfsPorNivel(Nodo* raiz) {
    if (!raiz) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    int nivel = 0;
    while (!cola.empty()) {
        int tam = cola.size();
        cout << "Profundidad " << nivel << ": ";
        for (int i = 0; i < tam; i++) {
            Nodo* actual = cola.front(); cola.pop();
            cout << actual->nombre << " | ";
            if (actual->izquierda) cola.push(actual->izquierda);
            if (actual->derecha)   cola.push(actual->derecha);
        }
        cout << "\n";
        nivel++;
    }
}

void linea() { cout << string(36, '-') << "\n"; }

// ── Menú interactivo ────────────────────────────────────────

void mostrarMenu() {
    cout << "\n=== MENU INTERACTIVO: SISTEMA WEB ===\n";
    cout << "1. Mostrar Menu Principal (Preorden)\n";
    cout << "2. Procesar Modulos Internos (Postorden)\n";
    cout << "3. Mostrar Mapa del Sitio (BFS)\n";
    cout << "4. Salir\n";
    cout << "Ingrese una opcion: ";
}

int main() {
    // Construir el árbol del sistema web
    Nodo* raiz          = new Nodo("Sistema Web");
    raiz->izquierda     = new Nodo("Usuarios");
    raiz->derecha       = new Nodo("Inventario");
    raiz->izquierda->izquierda = new Nodo("Registrar");
    raiz->izquierda->derecha   = new Nodo("Buscar");
    raiz->derecha->izquierda   = new Nodo("Productos");
    raiz->derecha->derecha     = new Nodo("Reportes");

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        linea();

        switch (opcion) {
            case 1:
                cout << "\n=== MENU PRINCIPAL ===\n";
                preorden(raiz);
                break;
            case 2:
                cout << "\n=== PROCESANDO MODULOS ===\n";
                postorden(raiz);
                break;
            case 3:
                cout << "\n=== MAPA DEL SITIO ===\n";
                bfsPorNivel(raiz);
                break;
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
        linea();
    } while (opcion != 4);

    return 0;
}
