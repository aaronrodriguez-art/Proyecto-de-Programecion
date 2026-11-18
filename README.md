# Sistema de gestión de una planilla hospitalaria

Proyecto desarrollado en C++ para administrar los departamentos, el personal y el cálculo de planillas de un hospital mediante persistencia en archivos de texto.

## Integrantes
* Ariana Castro Garita — `208550745`
* Keylor Mitchell Bejarano — `703380088`
* Aaron Rodriguez Lozano — `209100389`

## Instrucciones de compilación
1. Descargá el archivo `.zip` desde este repositorio o cloná el proyecto.
2. Descomprimí la carpeta en tu computadora.
3. Abrí el archivo de proyecto (`.zpr`) en **Zinjai**.
4. Compilá para verificar que no existan errores.
5. Ejecutá el programa desde el mismo entorno.

## Guía de uso

Al iniciar la aplicación se desplegará el menú principal con las siguientes opciones:

1. **Registrar departamento**  
   Solicita el código y el nombre del departamento. Luego consulta si deseás agregar un puesto (pidiendo su código y nombre en caso afirmativo) y confirma el registro al finalizar.  
   > **Validaciones:** El código y el nombre no pueden quedar vacíos. No se permiten códigos de departamento repetidos ni puestos duplicados dentro de un mismo departamento.

2. **Mostrar departamentos**  
   Despliega en pantalla el listado de departamentos registrados junto con sus puestos asociados.

3. **Registrar empleado**  
   Permite ingresar personal seleccionando previamente el rol: **Médico**, **Enfermero** o **Administración**.  
   * **Datos generales:** Nombre, cédula y código de empleado.
   * **Médico:** Especialidad, años de experiencia y turno de guardia.
   * **Enfermero:** Área asignada y confirmación de turno de guardia.
   * **Administración:** Departamento asignado y confirmación de acceso financiero.  
   > **Validaciones:** No se permiten cédulas duplicadas, cédulas o códigos numéricos menores o iguales a cero, nombres vacíos ni años de experiencia negativos.

4. **Mostrar empleados**  
   Muestra la información completa de todos los colaboradores registrados en el sistema.

5. **Generar un comprobante de pago**  
   Solicita la cédula del empleado, el período de pago (ej. *noviembre 2026*), el código del departamento (opcional, puede dejarse vacío), la cantidad de horas trabajadas y el monto por bono nocturno o de guardia (`0` si no aplica). Al finalizar, imprime el comprobante y guarda el registro.  
   > **Validaciones:** El empleado debe existir, el período no puede ir vacío y no se permite generar dos comprobantes para un mismo empleado en el mismo período. Si se indica un departamento, este debe existir. Las horas y montos de bono no pueden ser negativos.

6. **Mostrar todos los comprobantes de pago**  
   Lista todos los comprobantes generados hasta el momento.

7. **Mostrar comprobantes de un empleado**  
   Solicita la cédula de un empleado y muestra únicamente su historial de comprobantes.

8. **Total de la planilla por periodo**
