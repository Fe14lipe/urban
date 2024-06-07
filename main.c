#include <stdio.h>
#include "urban.h"
#include "lectura.h"

int main() {
    int opcion;

    do {
      Menu();
      opcion = leerEntero("escoja una opcion: ");

        switch (opcion) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}


