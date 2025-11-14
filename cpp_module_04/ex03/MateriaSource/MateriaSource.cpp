#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

}

MateriaSource::MateriaSource(const MateriaSource& other) {

	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {

	if (this != &other) {
		// copy members
	}
	return *this;
}

MateriaSource::~MateriaSource() {

}
