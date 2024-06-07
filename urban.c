#include <stdio.h>
#include <string.h>
#include "urban.h"


#define MAX_PRODUCTS 100

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

Producto inventario[MAX_PRODUCTS];
int reconteoProductos = 0;

void agregarProducto() {
    if (reconteoProductos >= MAX_PRODUCTS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", inventario[reconteoProductos].nombre);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &inventario[reconteoProductos].cantidad);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &inventario[reconteoProductos].precio);

    reconteoProductos++;
    printf("Producto agregado exitosamente.\n");
}

void editarProducto() {
    char name[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", name);

    for (int i = 0; i < reconteoProductos; i++) {
        if (strcmp(inventario[i].nombre, name) == 0) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", inventario[i].nombre);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventario[i].cantidad);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventario[i].precio);

            printf("Producto editado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void borrarProducto() {
    char name[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", name);

    for (int i = 0; i < reconteoProductos; i++) {
        if (strcmp(inventario[i].nombre, name) == 0) {
            for (int j = i; j < reconteoProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            reconteoProductos--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listadeProductos() {
    if (reconteoProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("Productos en el inventario:\n");
    for (int i = 0; i < reconteoProductos; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

void Menu(){
      printf("\nSistema de Inventario de Tienda de Ropa Urbana\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
}