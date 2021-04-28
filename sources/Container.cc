#include "Container.hh"

template <class ID, class T, class ContainerType>
Container<ID,T,ContainerType>::Container(ContainerStrategy<ID,T,ContainerType> & container): container(container) {}

template <class ID, class T, class ContainerType>
bool Container<ID,T,ContainerType>::contains(ID id) const { return container.contains(id); }

template <class ID, class T, class ContainerType>
T & Container<ID,T,ContainerType>::operator[](ID id) { return container[id]; }

template <class ID, class T, class ContainerType>
const T & Container<ID,T,ContainerType>::operator[](ID id) const { return container[id]; }

template <class ID, class T, class ContainerType>
int Container<ID,T,ContainerType>::count() const { return container.count(); }

template <class ID, class T, class ContainerType>
void Container<ID,T,ContainerType>::add(ID newElementID, T newElement) { container.add(newElementID, newElement); }

template <class ID, class T, class ContainerType>
void Container<ID,T,ContainerType>::remove(ID id) { container.remove(id); }

template <class ID, class T, class ContainerType>
void Container<ID,T,ContainerType>::setSize(int newSize) { container.setSize(newSize); }

template <class ID, class T, class ContainerType>
void Container<ID,T,ContainerType>::append(T newElement) { container.append(newElement); }

template <class ID, class T, class ContainerType>
typename ContainerType::iterator Container<ID,T,ContainerType>::begin() { return container.begin(); }

template <class ID, class T, class ContainerType>
typename ContainerType::iterator Container<ID,T,ContainerType>::end() { return container.end(); }

template <class ID, class T, class ContainerType>
typename ContainerType::const_iterator Container<ID,T,ContainerType>::begin() const { return container.begin(); }

template <class ID, class T, class ContainerType>
typename ContainerType::const_iterator Container<ID,T,ContainerType>::end() const { return container.end(); }