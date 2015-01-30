#ifndef ATOM_H_
#define ATOM_H_

#include <map>
#include <memory>
#include <string>

class Atom
{
    public:
        /**
         * @brief Type of the type of atom
         */
        typedef std::string key_type;

        /**
         * @brief Creates an atom of type
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
        void save() const;

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
        static Atom* create(key_type type);

        /**
         * @brief Finds an atom of type `type` if not found it creates
         *        a new instance
         *
         * @param type
         * @return An observer pointer to the atom stored
         */
        static Atom* getOrCreate(key_type type);

        /**
         * @brief Finds an atom of type `type` if not found fails
         *
         * @param type
         * @return An observer pointer to the atom stored
         */
        static Atom* getOrFail(key_type type);

    protected:
        key_type _type;

    private:
        static std::map<key_type, std::shared_ptr<Atom>> atoms;

};

#endif
