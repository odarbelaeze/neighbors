#include "Node.h"

Node::Node (Node::id_type id, Node::data_type data, Node::pos_type pos, bool ghost)
    : _id(id), _data(data), _pos(pos), _is_ghost(ghost)
{
}


Node::Node (Node::id_type id, Node::data_key_type key, Node::pos_type pos, bool ghost)
    : _id(id),
      _data(Node::data_store_type::getOrCreate(key)),
      _pos(pos),
      _is_ghost(ghost)
{
}


Node::~Node ()
{
}


Node::value_type Node::operator[] (size_t i) const
{
    return _pos[i];
}


bool Node::operator== (const Node& other) const
{
    if (this->_is_ghost || other._is_ghost) return false;
    return this->_id == other._id;
}


bool Node::operator!= (const Node& other) const
{
    return !(*this == other);
}


Node::value_type Node::distanceTo(const Node::pos_type& pos) const
{
    // Deffer to the pos type
    return _pos.distanceTo(pos);
}


Node::value_type Node::distanceTo(const Node& other) const
{
    return this->distanceTo(other._pos);
}


const Node::id_type& Node::id() const
{
    return this->_id;
}



const Node::data_type& Node::data() const
{
    return this->_data;
}



const Node::pos_type& Node::pos() const
{
    return this->_pos;
}

