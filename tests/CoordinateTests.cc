#include <memory>

#include "gtest/gtest.h"

#include "Coordinate.h"


class CoordinateTest : public ::testing::Test
{
    protected:
        virtual void SetUp()
        {
            x = 0.5;
            y = 0.8;
            z = -10;

            coordinate = Coordinate(x, y, z);
        }

        Coordinate::value_type x;
        Coordinate::value_type y;
        Coordinate::value_type z;

        Coordinate coordinate;
        Coordinate origin;
};


TEST_F(CoordinateTest, itCreatesACoordinateWithNoParameters)
{
    ASSERT_NO_THROW(auto coord = Coordinate());
}


TEST_F(CoordinateTest, itCreatesACoordinateOutOf3Parameters)
{
    ASSERT_NO_THROW(auto coord = Coordinate(0, 0, 0));
}


TEST_F(CoordinateTest, itCreatesACoordinateOutOfAnInitializerList)
{
    ASSERT_NO_THROW(auto coord = (Coordinate{0, 0, 0}));
}


TEST_F(CoordinateTest, bracketAccesorReturnsCorrectValues)
{
    ASSERT_EQ(x, coordinate[0]);
    ASSERT_EQ(y, coordinate[1]);
    ASSERT_EQ(z, coordinate[2]);
}


TEST_F(CoordinateTest, bracketAccesorFailsOnWrongIndex)
{
    ASSERT_THROW(coordinate[3], std::out_of_range);
    ASSERT_THROW(coordinate[-1], std::out_of_range);
}


TEST_F(CoordinateTest, methodAccesorsYieldCorrectValues)
{
    ASSERT_FLOAT_EQ(x, coordinate.x());
    ASSERT_FLOAT_EQ(y, coordinate.y());
    ASSERT_FLOAT_EQ(z, coordinate.z());
}


TEST_F(CoordinateTest, distanceToYieldsCorrectValues)
{
    Coordinate b(0, 0, 1);
    Coordinate c(0, 1, 1);
    Coordinate d(1, 1, 1);
    ASSERT_FLOAT_EQ(1.0, origin.distanceTo(b));
    ASSERT_FLOAT_EQ(std::sqrt(2), origin.distanceTo(c));
    ASSERT_FLOAT_EQ(std::sqrt(3), origin.distanceTo(d));
}


TEST_F(CoordinateTest, normYieldsDistanceToOrigin)
{
    ASSERT_FLOAT_EQ(origin.distanceTo(coordinate), coordinate.norm());
    ASSERT_FLOAT_EQ(coordinate.distanceTo(origin), coordinate.norm());
}


TEST_F(CoordinateTest, aCoordinateMovesCorrectly)
{
    Coordinate source{1, 2, 3};
    Coordinate delta {0, -1, -2};
    Coordinate target{1, 1, 1};
    Coordinate result = source.move(delta);
    ASSERT_FLOAT_EQ(target.x(), result.x());
    ASSERT_FLOAT_EQ(target.y(), result.y());
    ASSERT_FLOAT_EQ(target.z(), result.z());
}


TEST_F(CoordinateTest, movingACoordinateYieldsAnIndependentInstance)
{
    std::shared_ptr<Coordinate> source(new Coordinate(0, 0, 0));
    auto result = std::make_shared<Coordinate>(source->move(Coordinate(1, 1, 1)));
    ASSERT_NE(source, result);
}
