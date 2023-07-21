#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <unordered_map>
#include <queue>
#include <stack>
#include "Graph.cpp"

using namespace std;

/*void rutaDistancia () {
    ifstream inputFile ("C:\\Users\\AlexP\\Downloads\\lastproyect2 - Clion\\Chapinero.txt");

    if (!inputFile.is_open()) {
        cout << "Hubo problemas al abrir el archivo. Inténtalo de nuevo." << endl;
        return ;
    }

    Graph<string> graph;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string from, to;
        int weight;

        ss >> from >> to >> weight;

        graph.addEdge(from, to, weight);
    }

    inputFile.close();
    cin.ignore();

    string start, end;

    cout << "Ingrese la direccion de inicio: ";
    getline(cin, start);
    cout << "Ingrese la direccion de destino: ";
    getline(cin, end);

    Vertex<string>* startVertex = graph.getVertex(start);
    Vertex<string>* endVertex = graph.getVertex(end);

    if (!startVertex || !endVertex) {
        cout << "Direcciones invalidas. Verifique la informacion ingresada." << endl;
        return ;
    }

    // Perform Dijkstra's algorithm
    unordered_map<Vertex<string>*, int> distance;
    unordered_map<Vertex<string>*, Vertex<string>*> parentMap;
    priority_queue<pair<int, Vertex<string>*>, vector<pair<int, Vertex<string>*>>, greater<pair<int, Vertex<string>*>>> pq;

    // Initialize distances to infinity
    for (int i = 0; i < graph.vertexList.size(); i++) {
        Vertex<string>* vertex = graph.vertexList.get(i);
        distance[vertex] = numeric_limits<int>::max();
    }

    distance[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        Vertex<string>* current = pq.top().second;
        pq.pop();

        if (current == endVertex) {
            break;
        }

        List<Edge<string>*> neighbors = current->connectedTo;
        for (int i = 0; i < neighbors.size(); i++) {
            Edge<string>* neighbor = neighbors.get(i);
            Vertex<string>* neighborVertex = neighbor->to;
            int weight = neighbor->weight;
            int newDistance = distance[current] + weight;

            if (distance.find(neighborVertex) == distance.end() || newDistance < distance[neighborVertex]) {
                distance[neighborVertex] = newDistance;
                parentMap[neighborVertex] = current;
                pq.push(make_pair(newDistance, neighborVertex));
            }

        }
    }

    // Check if a path was found
    if (parentMap.find(endVertex) == parentMap.end()) {
        cout << "No se encontro una ruta desde " << start << " hasta " << end << "." << endl << endl;
        return ;
    }

    // Reconstruct the path
    cout << "Ruta desde " << start << " hasta " << end << ":" << endl;

    stack<string> pathStack;
    Vertex<string>* current = endVertex;

    while (current != nullptr) {
        pathStack.push(current->data);
        current = parentMap[current];
    }

    cout << "Pasa por las rutas: " << endl;

    while (!pathStack.empty()) {
        cout << pathStack.top() << " -> ";
        pathStack.pop();
    }

    cout << endl;

    // Calculate the total weight
    int totalWeight = distance[endVertex];
    cout << "Distancia total del recorrido: " << totalWeight << " metros" << endl;
}*/

void rutaDistancia() {
    ifstream inputFile("C:\\Users\\joand\\OneDrive\\Escritorio\\lastproyect2 - Clion\\Chapinero.txt");

    if (!inputFile.is_open()) {
        cout << "Hubo problemas al abrir el archivo. Inténtalo de nuevo." << endl;
        return;
    }

    Graph<string> graph;
    string line;



    while (getline(inputFile, line)) {
        stringstream ss(line);
        string from, to;
        int weight;


        ss >> from >> to>>weight;

        // Calcula el tiempo como la distancia dividida por la velocidad


        graph.addEdge(from, to, weight);
    }

    inputFile.close();
    cin.ignore();

    string start, end;

    cout << "Ingrese la direccion de inicio: ";
    getline(cin, start);

    cout << "Ingrese la direccion de destino: ";
    getline(cin, end);

    Vertex<string>* startVertex = graph.getVertex(start);
    Vertex<string>* endVertex = graph.getVertex(end);

    if (!startVertex || !endVertex) {
        cout << "Direcciones invalidas. Verifique la informacion ingresada." << endl;
        return;
    }

    // Perform Dijkstra's algorithm

    unordered_map<Vertex<string>*, Vertex<string>*> parentMap;
    unordered_map<Vertex<string>*, int> distance;
    priority_queue<pair<int, Vertex<string>*>, vector<pair<int, Vertex<string>*>>, greater<pair<int, Vertex<string>*>>> pq;

    // Initialize distances to infinity
    for (int i = 0; i < graph.vertexList.size(); i++) {
        Vertex<string>* vertex = graph.vertexList.get(i);
        distance[vertex] = numeric_limits<int>::max();
    }

    distance[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        Vertex<string>* current = pq.top().second;
        pq.pop();

        if (current == endVertex) {
            break;
        }

        List<Edge<string>*> neighbors = current->connectedTo;
        for (int i = 0; i < neighbors.size(); i++) {
            Vertex<string>* neighborVertex = neighbors.get(i)->to;
            int weight = neighbors.get(i)->weight;
            int newDistance = distance[current] + weight;

            if (newDistance < distance[neighborVertex]) {
                distance[neighborVertex] = newDistance;
                parentMap[neighborVertex] = current;
                pq.push(make_pair(newDistance, neighborVertex));
            }
        }
    }

    // Check if a path was found
    if (parentMap.find(endVertex) == parentMap.end()) {
        cout << "No se encontro una ruta desde " << start << " hasta " << end << "." << endl;
        return;
    }

    // Reconstruct the path
    cout << "Ruta desde " << start << " hasta " << end << ":" << endl << endl;

    stack<string> pathStack;
    Vertex<string>* current = endVertex;

    while (current != nullptr) {
        pathStack.push(current->data);
        current = parentMap[current];
    }

    cout << "Pasa por las rutas: " << endl;

    while (!pathStack.empty()) {
        cout << pathStack.top() << " -> ";
        pathStack.pop();
    }

    cout << endl;

    // Calculate the total time

    int totalWeight = distance[endVertex];

    cout << "Total del recorrido: " << totalWeight << " metros" << endl;
}

void rutaTiempo() {
    ifstream inputFile("C:\\Users\\joand\\OneDrive\\Escritorio\\lastproyect2 - Clion\\Chapinero.txt");

    if (!inputFile.is_open()) {
        cout << "Hubo problemas al abrir el archivo. Inténtalo de nuevo." << endl;
        return;
    }

    Graph<string> graph;
    string line;

    random_device rd;
    mt19937 gen(rd());
   uniform_real_distribution<double> velocidad(0.0, 100.0); // Números aleatorios entre 30 y 40

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string from, to;
        int weight;


        ss >> from >> to>>weight;

        // Calcula el tiempo como la distancia dividida por la velocidad
        weight =weight/ velocidad(gen);

        graph.addEdge(from, to, weight);
    }

    inputFile.close();
    cin.ignore();

    string start, end;

    cout << "Ingrese la direccion de inicio: ";
    getline(cin, start);

    cout << "Ingrese la direccion de destino: ";
    getline(cin, end);

    Vertex<string>* startVertex = graph.getVertex(start);
    Vertex<string>* endVertex = graph.getVertex(end);

    if (!startVertex || !endVertex) {
        cout << "Direcciones invalidas. Verifique la informacion ingresada." << endl;
        return;
    }

    // Perform Dijkstra's algorithm

    unordered_map<Vertex<string>*, Vertex<string>*> parentMap;
    unordered_map<Vertex<string>*, int> distance;
    priority_queue<pair<int, Vertex<string>*>, vector<pair<int, Vertex<string>*>>, greater<pair<int, Vertex<string>*>>> pq;

    // Initialize distances to infinity
    for (int i = 0; i < graph.vertexList.size(); i++) {
        Vertex<string>* vertex = graph.vertexList.get(i);
        distance[vertex] = numeric_limits<int>::max();
    }

    distance[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        Vertex<string>* current = pq.top().second;
        pq.pop();

        if (current == endVertex) {
            break;
        }

        List<Edge<string>*> neighbors = current->connectedTo;
        for (int i = 0; i < neighbors.size(); i++) {
            Vertex<string>* neighborVertex = neighbors.get(i)->to;
            int weight = neighbors.get(i)->weight;
            int newDistance = distance[current] + weight;

            if (newDistance < distance[neighborVertex]) {
                distance[neighborVertex] = newDistance;
                parentMap[neighborVertex] = current;
                pq.push(make_pair(newDistance, neighborVertex));
            }
        }
    }

    // Check if a path was found
    if (parentMap.find(endVertex) == parentMap.end()) {
        cout << "No se encontro una ruta desde " << start << " hasta " << end << "." << endl;
        return;
    }

    // Reconstruct the path
    cout << "Ruta desde " << start << " hasta " << end << ":" << endl << endl;

    stack<string> pathStack;
    Vertex<string>* current = endVertex;

    while (current != nullptr) {
        pathStack.push(current->data);
        current = parentMap[current];
    }

    cout << "Pasa por las rutas: " << endl;

    while (!pathStack.empty()) {
        cout << pathStack.top() << " -> ";
        pathStack.pop();
    }

    cout << endl;

    // Calculate the total time

    int totalWeight = distance[endVertex];

    cout << "Tiempo total del recorrido: " << totalWeight << " minutos" << endl;
}

int main () {
    system("cls");
    int opcion = 0;
    bool salir = false;
    do {
        system("cls");
        cout << "RUTA SITP CHAPINERO" << endl;
        cout << "1. Buscar la ruta mas corta (metros)" << endl;
        cout << "2. Buscar la ruta mas rapida (minutos)" << endl;
        cout << "3. Paseo por chapinero (profundidad)"<< endl;
        cout << "4. Salir" << endl;
        cout << "Escoja una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Opcion invalida. Seleccione alguna de las opciones disponibles." << endl;
            system("pause");
            continue;
        }

        if (opcion < 1 || opcion > 4) {
            cout << "Opcion invalida. Seleccione algunas de las opciones disponibles." << endl;
            system("pause");
            continue;
        }

        switch (opcion) {
            case 1:
                system("cls");
                rutaDistancia();
                system("pause");
                break;
            case 2:
                system("cls");
                rutaTiempo();
                system("pause");
                break;
            case 3:
                break;
            case 4:
                cout << "Esta seguro de que desea salir? (S/N): ";
                char confirmacion;
                cin >> confirmacion;
                if (confirmacion == 'S' || confirmacion == 's') {
                    salir = true;
                }
                break;
            default:
                break;
        }
    }while (!salir);

    return 0;
}
