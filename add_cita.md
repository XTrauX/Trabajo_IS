# **Añadir nueva cita**
**ID:** 09 **Descripción:** Se crea una nueva cita.

**Actores principales:** Secretario.    **Actores secundarios:** Ninguno.

**Precondiciones:**
- Acceder al paciente a través de consultar un paciente o lista de pacientes.

**Flujo principal:**
1. El secretario desea añadir una nueva cita.
2. El secretario accede a un paciente.
3. El secretario abre el cuadro de dialogo de añadir una nueva cita.
4. El sistema le pide los datos al secretario sobre la nueva cita.


**Postcondiciones:**
- Ninguna.

**Flujos alternativos:**
- Si existe otra cita en la misma hora se muestra un mensaje de error avisando que ya hay una cita a esa hora.
- Si no es posible crear una nueva cita se muestra un mensaje de error.
