# **Buscar un paciente por apellido**
**ID:** 01 **Descripción:** Se busca a un paciente a través de su nombre o apellido.

**Actores principales:** Secretario.    **Actores secundarios:** Ninguno.

**Precondiciones:**
- Ninguna.

**Flujo principal:**
1. El secretario desea buscar un paciente.
2. El secretario abre el cuadro de diálogo de búsqueda del paciente en el menú principal.
3. El secretario introduce el apellido o el nombre del paciente.
4. El sistema muestra por pantalla el paciente y la operación de consultar paciente.

**Postcondiciones:**
- Se muestra al secretario la operación de consultar un paciente.

**Flujos alternativos:**
- Si no existe un paciente se muestra un mensaje de error.
- Si existe más de un paciente con el mismo apellido se muestran para que el secretario elija uno.
- Si existe más de un paciente con el mismo nombre se muestran para que el secretario elija uno.
