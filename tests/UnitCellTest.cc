#include "gtest/gtest.h"

#include "UnitCell.h"


class UnitCellTest : public ::testing::Test
{
    protected:
        virtual void SetUp()
        {
            a = 1; b = 2; c = 3;
            cubic = UnitCell(a, a, a);
            tetragonal = UnitCell(a, b, c);

            origin = UnitCell::vector_type();
            pos = UnitCell::vector_type(a, b, c);

            rhombohedral_vector = UnitCell::vector_type(1, 1, 1);
            rhombohedral_vector = (1.0 / rhombohedral_vector.norm()) *
                                  rhombohedral_vector;

            ui = UnitCell::vector_type(1, 0, 0);
            uj = UnitCell::vector_type(0, 1, 0);
            uk = UnitCell::vector_type(0, 0, 1);

            rhombohedral = UnitCell(a, a, a,
                                    ui, uj, rhombohedral_vector);
        }

        double a, b, c;

        UnitCell cubic;
        UnitCell tetragonal;
        UnitCell rhombohedral;

        UnitCell::vector_type origin;
        UnitCell::vector_type pos;

        UnitCell::vector_type rhombohedral_vector;

        UnitCell::vector_type ui, uj, uk;
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

TEST_F(UnitCellTest, rhombohedralUnitCellTranslatesOriginProperly)
{
    auto translated = rhombohedral.translate(2, 2, 2);
    auto expected = 2 * a * ui + 2 * a * uj + 2 * a * rhombohedral_vector;
    ASSERT_FLOAT_EQ(expected.x(), translated.x());
    ASSERT_FLOAT_EQ(expected.y(), translated.y());
    ASSERT_FLOAT_EQ(expected.z(), translated.z());
}


TEST_F(UnitCellTest, cubicUnitCellScalesToOnes)
{
    auto scaled = cubic.scale(Coordinate(a, a, a));
    ASSERT_FLOAT_EQ(1, scaled.x());
    ASSERT_FLOAT_EQ(1, scaled.y());
    ASSERT_FLOAT_EQ(1, scaled.z());
}


TEST_F(UnitCellTest, tetragonalUnitCellScalesToOnes)
{
    auto scaled = tetragonal.scale(Coordinate(a, b, c));
    ASSERT_FLOAT_EQ(1, scaled.x());
    ASSERT_FLOAT_EQ(1, scaled.y());
    ASSERT_FLOAT_EQ(1, scaled.z());
}


TEST_F(UnitCellTest, rhombohedralUnitCellScalesToOnes)
{
    auto scaled = rhombohedral.scale(rhombohedral.translate(1, 1, 1));
    ASSERT_FLOAT_EQ(1, scaled.x());
    ASSERT_FLOAT_EQ(1, scaled.y());
    ASSERT_FLOAT_EQ(1, scaled.z());
}


TEST_F(UnitCellTest, cubicUnitCellUnscalesFromOnes)
{
    auto expected = cubic.translate(1, 1, 1);
    auto unscaled = cubic.unscale(Coordinate(1, 1, 1));
    ASSERT_FLOAT_EQ(expected.x(), unscaled.x());
    ASSERT_FLOAT_EQ(expected.y(), unscaled.y());
    ASSERT_FLOAT_EQ(expected.z(), unscaled.z());

}


TEST_F(UnitCellTest, tetragonalUnitCellUnscalesFromOnes)
{
    auto expected = tetragonal.translate(1, 1, 1);
    auto unscaled = tetragonal.unscale(Coordinate(1, 1, 1));
    ASSERT_FLOAT_EQ(expected.x(), unscaled.x());
    ASSERT_FLOAT_EQ(expected.y(), unscaled.y());
    ASSERT_FLOAT_EQ(expected.z(), unscaled.z());

}


TEST_F(UnitCellTest, rhombohedralUnitCellUnscalesFromOnes)
{
    auto expected = rhombohedral.translate(1, 1, 1);
    auto unscaled = rhombohedral.unscale(Coordinate(1, 1, 1));
    ASSERT_FLOAT_EQ(expected.x(), unscaled.x());
    ASSERT_FLOAT_EQ(expected.y(), unscaled.y());
    ASSERT_FLOAT_EQ(expected.z(), unscaled.z());

}
