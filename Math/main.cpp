#include <iostream>
#include <iomanip>
using namespace std;

#include "Vector3.h"
#include <cassert>

constexpr float Epsilon = 0.00001f;
bool Equals(float value)
{
    // Is the distance between lhs and rhs less than EPSILON?
    return fabs(value) < Epsilon ? true : false;
}

int main()
{
	cout << "Starting program...\n\n";    
    cout << "*******************************************************\n";
    
    cout << "Cross product\n";
    Vector3 cv1(1.0f, 0.0f, 0.0f);
    Vector3 cv2(0.0f, 6.0f, 0.0f);

    float* angles = Vector3::Angle(cv1, cv2);
    float angleInDegree = angles[0];
    cout << "Angle between vectors in degrees : " << "(" << cv1.GetX() << ", " << cv1.GetY() << ", " << cv1.GetZ() << ") and : " << "(" << cv2.GetX() << ", " << cv2.GetY() << ", " << cv2.GetZ() << ") : " << angleInDegree <<  endl << endl;

    Vector3 result = cv1.Cross(cv2);

    cout << "Vector v1 :\t" << cv1.GetX() << "\t" << cv1.GetY() << "\t" << cv1.GetZ() << endl;
    cout << "Vector v2 :\t" << cv2.GetX() << "\t" << cv2.GetY() << "\t" << cv2.GetZ() << endl;
    cout << "Vector result :\t" << result.GetX() << "\t" << result.GetY() << "\t" << result.GetZ() << endl;
    cout << "Length of the product : " << result.Length() << endl << endl;

    float length = cv1.CrossLength(cv2);
    cout << "Length of the product CrossLength : " << length << endl << endl;

    float length2 = cv1.CrossLength(cv2, angles[0]);
    cout << "Length of the product CrossLength2 : " << length2 << endl << endl;

    float sinVal = sinf(angles[0]);
    if (Equals(sinVal))
        sinVal = floor(fabs(sinf(angles[0])));

    cout << "Sin of the angle : " << sinf(angles[0]) << endl;
    cout << "Sin of the angle after correction : " << sinVal << endl;
    float area = cv1.Length() * cv2.Length() * sinf(angles[0]);
    cout << "Area of the paralellogram : " << area << endl;
    
    cout << "\n********************************************\nCross product\n\n";

    Vector3 cross1(0.0f, 1.0f, 3.0f);
    Vector3 cross2(5.0f, 1.0f, 0.0f);

    Vector3 crossProd = cross1.Cross(cross2);

    cout << "Vector Cross product :\t" << crossProd.GetX() << "\t" << crossProd.GetY() << "\t" << crossProd.GetZ() << endl;


    /*
    float angle = Vector3::Angle(vd1, vd2);
    cout << "Angle between vectors : " << "(" << vd1.GetX() << ", " << vd1.GetY() << ", " << vd1.GetZ() << ") and : " << "(" << vd2.GetX() << ", " << vd2.GetY() << ", " << vd2.GetZ() << ")" << endl;
    cout << "Dot product :\t" << vd1.Dot(vd2) << endl;
    cout << "Length vd1 :\t" << vd1.Length() << endl;
    cout << "Length vd2 :\t" << vd2.Length() << endl;
    cout << "Angle between both vectors :\t" << angle << endl;
    */

    Vector3 v = Vector3(1.0f, 2.0f, 3.0f);
    Vector3 v2 = v / 0.0f;

    cout << "\n\nVector v :\t" << v2.GetX() << "\t" << v2.GetY() << "\t" << v2.GetZ() << endl;

    cout << "\n\n";



    void may_throw();
    void no_throw() noexcept;
    auto lmay_throw = [] {};
    auto lno_throw = []() noexcept {};

    Vector3 v3 = Vector3(1.0f, 2.0f, 3.0f);



    std::cout << std::boolalpha
        << "Is may_throw() noexcept? " << noexcept(Vector3::Length(v3)) << '\n';

    

    cout << endl << endl;
	return 0;
}