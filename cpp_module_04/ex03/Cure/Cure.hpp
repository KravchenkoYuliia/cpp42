#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

class Cure {
    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        
	~Cure();

};

#endif
