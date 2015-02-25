#include "Coordinate.h"


Coordinate::Coordinate ()
    : _vec{ {0.0, 0.0, 0.0} }
{
}


Coordinate::Coordinate (value_type x, value_type y, value_type z)
    : _vec{ {x, y, z} }
{
}


Coordinate::Coordinate (const store_type& array)
    : _vec(array)
{
}


Coordinate::~Coordinate ()
{
}


Coordinate::value_type Coordinate::operator[] (std::size_t i) const
{
    return _vec.at(i);
}


Coordinate& Coordinate::operator+= (const Coordinate& other)
{
    this->_vec[0] += other._vec[0];
    this->_vec[1] += other._vec[1];
    this->_vec[2] += other._vec[2];

    return *this;
}


Coordinate& Coordinate::operator-= (const Coordinate& other)
{
    this->_vec[0] -= other._vec[0];
    this->_vec[1] -= other._vec[1];
    this->_vec[2] -= other._vec[2];

    return *this;
}


Coordinate& Coordinate::operator*= (const Coordinate::value_type& other)
{
    this->_vec[0] *= other;
    this->_vec[1] *= other;
    this->_vec[2] *= other;

    return *this;
}


const Coordinate operator+ (Coordinate lhs, const Coordinate& rhs)
{
    return lhs += rhs;
}


const Coordinate operator- (Coordinate lhs, const Coordinate& rhs)
{
    return lhs -= rhs;
}


const Coordinate operator* (Coordinate lhs, const double& rhs)
{
    return lhs *= rhs;
}


const Coordinate operator* (double lhs, const Coordinate& rhs)
{
    // Requires a non const instance of the rhs
    return Coordinate(rhs) *= lhs;
}


Coordinate::value_type Coordinate::x () const
{
    return _vec[0];
}


Coordinate::value_type Coordinate::y () const
{
    return _vec[1];
}


Coordinate::value_type Coordinate::z () const
{
    return _vec[2];
}


Coordinate::value_type Coordinate::dot (const Coordinate& other) const
{
    return (this->_vec[0] * other._vec[0] +
            this->_vec[1] * other._vec[1] +
            this->_vec[2] * other._vec[2]);
}


Coordinate::value_type dot (const Coordinate& one, const Coordinate& other)
{
    return one.dot(other);
}


Coordinate::value_type Coordinate::distanceTo (const Coordinate& other) const
{
    auto&& a = this->_vec;
    auto&& b = other._vec;
    return std::pow(
            (b[0] - a[0]) * (b[0] - a[0]) +
            (b[1] - a[1]) * (b[1] - a[1]) +
            (b[2] - a[2]) * (b[2] - a[2]),
            0.5);
}


Coordinate::value_type Coordinate::norm() const
{
    return this->distanceTo(Coordinate());
}


Coordinate Coordinate::move (const Coordinate& other) const
{
    Coordinate coordinate = *this;
    coordinate._vec[0] += other._vec[0];
    coordinate._vec[1] += other._vec[1];
    coordinate._vec[2] += other._vec[2];
    return coordinate;
}
