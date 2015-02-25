#include "UnitCell.h"

UnitCell::UnitCell() :
    _ucx(1.0), _ucy(1.0), _ucz(1.0),
    _ucvx(1.0, 0.0, 0.0),
    _ucvy(0.0, 1.0, 0.0),
    _ucvz(0.0, 0.0, 1.0)
{
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
}


UnitCell::UnitCell (
        const real_type ucx,
        const real_type ucy,
        const real_type ucz,
        const vector_type ucvx,
        const vector_type ucvy,
        const vector_type ucvz) :
    _ucx(ucx), _ucy(ucx), _ucz(ucx),
    _ucvx(ucvx), _ucvy(ucvy), _ucvz(ucvz)
{
}


UnitCell::~UnitCell ()
{
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
        vector_type pos) const
{
    return pos + this->translate(i, j, k);
}
