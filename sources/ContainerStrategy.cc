#include "ContainerStrategy.hh"

template <class ID, class T, class Container>
ContainerStrategy<ID,T,Container>::ContainerStrategy(): container(Container()) {}

template <class ID, class T, class Container>
void ContainerStrategy<ID,T,Container>::add(ID newElementID, T newElement) { /*assert(false)*/; newElementID = newElementID; newElement = newElement; }

template <class ID, class T, class Container>
void ContainerStrategy<ID,T,Container>::remove(ID id) { /*assert(false)*/; id = id; }

template <class ID, class T, class Container>
void ContainerStrategy<ID,T,Container>::setSize(int newSize) { /*assert(false)*/; newSize = newSize; }

template <class ID, class T, class Container>
void ContainerStrategy<ID,T,Container>::append(T newElement) { /*assert(false)*/; newElement = newElement; }