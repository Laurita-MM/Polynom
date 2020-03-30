#include "pch.h"
#include "iostream"
#include "../TPolinom/TPolinom.h"

using namespace std;

TEST(TPolinomTest, can_create_a_monom)
{
	int mas[1][2];
	mas[0][0] = 3;
	mas[0][1] = 123;
	ASSERT_NO_THROW(TMonom mon(mas));
	TMonom mon(mas);
	EXPECT_EQ(mon.coeff, mas[0][0]);
	EXPECT_EQ(mon.px, 1);
	EXPECT_EQ(mon.py, 2);
	EXPECT_EQ(mon.pz, 3);
}

TEST(TPolinomTest, can_compare_the_monoms) {
	int mas[1][2];
	mas[0][0] = 3;
	mas[0][1] = 123;
	TMonom mon(mas);
	int mas1[1][2];
	mas[0][0] = 3;
	mas[0][1] = 123;
	TMonom mon1(mas1);
	ASSERT_NO_THROW(mon==mon1);
}

TEST(TPolinomTest, can_create_a_polinom)
{
	int** mas;
	mas = new int* [2];
	for (int i = 0; i < 2; i++)
		mas[i] = new int[2];
	mas[0][0] = 1;
	mas[0][1] = 123;
	mas[1][0] = 3;
	mas[1][1] = 234;
	ASSERT_NO_THROW(TPolinom pol(mas, 2));
	TPolinom pol(mas, 2);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 2);
	EXPECT_EQ(pol.GetMonom().py, 3);
	EXPECT_EQ(pol.GetMonom().pz, 4);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 1);
	EXPECT_EQ(pol.GetMonom().px, 1);
	EXPECT_EQ(pol.GetMonom().py, 2);
	EXPECT_EQ(pol.GetMonom().pz, 3);


}
TEST(TPolinomTest, can_assigned_polinom_to_another)
{
	int** mas;
	mas = new int* [2];
	for (int i = 0; i < 2; i++)
		mas[i] = new int[2];
	mas[0][0] = 1;
	mas[0][1] = 123;
	mas[1][0] = 32;
	mas[1][1] = 321;
	TPolinom pol(mas, 2);

	int** mas2;
	mas2 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas2[i] = new int[2];
	mas2[0][0] = 3;
	mas2[0][1] = 345;
	mas2[1][0] = 4;
	mas2[1][1] = 567;
	TPolinom pol1(mas2, 2);
	ASSERT_NO_THROW(pol = pol1);
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 4);
	EXPECT_EQ(pol.GetMonom().px, 5);
	EXPECT_EQ(pol.GetMonom().py, 6);
	EXPECT_EQ(pol.GetMonom().pz, 7);
	pol.GoNext();
	EXPECT_EQ(pol.GetMonom().coeff, 3);
	EXPECT_EQ(pol.GetMonom().px, 3);
	EXPECT_EQ(pol.GetMonom().py, 4);
	EXPECT_EQ(pol.GetMonom().pz, 5);

}
TEST(TPolinomTest, is_inverse_polynomials_are_reduced)
{
	int** mas;
	mas = new int* [2];
	for (int i = 0; i < 2; i++)
		mas[i] = new int[2];
	mas[0][0] = 1;
	mas[0][1] = 123;
	mas[1][0] = 3;
	mas[1][1] = 321;
	TPolinom pol(mas, 2);

	int** mas2;
	mas2 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas2[i] = new int[2];
	mas2[0][0] = -1;
	mas2[0][1] = 123;
	mas2[1][0] = -3;
	mas2[1][1] = 321;
	TPolinom pol1(mas2, 2);

	int** mas3;
	mas3 = new int* [1];
	for (int i = 0; i < 1; i++)
		mas3[i] = new int[2];
	mas3[0][0] = 0;
	mas3[0][1] = 0;
	TPolinom pol2(mas3, 1);
	pol += pol1;
	pol.Reset();
	EXPECT_EQ(pol.GetMonom().coeff, 0);
	EXPECT_EQ(pol.GetMonom().px, 0);
	EXPECT_EQ(pol.GetMonom().py, 0);
	EXPECT_EQ(pol.GetMonom().pz, -1);
}
TEST(TPolinomTest, can_multiply_polinom_by_a_monom) {
	int mas[1][2];
	mas[0][0] = 3;
	mas[0][1] = 123;
	TMonom mon(mas);

	int** mas2;
	mas2 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas2[i] = new int[2];
	mas2[0][0] = -1;
	mas2[0][1] = 123;
	mas2[1][0] = -3;
	mas2[1][1] = 321;
	TPolinom pol2(mas2, 2);

	/*int** mas3;
	mas3 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas3[i] = new int[2];
	mas3[0][0] = 0;
	mas3[0][1] = 0;
	mas3[1][0] = 0;
	mas3[1][1] = 0;
	TPolinom pol2(mas3, 1);*/

	ASSERT_NO_THROW(pol2 *= mon);
	/*cout << "pol2 = " << pol2 << endl;*/
	pol2.Reset();
	EXPECT_EQ(pol2.GetMonom().coeff, -9);
	EXPECT_EQ(pol2.GetMonom().px, 4);
	EXPECT_EQ(pol2.GetMonom().py, 4);
	EXPECT_EQ(pol2.GetMonom().pz, 4);
	pol2.GoNext();
	EXPECT_EQ(pol2.GetMonom().coeff, -3);
	EXPECT_EQ(pol2.GetMonom().px, 2);
	EXPECT_EQ(pol2.GetMonom().py, 4);
	EXPECT_EQ(pol2.GetMonom().pz, 6);
}
TEST(TPolinomTest, can_multiply_polinom_by_a_constant) {
	int** mas2;
	mas2 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas2[i] = new int[2];
	mas2[0][0] = 1;
	mas2[0][1] = 123;
	mas2[1][0] = 2;
	mas2[1][1] = 321;
	TPolinom pol1(mas2, 2);

	int a = 3;
	pol1 *= a;
	pol1.Reset();
	EXPECT_EQ(pol1.GetMonom().coeff, 6);
	pol1.GoNext();
	EXPECT_EQ(pol1.GetMonom().coeff, 3);
}

TEST(TPolinomTest, can_add_a_monom_to_a_polinom) {
	int mas[1][2];
	mas[0][0] = 2;
	mas[0][1] = 245;
	TMonom mon(mas);
	int** mas2;
	mas2 = new int* [2];
	for (int i = 0; i < 2; i++)
		mas2[i] = new int[2];
	mas2[0][0] = 1;
	mas2[0][1] = 123;
	mas2[1][0] = 3;
	mas2[1][1] = 321;
	TPolinom pol2(mas2, 2);
	pol2.InsMonom(mon);
	pol2.Reset();
	EXPECT_EQ(pol2.GetMonom().coeff, 3);
	EXPECT_EQ(pol2.GetMonom().px, 3);
	EXPECT_EQ(pol2.GetMonom().py, 2);
	EXPECT_EQ(pol2.GetMonom().pz, 1);
	pol2.GoNext();
	EXPECT_EQ(pol2.GetMonom().coeff, 2);
	EXPECT_EQ(pol2.GetMonom().px, 2);
	EXPECT_EQ(pol2.GetMonom().py, 4);
	EXPECT_EQ(pol2.GetMonom().pz, 5);
	pol2.GoNext();
	EXPECT_EQ(pol2.GetMonom().coeff, 1);
	EXPECT_EQ(pol2.GetMonom().px, 1);
	EXPECT_EQ(pol2.GetMonom().py, 2);
	EXPECT_EQ(pol2.GetMonom().pz, 3);
}