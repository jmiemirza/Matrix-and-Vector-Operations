#pragma once
#include <iostream>

namespace Matrixnamespace {
	class Matrix
	{

	private:
		int m_rows, m_cols;
		int** mat;
	public:

		Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
			this->mat = generateMatrix(this->m_rows, this->m_cols);
		}
		~Matrix() {
		}

		int** generateMatrix(int rows, int cols);
		void populateMatrix(int* src, int src_size);

		//Operator Overlading
		friend std::ostream& operator<<(std::ostream& output, const Matrix& mat);
		Matrix operator+(Matrix& mat);
		void operator*(int scalar);
		Matrix operator*(Matrix& mat);
		int getValueAt(int i, int j) const;
		int getNumRows() const;
		int getNumCols() const;
		int* inputDynamicValues(int rows, int cols);
	};
};