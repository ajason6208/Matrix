#include <iostream>
#include <tuple>
#include "MATRIX.h"

using namespace std;

int main() {

	/****************************** Initialize *******************************/
	MATRIX<double> m1; // [ [ [0] ] ]
	
	MATRIX<double> m2(3, 4, 5); // 產生一個 3(depth) * 4(row) * 5(column) 的矩陣，值均為0
	
	MATRIX<double> m3;  
	m3 = m2; // 透過另一個 matrix 初始

	/****************************** Assign Value *****************************/
	m2(0, 0, 0) = 1;
	m2(1, 0, 0) = 2;
	m2(2, 0, 0) = 3;

	/****************************** Print Value ******************************/
	m2.print_matrix(); // 印出整個矩陣
	cout << m2(0, 0, 0) << endl; // 印出單一元素

	/****************************** Matrxi Operator **************************/
	MATRIX<double> m4(3, 4, 5), m5(3, 5, 2), m6(3, 4, 3);
	m1 = m2 + m3; 
	m1 = m1 - m2;
	m1 = m4 * m5; 
	//m1 = m4 * m6; // 維度錯誤，會秀出矩陣維度
	m1 = m1 * 2;
	m1 = m1 / 2;

	system("pause");
}