/*Objetivo del proyecto: Conseguir la presencia del CEO en un momento clave de la empresa,evitando culaquier obstaculo,que le impida llegar a tiempo a su reunión en Barcelona*/
#include <iostream>
#include <string>
using namespace std;

// Estructura simple para almacenar la información de cada tarea
struct Tarea {
    string id;
    string descripcion;
    int duracion;
    string recurso;
    int tiempo_inicio;
};

int main() {
    // Declaramos un array de tareas
    Tarea tareas[13];  // 13 tareas en total

    // Inicializamos las tareas con sus datos
    // Tarea A
    tareas[0].id = "A";
    tareas[0].descripcion = "Reserva de vuelo";
    tareas[0].duracion = 20;
    tareas[0].recurso = "Ejecutivo";
    tareas[0].tiempo_inicio = 0;

    // Tarea B
    tareas[1].id = "B";
    tareas[1].descripcion = "Informar a casa para empacar";
    tareas[1].duracion = 5;
    tareas[1].recurso = "Personal Casa";
    tareas[1].tiempo_inicio = 0;

    // Tarea C
    tareas[2].id = "C";
    tareas[2].descripcion = "Empacar maletas";
    tareas[2].duracion = 40;
    tareas[2].recurso = "Personal Casa";
    tareas[2].tiempo_inicio = 5;  // Después de B

    // ... y así sucesivamente para todas las tareas
    // Tarea D
    tareas[3].id = "D";
    tareas[3].descripcion = "Preparacion del billete";
    tareas[3].duracion = 10;
    tareas[3].recurso = "Asistente";
    tareas[3].tiempo_inicio = 20;  // Después de A

    // Resto de tareas...
    // (Las incluyo resumidas para simplicidad)
    tareas[4] = {"E", "Recoger el billete", 5, "Asistente", 30};
    tareas[5] = {"F", "Llevar el billete", 10, "Asistente", 35};
    tareas[6] = {"G", "Recoger las maletas", 20, "Personal Casa", 45};
    tareas[7] = {"H", "Llevar maletas", 25, "Personal Casa", 65};
    tareas[8] = {"I", "Conversacion documentos", 35, "Ejecutivo", 20};
    tareas[9] = {"J", "Dictar instrucciones", 25, "Ejecutivo", 55};
    tareas[10] = {"K", "Reunir documentos", 15, "Asistente", 55};
    tareas[11] = {"L", "Organizar documentos", 5, "Ejecutivo", 70};
    tareas[12] = {"M", "Viajar al aeropuerto", 25, "Ejecutivo", 75};

    // Mostrar la programación para cada recurso
    cout << "\n=== PROGRAMACION POR RECURSO ===\n" << endl;

    // Array con los nombres de los recursos
    string recursos[3] = {"Ejecutivo", "Asistente", "Personal Casa"};

    // Para cada recurso
    for(int i = 0; i < 3; i++) {
        cout << "\nTareas para " << recursos[i] << ":" << endl;
        cout << "--------------------------------" << endl;
        cout << "Tarea | Descripcion | Inicio | Fin | Duracion" << endl;
        cout << "--------------------------------" << endl;

        // Buscar todas las tareas de este recurso
        for(int j = 0; j < 13; j++) {
            if(tareas[j].recurso == recursos[i]) {
                cout << tareas[j].id << " | "
                     << tareas[j].descripcion << " | "
                     << tareas[j].tiempo_inicio << " | "
                     << tareas[j].tiempo_inicio + tareas[j].duracion << " | "
                     << tareas[j].duracion << " min" << endl;
            }
        }
    }

    // Calcular tiempo total del proyecto
    int tiempo_maximo = 0;
    for(int i = 0; i < 13; i++) {
        int tiempo_fin = tareas[i].tiempo_inicio + tareas[i].duracion;
        if(tiempo_fin > tiempo_maximo) {
            tiempo_maximo = tiempo_fin;
        }
    }

    cout << "\nTiempo total del proyecto: " << tiempo_maximo << " minutos" << endl;

    return 0;
}

