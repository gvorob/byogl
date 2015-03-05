#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Vect4 {
	public:
		double coord[4];

		Vect4();
		Vect4(double x, double y, double z);

		static Vect4 Zero();

		double& operator[] (const int& i);

		Vect4 inverse();
		std::string to_string();
};

class Mat4 {
	private:
		double mat[16]; //c1(r1234) c2(r1234) ...

	public:
		static Mat4 ZeroMat();
		static Mat4 IdentityMat();
		static Mat4 ScaleMat(Vect4 v);
		static Mat4 TranslateMat(Vect4 v);
		//All rotations in radians
		static Mat4 RotateXMat(double theta);
		static Mat4 RotateYMat(double theta);
		static Mat4 RotateZMat(double theta);

		static Mat4 ProjectPersp();//Needs to be normalized after this
		static Mat4 ProjectOrtho();//Not implemented

		static Mat4 mult(Mat4 left, Mat4 right);//Multiply left by right, return product in new matrix

		Vect4 mult(Vect4 v);//Multiply a vect4 by this
		
		static int index(int r, int c); //Indexes into the matrix (0 indexed)

		std::string to_string();
};

#endif
