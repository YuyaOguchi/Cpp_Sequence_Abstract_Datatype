//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 2 b
//  2/10/2016
//  sequence class for abstract datatype assuming it can be comparable datatype

#include <cstdlib>  // Provides size_t

template <typename T>
class sequence{
private:
    T *data;
    T used;
    T current_index;
public:
    typedef double value_type;
    typedef int size_type;
    static const size_type CAPACITY = 30;
    // CONSTRUCTOR
    sequence( );
    // MODIFICATION MEMBER FUNCTIONS
    void start( );
    void advance( );
    void insert(const T& entry);
    void attach(const T& entry);
    void frontInsert(const T& entry);
    void frontDelete(const T& entry);
    void backInsert(const T& entry);
    void backDelete(const T& entry);
    void remove_current( );
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) ;
    bool is_item( );
    value_type current( );
    void dump();
    sequence operator+(const sequence& s1);
    sequence operator+=(const sequence& s1);
};
