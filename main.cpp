#include <iostream>
#include <tuple>
#include "MATRIX.h"

using namespace std;

int main() {

	/****************************** Initialize *******************************/
	MATRIX<double> m1; // [ [ [0] ] ]
	
	MATRIX<double> m2(3, 4, 5); // ���ͤ@�� 3(depth) * 4(row) * 5(column) ���x�}�A�ȧ���0
	
	MATRIX<double> m3;  
	m3 = m2; // �z�L�t�@�� matrix ��l

	/****************************** Assign Value *****************************/
	m2(0, 0, 0) = 1;
	m2(1, 0, 0) = 2;
	m2(2, 0, 0) = 3;

	/****************************** Print Value ******************************/
	m2.print_matrix(); // �L�X��ӯx�}
	cout << m2(0, 0, 0) << endl; // �L�X��@����

	/****************************** Matrxi Operator **************************/
	MATRIX<double> m4(3, 4, 5), m5(3, 5, 2), m6(3, 4, 3);
	m1 = m2 + m3; 
	m1 = m1 - m2;
	m1 = m4 * m5; 
	//m1 = m4 * m6; // ���׿��~�A�|�q�X�x�}����
	m1 = m1 * 2;
	m1 = m1 / 2;

	system("pause");
}