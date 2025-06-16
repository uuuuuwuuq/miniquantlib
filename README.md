# miniquantlib

a lightweight, header-only c++ numerical library for vectors and matrices. this project is built from scratch to reinforce understanding of low-level data structures, linear algebra, and performance-oriented c++ development. it is inspired by eigen and boost but intentionally minimal and educational.

---

## features

- templated `vector<T>` and `matrix<T>` classes
- basic arithmetic: addition, subtraction, scalar multiplication
- dot product and vector norms
- matrix-vector multiplication
- matrix transposition
- random utility functions (uniform sampling)
- header-only design for easy integration

---

## directory structure
```bash
miniquantlib/
├── include/
│ ├── vector.hpp # vector implementation
│ ├── matrix.hpp # matrix implementation
│ └── utils.hpp # random number utilities
├── tests/
│ └── test_main.cpp # basic test and demo code
└── CMakeLists.txt # cmake build configuration
```

---

## build instructions

### prerequisites

- c++20 compatible compiler
- cmake 3.10 or higher

### steps

```bash
git clone https://github.com/yourusername/miniquantlib.git
cd miniquantlib
mkdir build && cd build
cmake ..
make
./test_exec
```
you can also open the project in clion and run it directly.

---

## usage example
```bash
#include "vector.hpp"
#include "matrix.hpp"

mql::vector<double> v = {1.0, 2.0, 3.0};
std::cout << "norm: " << v.norm() << "\n";

mql::matrix<double> a(2, 3);
a(0, 0) = 1.0; a(0, 1) = 2.0; a(0, 2) = 3.0;
// ...
std::cout << "a * v: " << (a * v) << "\n";
```
