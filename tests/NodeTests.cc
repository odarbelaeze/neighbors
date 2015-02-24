#include "gtest/gtest.h"

#include "Atom.h"
#include "Coordinate.h"
#include "Node.h"

class NodeTest : public ::testing::Test
{
    public:
        NodeTest()
           : id(1), pos(1, 1, 1), atom(Atom::create("Au")),
             node(id, atom.lock(), pos),
             ghost(id, atom.lock(), pos, true),
             not_ghost(id, atom.lock(), pos, false) {}

    protected:

        // virtual void SetUp()

        // virtual void TearDown()

        Atom::weak_ptr_type atom;
        size_t id;
        Coordinate pos;

        Node node;
        Node ghost;
        Node not_ghost;
};

TEST_F(NodeTest, itCreatesANodeAcceptingTheParameters)
{
    ASSERT_NO_THROW(Node node_ex(id, atom.lock(), pos, true));
    ASSERT_NO_THROW(Node node_ex(id, atom.lock(), pos, false));
    ASSERT_NO_THROW(Node node_ex(id, atom.lock(), pos));
}

TEST_F(NodeTest, bracketAccesorOperatorYieldsRightValue)
{
    ASSERT_FLOAT_EQ(1.0, node[0]);
    ASSERT_FLOAT_EQ(1.0, node[1]);
    ASSERT_FLOAT_EQ(1.0, node[2]);
}

TEST_F(NodeTest, equalityOperatorReturnsTrueOnSameIdNotGohsts)
{
    ASSERT_TRUE(not_ghost == not_ghost);
}

TEST_F(NodeTest, equalityOperatorReturnsFalseOnSameIdGohsts)
{
    ASSERT_FALSE(ghost == ghost);
}

TEST_F(NodeTest, equalityOperatorReturnsFalseOnSameIdOneGost)
{
    ASSERT_FALSE(ghost == not_ghost);
    ASSERT_FALSE(not_ghost == ghost);
}

TEST_F(NodeTest, inequalityOperatorReturnsFalseOnSameIdNotGohsts)
{
    ASSERT_FALSE(not_ghost != not_ghost);
}

TEST_F(NodeTest, inequalityOperatorReturnsTrueOnSameIdGohsts)
{
    ASSERT_TRUE(ghost != ghost);
}

TEST_F(NodeTest, inequalityOperatorReturnsTrueOnSameIdOneGost)
{
    ASSERT_TRUE(ghost != not_ghost);
    ASSERT_TRUE(not_ghost != ghost);
}

TEST_F(NodeTest, idAccesorRetrurnsRightId)
{
    ASSERT_EQ(id, node.id());
}

TEST_F(NodeTest, dataAccesorReturnsTheSamePointer)
{
    ASSERT_EQ(atom.lock(), node.data());
}

TEST_F(NodeTest, posAccesorReturnsTheRightPos)
{
    for (size_t i = 0; i < 3; ++i)
    {
        ASSERT_FLOAT_EQ(pos[i], node.pos()[i]);
    }
}
