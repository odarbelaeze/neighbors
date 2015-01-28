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
     * @param pos
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
     * @param pos
     * @param range
     * @return a vector holding the nodes
     */
    node_list_type findWithinRange (node_type ref, double range) const;

    /**
     * @brief Returns all the nodes in the repo
     *
     * @return a vector holding the nodes
     */
    node_list_type all() const;

protected:
    /**
     * @brief A __k__-dimensional tree used for performance reasons
     */
    tree_type _tree;
};

#endif
