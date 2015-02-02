#include "Atom.h"

std::map<Atom::key_type, Atom::shared_ptr_type> Atom::atoms = {};


Atom::Atom (Atom::key_type type)
    : _type(type)
{
}


Atom::~Atom ()
{
}


void Atom::save()
{
    auto&& sptr = this->shared_from_this();
    Atom::atoms[this->_type] = sptr;
}


Atom::key_type Atom::type() const
{
    return this->_type;
}


Atom::weak_ptr_type Atom::create(Atom::key_type type)
{
    atoms[type] = std::shared_ptr<Atom>(new Atom(type));
    return atoms[type];
}


Atom::weak_ptr_type Atom::getOrCreate(Atom::key_type type)
{
    auto it = atoms.find(type);
    if (it == atoms.end()) return Atom::create(type);
    return (it->second);
}


Atom::weak_ptr_type Atom::getOrFail(Atom::key_type type)
{
    return atoms.at(type);
}

