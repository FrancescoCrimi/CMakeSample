# CMakeSample Monorepo

---

This repository is a **monorepo** that collects several sample projects in C and C++ managed with **CMake**. The main goal, and above all, is to **demonstrate the functioning of CMake**. Its configuration is particularly versatile, being designed to support the compilation of **all projects** with **two different toolchains**:
* **MSVC (Microsoft Visual C++)** with dependency management via **Vcpkg**.
* **MinGW-w64 GCC/Clang** via the **MSYS2** environment.

---

## Projects Contained

Here is a list of the projects present in this monorepo:

* ### `CApp`
Project with two console executables and a library in **C**.

* ### `CppApp`
Project with two console executables and a library in **C++**.

* ### `Gtk3App`
A project with two gui executables and a library in **C** and **Gtk3**.

* ### `Gtk4App`
A project with two gui executables and a library in **C** and **Gtk4**.

* ### `GtkmmApp`
A gui project in **C++** and **Gtkmm4**.

* ### `SQLiteApp`
A console project in **C** that uses the **SQLite** library.

* ### `SQLiteCppApp`
A console project in **C++** that uses the **SQLiteCpp** library.

---

## How to Build the Project

To build this monorepo, it is essential to have **CMake**, **Ninja**, **Vcpkg** or **MSYS2** installed and configured correctly. The `CMakePresets.json` is configured to simplify the build process with both toolchains.

### Building with MSVC (Microsoft Visual C++) and Vcpkg
* Make sure that `VCPKG_ROOT` is set correctly in your environment (e.g., `C:\path\to\your\vcpkg`).
* Install the necessary project dependencies (e.g., SQLiteCpp) for the MSVC toolchain

### Building with MSYS2 (MinGW-w64 GCC/Clang)
* **Make sure that the `bin` directory of your MSYS2 installation (e.g., `C:\msys64\mingw64\bin`) is included in your system or terminal session's PATH.** This allows CMake and the build system to find the GCC/Clang compilers and other utilities.
* Make sure you have installed the necessary libraries via MSYS2's `pacman` (e.g. `pacman -S mingw-w64-x86_64-sqlite3` for SQLite, if you don't manage it with Vcpkg for this toolchain).

---

## Projects and Tools Used

This monorepo makes extensive use of the following technologies and libraries, which are essential for its setup and operation:

* **[SQLite](https://www.sqlite.org/index.html)**: A lightweight, self-contained, embedded SQL database library.
* **[SQLiteCpp](https://github.com/SRombauts/SQLiteCpp)**: A modern C++ wrapper for the SQLite library.
* **[GTK](https://www.gtk.org/)**: The GNU Image Manipulation Program Toolkit, a cross-platform library for creating graphical user interfaces (GUIs).
* **[GTKMM](https://www.gtkmm.org/)**: A set of official C++ wrappers for the GTK library, providing an object-oriented interface.
* **[CMake](https://cmake.org/)**: An open-source, cross-platform tool for managing the software build process. It is the backbone of this monorepo.
* **[Ninja](https://ninja-build.org/)**: A small build system focused on speed, often used as a generator with CMake.
* **[MSYS2](https://www.msys2.org/)**: A software environment and distribution for Windows that provides a Unix-like toolset and a package management system for installing compilers (such as MinGW-w64 GCC/Clang) and libraries.
* **[Vcpkg](https://vcpkg.io/en/index.html)**: A cross-platform C/C++ package manager from Microsoft, used to simplify library acquisition and management.

---
