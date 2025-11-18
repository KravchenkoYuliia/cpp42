#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {

	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {

	if (this != &other) {
		// copy members
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {

}
