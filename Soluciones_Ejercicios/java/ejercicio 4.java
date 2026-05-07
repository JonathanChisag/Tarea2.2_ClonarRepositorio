// ============================================================
//  EJERCICIO 4 - Contar la cantidad de hojas del árbol
//  Una hoja es un nodo sin hijos izquierdo ni derecho.
// ============================================================

public class Main {

    static class Nodo {
        int dato;
        Nodo izquierda, derecha;
        Nodo(int valor) { this.dato = valor; }
    }

    // ── Funciones principales del ejercicio ─────────────────

    static int contarNodos(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }

    static int contarHojas(Nodo raiz) {
        if (raiz == null) return 0;
        if (raiz.izquierda == null && raiz.derecha == null) return 1;
        return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }

    static void mostrarHojas(Nodo raiz) {
        if (raiz == null) return;
        if (raiz.izquierda == null && raiz.derecha == null) {
            System.out.print(raiz.dato + " ");
            return;
        }
        mostrarHojas(raiz.izquierda);
        mostrarHojas(raiz.derecha);
    }

    // ── Visualización ────────────────────────────────────────

    static void imprimirArbol(Nodo nodo, String prefijo, boolean esIzquierda) {
        if (nodo == null) return;
        System.out.println(prefijo + (esIzquierda ? "|-->" : "\\-->") + " " + nodo.dato);
        String nuevo = prefijo + (esIzquierda ? "|    " : "     ");
        imprimirArbol(nodo.izquierda, nuevo, true);
        imprimirArbol(nodo.derecha,   nuevo, false);
    }

    static void imprimirArbolCompleto(Nodo raiz) {
        if (raiz == null) return;
        System.out.println(raiz.dato);
        imprimirArbol(raiz.izquierda, "", true);
        imprimirArbol(raiz.derecha,   "", false);
    }

    static void linea() { System.out.println("-".repeat(40)); }

    public static void main(String[] args) {
        Nodo raiz = new Nodo(10);
        raiz.izquierda       = new Nodo(5);
        raiz.derecha         = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha   = new Nodo(7);
        raiz.derecha.izquierda   = new Nodo(12);
        raiz.derecha.derecha     = new Nodo(20);
        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha   = new Nodo(3);
        raiz.derecha.derecha.izquierda     = new Nodo(18);
        raiz.derecha.derecha.derecha       = new Nodo(25);

        linea();
        System.out.println("      --- EJERCICIO 4 (Java) ---");
        System.out.println("        Contar hojas del arbol");
        linea();

        System.out.println("\nArbol Estructurado:");
        imprimirArbolCompleto(raiz);

        linea();
        System.out.println("Nodos totales:     " + contarNodos(raiz));
        System.out.println("Cantidad de hojas: " + contarHojas(raiz));
        System.out.print("Nodos hoja:        "); mostrarHojas(raiz); System.out.println();
        linea();
    }
}
