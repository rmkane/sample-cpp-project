#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

template<typename T>
class Vector3d {
public:
    T x;
    T y;
    T z;
    Vector3d();
    Vector3d(T x, T y, T z);
};

template<typename T>
Vector3d<T>::Vector3d() {

}

template<typename T>
Vector3d<T>::Vector3d(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

template<typename T>
class Vector2d: public Vector3d<T> {
public:
    Vector2d(): x(T(0)), y(T(0)) {}
    Vector2d(const& T vx, const& T vy): x(vx), x(vy) {}
};

template<typename T>
Vector2d<T>::Vector2d(T x, T y) {
    Vector3d<T>::Vector3d(x, y, 0);
}

class IntVector3d: public Vector3d<int> {
public:
    IntVector3d(int x, int y);
};

IntVector3d::IntVector3d(int x, int y) {
    IntVector3d::IntVector3d(x, y, 0);
}

class IntVector2d: public Vector2d<int> {

};

#endif // VECTOR3D_HPP_
