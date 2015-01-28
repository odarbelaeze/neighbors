#include "Node.h"

Node::Node (Node::id_type id, Node::type_type type, Node::pos_type pos)
    : _id(id), _type(type), _pos(pos)
{
}


Node::~Node ()
{
}


Node::value_type Node::operator[] (const size_t i) const
{
    return _pos[i];
}


bool Node::operator== (const Node& other) const
{
    return this->_id == other._id;
}


bool Node::operator!= (const Node& other) const
{
    return !(*this == other);
}


Node::value_type Node::distanceTo(const Node::pos_type& pos) const
{
    auto diff = pos - this->_pos;
    return std::sqrt((diff * diff).sum());
}


Node::value_type Node::distanceTo(const Node& other) const
{
    return this->distanceTo(other._pos);
}


const Node::id_type& Node::id() const
{
    return this->_id;
}



const Node::type_type& Node::type() const
{
    return this->_type;
}



const Node::pos_type& Node::pos() const
{
    return this->_pos;
}

