import java.util.LinkedList;
import java.util.Queue;

// ============================================================
//  EJERCICIO 1 - Recorridos de Árbol Binario (Java)
//  Árbol:        10
//               /  \
//              5    15
//             / \   / \
//            2   7 12  20
// ============================================================

public class Main {

    static class Nodo {
        int dato;
        Nodo izquierda, derecha;
        Nodo(int valor) { this.dato = valor; }
    }

    // ── Recorridos ──────────────────────────────────────────

    static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    static void bfs(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha   != null) cola.add(actual.derecha);
        }
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
        Nodo raiz            = new Nodo(10);
        raiz.izquierda       = new Nodo(5);
        raiz.derecha         = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha   = new Nodo(7);
        raiz.derecha.izquierda   = new Nodo(12);
        raiz.derecha.derecha     = new Nodo(20);

        linea();
        System.out.println("         --- EJERCICIO 1 (Java) ---");
        linea();

        System.out.println("\nArbol Estructurado:");
        imprimirArbolCompleto(raiz);

        linea();
        System.out.print("Preorden:   "); preorden(raiz);  System.out.println();
        System.out.print("Inorden:    "); inorden(raiz);   System.out.println();
        System.out.print("Postorden:  "); postorden(raiz); System.out.println();
        System.out.print("BFS:        "); bfs(raiz);       System.out.println();
        linea();
    }
}
