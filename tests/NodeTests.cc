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

TEST_F(NodeTest, bracketAccesorOperatorThrowsExceptionWhenIndexIsWrong)
{
    Node node(id, atom.lock(), pos);
    ASSERT_THROW(node[-1], std::out_of_range);
    ASSERT_THROW(node[3], std::out_of_range);
    ASSERT_THROW(node[4], std::out_of_range);
}

