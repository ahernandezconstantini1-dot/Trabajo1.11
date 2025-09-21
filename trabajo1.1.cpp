#include <iostream>

// Cambia valores del booleano
void modificar(bool arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (i % 2 != 0);
    }
}

// Cambia valores en arreglo de enteros y los imprime
void modificar(int arr[], int n) {
    int* puntero = arr;
    for (int i = 0; i < n; i++) {
        *puntero = *puntero % 2;
        std::cout << "Direccion: " << puntero << "  Valor: " << *puntero << std::endl;
        puntero++;
    }
}

int main() {
    // Arreglo de booleanos
    bool buleano[5];
    modificar(buleano, 5);

    std::cout << " Booleano \n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Buleano[" << i << "] = "
            << std::boolalpha << buleano[i] << std::endl;
    }

    // Arreglo de enteros
    std::cout << "\n Enteros \n";
    int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };
    modificar(nums, 10);

    return 0;
}
