#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <array>
#include <cmath>

class Coordinate
{
    public:

        /**
         * @brief Type of value to store the coordinates
         */
        typedef double value_type;

        /**
         * @brief Underlying storage array
         */
        typedef std::array<value_type, 3> store_type;

        /**
         * @brief Builds the origin coordinate
         */
        Coordinate ();

        /**
         * @brief Builds a coordinate out of the tree coordinates
         *
         * @param x
         * @param y
         * @param z
         */
        Coordinate (value_type x, value_type y, value_type z);

        /**
         * @brief Builds a coordinate out of an underlying array
         *
         * @param array
         */
        Coordinate (const store_type& array);

        /**
         * @brief Forcing the compiler to generate a copy constructor
         */
        Coordinate (const Coordinate&) = default;

        /**
         * @brief Destroys the coordinate
         */
        virtual ~Coordinate ();

        /**
         * @brief Bracket accesor
         *
         * @param i
         * @return Coordinate at i
         */
        value_type operator[] (std::size_t i) const;

        /**
         * @brief Compund assignment operator to add another coordinate.
         *
         * @param other
         *
         * @return Coordinate&
         */
        Coordinate& operator+= (const Coordinate& other);

        /**
         * @brief Compund assignment operator to substract another coordinate.
         *
         * @param other
         *
         * @return Coordinate&
         */
        Coordinate& operator-= (const Coordinate& other);

        /**
         * @brief Compund assignment operator to do scalar product.
         *
         * @param other
         *
         * @return Coordinate&
         */
        Coordinate& operator*= (const value_type& other);

        /**
         * @brief Non destructive add operation for coordinates
         *
         * @param lhs
         * @param rhs
         *
         * @return const Coordinate
         */
        friend const Coordinate operator+ (Coordinate lhs, const Coordinate& rhs);

        /**
         * @brief Non destructive subtract operation for coordinates
         *
         * @param lhs
         * @param rhs
         *
         * @return const Coordinate
         */
        friend const Coordinate operator- (Coordinate lhs, const Coordinate& rhs);

        /**
         * @brief Non destructive scalar product for coordinates
         *
         * @param lhs
         * @param rhs
         *
         * @return const Coordinate
         */
        friend const Coordinate operator* (Coordinate lhs, const value_type& rhs);

        /**
         * @brief Non destructive scalar product for coordinates in reversed order
         *
         * @param lhs
         * @param rhs
         *
         * @return const Coordinate
         */
        friend const Coordinate operator* (value_type lhs, const Coordinate& rhs);

        /**
         * @brief Returns the coordinate at `x`
         *
         * @return Coordinate at `x`
         */
        value_type x () const;

        /**
         * @brief Returns the coordinate at `y`
         *
         * @return Coordinate at `y`
         */
        value_type y () const;

        /**
         * @brief Returns the coordinate at `y`
         *
         * @return Coordinate at `y`
         */
        value_type z () const;

        /**
         * @brief Compute the dot product between coordinates seeing
         *        them as vectors
         *
         * @param other
         *
         * @return value_type
         */
        value_type dot (const Coordinate& other) const;

        /**
         * @brief Non member dot __operator__ for coordinates
         *        seen as vectors.
         *
         * @param one
         * @param other
         *
         * @return value type
         */
        friend value_type dot (const Coordinate& one, const Coordinate& other);

        /**
         * @brief Returns the euclidean distance to other coordinate
         *
         * @param other
         *
         * @return Distance
         */
        value_type distanceTo (const Coordinate& other) const;

        /**
         * @brief Computes the distance of the coordinate to the
         *        origin.
         *
         * @return value_type
         */
        value_type norm() const;

        /**
         * @brief Returns a new coordinate instance
         *
         * Computes a new Coordinate instance by moving to the coordinate
         * other using this coordinate as the origin.
         *
         * @param other
         *
         * @return A new coordinate instance
         */
        Coordinate move (const Coordinate& other) const;

    protected:
        /**
         * @brief Underlying array containig the coordinate
         */
        store_type _vec;

};

#endif
