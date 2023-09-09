#include <stdio.h>
#include <string.h>

// EJERCICIO 1 Y 2 ---------------------------------------------------------
struct Estudiante 
{
    char nombre[50];
    int numeroLista;
    float promedioFinal;
};

// EJERCICIO 3 Y 4 ---------------------------------------------------------
struct Libro 
{
    char titulo[100];
    char autor[50];
    char ISBN[13];
    float precio;
};

// EJERCICIO 5 ---------------------------------------------------------
struct Producto 
{
    char nombre[50];
    int ID;
    float precio;
    int cantidad;
};

// AQUI SE AGREGA EL PRODUCTO
void agregarProducto(struct Producto productos[], int *numProductos) 
{
    if (*numProductos < 5) 
	{
        struct Producto nuevoProducto;
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Ingrese el ID del producto: ");
        scanf("%d", &nuevoProducto.ID);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &nuevoProducto.precio);
        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &nuevoProducto.cantidad);

        productos[*numProductos] = nuevoProducto;
        (*numProductos)++;
        printf("Producto agregado con exito.\n");
        
    } else {
        printf("No se pueden agregar mas productos. La lista esta llena.\n");
    }
}

// SE BUSCA EL PRODUCTO CON EL PRECIO MAS ALTO
void encontrarProductoMayorValor(struct Producto productos[], int numProductos) 
{
    if (numProductos > 0) 
	{
        struct Producto mayorValor = productos[0];

        for (int i = 1; i < numProductos; i++) 
		{        	
            if (productos[i].precio > mayorValor.precio) 
			{
                mayorValor = productos[i];
            }
        }
        
        // AQUI SE IMPRIME EL PRODUCTO CON EL PRECIO MAS ALTO

        printf("Producto con el mayor valor:\n");
        printf("Nombre: %s\n", mayorValor.nombre);
        printf("ID: %d\n", mayorValor.ID);
        printf("Precio: %.2f\n", mayorValor.precio);
        printf("Cantidad: %d\n", mayorValor.cantidad);
        
    } else {
        printf("No hay productos.\n");
    }
}

// AQUI SE MUESTRA EL STOCK
void mostrarStock(struct Producto productos[], int numProductos) 
{
    printf("Stock actual de productos:\n");
    for (int i = 0; i < numProductos; i++) 
	{
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("ID: %d\n", productos[i].ID);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("Cantidad: %d\n", productos[i].cantidad);
        printf("\n");
        
    }
}

int main() 
{    
    
    //BONUS
    
    printf("EL LINK PARA DESCARGAR PELICULAS SE ENCUENTRA EN EL COMENTARIO DE LA ENTREGA LINK:  https://v1.cinecalidad.com.mx/\n\n");
	
	//EJERCICIO 1 Y 2 ---------------------------------------------------------
    
    printf("EJERCICIO 1 Y 2\n\n");
    
	struct Estudiante estudiantes[5];

    for (int i = 0; i < 5; i++) 
	{
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i].nombre);
        printf("Ingrese el numero de lista del estudiante %d: ", i + 1);
        scanf("%d", &estudiantes[i].numeroLista);
        printf("Ingrese el promedio final del estudiante %d: ", i + 1);
        scanf("%f", &estudiantes[i].promedioFinal);
        
    }
    
    printf("\nInformacion de los estudiantes:\n");
    
    for (int i = 0; i < 5; i++) 
	{
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Numero de lista: %d\n", estudiantes[i].numeroLista);
        printf("Promedio final: %.1f\n", estudiantes[i].promedioFinal);
        printf("\n");
        
    }

    //EJERCICIO 3 Y 4 ---------------------------------------------------------
	
	printf("\n\nEJERCICIO 3 Y 4\n\n");
	
	struct Libro libros[5];

    for (int i = 0; i < 5; i++) 
	{
        printf("\nIngrese el titulo del libro %d: ", i + 1);
        scanf("%s", libros[i].titulo);
        printf("Ingrese el autor del libro %d: ", i + 1);
        scanf("%s", libros[i].autor);
        printf("Ingrese el ISBN del libro %d: ", i + 1);
        scanf("%s", libros[i].ISBN);
        printf("Ingrese el precio del libro %d: ", i + 1);
        scanf("%f", &libros[i].precio);
        
    }
    
    // AQUI SE BUSCA EL PRECIO MAS ALTO

    int indiceMaxPrecio = 0;
    float maxPrecio = libros[0].precio;

    for (int i = 1; i < 5; i++) 
	{
        if (libros[i].precio > maxPrecio) 
		{
            maxPrecio = libros[i].precio;
            indiceMaxPrecio = i;
            
        }
    }
    
    // SE MUESTRA EL PRECIO MAS ALTO JUNTO CON SU LIBRO

    printf("\nLibro con el precio mas alto:\n");
    printf("Titulo: %s\n", libros[indiceMaxPrecio].titulo);
    printf("Autor: %s\n", libros[indiceMaxPrecio].autor);
    printf("ISBN: %s\n", libros[indiceMaxPrecio].ISBN);
    printf("Precio: %.2f\n", libros[indiceMaxPrecio].precio);
    
    // EJERCICIO 5 ---------------------------------------------------------
    
    printf("\n\nEJERCICIO 5\n\n");
    
    struct Producto productos[5];
    int numProductos = 0;
    int opcion;

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Agregar un producto\n");
        printf("2. Mostrar el producto de mayor valor\n");
        printf("3. Mostrar el stock actual de productos\n");
        printf("4. Salir\n");
        printf("\nSeleccione una opcion (1-4): ");
        scanf("%d", &opcion);

        switch (opcion) 
		{
            case 1:
                agregarProducto(productos, &numProductos);
                break;
            case 2:
                encontrarProductoMayorValor(productos, numProductos);
                break;
            case 3:
                mostrarStock(productos, numProductos);
                break;
            case 4:
                printf("Salir del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida (1-4).\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}