# Exam03 - Proyectos de 42 School

Este repositorio contiene las implementaciones de las funciones requeridas para el **Exam03 de 42 School**, un examen que evalúa la capacidad de manejar argumentos variables y descriptores de archivo.

---

![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![42 School](https://img.shields.io/badge/42-School-000000.svg)


---

## 📚 Índice de Contenidos

- [Introducción](#introducción)
- [Proyectos del Examen](#proyectos-del-examen)
  - [ft_printf](#ft_printf)
  - [get_next_line](#get_next_line)
- [Cómo Compilar y Probar](#cómo-compilar-y-probar)
- [Conceptos Clave](#conceptos-clave)

---

## Introducción


### ft_printf

Una recreación de la función `printf` de la librería estándar de C. Pone a prueba el manejo de un número variable de argumentos.

### get_next_line

Una función que lee el contenido de un descriptor de archivo línea por línea. Evalúa el manejo de variables estáticas, memoria dinámica y operaciones de lectura.

---

## Proyectos del Examen

### ft_printf

Una función que formatea e imprime datos en la salida estándar.

**Especificadores Soportados:**

- `%s`: Imprime una cadena de caracteres. Maneja el caso `(null)` si el puntero es nulo.
- `%d`: Imprime un número entero decimal con signo. Maneja correctamente el caso `INT_MIN`.
- `%x`: Imprime un número en formato hexadecimal (en minúsculas).

**Archivos:**

- `ft_printf.c`

---

### get_next_line

Una función que devuelve una línea leída de un descriptor de archivo.

**Características:**

- **Lectura Eficiente**: Utiliza un búfer estático para minimizar el número de llamadas al sistema (`read`).
- **Manejo de Múltiples FDs**: Capaz de gestionar la lectura de varios descriptores de archivo simultáneamente (aunque la versión del examen suele probarse con uno solo).
- **Memoria Dinámica**: Asigna la memoria necesaria para cada línea devuelta.

**Archivos:**

- `get_next_line.c`
- `get_next_line.h`

---

## ⚙️ Cómo Compilar y Probar

Para compilar cada proyecto, puedes usar un comando similar al siguiente desde el directorio correspondiente.
Asegúrate de incluir un archivo `main.c` para realizar tus pruebas.
