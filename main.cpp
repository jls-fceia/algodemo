#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort, std::find
#include <numeric>   // Para std::accumulate

bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Crear un vector de enteros
    std::vector<int> numbers;

    // Llenar el vector con números enteros aleatorios entre 1 y 1000
    for (int i = 0; i < 50; i++) {
        numbers.push_back(rand() % 1000 + 1);
    }

    // 1. Ordenar el vector usando std::sort
    std::sort(numbers.begin(), numbers.end());

    // Mostrar el vector ordenado
    std::cout << "Vector ordenado: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 2. Buscar un elemento usando std::find
    int target = 5;
    auto it = std::find(numbers.begin(), numbers.end(), target);
    if (it != numbers.end()) {
        std::cout << "Elemento " << target << " encontrado en el vector." << std::endl;
    } else {
        std::cout << "Elemento " << target << " no encontrado." << std::endl;
    }

    // 3. Calcular la suma de los elementos usando std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "La suma de los elementos es: " << sum << std::endl;

    // 4. Contar los números primos en el vector
    int count = std::count_if(numbers.begin(), numbers.end(), esPrimo);
    std::cout << "Cantidad de números primos en el vector: " << count << std::endl;

    // 5. Encontrar los números primos en el vector
    std::vector<int> primeNumbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(primeNumbers), esPrimo);
    std::cout << "Números primos en el vector: ";
    for (int num : primeNumbers) {
        std::cout << num << " ";
    }

    // 6. Transformar los números en su cuadrado en el vector
    // Usar std::transform para calcular los cuadrados
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int x) {
        return x * x; // Función lambda que calcula el cuadrado
    });
    std::cout << "\nCuadrados de los números en el vector: ";
    for (int num : squares) {
        std::cout << num << " ";
    }

    return 0;
}