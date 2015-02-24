#include "Coordinate.h"


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


Coordinate Coordinate::move (const Coordinate& other) const
{
    Coordinate coordinate = *this;
    coordinate._vec[0] += other._vec[0];
    coordinate._vec[1] += other._vec[1];
    coordinate._vec[2] += other._vec[2];
    return coordinate;
}

