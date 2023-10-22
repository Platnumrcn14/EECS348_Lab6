#include <iostream>
#include <fstream>
#include <vector>

int main() {
    const char* filename = "matrix_input.txt";

    std::ifstream file(filename);

    if (file.is_open()) {
        int N;
        file >> N;
        
        std::vector<std::vector<int>> matrixA(N, std::vector<int>(N));
        std::vector<std::vector<int>> matrixB(N, std::vector<int>(N));
        std::vector<std::vector<int>> matrixSum(N, std::vector<int>(N));
        std::vector<std::vector<int>> matrixProduct(N, std::vector<int>(N));
        std::vector<std::vector<int>> matrixDiff(N, std::vector<int>(N));

        int num;

        for (int i = 0; i < N * 2; i++) {
            for (int j = 0; j < N; j++) {
                if (file >> num) {
                    if (i < N) {
                        matrixA[i][j] = num;
                    } else {
                        matrixB[i - N][j] = num;
                    }
                }
            }
        }


        file.close();
        std::cout << "Derek Norton" << std::endl;
        std::cout << "Lab #6: Matrix manipulation" << std::endl;
        std::cout << std::endl;
        
        std::cout << "Matrix A:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << matrixA[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Matrix B:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << matrixB[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Matrix Sum (A + B):" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
                std::cout << matrixSum[i][j] << " ";
            }
            std::cout << std::endl;
        } 
        std::cout << std::endl;
        std::cout << "Matrix Product (A * B):" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                matrixProduct[i][j] += matrixA[i][k] * matrixB[k][j];
                }
                std::cout << matrixProduct[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Matrix Difference (A - B):" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
                std::cout << matrixDiff[i][j] << " ";
            }
            std::cout << std::endl;
        }
    
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
    return 0;
}
