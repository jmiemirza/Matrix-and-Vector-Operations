#include "Vector.h"
#include <iostream>

namespace Vectornamespace{
	/*Method Implementation for Vector Class*/

	int* Vector::generateVector(int length) {
		int* temp_vec = new int[length];

		return temp_vec;
	}

	void Vector::populateVector(int* src, int length) {
		int len = 0;
		for (int i = 0; i < length; i++) {
			this->vector[i] = src[len++];
		}
	}

	void Vector::printVector() const {
		std::cout << "The Vector is: " << std::endl;
		for (int i = 0; i < m_length; i++) {
			std::cout << this->vector[i] << " ";
		}
		std::cout << std::endl;
	}

	int Vector::getVectorLength() const {
		{
			return this->m_length;
		}
	}

	int Vector::getValueAt(int pos) const {
			return this->vector[pos];
	}

	Vector Vector::operator+(Vector & vec) {
		if (this->m_length != vec.getVectorLength()) {
			std::cout << "The length of both the vectors should be same for addition." << std::endl;
			exit(-1);
		}

		Vector result(this->m_length);

		for (int i = 0; i < this->m_length; i++) {
			result.vector[i] = this->vector[i] + vec.getValueAt(i);
		}
		return result;
	}

	void Vector::operator*(int multiplier) {
		for (int i = 0; i < this->m_length; i++) {
			this->vector[i] *= multiplier;
		}
	}

	Vector Vector::operator*(Vector & vec) {
		if (this->m_length != vec.getVectorLength()) {
			std::cout << "The length is not same for both Vectors." << std::endl;
			exit(-1);
		}

		Vector result(this->m_length);
		int res = 0;
		for (int i = 0; i < this->m_length; i++) {
			result.vector[i] = this->vector[i] * vec.getValueAt(i);
		}
		return result;
	}

	std::ostream & operator<<(std::ostream & output, const Vectornamespace::Vector & vec)
	{
		for (int i = 0; i < vec.getVectorLength(); i++) {
			output << vec.getValueAt(i) << " ";
		}
		std::cout << std::endl;
		return output;
	}
	
	int* Vector::inputDynamicValues(int size) {
		int* inp_val;
		int numbers = 0;
		inp_val = new int[size];

		std::cout << "Please enter " << size << " integer values to fill up your vector:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Enter " << i << " element:" << std::endl;
			std::cin >> numbers;
			inp_val[i] = numbers;
		}
		return inp_val;
	}
}

int main() {

	std::cout << "Enter the number of elements you want in vector A:" << std::endl;
	int size = 0;
	
	std::cin >> size;
	Vectornamespace::Vector VecA(size);
	auto src_A = VecA.inputDynamicValues(size);
	VecA.populateVector(src_A, size);
	std::cout << "The Vector A is: " << VecA << std::endl;

	std::cout << "Please enter the number of elements you want in vector B:" << std::endl;
	int size_1 = 0;
	std::cin >> size_1;
	Vectornamespace::Vector VecB(size_1);
	auto src_B = VecB.inputDynamicValues(size_1);
	VecB.populateVector(src_B, size_1);
	std::cout << "The Vector B is: " << VecB << std::endl;

	for (int k = 0; k < 100; k++) {

		int choice;
		std::cout << "Press 1 for testing Scalar Multiplication: (A*2)\nPress 2 for testing Vector Addition: (A+B)\nPress 3 for testing Vector Multiplication: (A*B) \nPress 4 for exiting." << std::endl;
		std::cin >> choice;

		if (choice == 1) {
			VecA * 2;
			std::cout << "The result of Scalar Multiplication is:" << VecA << std::endl;
		}

		else if (choice == 2) {
			std::cout << "The result of Vector Addition is:" << VecA + VecB << std::endl;
		}

		else if (choice == 3) {
			std::cout << "The result of Vector Multiplication is:" << VecA * VecB << std::endl;
		}
		else if (choice == 4) {
			exit(-1);
		}

		else {
			std::cout << "The choice is wrong." << std::endl;
			exit(-1);
		}
	}
	
	return 0;
}