//
// Created by Lucia Abad on 20/12/24.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <locale>
#include <limits>

// Ejercicio 1: Lectura y escritura en flujos estándar
void ejercicio1() {
    int num;
    std::cout << "Ejercicio 1: Ingrese un número entero: ";
    std::cin >> num;

    if (std::cin.fail()) {
        std::cerr << "Entrada inválida.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "El número ingresado es: " << num << std::endl;

    // Escribir en un archivo de salida
    std::ofstream outputFile("salida.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "Número ingresado: " << num << std::endl;
        std::cout << "Se ha escrito correctamente en 'salida.txt'.\n";
        outputFile.close();
    } else {
        std::cerr << "No se pudo abrir el archivo 'salida.txt'.\n";
    }
}

// Ejercicio 2: Flujos de archivos (escribir y leer)
void ejercicio2() {
    // Escribir algo en 'entrada.txt' para probar la lectura
    std::ofstream outputFile("entrada.txt");
    if (outputFile.is_open()) {
        outputFile << "Esto es un texto de prueba en entrada.txt.\n";
        std::cout << "Se ha escrito en 'entrada.txt'.\n";
        outputFile.close();
    } else {
        std::cerr << "No se pudo abrir 'entrada.txt' para escribir.\n";
        return;
    }

    // Ahora leer el contenido de 'entrada.txt'
    std::ifstream inputFile("entrada.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo 'entrada.txt'. Asegúrate de que exista en el directorio de trabajo.\n";
        return;  // Salir si el archivo no se puede abrir
    }

    std::cout << "Contenido de 'entrada.txt':\n";
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    inputFile.close();
}

// Ejercicio 3: Formato y manipuladores de flujo
void ejercicio3() {
    double num;
    std::cout << "Ejercicio 3: Ingresa un número con decimales: ";

    // Configurar el flujo para aceptar coma como separador decimal
    std::cin.imbue(std::locale("es_ES.UTF-8"));

    std::cin >> num;

    // Verificar si la entrada es válida
    if (std::cin.fail()) {
        std::cerr << "Entrada inválida.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpiar el flujo
        return;
    }

    std::cout << "El número con formato de 2 decimales es: "
              << std::fixed << std::setprecision(2) << num << std::endl;
}

// Ejercicio 4: Uso de stringstream
void ejercicio4() {
    std::string text;
    std::cout << "Ejercicio 4: Ingresa una línea de texto: ";

    std::cin.ignore();  // Ignorar el salto de línea pendiente de la entrada anterior
    std::getline(std::cin, text);

    std::stringstream ss(text);
    std::string word;

    std::cout << "Palabras en la línea ingresada:\n";
    while (ss >> word) {
        std::cout << word << std::endl;
    }
}

// Ejercicio 5: Argumentos de línea de comandos y flujos
void ejercicio5(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Por favor, proporciona un argumento de texto.\n";
        return;
    }

    std::ofstream outputFile("argumentos.txt");
    if (outputFile.is_open()) {
        for (int i = 1; i < argc; ++i) {
            outputFile << argv[i] << " ";
        }
        std::cout << "Los argumentos fueron escritos correctamente en 'argumentos.txt'.\n";
        outputFile.close();
    } else {
        std::cerr << "No se pudo abrir el archivo 'argumentos.txt'.\n";
    }
}

int main(int argc, char* argv[]) {
    ejercicio1();
    ejercicio2();  // Aquí escribe y lee 'entrada.txt'
    ejercicio3();
    ejercicio4();
    ejercicio5(argc, argv);

    return 0;
}
