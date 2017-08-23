#ifndef IMODE_H
#define IMODE_H
#include "app.h"
#include <tuple>

class iMode{
public:
	iMode() = default;
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void update(const app&,sf::Texture&) = 0;
private:
	
};

#endif //learn TMP

