#include<iostream>
#include<math.h>

using namespace std;

class Vector3D
{
public:
    // Основни Стойности
    float x;
    float y;
    float z;

    // Конструктори
    Vector3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3D(float x1 = 0, float y1 = 0, float z1 = 0)
    {
        x = x1;
        y = y1;
        z = z1;
    }


    // Декларации на функции
    Vector3D(const Vector3D& vec);
    Vector3D operator+(const Vector3D& vec);
    Vector3D& operator+=(const Vector3D& vec);
    Vector3D operator-(const Vector3D& vec);  
    Vector3D& operator-=(const Vector3D& vec);
    Vector3D operator*(float value);
    Vector3D& operator*=(float value);
    Vector3D operator/(float value);
    Vector3D& operator/=(float value);
    Vector3D& operator=(const Vector3D& vec);
    Vector3D CrossProduct(const Vector3D& vec);
    float DotProduct(const Vector3D& vec);
    float magnitude();
    float square();
    float distance(const Vector3D& vec);
    float getX();
    float getY();
    float getZ();
    void display();
};
//Оператор за събиране с + и +=

Vector3D Vector3D::operator+(const Vector3D& vec)
{
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}
// Оператор за изваждане - и -=
Vector3D Vector3D::operator-(const Vector3D& vec)
{
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

// Оператори за произведение * и *=

Vector3D Vector3D::operator*(float value)
{
    return Vector3D(x * value, y * value, z * value);
}



Vector3D& Vector3D::operator*=(float value)
{
    x *= value;
    y *= value;
    z *= value;
    return *this;
}

// Оператори за деление / и /=
Vector3D Vector3D ::operator/(float value)
{
    return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D ::operator/=(float value)
{
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

// Оператор за пресвояване =
Vector3D& Vector3D::operator=(const Vector3D& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

//Точково Произведение
float Vector3D::DotProduct(const Vector3D& vec)
{
    return x * vec.x + vec.y * y + vec.z * z;
}

//cross product
Vector3D Vector3D::CrossProduct(const Vector3D& vec)
{
    float ni = y * vec.z - z * vec.y;
    float nj = z * vec.x - x * vec.z;
    float nk = x * vec.y - y * vec.x;
    return Vector3D(ni, nj, nk);
}


// Дължина и квадратура на вектор
float Vector3D::magnitude()
{
    return sqrt(square());
}

float Vector3D::square()
{
    return x * x + y * y + z * z;
}

//Разстояние между един Вектор до друг

float Vector3D::distance(const Vector3D& vec)
{
    Vector3D dist = *this - vec;
    return dist.magnitude();
}

//Стойности за взимане от вектор

float Vector3D::getX()
{
    return x;
}

float Vector3D::getY()
{
    return y;
}

float Vector3D::getZ()
{
    return z;
}

void Vector3D::display()
{
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    Vector3D a = Vector3D(2, 5, 7);
    Vector3D b = Vector3D(3, 7, 10);
    
    Vector3D c = a + b; // Тест за събиране
    Vector3D d = a - b; // Тест за изваждане
    Vector3D e = a - b; // Тест за умножение
    Vector3D f = a - b; // Тест за деление

    Vector3D g = a.distance(b); // Тест за дължина
    float h = a.DotProduct(b); // Тест за Точково произведение
    Vector3D i = a.CrossProduct(b); // Тест за кръстосано произведение

    Vector3D j = a.square(); // квадратура на вектора

    c.display();
    d.display();
    e.display();
    f.display();
    g.display();
    std::cout << h << std::endl;
    i.display();
    j.display();
}