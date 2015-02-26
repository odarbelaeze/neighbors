#include "gtest/gtest.h"

#include "UnitCell.h"


class UnitCellTest : public ::testing::Test
{
    protected:
        virtual void SetUp()
        {
            a = 1; b = 2; c = 3;
            origin = UnitCell::vector_type();
            cubic = UnitCell(a, a, a);
            tetragonal = UnitCell(a, b, c);
        }

        double a, b, c;

        UnitCell cubic;
        UnitCell tetragonal;

        UnitCell::vector_type origin;
};


TEST_F(UnitCellTest, unitcellTranslatesOriginProperly)
{
    auto translated = cubic.translate(1, 1, 1);
    ASSERT_FLOAT_EQ(1 * a, translated.x());
    ASSERT_FLOAT_EQ(1 * a, translated.y());
    ASSERT_FLOAT_EQ(1 * a, translated.z());
}


TEST_F(UnitCellTest, tetragonalUnitCellTranslatesOriginProperly)
{
    auto translated = tetragonal.translate(2, 2, 2);
    ASSERT_FLOAT_EQ(2 * a, translated.x());
    ASSERT_FLOAT_EQ(2 * b, translated.y());
    ASSERT_FLOAT_EQ(2 * c, translated.z());
}

