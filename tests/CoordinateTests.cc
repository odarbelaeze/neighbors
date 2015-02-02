#include <memory>

#include "gtest/gtest.h"

#include "Coordinate.h"


TEST(CoordinateTests, itCreatesACoordinateOutOf3Parameters)
{
    ASSERT_NO_THROW(auto coord = Coordinate(0, 0, 0));
}


TEST(CoordinateTests, itCreatesACoordinateOutOfAnInitializerList)
{
    ASSERT_NO_THROW(auto coord = (Coordinate{0, 0, 0}));
}


TEST(CoordinateTests, bracketAccesorReturnsCorrectValues)
{
    double x = 0.5, y = 0.8, z = -10;
    Coordinate coordinate(x, y, z);
    ASSERT_EQ(x, coordinate[0]);
    ASSERT_EQ(y, coordinate[1]);
    ASSERT_EQ(z, coordinate[2]);
}


TEST(CoordinateTests, methodAccesorsYieldCorrectValues)
{
    double x = 0.5, y = 0.8, z = -10;
    Coordinate coordinate(x, y, z);
    ASSERT_EQ(x, coordinate.x());
    ASSERT_EQ(y, coordinate.y());
    ASSERT_EQ(z, coordinate.z());
}


TEST(CoordinateTests, distanceToYieldsCorrectValues)
{
    Coordinate a(0, 0, 0);
    Coordinate b(0, 0, 1);
    Coordinate c(0, 1, 1);
    Coordinate d(1, 1, 1);
    ASSERT_FLOAT_EQ(1.0, a.distanceTo(b));
    ASSERT_FLOAT_EQ(std::sqrt(2), a.distanceTo(c));
    ASSERT_FLOAT_EQ(std::sqrt(3), a.distanceTo(d));

}


TEST(CoordinateTests, aCoordinateMovesCorrectly)
{
    Coordinate source{1, 2, 3};
    Coordinate delta {0, -1, -2};
    Coordinate target{1, 1, 1};
    Coordinate result = source.move(delta);
    ASSERT_FLOAT_EQ(target.x(), result.x());
    ASSERT_FLOAT_EQ(target.y(), result.y());
    ASSERT_FLOAT_EQ(target.z(), result.z());
}


TEST(CoordinateTests, movingACoordinateYieldsAnIndependentInstance)
{
    std::shared_ptr<Coordinate> source(new Coordinate(0, 0, 0));
    auto result = std::make_shared<Coordinate>(source->move(Coordinate(1, 1, 1)));
    ASSERT_NE(source, result);
}

