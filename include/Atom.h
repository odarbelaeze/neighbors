/**
 * @file Atom.h
 * @brief It defines a Atom class that acts as an instance and a static store
 * @author Oscar David Arbeláez
 * @version 0.0.1
 * @date 2015-02-02
 */
#ifndef ATOM_H_
#define ATOM_H_

#include <map>
#include <memory>
#include <string>

/**
 * @brief Defines an Atom class and container
 *
 * For now it just stores the type of atom and manages to use only
 * one instance of each type.
 *
 * @note: If you want to instantiate an Atom and then call the save
 *        method on it, make sure that you wrap your object into a shared
 *        pointer `auto instance = std::make_shared<Atom>('Fe');`
 */
class Atom : public std::enable_shared_from_this<Atom>
{
    public:
        /**
         * @brief Type of the type of atom
         */
        typedef std::string key_type;

        /**
         * @brief A shared pointer to an Atom
         */
        typedef std::shared_ptr<Atom> shared_ptr_type;

        /**
         * @brief A weak ptr to an atom
         */
        typedef std::weak_ptr<Atom> weak_ptr_type;

        /**
         * @brief Creates an Atom of type
         *
         * @param type
         */
        Atom (key_type type);

        /**
         * @brief Destroys the atom instance but doesn't delete it from the
         *        map.
         */
        virtual ~Atom ();

        /**
         * @brief Registers the atom instance into the static map
         */
        void save();

        /**
         * @brief Returns the type of the atom on use.
         *
         * @return The atoms type
         */
        key_type type() const;

        /**
         * @brief Creates a new atom and stores it into the map
         *
         * @param type
         * @return An observer pointer to the atom stored
         */
        static weak_ptr_type create(key_type type);

        /**
         * @brief Finds an atom of type `type` if not found it creates
         *        a new instance
         *
         * @param type
         * @return An observer pointer to the atom stored
         */
        static weak_ptr_type getOrCreate(key_type type);

        /**
         * @brief Finds an atom of type `type` if not found fails
         *
         * @param type
         * @return An observer pointer to the atom stored
         */
        static weak_ptr_type getOrFail(key_type type);

    protected:
        /**
         * @brief Type of this instance of atom
         */
        key_type _type;

    private:
        /**
         * @brief Store of atoms that allows having just one for each type
         */
        static std::map<key_type, shared_ptr_type> atoms;

};

#endif
