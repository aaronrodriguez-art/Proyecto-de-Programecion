# Proyecto de programacion 

# Sistema de gestion de una planilla hospitalaria

## Integrantes 
Ariana Castro Garita - 208550745
Keylor Mitchell Bejarano -
Aaron Rodriguez Lozano -

## Instrucciones de compilación
1. Descargar el archivo .zip desde el respositorio.
2. Descomprimir el archivo.
3. Abrir el proyecto en Zinjai.
4. Compilar para confirmar que no hay errores.
5. Ejecutar el proyecto desde Zinjai.

## Guía de uso

Una vez ejecutado el programa aparece el siguiente menu de opciones:

1. Registrar departamento.
   Esta opción solicita el código del departamento, nombre, confirmación para agregar un puesto y si lo agrega se va a
   solicitar un código y el nombre del puesto. Cuando finalice se confirma que el departamento fue registrado.
   ## EL CODIGO Y EL NOMBRE NO PUEDEN IR VACIOS. Tampoco permite registrar un departamento codigo que se repita ni puestos
   ## duplicados en el mismo departamento. 
3. Mostrar departamentos.
   Esta opción permite mostrar la información de los departamentos.
5. Registrar empleado.
   Esta opción permite registrar un empleado. Primero pregunta si es: médico, enfermero, administración. Al seleccionar alguna de esas opciones solicita como datos generales: nombre, cedula y código del empleado. Adicionalmente, si seleccionó médico pregunta por: especialidad, años de experiencia y turno de guardia. Si seleccionó enfermero: área asignada, confirmación de si está en guardia. Y si es administración: departamento y confirma si tiene un acceso financiero.
   ## NO SE PUEDEN REPETIR CEDULAS REPETIDAD, CEDULAS O CODIGOS NUMERICOS MENORES O IGUAL A CERO, ASI COMO NOMBRES VACIOS O
   ## AÑOS DE EXPERIENCIA NEGATIVOS.
7. Mostrar empleados.
   Esta opción permite mostrar la información de los empleados.
9. Generar un comprobante de pago.
    Esta opción permite generar un comprobante de pago. Este solicita los siguientes datos: cedula del empleado, periodo de pago (ejemplo: noviembre 2026), código del departamento (vacío si no aplica), cantidad de horas trabajadas y monto de bono nocturno o de guarda (0 si no corresponde). Cuando termina se muestra el comprobante con los datos del pago y se guarda la información.
   ## EL EMPLEADO DEBE EXISTIR, PERIODO NO PUEDE ESTAR VACIO Y NO SE PUEDEN CREAR DOS COMPROBANTES PARA UN MISMO EMPLEADO EN EL MISMO PERDIODO. SI SE ANOTA UN DEPARTAMENTE DEBE EXISTIR Y LAS HORAS EXTRA Y DE BONO NO PUEDE SER NEGATIVO.
11. Mostrar todos los comprobantes de pago.
    Esta opción muestra todos los comprobantes de pago en el sistema.
13. Mostrar comprobantes de un empleado.
    Esta opción muestra el comprobante de un empleado. Solo solicita la cedula para mostrarlo.
15. Total de la planilla por periodo.
    Esta opción muestra el monto neto TOTAL que debe pagarse. Solo solicita el periodo de pago para calcular y mostrar de la suma correspondiente a el periodo.
17. Eliminar comprobante.
    Esta opción permite eliminar un comprobante de pago ya registrado. Esta solo solicita el código del comprobante que quiere eliminar. Si existe se elimina, pero sino existe sale el respectivo mensaje que informa que no existe.
19. Guardar datos.
    Esta opción permite guardar manualmente la información actual del sistema en los archivos de texto.
0. Salir (guarda antes de cerrar).
   Esta opción finaliza la ejecución del programa.

   ## Archivos de texto
   En los archivos llamados: departamentos.txt, empleados.txt y planilla.txt, se muestra la información ingresada en las respectivas opciones.

