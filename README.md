# Villalobos_Victoria_3ExamenCpp
https://github.com/victoriavillapad06/Villalobos_Victoria_3ExamenCpp.git

-Función Load_Preset()-Crea un vector de punteros compartidos tasks que almacena tareas.
Cada tarea se define con los siguientes atributos:
Un nombre descriptivo (Task("Nombre", duración, ...)).
Una duración en unidades de tiempo.
Dependencias opcionales: tareas que deben completarse antes de que esta pueda comenzar.
Tipo de trabajador requerido, si aplica.
-Función algoritm
Flujo General de la Simulación
La lógica de la función algoritm() Esta función organiza la simulación para completar todas las tareas usando un conjunto de trabajadores.
-Configurar los trabajadores y tareas:
Se cargan los trabajadores con sus roles específicos.
Se cargan las tareas predefinidas con sus dependencias.
-Bucle principal:
El programa iterará en un ciclo while hasta que todas las tareas sean completadas (allTasksCompleted = true).
-Dentro del bucle:
Se verifica el estado de cada trabajador y tarea.
Se asignan tareas a trabajadores disponibles, respetando dependencias y restricciones.
Los trabajadores progresan en sus tareas asignadas.
Se verifica si todas las tareas están completas para decidir si el ciclo debe continuar.
-Finalizar la simulación:
Cuando todas las tareas estén completas, el bucle while termina.
Se devuelve el tiempo total (time) que tomó completar todas las tareas.
- Estructura General del Bucle while
  Objetivo: Continuar mientras haya tareas pendientes de completar.
La variable allTasksCompleted indica si todas las tareas han sido completadas. Se asume inicialmente que todas están completas en cada iteración.
Inicializar: Asumir que todas las tareas están completas y comenzar a simular el tiempo.
Ordenar las tareas por duración para priorizar las más rápidas.
Asignar tareas a trabajadores disponibles que cumplan con las condiciones.
Actualizar el estado de todos los trabajadores para reflejar el progreso de las tareas.
Verificar si hay tareas pendientes.
Repetir el proceso hasta que todas las tareas estén completadas.
Devolver el tiempo total de la simulación.


-Task
Una tarea puede tener:
Dependencias que deben completarse antes de que esta comience.
Un tipo de trabajador específico requerido para completarla.
Durante la simulación:
Se verifica si la tarea puede realizarse usando can_be_done().
Si un trabajador adecuado está disponible, se le asigna la tarea usando setWorker().
El tiempo restante se reduce progresivamente mediante Update().
Cuando el tiempo restante llega a 0, la tarea se marca como completada mediante isCompleted().

-Worker
La clase Worker gestiona a los trabajadores en un entorno donde:
Los trabajadores tienen roles específicos (CEO, AGENCY, GENERIC).
Cada trabajador puede manejar una tarea a la vez.
Se verifica que la tarea asignada sea apropiada para el tipo de trabajador.
Proporciona mecanismos para monitorear y actualizar el progreso de las tareas asignadas.
Esta implementación asegura que los trabajadores operen dentro de las restricciones de roles y que las tareas se asignen y completen correctamente.
---Clase Task
Atributos principales:
Nombre de la tarea: std::string name define el identificador único de la tarea.
Duración total: int duration especifica el tiempo necesario para completar la tarea.
Tiempo restante: int remaining_time controla cuánto tiempo queda para finalizar la tarea.
Trabajador asignado: Worker* assigned_worker señala al trabajador que está realizando la tarea.
Tipo de trabajador requerido: WorkerType worker_type define qué tipo de trabajador puede realizar la tarea.
Dependencias: std::vector<std::shared_ptr<Task>> dependencies almacena las tareas que deben completarse antes de iniciar esta tarea.
---Clase Worker
Atributos principales:
Tipo del trabajador: WorkerType type es una propiedad fija que define el rol del trabajador (CEO, AGENCY, GENERIC).
Tarea actual: std::shared_ptr<Task> currentTask apunta a la tarea que el trabajador está ejecutando en un momento dado.
Aceptación de tareas específicas: bool specific_task indica si el trabajador solo puede realizar tareas específicas o acepta cualquier tarea compatible con su tipo.
Flujo de la Simulación
Inicialización de tareas:
Se crea un vector de tareas, incluyendo su configuración inicial como duración, dependencias, y el tipo de trabajador necesario.
Definición de trabajadores:
Un vector de trabajadores se configura con roles específicos, como CEO, AGENCY, o GENERIC, y se indica si aceptan tareas específicas.
Simulación paso a paso:
Se avanza minuto a minuto en el tiempo simulado.
Las tareas pendientes se analizan para determinar si sus dependencias se han cumplido.
Las tareas disponibles se asignan a trabajadores libres, respetando las restricciones de tipo de trabajador y dependencias.
Los trabajadores progresan en sus tareas, y las tareas completadas liberan a los trabajadores.
Reporte de resultados:
Al finalizar, se imprimen los detalles de las tareas completadas, el tiempo total de la simulación y el rendimiento de los trabajadores.
Este enfoque organiza de manera estructurada la ejecución y gestión de las tareas y trabajadores, optimizando el flujo de trabajo y asegurando que se respeten las dependencias y restricciones del sistema.








