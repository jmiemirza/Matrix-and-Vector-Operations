#pragma once
#include <iostream>
namespace Vectornamespace{
	class Vector
	{

	private:
		int m_length;

		int* vector;


	public:
		Vector(int length) : m_length(length) {
			this->vector = generateVector(this->m_length);
		}
		~Vector() {
		}

		int* generateVector(int length);
		void populateVector(int* src, int length);
		void printVector() const;

		//Operator Overloading
		friend std::ostream& operator<<(std::ostream& output, const Vector& vec);
		Vector operator+(Vector& vec);
		void operator*(int scalar);
		Vector operator*(Vector& vec);
		int getValueAt(int pos) const;
		int getVectorLength() const;
		int* inputDynamicValues(int size);
	};
};