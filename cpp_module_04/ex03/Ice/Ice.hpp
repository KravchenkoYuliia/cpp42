#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice {
    public:
        Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        
	~Ice();

};

#endif
