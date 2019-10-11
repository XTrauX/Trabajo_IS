**ID:** 01 **Nombre:** Buscar un paciente por apellido

**Prioridad** (de 1 a 5): 5 **Puntos estimado:** 2 **Iteración:** 1

**Responsable:** Tomás Marín Sanz

**Descripción**

Como *secretario* quiero *buscar a un paciente* para *poder consultar su información y ejecutar las operaciones relacionadas*

**Validación**

- Se podrá buscar cualquier paciente.
- No hará falta introducir los dos apellidos.
- Si existen varios resultados en la búsqueda se dará opción a elegir entre ellos.
- Contempla que no se encuentre nada.
- Se debe mostrar la operación *consultar paciente*.


**ID:** 02 **Nombre:** Consultar paciente

**Prioridad** (de 1 a 5): 5 **Puntos estimado:** 1 **Iteración:** 3

**Responsable:** Tomás Marín Sanz

**Descripción**

Como *secretario* quiero *consultar los datos de un paciente* para *conseguir información y realizar las operaciones posibles*

**Validación**

- Se podrá consultar cualquier paciente.
- Será representada la falta de información si la hay.
- Deberá mostrar todos los datos del paciente.
- Deberá mostrar las operaciones posibles sobre el paciente.


**ID:** 03 **Nombre:** Consultar cita/s diaria/s

**Prioridad** (de 1 a 5): 5 **Puntos estimado:** 2 **Iteración:** 1

**Responsable:** Carlos Revuelto Quero

**Descripción**

Como *secretario* quiero *consultar las citas que tengo hoy* para *saber que tengo que hacer*

**Validación**

- Deberá mostrar solo las citas de los pacientes de el día en el que se encuentre.
- Se deberá contemplar si no hay citas en ese día.
- Deberá mostrar el nombre completo del paciente y a la hora que será la cita.
- Deberá mostrar las citas por orden cronológico.
- No mostrará las citas que ya hayan ocurrido en el día.


**ID:** 04 **Nombre:** Consultar cita de un paciente

**Prioridad** (de 1 a 5): 4 **Puntos estimado:** 1 **Iteración:** 2

**Responsable:** Carlos Revuelto Quero

**Descripción**

Como *secretario* quiero *consultar las citas que tiene un paciente* para *obtener información y realizar las operaciones correspondientes*

**Validación**

- Se podrá realizar con cualquier paciente.
- Deberá contemplar si no hay citas.
- Debe mostrar las citas tanto del pasado como las que no  han ocurrido.
- Deberá mostrar la fecha y hora de la cita.
- Deberá mostrar la opción de *modificar cita*.


**ID:** 05 **Nombre:** Consultar historial médico de un paciente

**Prioridad** (de 1 a 5): 3 **Puntos estimado:** 1 **Iteración:** 2

**Responsable:** Tomás Marín Sanz

**Descripción**

Como *secretario* quiero *consultar el historial médico de un paciente* para *conocer su información para tratarla*

**Validación**

- Se podrá realizar con cualquier paciente.
- Se mostrarán todos lo datos del historial.
- Se deberá contemplar si no tiene historial.


**ID:** 06 **Nombre:** Consultar tratamientos de un paciente

**Prioridad** (de 1 a 5): 3 **Puntos estimado:** 1 **Iteración:** 2

**Responsable:** Carlos Revuelto Quero

**Descripción**

Como *secretario* quiero *consultar los tratamientos de un paciente* para *obtener información, actuar acorde y realizar las operaciones posibles*

**Validación**

- Se podrá realizar con cualquier paciente.
- Se deberá contemplar si no tiene ningún tratamiento.
- Se deberán mostrar todos lo datos de los tratamientos.
- Se deberán mostrar las operaciones posibles.

**ID** 07 **Nombre:** Consultar lista de pacientes

**Prioridad** (de 1 a 5): 1 **Puntos estimado:** 1 **Iteración** 1

**Responsable:** Luis Revuelto Martínez

**Descripción**

Como *secretario* quiero *consultar todos los pacientes que tengo* para *obtener información y realizar la operación posible*

**Validación**

- Se deberán mostrar a todos los pacientes.
- Se deberá contemplar si no hay pacientes.
- Se deberá poder elegir a cualquier paciente que se quiera para consultarlo.
- Deberá estar ordenado por orden alfabético por apellidos.
- Deberá mostrar apellidos y nombre en ese orden.


**ID** 08 **Nombre:** Añadir un nuevo historial médico

**Prioridad** (de 1 a 5): 3 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Luis Revuelto Martínez

**Descripción**

Como *secretario* quiero *añadir un historial médico a un paciente* para *actualizar su historial*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- No deberá afectar al historial previo, si lo tiene.
- Deberá almacenar la fecha junto con el historial.
- Deberá preguntar si se está seguro de añadir el historial, mostrándolo por pantalla.


**ID** 09 **Nombre:** Añadir nueva cita

**Prioridad** (de 1 a 5): 4 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Tomás Marín Sanz

**Descripción**

Como *secretario* quiero *anotar una cita de un paciente* para *saber cuando tengo cita con el paciente*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- Deberá pedir la fecha en la que se realice la cita.
- Deberá comprobar que no hay una cita en la fecha seleccionada.
- No se podrá añadir una cita a una fecha del pasado.


**ID** 10 **Nombre:** Añadir nuevo paciente

**Prioridad** (de 1 a 5): 5 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Tomás Marín Sanz

**Descripción**

Como *secretario* quiero *anotar a un nuevo paciente* para *tenerlo guardado en mi sistema*

**Validación**

- Podrá añadir a cualquier paciente.
- Se deberán pedir todos los datos que se deban.
- Se deberá comprobar si el paciente a añadir ya existe.
- Pedirá de forma obligatoria el nombre completo, el teléfono de contacto o la dirección postal.


**ID** 11 **Nombre:** Añadir nuevo tratamiento

**Prioridad** (de 1 a 5): 3 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Luis Revuelto Martínez

**Descripción**

Como *secretario* quiero *añadirle  un tratamiento a un paciente* para *tratar su problema y guardarlo en mi sistema*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- Deberá pedir todos los datos de manera obligatoria menos la anotación.
- No se podrá introducir una fecha del pasado.


**ID** 12 **Nombre:** Modificar una cita

**Prioridad** (de 1 a 5): 4 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Carlos Revuelto Quero

**Descripción**

Como *secretario* quiero *modificar o eliminar una cita con un paciente* para *cambiar la fecha o borrar la cita*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- No se podrá modificar una fecha a otra ya asignada.
- No se podrá modificar o eliminar una cita del pasado.


**ID** 13 **Nombre:** Modificar un paciente

**Prioridad** (de 1 a 5): 1 **Puntos estimado:** 3 **Iteración** 2

**Responsable:** Luis Revuelto Martínez

**Descripción**

Como *secretario* quiero *modificar o eliminar los datos de un paciente de mi sistema* para *actualizar sus datos o borrarlos*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- No se podrá modificar el nombre de un paciente a otro ya existente en el sistema.
- Se deberán borrar todos los datos en relación con ese paciente en caso de decidir eliminarlo.
- Se deberá preguntar si se está seguro de la acción en caso de eliminar un paciente.


**ID** 14 **Nombre:** Modificar un tratamiento

**Prioridad** (de 1 a 5): 3 **Puntos estimado:** 2 **Iteración** 1

**Responsable:** Carlos Revuelto Quero

**Descripción**

Como *secretario* quiero *modificar o eliminar un tratamiento de un paciente* para *actualizar o borrar el tratamiento*

**Validación**

- Se deberá poder realizar con cualquier paciente.
- No se podrá modificar o eliminar un tratamiento del pasado.
- No se podrá cambiar la fecha a una del pasado.
- Se deberá preguntar si se está seguro en caso de eliminar un tratamiento.
