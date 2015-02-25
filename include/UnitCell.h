#ifndef UNIT_CELL_H_
#define UNIT_CELL_H_

#include "Coordinate.h"

class UnitCell
{
    public:

        /**
         * @brief Type to use as vector
         */
        typedef Coordinate vector_type;

        /**
         * @brief Type to use as real
         */
        typedef Coordinate::value_type real_type;

        /**
         * @brief Type to use as integer
         */
        typedef int integer_type;

        /**
         * @brief Builds a cubic unitcell
         */
        UnitCell ();

        /**
         * @brief Builds an orthorhombic unit cell
         *
         * @param a
         * @param b
         * @param c
         */
        UnitCell (
                const real_type a,
                const real_type b,
                const real_type c);

        /**
         * @brief Builds a triclinic lattice out of vectors
         *
         * @param ucvx
         * @param ucvy
         * @param ucvz
         */
        UnitCell (
                const vector_type& ucvx,
                const vector_type& ucvy,
                const vector_type& ucvz);

        /**
         * @brief Builds a new unicell using the lattice parameters and
         *        the lattice unitvectors.
         *
         * @param ucx
         * @param ucy
         * @param ucz
         * @param ucvx
         * @param ucvy
         * @param ucvz
         */
        UnitCell(
                const real_type ucx,
                const real_type ucy,
                const real_type ucz,
                const vector_type ucvx,
                const vector_type ucvy,
                const vector_type ucvz);

        /**
         * @brief Destroys the unit cell
         */
        virtual ~UnitCell ();

        /**
         * @brief Translate the origin according to the unit cell
         *
         * @param i
         * @param j
         * @param k
         *
         * @return a new vector
         */
        vector_type
            translate(
                    integer_type i,
                    integer_type j,
                    integer_type k) const;

        /**
         * @brief Translate a position according to the unit cell
         *
         * @param i
         * @param j
         * @param k
         * @param pos
         *
         * @return a new vector
         */
        vector_type
            translate(
                    integer_type i,
                    integer_type j,
                    integer_type k,
                    vector_type pos) const;

    private:

        /**
         * @brief Unit cell size x
         */
        real_type _ucx;

        /**
         * @brief Unit cell size y
         */
        real_type _ucy;

        /**
         * @brief Unit cell size z
         */
        real_type _ucz;

        /**
         * @brief Unit vector
         */
        vector_type _ucvx;

        /**
         * @brief Unit vector
         */
        vector_type _ucvy;

        /**
         * @brief Unit vector
         */
        vector_type _ucvz;

};

#endif