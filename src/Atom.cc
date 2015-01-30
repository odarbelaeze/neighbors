#include "Atom.h"


Atom::Atom (Atom::key_type type)
    : _type(type)
{
}


Atom::~Atom ()
{
}


void Atom::save() const
{
    atoms[this->_type] = std::shared_ptr<Atom>(this);
}


Atom::key_type Atom::type() const
{
    return this->_type;
}


Atom* Atom::create(Atom::key_type type)
{
    atoms[type] = std::shared_ptr<Atom>(new Atom(type));
    return atoms[type].get();
}


Atom* Atom::getOrCreate(Atom::key_type type)
{
    auto it = atoms.find(type);
    if (it == atoms.end()) return Atom::create(type);
    return (it->second).get();
}


Atom* Atom::getOrFail(Atom::key_type type)
{
    return atoms.at(type).get();
}

