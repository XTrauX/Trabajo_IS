# **Requisitos**
## **Requisitos funcionales:**

  - Buscar un paciente.
  - Buscar un paciente por nombre.
  - Buscar un paciente por apellido.
  - Consultar un paciente.
  - Consultar cita/s diarias.
  - Consultar cita/s de un paciente.
  - Consultar historial médico.
  - Consultar tratamiento médico de un paciente.
  - Consultar lista de los pacientes.
  - Añadir historial médico.
  - Añadir cita.
  - Añadir paciente.
  - Añadir tratamiento médico.
  - Modificar/Cancelar cita.
  - Modificar/Eliminar paciente.
  - Modificar/Eliminar tratamiento.

## **Requisitos no funcionales**

  - Preferiblemente que la aplicación software tenga una interfaz de ventana.
  - No borrar el historial de clientes cuando dejen de venir.
  - No modificar el historial médico de los clientes.
  - Preguntar si está seguro de añadir un historial médico.
  - Preguntar si está seguro de borrar algo antes de eliminarlo.
  - Es importante que las citas no se solapen.
  - Primero en aparecer al iniciar la aplicación software que sean las citas del día.
  - Tiene que funcionar en un sistema operativo Linux.
  - Pacientes mostrados por orden alfabético.

## **Campos de los datos**

  - **Paciente:**

    + Apellidos
    + Nombre
    + Dirección postal
    + Fecha de nacimiento
    + Teléfono de contacto
    + Seguro de salud
    + Tratamiento actual
    + Enfermedad actual

  - **Cita:**

    + Id
    + Fecha
    + Hora
    + Duración

  - **Historial médico:**

    + Enfermedades
    + Síntomas
    + Causas de la cita

  - **Tratamiento:**

    + Id
    + Medicamento
    + Concentración/regularidad
    + Fecha
    + Regularidad
    + Estado
    + Notas
