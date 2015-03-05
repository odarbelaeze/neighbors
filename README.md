# neighbors

**neighbors** is a program that allows you to compute pair-wise
interactions, given different cut-off radiuses, in systems with large
amounts of atoms. The problem trying to be addressed here is that
computing pair wise interactions in a naïve way requires computations
of **O(n^2)** complexity. Using a _kdtree_ to wrap the input data would
reduce that complexity to **O(R N log(N))** where **R** is the average
number of interactions of each site.

## Getting started

### Installing

This program requires at least _gcc-4.9_ to compile, the installation
process may vary according to your operating system, but for Ubuntu
14.04 you need to pull in the toolchain testing repository, update and
install the g++-4.9 package as well as cmake that will be needed later
on,

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install g++-4.9

Then you need to recursively clone the **neighbors** repository and
cd into the directory

    git clone --recursive https://github.com/odarbelaeze/neighbors.git
    cd neighbors

Finally you'll need to build the program, for this you'll need cmake,

    mkdir build
    cd build
    cmake ..
    make

Once you do this you'll have the neighbors program ready to go, you
could do `sudo make install` in order to install the program system
wide, but that's ill advised due to the early stage of development of
this program.

### Building the documentation

Documentation is a big part of the neighbors program, the code
documentation is written into the header files, you can build the
documentation using just by running doxygen in the projects, folder,

    # sudo apt-get install doxygen doxygen-latex
    doxygen
    cd docs
    make latex      # or latexpdf or html

The de documentation will be generated in the `docs/build` directory.

### Building the test suite

In order to build the test suite you just need to install
the [gtest](https://github.com/odarbelaeze/neighbors.git)
framework and make it findable by cmake, you can get instructions
[here](http://www.cmake.org/cmake/help/v3.0/module/FindGTest.html)

    # Install gtest and make it findable
    cd build
    cmake ..
    make
    ./tests

## Running the program

### Specifying interactions

In order to run the program you'll need a `neighbors.json` file this
specifies the kind of interactions that the program will deal with, an
example of the file is given next:

    {
        "doc": {
            "0": "Sites type 0 are this and that...",
            "1": "Sites type 1 are this and that...",
            "0-0": "This interaction is due to something and..."
        },
        "unitcell": {
            "scale": 1.0,
            "parameters": [1.0, 1.0, 1.0],
            "unit_vectors": {
                "uvx": [1.0, 0.0, 0.0],
                "uvy": [0.0, 1.0, 0.0],
                "uvz": [0.0, 0.0, 1.0]
            }
        },
        "periodicity": {
            "x": false,
            "y": false,
            "z": false
        },
        "interactions": {
            "0-0": {
                "cut": 1.0,
                "exchange": 0.5
            },
            "0-1": {
                "cut": 1.0,
                "exchange": 0.5
            },
            "1-0": {
                "cut": 1.0,
                "exchange": 0.5
            },
            "1-1": {
                "cut": 1.0,
                "exchange": 0.5
            }
        }
    }

The *doc* block specifies any documentation that you'll need to
understand the input file in the future, those are notes for the future
you. The *unitcell* block specifies the form of your system is useful
for repeating your system and defining interactions with periodic
boundary conditions. The *periodicity* object specifies if the cell
is periodic or free in each of the directions. Finally the *interactios*
object specify the different interactions between types of atoms.

### Representing the sites

**neighbors** expect a CSV representation of the sites to work with the
format is as follows,

    <x> <y> <z> <type_id>

The *type_id* should be a string without dashes ("-"), because the
interaction markers are made of two type ids separated with a dash.

### Interpreting the output

**neighbors** will output the information relevant to the interactions
in the system, the CSV format will be,

    <int_id> <site_i> <site_j> [<dx> <dy> <dz>] <exchange>

*<dx> <dy> <dz>* are toggled by leaving out the plain flag in the
program's invocation.

