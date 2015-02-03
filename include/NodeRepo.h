/**
 * @file NodeRepo.h
 * @brief Defines a Node repository
 * @author Oscar David Arbeláez
 * @version 0.0.1
 * @date 2015-01-28
 */

#ifndef NODE_REPO_H_
#define NODE_REPO_H_

#include <algorithm>
#include <iterator>
#include <functional>

#include "Node.h"

#include "kdtree++/kdtree.hpp"

/**
 * @brief Defines a Node repository that can be queried
 */
class NodeRepo
{
    public:

        /**
         * @brief The kdtree type to be used
         */
        typedef KDTree::KDTree<3, Node> tree_type;

        /**
         * @brief Iterator over the nodes in the tree
         */
        typedef tree_type::const_iterator const_iterator;

        /**
         * @brief The position type of the Node
         */
        typedef Node node_type;

        /**
         * @brief the type used to return node lists
         */
        typedef std::vector<Node> node_list_type;

        /**
         * @brief Builds a Node repository with a derault tree
         *
         * @param tree
         */
        NodeRepo (const tree_type& tree = tree_type());

        /**
         * @brief Destroys the Node repository relying on the default destructors
         */
        virtual ~NodeRepo ();

        /**
         * @brief Inserts the given node into the tree
         *
         * @param node
         * @return this node for a fluent API
         */
        NodeRepo& insert (const Node& node);

        /**
         * @brief Balances the tree for greater performance
         *
         * @return this node for a fluent API
         */
        NodeRepo& optimize ();

        /**
         * @brief Returns a vector holding the nodes within the specified sphere
         *
         * @param ref
         * @param radius
         * @return a vector holding the nodes
         */
        node_list_type findWithinSphere (node_type ref, double radius) const;

        /**
         * @brief Returns a vector holding the nodes within the range
         *
         * The range is computed using the Manhattan distance around the
         * specified position `pos`
         *
         * @param ref
         * @param range
         * @return a vector holding the nodes
         */
        node_list_type findWithinRange (node_type ref, double range) const;

        /**
         * @brief Returns all the nodes in the repo
         *
         * @note This operation is implemented in a very expensive way.
         *
         * @return a vector holding the nodes
         */
        node_list_type all() const;

        /**
         * @brief Const forward iterator to the leftmost item of the tree
         *
         * @return const_iterator
         */
        const_iterator begin() const;

        /**
         * @brief Const fordwar iterator to one past the last element of the tree
         *
         * @return const_iterator
         */
        const_iterator end() const;

    protected:
        /**
         * @brief A __k__-dimensional tree used for performance reasons
         */
        tree_type _tree;
};

#endif
