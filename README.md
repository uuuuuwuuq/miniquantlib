# MiniQuantLib 📊

Welcome to **MiniQuantLib**, a minimal C++ library designed for vector and matrix operations. This library aims to explore numerical computing and performance-oriented design. Whether you are a student, researcher, or professional, MiniQuantLib provides the tools you need for efficient mathematical computations.

[![Latest Release](https://img.shields.io/github/release/uuuuuwuuq/miniquantlib.svg)](https://github.com/uuuuuwuuq/miniquantlib/releases)

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features

MiniQuantLib offers a variety of features for users interested in linear algebra and numerical computation:

- **Vector Operations**: Perform basic operations like addition, subtraction, and scalar multiplication.
- **Matrix Operations**: Execute matrix addition, multiplication, and transposition.
- **Template Metaprogramming**: Leverage C++ templates for type-safe operations.
- **Performance**: Designed with performance in mind, suitable for quantitative finance and scientific computing.
- **Lightweight**: Minimal dependencies make it easy to integrate into existing projects.

## Installation

To get started with MiniQuantLib, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/uuuuuwuuq/miniquantlib.git
   cd miniquantlib
   ```

2. **Build the Library**:
   You can build the library using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run Tests** (optional):
   After building, you can run the tests to ensure everything works as expected:
   ```bash
   make test
   ```

For pre-built binaries, check the [Releases section](https://github.com/uuuuuwuuq/miniquantlib/releases) to download the latest version.

## Usage

Using MiniQuantLib is straightforward. Below are some examples to get you started.

### Vector Operations

```cpp
#include "miniquantlib/vector.h"

int main() {
    Vector v1(3);
    Vector v2(3);

    v1[0] = 1.0; v1[1] = 2.0; v1[2] = 3.0;
    v2[0] = 4.0; v2[1] = 5.0; v2[2] = 6.0;

    Vector v3 = v1 + v2; // Vector addition
    // v3 now contains [5.0, 7.0, 9.0]
}
```

### Matrix Operations

```cpp
#include "miniquantlib/matrix.h"

int main() {
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    m2(0, 0) = 5; m2(0, 1) = 6;
    m2(1, 0) = 7; m2(1, 1) = 8;

    Matrix m3 = m1 * m2; // Matrix multiplication
    // m3 now contains [[19, 22], [43, 50]]
}
```

### Template Metaprogramming

MiniQuantLib utilizes C++ templates to allow for type-safe operations. This ensures that your code is both efficient and easy to read.

```cpp
template<typename T>
T dot_product(const Vector<T>& v1, const Vector<T>& v2) {
    T result = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}
```

## Documentation

Comprehensive documentation is available to help you navigate through the library's features and functionalities. You can find it [here](https://github.com/uuuuuwuuq/miniquantlib/wiki).

## Contributing

We welcome contributions from the community. To contribute:

1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Submit a pull request.

Please ensure your code follows the existing style and includes tests for new features.

## License

MiniQuantLib is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact

For questions or feedback, please reach out via the GitHub issues page or directly through email.

---

For the latest releases, visit [this link](https://github.com/uuuuuwuuq/miniquantlib/releases) to download and execute the necessary files. Your contributions and feedback are invaluable to the growth of MiniQuantLib. Happy coding!