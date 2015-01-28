/**
 * @file Node.h
 * @brief Defines a Node class that interacts with libkdtree
 * @author Oscar David Arbeláez
 * @version 0.0.1
 * @date 2015-01-28
 */

#ifndef NODE_H_
#define NODE_H_

#include <cmath>
#include <string>
#include <valarray>

/**
 * @brief Stores some data and relates it to a point in space
 */
class Node
{
public:

    /**
     * @brief Type of id stored
     */
    typedef size_t id_type;

    /**
     * @brief Type of node
     */
    typedef std::string type_type;

    /**
     * @brief Type of value to adhere to the interface required by libkdtree
     */
    typedef double value_type;

    /**
     * @brief Type used to store the position of a node
     */
    typedef std::valarray<value_type> pos_type;

    /**
     * @brief Builds a node with id, type and position
     *
     * @param id
     * @param type
     * @param pos
     */
    Node (id_type id, type_type type, pos_type pos);

    /**
     * @brief Should destroy the node calling default destructors
     */
    virtual ~Node ();

    /**
     * @brief Returns the position of the node at the `i`th axis
     *
     * @param i the axis
     * @return the `i`th component of the position of the node
     */
    value_type operator[] (size_t i) const;

    /**
     * @brief Compares the node with other according to their ids
     *
     * @param other
     *
     * @return
     */
    bool operator== (const Node& other) const;

    /**
     * @brief Tests unequallity of this node with other according to their ids
     *
     * @param other
     *
     * @return
     */
    bool operator!= (const Node& other) const;

    /**
     * @brief Computes the distance of the node to a remote position
     *
     * @param pos
     * @return distance
     */
    value_type distanceTo(const pos_type& pos) const;

    /**
     * @brief Computes the euclidean distance to other node
     *
     * @param other
     * @return distance
     */
    value_type distanceTo(const Node& other) const;

    /**
     * @brief accesor for the id member
     *
     * @return id
     */
    const id_type& id() const;

    /**
     * @brief Accesor for the type member
     *
     * @return type
     */
    const type_type& type() const;

    /**
     * @brief Accesor for the pos member
     *
     * @return pos
     */
    const pos_type& pos() const;

protected:
    /**
     * @brief Node identifier
     */
    id_type _id;

    /**
     * @brief An identifier for the type of node
     */
    type_type _type;


    /**
     * @brief Vector type holding the position of the node in the space
     */
    pos_type _pos;
};

#endif
