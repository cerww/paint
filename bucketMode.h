#ifndef BUCKETMODE_H
#define BUCKETMODE_H
#include "ColorMode.h"
#include "brush.h"

class bucketMode:public iColorMode{
public:
	bucketMode() = default;
	void draw(sf::RenderWindow&) override final;
	void update(const app&,sf::Texture&) override final;
private:
	bucketBrush m_b = bucketBrush(0,sf::Color::Black);
};

#endif

