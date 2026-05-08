# Object Oriented Programming 101
This repository contains the revisited source code of a project originally developed as part of a **Object Oriented Programming** course at **UTC** during the **Spring 2023** semester.

While the project is simple, the work here was an opportunity to learn CMake, Qt, and idiomatic C++ (RAII, STL) by applying real-world software engineering practices to the project.

## The project

The project was to be completed during the semester by groups of four to five. In addition to the source code, students were required to write three intermediary reports during the semester and a final report.

To preserve the confidentiality of the original academic material, the following instructions are descriptions based on the original, rather than exact reproductions.

### Schotten Totten

**Schotten Totten** is a 2-player card game where players compete to win "stones" (or territories) on a battlefield. By forming card combinations (e.g., three of a kind, run) on each stone, players try to outscore their opponents and secure the majority of stones.

### Specifications 
The project was to design and develop a **C++** application which allowed us to play the **Schotten Totten** card game. 

The project specification was as follows:
- Every functionalities of the original game were to be implemented
- Either or both player could be an "AI"
- The game must be playable at least using a CLI, at best a Qt GUI
- The application architecture should be easily extensible, allowing a selection of new functionalities to be added with minimal refactoring.

## Quality and CI/CD Processes
This project code quality and non-regression is ensured through a multitude of means, described as follows.

### Branching Strategy
This repository follows a GitHubflow branching strategy.

### Static Code Analysis

- **Linting**: Security, deprecation and standard compliance are strictly ensured through ``clang-tidy`` and ``-Werror`` option. Warnings may only be ignored when compliance is impossible.

- **Code Style Enforcement**: Homogenous code style is ensured through ``clang-format``.

- **Pipeline Integration**: Each merge request on the ``main`` branch will trigger both linter and code style checks to ensure code quality.

### Build Verification
- **Build automation**: The project, as well as test programs builds are automated by **CMake**
- **Pipeline Integration**: Each merge request on the ``main`` branch will trigger a build test to ensure code validity.

### Automated Testing

- **Unit tests**: Core functionalities of both assignments are covered by associated test programs written using the **Google Test** test framework.
- **Pipeline Integration**: Each merge request on the ``main`` branch will run test artifacts to ensure non-regression. Moreover, a verification is run monthly.

### Automated Delivery
- **Release creation**: Upon pushing a tag on the ``main`` branch, a new release containing the source code and built binaries is automatically created.

## Getting started
TODO: Getting started, get/build/run the code etc.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute the code as per the terms of the license.


## Acknowledgments

- **Schotten Totten**: Designed by Reiner Knizia and published by IELLO.
