import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// ============================================================
//  EJERCICIO 5 - Sistema Web como árbol binario (Java)
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

public class Main {

    static class Nodo {
        String nombre;
        Nodo izquierda, derecha;
        Nodo(String n) { this.nombre = n; }
    }

    // ── Recorridos ──────────────────────────────────────────

    static void preorden(Nodo raiz, String prefijo, boolean esIzquierda) {
        if (raiz == null) return;
        if (prefijo.isEmpty()) {
            System.out.println("- " + raiz.nombre);
        } else {
            System.out.println(prefijo + "  - " + raiz.nombre);
        }
        String nuevo = prefijo + "  ";
        preorden(raiz.izquierda, nuevo, true);
        preorden(raiz.derecha,   nuevo, false);
    }

    static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.println("Cargando dependencias de: [" + raiz.nombre + "]");
    }

    static void bfsPorNivel(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        int nivel = 0;
        while (!cola.isEmpty()) {
            int tam = cola.size();
            System.out.print("Profundidad " + nivel + ": ");
            for (int i = 0; i < tam; i++) {
                Nodo actual = cola.poll();
                System.out.print(actual.nombre + " | ");
                if (actual.izquierda != null) cola.add(actual.izquierda);
                if (actual.derecha   != null) cola.add(actual.derecha);
            }
            System.out.println();
            nivel++;
        }
    }

    static void linea() { System.out.println("-".repeat(36)); }

    static void mostrarMenu() {
        System.out.println("\n=== MENU INTERACTIVO: SISTEMA WEB ===");
        System.out.println("1. Mostrar Menu Principal (Preorden)");
        System.out.println("2. Procesar Modulos Internos (Postorden)");
        System.out.println("3. Mostrar Mapa del Sitio (BFS)");
        System.out.println("4. Salir");
        System.out.print("Ingrese una opcion: ");
    }

    public static void main(String[] args) {
        Nodo raiz      = new Nodo("Sistema Web");
        raiz.izquierda = new Nodo("Usuarios");
        raiz.derecha   = new Nodo("Inventario");
        raiz.izquierda.izquierda = new Nodo("Registrar");
        raiz.izquierda.derecha   = new Nodo("Buscar");
        raiz.derecha.izquierda   = new Nodo("Productos");
        raiz.derecha.derecha     = new Nodo("Reportes");

        Scanner sc = new Scanner(System.in);
        int opcion;

        do {
            mostrarMenu();
            opcion = sc.nextInt();
            linea();

            switch (opcion) {
                case 1:
                    System.out.println("\n=== MENU PRINCIPAL ===");
                    preorden(raiz, "", true);
                    break;
                case 2:
                    System.out.println("\n=== PROCESANDO MODULOS ===");
                    postorden(raiz);
                    break;
                case 3:
                    System.out.println("\n=== MAPA DEL SITIO ===");
                    bfsPorNivel(raiz);
                    break;
                case 4:
                    System.out.println("\nSaliendo del programa...");
                    break;
                default:
                    System.out.println("Opcion no valida. Intente de nuevo.");
            }
            linea();
        } while (opcion != 4);

        sc.close();
    }
}
