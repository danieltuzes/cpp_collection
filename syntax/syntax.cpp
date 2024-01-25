#include <iostream>
#include <array>
#include <tuple>

using namespace std;

struct Vector2
{
    array<float, 2> elements;
    
          float& operator[](int i)       {return elements[i];};
    const float& operator[](int i) const {return elements[i];};
};


float myvar3[2] = {2,3};
array<float,2> myvar5{{2,2}};


vector<float,2> myvect{2,2};


Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
    return Vector2{{lhs[0] + rhs[0], lhs[1] + rhs[1]}}; // no problem
    // return {{lhs[0] + rhs[0], lhs[1] + rhs[1]}}; // no problem
    
}

ostream& operator<< (ostream& o, const Vector2& v)
{
    o << "{ " << v[0] << ", " << v[1] << " }";
    return o;
}

template<typename T>
class Vector3 
{
    T* data;
    size_t sz;

    Vector3(): data(nullptr), sz(0) {}
    Vector3(Vector const& other);
    Vector3(Vector && other);
    Vector3& operator=(Vector const& other) {};
    Vector3& operator=(Vector && other) {};
    ~Vector3() {delete[] data; sz = 0;}
};

template<typename T, int N> struct Vector
{
    array<T,n> a;
    size_t age;

    Vector(initializer_list<T> il, int)
    {
        age = *il.begin();
        copy(il.begin()+1, il.end(), a.begin());
    }
};

Vector<int,3> myvec{{1,2,3},3};

int main()
{

    std::array<float, 2> myarr{0,1};
    Vector2 myvec{myarr};
    Vector2 myvec2{{3,3}};
    myvec[0] = 1;
    myvec[1] = 2;
    cout << myvec;
    cout << myvec + myvec2;

    cout << "hi";
}