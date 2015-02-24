#include "gtest/gtest.h"

#include "Atom.h"
#include "Coordinate.h"
#include "Node.h"

class NodeTest : public ::testing::Test
{
    public:
        NodeTest() : pos(1, 1, 1) {}

    protected:

        virtual void SetUp()
        {
            id = 1;
            this->atom = Atom::create("Au");
            this->pos = Coordinate(1, 1, 1);
        }

        // virtual void TearDown()

        size_t id;
        Atom::weak_ptr_type atom;
        Coordinate pos;
};

TEST_F(NodeTest, itCreatesANodeAcceptingTheParameters)
{
    auto ghost = false;
    ASSERT_NO_THROW(Node node(id, atom.lock(), pos, ghost));
    ASSERT_NO_THROW(Node node(id, atom.lock(), pos));
}

TEST_F(NodeTest, bracketAccesorOperatorYieldsRightValue)
{
    Node node(id, atom.lock(), pos);
    ASSERT_FLOAT_EQ(1.0, node[0]);
    ASSERT_FLOAT_EQ(1.0, node[1]);
    ASSERT_FLOAT_EQ(1.0, node[2]);
}

TEST_F(NodeTest, equalityOperatorReturnsTrueOnSameIdNotGohsts)
{
    Node node_a(id, atom.lock(), pos, false);
    Node node_b(id, atom.lock(), pos, false);
    ASSERT_TRUE(node_a == node_b);
}

TEST_F(NodeTest, equalityOperatorReturnsFalseOnSameIdGohsts)
{
    Node node_a(id, atom.lock(), pos, true);
    Node node_b(id, atom.lock(), pos, true);
    ASSERT_FALSE(node_a == node_b);
}

TEST_F(NodeTest, equalityOperatorReturnsFalseOnSameIdOneGost)
{
    Node node_a(id, atom.lock(), pos, true);
    Node node_b(id, atom.lock(), pos, false);
    ASSERT_FALSE(node_a == node_b);
    ASSERT_FALSE(node_b == node_a);
}

TEST_F(NodeTest, inequalityOperatorReturnsFalseOnSameIdNotGohsts)
{
    Node node_a(id, atom.lock(), pos, false);
    Node node_b(id, atom.lock(), pos, false);
    ASSERT_FALSE(node_a != node_b);
}

TEST_F(NodeTest, inequalityOperatorReturnsTrueOnSameIdGohsts)
{
    Node node_a(id, atom.lock(), pos, true);
    Node node_b(id, atom.lock(), pos, true);
    ASSERT_TRUE(node_a != node_b);
}

TEST_F(NodeTest, inequalityOperatorReturnsTrueOnSameIdOneGost)
{
    Node node_a(id, atom.lock(), pos, true);
    Node node_b(id, atom.lock(), pos, false);
    ASSERT_TRUE(node_a != node_b);
    ASSERT_TRUE(node_b != node_a);
}

TEST_F(NodeTest, idAccesorRetrurnsRightId)
{
    Node node(id, atom.lock(), pos);
    ASSERT_EQ(id, node.id());
}

TEST_F(NodeTest, dataAccesorReturnsTheSamePointer)
{
    Node node(id, atom.lock(), pos);
    ASSERT_EQ(atom.lock(), node.data());
}

TEST_F(NodeTest, posAccesorReturnsTheRightPos)
{
    Node node(id, atom.lock(), pos);
    for (size_t i = 0; i < 3; ++i)
    {
        ASSERT_FLOAT_EQ(pos[i], node.pos()[i]);
    }
}
