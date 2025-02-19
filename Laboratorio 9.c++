#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void agregarTarea(stack<string>& pila, queue<string>& cola, const string& tarea) {
    pila.push(tarea);
    cola.push(tarea);
}

void completarUltimaTarea(stack<string>& pila) {
    if (!pila.empty()) {
        cout << "Completando tarea: " << pila.top() << endl;
        pila.pop();
    } else {
        cout << "No hay tareas para completar." << endl;
    }
}

void atenderTareaMasAntigua(queue<string>& cola) {
    if (!cola.empty()) {
        cout << "Atendiendo tarea: " << cola.front() << endl;
        cola.pop();
    } else {
        cout << "No hay tareas para atender." << endl;
    }
}

void mostrarTareas(const stack<string>& pila, const queue<string>& cola) {
    stack<string> tempPila = pila;
    queue<string> tempCola = cola;

    cout << "\nTareas en la pila (ultima primero):" << endl;
    if (tempPila.empty()) {
        cout << "No hay tareas en la pila." << endl;
    } else {
        while (!tempPila.empty()) {
            cout << tempPila.top() << endl;
            tempPila.pop();
        }
    }

    cout << "\nTareas en la cola (primera primero):" << endl;
    if (tempCola.empty()) {
        cout << "No hay tareas en la cola." << endl;
    } else {
        while (!tempCola.empty()) {
            cout << tempCola.front() << endl;
            tempCola.pop();
        }
    }
}

int main() {
    stack<string> pila;
    queue<string> cola;
    int opcion;
    string tarea;

    do {
        cout << "\n--- Gestor de Tareas ---" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Completar ultima tarea" << endl;
        cout << "3. Atender tarea mas antigua" << endl;
        cout << "4. Mostrar todas las tareas" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Introduce la tarea: ";
                getline(cin, tarea);
                agregarTarea(pila, cola, tarea);
                break;
            case 2:
                completarUltimaTarea(pila);
                break;
            case 3:
                atenderTareaMasAntigua(cola);
                break;
            case 4:
                mostrarTareas(pila, cola);
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}


