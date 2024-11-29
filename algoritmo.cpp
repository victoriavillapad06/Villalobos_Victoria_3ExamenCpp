//
// Created by victo on 28/11/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "algoritmo.h"

#include "Clases/Task.h"
using namespace std;


std::vector<std::shared_ptr<Task>> Load_Preset() {
    std::vector<std::shared_ptr<Task>> tasks;

    // Crear tareas y agregarlas al vector
    tasks.push_back(std::make_shared<Task>("Reserva de vuelo", 20)); // tasks[0]
    tasks.push_back(std::make_shared<Task>("Informar a casa para empacar", 5, WorkerType::CEO)); // tasks[1]
    tasks.push_back(std::make_shared<Task>("Empacar maletas", 40, std::vector<std::shared_ptr<Task>>{tasks[1]})); // tasks[2]
    tasks.push_back(std::make_shared<Task>("Preparación del billete por la agencia", 10, WorkerType::AGENCY, std::vector<std::shared_ptr<Task>>{tasks[0]})); // tasks[3]
    tasks.push_back(std::make_shared<Task>("Recoger el billete de la agencia", 5, std::vector<std::shared_ptr<Task>>{tasks[0], tasks[3]})); // tasks[4]
    tasks.push_back(std::make_shared<Task>("Llevar el billete a la oficina", 10, std::vector<std::shared_ptr<Task>>{tasks[4]})); // tasks[5]
    tasks.push_back(std::make_shared<Task>("Recoger las maletas de casa", 20, std::vector<std::shared_ptr<Task>>{tasks[2]})); // tasks[6]
    tasks.push_back(std::make_shared<Task>("Llevar maletas a la oficina", 25, std::vector<std::shared_ptr<Task>>{tasks[6]})); // tasks[7]
    tasks.push_back(std::make_shared<Task>("Conversación sobre documentos requeridos", 35, std::vector<std::shared_ptr<Task>>{tasks[5]})); // tasks[8]
    tasks.push_back(std::make_shared<Task>("Dictar instrucciones para ausencia", 25, WorkerType::CEO)); // tasks[9]
    tasks.push_back(std::make_shared<Task>("Reunir documentos", 15, std::vector<std::shared_ptr<Task>>{tasks[8]})); // tasks[10]
    tasks.push_back(std::make_shared<Task>("Organizar documentos", 5, std::vector<std::shared_ptr<Task>>{tasks[10]})); // tasks[11]
    tasks.push_back(std::make_shared<Task>("Viajar al aeropuerto y facturar", 25, WorkerType::CEO,
                                           std::vector<std::shared_ptr<Task>>{tasks[7], tasks[4], tasks[11]})); // tasks[12]

    return tasks;
}



int algoritm() {

    std::vector<Worker> workers = {
        Worker(WorkerType::CEO),
        Worker(WorkerType::AGENCY),
        Worker(WorkerType::GENERIC),
        Worker(WorkerType::GENERIC),
        Worker(WorkerType::GENERIC),
        Worker(WorkerType::GENERIC)
    };

    auto tasks = Load_Preset(); // Cargar las tareas predefinidas
    int time = 0;
    bool allTasksCompleted = false;

    // Mientras haya tareas incompletas
    while (!allTasksCompleted) {
        allTasksCompleted = true; // Suponemos que todas las tareas están completas al inicio de cada iteración
        time++; // Incrementar el tiempo simulado

        //std::cout << "--------------------------------" << std::endl;
        //std::cout << "Tiempo: " << time << std::endl;

        // Ordenar tareas por duración ascendente (las más rápidas primero)
        std::vector<std::shared_ptr<Task>> sorted_tasks = tasks;
        std::sort(sorted_tasks.begin(), sorted_tasks.end(), [](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) {
            return a->getDuration() < b->getDuration();
        });

        // Intentar asignar tareas a los trabajadores disponibles
        for (auto& worker : workers) {
            if (!worker.getState()) { // Si el trabajador está libre
                for (auto& task : sorted_tasks) {
                    if (task->can_be_done() && !task->isCompleted() && !task->getWorker()) {
                        if (worker.assignTask(task)) {
                            std::cout << "--------------------------------" << std::endl;
                            std::cout << "Tiempo: " << time << std::endl;
                            std::cout << "Tarea: " << task->getName() << " - Asignada a trabajador: " << worker.get_type() << std::endl;
                            break; // Asignar solo una tarea al trabajador
                        }
                    }
                }
            }
        }

        // Progresar el trabajo de todos los trabajadores
        for (auto& worker : workers) {
            worker.Update();
        }

        // Verificar si todas las tareas están completas
        for (const auto& task : tasks) {
            if (!task->isCompleted()) {
                allTasksCompleted = false; // Si al menos una tarea no está completa, seguimos
            }
        }
    }


    //cout << "--------------------------------" << endl;
    //for (auto& worker : workers) {
    //    worker.displayWorkerInfo();
    //    cout << "===" << endl;
    //}

    return time;
}