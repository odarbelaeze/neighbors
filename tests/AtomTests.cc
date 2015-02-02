#include "Atom.h"
#include "gtest/gtest.h"


TEST(AtomTest, Create) {
    std::weak_ptr<Atom> atom(Atom::create("Co"));
    EXPECT_FALSE(atom.expired());
    EXPECT_EQ("Co", atom.lock()->type());
}


TEST(AtomTest, AtomCreateCreatesANewInstanceOfAtom)
{
    std::weak_ptr<Atom> atom(Atom::getOrCreate("Co"));
    EXPECT_FALSE(atom.expired());
    EXPECT_EQ("Co", atom.lock()->type());
}


TEST(AtomTest, AtomCreateDoesNotCreateANewInstanceOfAtomIfItExists)
{
    std::weak_ptr<Atom> atom(Atom::create("Co"));
    std::weak_ptr<Atom> atom_get(Atom::getOrCreate("Co"));
    EXPECT_FALSE(atom.expired());
    EXPECT_EQ(atom.lock(), atom_get.lock());
}


TEST(AtomTest, AnAtomInstancePersitedToTheStoreAndTheShared)
{
    std::shared_ptr<Atom> atom(new Atom("Co"));
    atom->save();
    std::weak_ptr<Atom> atom_get(Atom::getOrCreate("Co"));
    EXPECT_FALSE(atom_get.expired());
    EXPECT_EQ(atom, atom_get.lock());
}

TEST(AtomTest, GetOrFailThrowsIfNotFound)
{
    EXPECT_THROW(Atom::getOrFail("Fe"), std::out_of_range);
}


TEST(AtomTest, GetOrFailDoesNotThrowExceptionIfFound)
{
    Atom::create("Co");
    EXPECT_NO_THROW(Atom::getOrFail("Co"));
}

