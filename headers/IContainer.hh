/**
@file IContainer.hh
@brief File containing the specification of the @c IContainer interface
*/

#ifndef ICONTAINER_HH
#define ICONTAINER_HH

#include "Namespaces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/**
<<<<<<< HEAD:headers/Interfaces.hh
@interface IPrintable
@brief IPrintable interface
*/
class IPrintable {
public:
	/**
<<<<<<< HEAD:headers/IContainer.hh
=======
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The @c IPrintable object is printed to the stdout
	*/
	virtual void print() const = 0;

	/**
>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df:headers/Interfaces.hh
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const IPrintable &printable);
};

/**
@Interface IReadable
@brief IReadable interface
*/
class IReadable {
public:	
	/**
	@brief Read to the @c IReadable object from the stdin
	@pre true
	@post The @c IReadable object is read from the stdin
	*/
	virtual void read() = 0;

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, IReadable &readable);
};

/**
=======
>>>>>>> d492b3a069c2074d005a742334644ac2220fcab0:headers/IContainer.hh
@interface IContainer
@brief @c IContainer interface
*/
template <typename ID, typename T>
class IContainer {
public:
<<<<<<< HEAD:headers/IContainer.hh

=======
>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df:headers/Interfaces.hh
	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	virtual bool containsElement(ID id) const = 0;
<<<<<<< HEAD:headers/IContainer.hh

	/**
	@brief Return wheter the @c IContainer object has an element with the same id as @c element
	@pre true
	@post @c true is returned if there is an element with the same id as @c element within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(T element) const;

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	T& getElement(ID id);
=======
>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df:headers/Interfaces.hh

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	virtual T& operator[](ID id) = 0;
<<<<<<< HEAD:headers/IContainer.hh

	/**
	@brief Returns the constant element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post A constant element with the given ID contained in the @c IContainer object is returned
	*/
	const T& getConstElement(ID id) const;

	/**
	@brief Returns the constant element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post A constant element with the given ID contained in the @c IContainer object is returned
	*/
	const T& operator[](ID id) const;
=======
>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df:headers/Interfaces.hh

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	virtual int getCount() const = 0;
<<<<<<< HEAD:headers/IContainer.hh

	/**
	@brief Add a new element, given such element
	@pre There is not any element with the same id as @c newElement within the @c IContainer object
	@post @c newElement is added to the @c IContainer object
	*/
	void addElement(T newElement);
=======
>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df:headers/Interfaces.hh

	/**
	@brief Add a new element, given such element's id
	@pre There is not any element with the given id within the @c IContainer object
	@post A new element with @c newElementID is added to the @c IContainer object
	*/
	virtual void addElement(ID newElementID) = 0;
};

#endif