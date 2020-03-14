#include "pch.h"
#include <iostream>
#include "../TPolinom/TPolinom.h"

using namespace std;

TEST(TPolinomTest, can_create_monom) 
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

TEST(TPolinomTest, can_create_polinom)
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
TEST(TPolinomTest, can_assigned_polinom_to_anouther)
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

    //int** mas;
    //mas = new int* [2];
    //for (int i = 0; i < 2; i++)
    //    mas[i] = new int[2];
    //mas[0][0] = 1;
    //mas[0][1] = 123;
    //mas[1][0] = 3;
    //mas[1][1] = 234;
    //TPolinom pol(mas, 2);

    //int** mas2;
    //mas2 = new int* [2];
    //for (int i = 0; i < 2; i++)
    //    mas2[i] = new int[2];
    //mas2[0][0] = 5;
    //mas2[0][1] = 367;
    //mas2[1][0] = 7;
    //mas2[1][1] = 126;
    //TPolinom pol2(mas2, 2);
    //ASSERT_NO_THROW(pol = pol2);
    //pol = pol2;
    //cout << "pol = " << pol << endl;
    //pol.Reset();
    //EXPECT_EQ(pol.GetMonom().coeff, 5);
    //EXPECT_EQ(pol.GetMonom().px, 3);
    //EXPECT_EQ(pol.GetMonom().py, 6);
    //EXPECT_EQ(pol.GetMonom().pz, 7);


    //pol.GetNext();

    //EXPECT_EQ(pol.GetMonom().coeff, 14);
    //EXPECT_EQ(pol.GetMonom().px, 1);
    //EXPECT_EQ(pol.GetMonom().py, 2);
    //EXPECT_EQ(pol.GetMonom().pz, 6);
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
    //cout << "pol2 = " << pol2 << endl;
   // std::cout << pol << pol1;
    pol += pol1;
    //cout << "pol = " << pol << endl;
    pol.Reset();
    EXPECT_EQ(pol.GetMonom().coeff, 0);
    EXPECT_EQ(pol.GetMonom().px, 0);
    EXPECT_EQ(pol.GetMonom().py, 0);
    EXPECT_EQ(pol.GetMonom().pz, -1);


}