#include <iostream>
int** create(size_t rows, size_t cols);
void remove(int** m, size_t rows, size_t cols);
void input(int** m, size_t rows, size_t cols);
void output(const int* const* m, size_t rows, size_t cols);
int** convert(const int* t, size_t n, const size_t* lns, size_t rows);

int main(){
	size_t rows = 0, cols = 0;
	std::cin >> rows >> cols;
	if (!std::cin) {
		return 1;
	}
	std::cout << rows << " "<< cols;
	std::cout << "\n";
}

void input(int** m, size_t rows, size_t cols) {}

void output(const int* const* m, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << m[i][j];
            if (j + 1 < cols) std::cout << " ";
        }
        std::cout << "\n";
    }
}

int** create(size_t rows, size_t cols) {
    int** result = new int*[rows];
    size_t i = 0;
    try {
        for (; i < rows; ++i) {
            result[i] = new int[cols];
        }
    }
    catch (...) {
        for (size_t j = 0; j < i; ++j) {
            delete[] result[j];
        }
        delete[] result;
        throw;
    }
    return result;
}

void remove(int** m, size_t rows, size_t /*cols*/) {
    if (m == nullptr) return;
    for (size_t i = 0; i < rows; ++i) {
        delete[] m[i];
    }
    delete[] m;
}
