# Get Next Line - Read a line from a file descriptor

![42BCN - GNL](https://github.com/Droied4/get_next_line/assets/69441843/3cad41ae-e166-4b45-bd04-a08fb999c10f)

## Description
The `get_next_line` project is a programming exercise that challenges you to implement a function capable of reading a line from a file descriptor. The primary goal is to develop a function that allows reading from a file descriptor efficiently, providing a line-by-line extraction from the given input. This project introduces the concept of static variables and encourages a deeper understanding of memory management and file I/O in the C programming language.

## Instructions

### 1. Compiling the archives

To compile the proiect, go to its path and run:

For __mandatory__ functions:
```
$ make
```
### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```
$ make fclean
```
### 3. Usage

- **Prototype:** `char *get_next_line(int fd);`
- **Parameters:**
  - 📁 `fd`: The file descriptor to read from.
- **Return value:**
  - 📜 Read line: Returns the next line from the specified file descriptor.
  - `🚫 NULL`: Indicates there is nothing else to read or an error occurred.
- **External functions:** `📖 read`, `🛠️ malloc`, `🗑️ free`
- **Description:** Writes a function that reads from a file descriptor (`fd`) and returns the next line of text.

## Repository Structure

```sh
└── get_next_line/
    ├── get_next_line.c
    ├── get_next_line.h
    ├── get_next_line_bonus.c
    ├── get_next_line_bonus.h
    ├── get_next_line_utils.c
    └── get_next_line_utils_bonus.c

```

---

## Info +

### ➡️ [Linkedin Profile](https://www.linkedin.com/in/droied/) ⬅️
![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)
### ➡️ [Intra Profile](https://profile.intra.42.fr/users/deordone) ⬅️
[![deordone 42 stats](https://badge.mediaplus.ma/DarkBlue/deordone)](https://github.com/oakoudad/badge42)
### ⬇️ [_Developed in_](nothing) ⬇️
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) 
### ⬇️ [_Version Control_](nothing) ⬇️
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
### ⬇️ [_Status_](nothing) ⬇️
[![archive](https://github.com/GIScience/badges/raw/master/status/archive.svg)](https://github.com/GIScience/badges#archive)
