#include "UnitCell.h"

UnitCell::UnitCell() :
    _ucx(1.0), _ucy(1.0), _ucz(1.0),
    _ucvx(1.0, 0.0, 0.0),
    _ucvy(0.0, 1.0, 0.0),
    _ucvz(0.0, 0.0, 1.0)
{
    this->_set_inv_vectors();
}


UnitCell::UnitCell (
        const UnitCell::real_type a,
        const UnitCell::real_type b,
        const UnitCell::real_type c) :
    _ucx(a), _ucy(b), _ucz(c),
    _ucvx(1.0, 0.0, 0.0),
    _ucvy(0.0, 1.0, 0.0),
    _ucvz(0.0, 0.0, 1.0)
{
    this->_set_inv_vectors();
}


UnitCell::UnitCell (
        const UnitCell::vector_type& ucvx,
        const UnitCell::vector_type& ucvy,
        const UnitCell::vector_type& ucvz) :
    _ucx(ucvx.norm()), _ucy(ucvy.norm()), _ucz(ucvz.norm())
{
    this->_ucvx = UnitCell::vector_type(
            ucvx.x() / this->_ucx,
            ucvx.y() / this->_ucx,
            ucvx.z() / this->_ucx);

    this->_ucvy = UnitCell::vector_type(
            ucvy.x() / this->_ucx,
            ucvy.y() / this->_ucx,
            ucvy.z() / this->_ucx);

    this->_ucvz = UnitCell::vector_type(
            ucvz.x() / this->_ucx,
            ucvz.y() / this->_ucx,
            ucvz.z() / this->_ucx);

    this->_set_inv_vectors();
}


UnitCell::UnitCell (
        const real_type ucx,
        const real_type ucy,
        const real_type ucz,
        const vector_type ucvx,
        const vector_type ucvy,
        const vector_type ucvz) :
    _ucx(ucx), _ucy(ucy), _ucz(ucz),
    _ucvx(ucvx), _ucvy(ucvy), _ucvz(ucvz)
{
    this->_set_inv_vectors();
}


UnitCell::~UnitCell ()
{
}


void UnitCell::_set_inv_vectors()
{
    auto vx = this->_ucx * this->_ucvx;
    auto vy = this->_ucy * this->_ucvy;
    auto vz = this->_ucz * this->_ucvz;

    _inv_ucvx = UnitCell::vector_type(
            vy.y() * vz.z() - vz.y() * vy.z(),
            vz.y() * vx.z() - vx.y() * vz.z(),
            vx.y() * vy.z() - vy.y() * vx.z());

    _inv_ucvy = UnitCell::vector_type(
            vz.x() * vy.z() - vy.x() * vz.z(),
            vx.x() * vz.z() - vz.x() * vx.z(),
            vy.x() * vx.z() - vx.x() * vy.z());

    _inv_ucvz = UnitCell::vector_type(
            vy.x() * vz.y() - vz.x() * vy.y(),
            vz.x() * vx.y() - vx.x() * vz.y(),
            vx.x() * vy.y() - vy.x() * vx.y());

    auto det = vx.dot(Coordinate(
                _inv_ucvx.x(),
                _inv_ucvy.x(),
                _inv_ucvz.x()));

    _inv_ucvx *= 1.0 / det;
    _inv_ucvy *= 1.0 / det;
    _inv_ucvz *= 1.0 / det;
}


UnitCell::vector_type UnitCell::translate(
        UnitCell::integer_type i,
        UnitCell::integer_type j,
        UnitCell::integer_type k) const
{
    return this->_ucvx * (this->_ucx * i) +
           this->_ucvy * (this->_ucy * j) +
           this->_ucvz * (this->_ucz * k) ;
}


UnitCell::vector_type UnitCell::translate(
        integer_type i,
        integer_type j,
        integer_type k,
        const vector_type& pos) const
{
    return pos + this->translate(i, j, k);
}


UnitCell::vector_type UnitCell::scale(
        const UnitCell::vector_type& pos) const
{
    return pos.x() * this->_inv_ucvx +
           pos.y() * this->_inv_ucvy +
           pos.z() * this->_inv_ucvz;
}

UnitCell::vector_type UnitCell::unscale(
        const UnitCell::vector_type& pos) const
{
    return pos.x() * this->_ucx * this->_ucvx +
           pos.y() * this->_ucy * this->_ucvy +
           pos.z() * this->_ucz * this->_ucvz;
}
