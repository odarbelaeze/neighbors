#include "gtest/gtest.h"

#include "Atom.h"
#include "Coordinate.h"
#include "Node.h"

TEST(NodeTests, itCreatesANodeAcceptingTheParameters)
{
    size_t id = 1;
    auto atom = Atom::create("Au");
    auto pos  = Coordinate(1, 1, 1);
    auto ghost = false;
    ASSERT_NO_THROW(Node node(id, atom.lock(), pos, ghost));
    ASSERT_NO_THROW(Node node(id, atom.lock(), pos));
}

