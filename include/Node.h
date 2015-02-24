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

#include "Atom.h"
#include "Coordinate.h"

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
         * @brief Repository containing the data
         */
        typedef Atom data_store_type;

        /**
         * @brief Type of data stored in the node
         */
        typedef Atom::shared_ptr_type data_type;

        /**
         * @brief Type of key used by the atom store
         */
        typedef Atom::key_type data_key_type;

        /**
         * @brief Type of value to adhere to the interface required by libkdtree
         */
        typedef double value_type;

        /**
         * @brief Type used to store the position of a node
         */
        typedef Coordinate pos_type;

        /**
         * @brief Builds a node with id, type and position
         *
         * @param id Id of this node
         * @param data Data to be stored in this node
         * @param pos Position of the node
         * @param ghost Is this node a ghost node
         */
        Node (id_type id, data_type data, pos_type pos, bool ghost=false);

        /**
         * @brief Builds a node finding the data by key
         *
         * @param id
         * @param key
         * @param pos
         * @param ghost
         */
        explicit Node (id_type id, data_key_type key, pos_type pos, bool ghost=false);

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
         * Two Nodes with the same `id` are considered identical except
         * when at least one of them are ghosts.
         *
         * @param other
         *
         * @return bool
         */
        bool operator== (const Node& other) const;

        /**
         * @brief Tests unequallity of this node with other according to
         *        their ids
         *
         * Two Nodes with the same `id` are considered identical except
         * when at least one of them are ghosts.
         *
         * @param other
         *
         * @return bool
         */
        bool operator!= (const Node& other) const;

        /**
         * @brief Computes the distance of the node to a remote position
         *
         * @param pos
         * @return distance
         */
        value_type distanceTo (const pos_type& pos) const;

        /**
         * @brief Computes the euclidean distance to other node
         *
         * @param other
         * @return distance
         */
        value_type distanceTo (const Node& other) const;

        /**
         * @brief accesor for the id member
         *
         * @return id
         */
        const id_type& id () const;

        /**
         * @brief Accesor for the type member
         *
         * @return The data stored in the node
         */
        const data_type& data () const;

        /**
         * @brief Accesor for the pos member
         *
         * @return pos
         */
        const pos_type& pos () const;

    protected:
        /**
         * @brief Node identifier
         */
        id_type _id;

        /**
         * @brief An identifier for the type of node
         */
        data_type _data;


        /**
         * @brief Vector type holding the position of the node in the space
         */
        pos_type _pos;


        /**
         * @brief A flag to indicate if the node is a ghost
         */
        bool _is_ghost;
};

#endif
