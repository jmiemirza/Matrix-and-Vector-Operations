#include "Matrix.h"
#include <iostream>

namespace Matrixnamespace {
	/*Method Implementation for Matrix Class*/
	int** Matrix::generateMatrix(int rows, int cols) {
		int** temp_mat = new int* [rows];

		for (int i = 0; i < rows; i++) {
			temp_mat[i] = new int[cols];
		}
		return temp_mat;
	}

	std::ostream& operator<<(std::ostream& output, const Matrix& mat) {
		for (int i = 0; i < mat.getNumRows(); i++) {
			for (int j = 0; j < mat.getNumCols(); j++)
			{
				output << mat.getValueAt(i, j) << " ";
			}
			output << std::endl;
		}
		return output;
	}


	void Matrix::populateMatrix(int* src, int src_size) {
		if (m_cols * m_rows != src_size) {
			std::cout << "Please check the number of rows and columns again." << std::endl;
			exit(-1);
		}
		int num_of_elements = 0;

		for (int i = 0; i < m_rows; i++) {
			for (int j = 0; j < m_cols; j++)
			{
				this->mat[i][j] = src[num_of_elements++];
			}
		}
	}

	Matrix Matrix::operator+(Matrix& mat) {

		if (this->m_rows != mat.getNumRows() || this->m_cols != mat.getNumCols()) {
			std::cout << "The number of rows and columns of both the matrix should be equal for Addition" << std::endl;
			exit(-1);
		}
		Matrix result(this->m_rows, this->m_cols);

		for (int i = 0; i < this->m_rows; i++) {
			for (int j = 0; j < this->m_cols; j++)
			{
				result.mat[i][j] = this->mat[i][j] + mat.getValueAt(i, j);
			}
		}
		return result;
	}

	void Matrix::operator*(int scalar) {
		for (int i = 0; i < this->m_rows; i++) {
			for (int j = 0; j < this->m_cols; j++)
			{
				this->mat[i][j] *= scalar;
			}
		}
	}

	Matrix Matrix::operator*(Matrix& mat) {
		if (this->m_cols != mat.getNumRows()) {
			std::cout << "The columns and rows of the two matrices must be similar for Multiplication" << std::endl;
			exit(-1);
		}

		Matrix result(this->m_rows, mat.getNumCols());

		for (int i = 0; i < this->m_rows; i++) {
			for (int j = 0; j < mat.getNumCols(); j++)
			{
				result.mat[i][j] = 0;
			}
		}

		for (int k = 0; k < this->m_rows; k++) {
			for (int l = 0; l < this->m_cols; l++) {
				for (int m = 0; m < this->m_cols; m++)
				{
					result.mat[k][l] += this->mat[k][m] * mat.getValueAt(m, l);
				}
			}
		}
		return result;
	}

	int* Matrix::inputDynamicValues(int rows, int cols)
	{
		int size = rows * cols, numbers = 0;
		int* inp_val = NULL;
		inp_val = new int[size];

		std::cout << "Please enter " << size << " integer values to fill up your Matrix:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Enter " << i << " element:" << std::endl;
			std::cin >> numbers;
			inp_val[i] = numbers;
		}
		return inp_val;
	}

	int Matrix::getValueAt(int i, int j) const {
		return this->mat[i][j];
	}

	int Matrix::Matrix::getNumRows() const {
		return this->m_rows;
	}

	int Matrix::getNumCols() const {
		return this->m_cols;
	}
}



int main() {
	std::cout << "Enter the Number of Rows and Columns of the Matrix A:" << std::endl;
	int rows = 0, cols = 0;
	std::cout << "Rows:";
	std::cin >> rows;
	std::cout << std::endl;
	std::cout << "Columns:";
	std::cin >> cols;
	std::cout << std::endl;
	Matrixnamespace::Matrix matA(rows, cols);
	auto src = matA.inputDynamicValues(rows, cols);
	matA.populateMatrix(src, rows * cols);
	std::cout << "Matrix A is: " << std::endl;
	std::cout << matA << std::endl;

	std::cout << "Enter the Number of Rows and Columns of the Matrix B:" << std::endl;
	int rows_1 = 0, cols_1 = 0;
	std::cout << "Rows:";
	std::cin >> rows_1;
	std::cout << std::endl;
	std::cout << "Columns:";
	std::cin >> cols_1;
	std::cout << std::endl;
	Matrixnamespace::Matrix matB(rows_1, cols_1);
	auto src_1 = matB.inputDynamicValues(rows_1, cols_1);
	matB.populateMatrix(src_1, rows_1 * cols_1);
	std::cout << "Matrix B is: " << std::endl;
	std::cout << matB << std::endl;

	for (int i = 0; i < 100; i++) {
		int choice;
		std::cout << "Press 1 for testing Matrix Addition: (A+B)\nPress 2 for testing scalar multiplication: (A*2)\nPress 3 for testing Matrix Multiplication: (A*B)\nPress 4 for Exiting." << std::endl;
		std::cin >> choice;

		if (choice == 1) {
			std::cout << "Matrix (A + B) is: " << std::endl;
			std::cout << matA + matB << std::endl;
		}

		else if (choice == 2) {
			std::cout << "Matrix (A * 2) is: " << std::endl;
			matA * 2;
			std::cout << matA << std::endl;
		}

		else if (choice == 3) {
			std::cout << "Matrix (A * B) is: " << std::endl;
			std::cout << matA * matB << std::endl;
		}
		else if (choice == 4) {
			return 0;
		}

		else {
			std::cout << "Not supported.";
			return 0;
		}
	}
	return 0;
}

