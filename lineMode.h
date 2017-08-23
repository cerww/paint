#ifndef LINEMODE_H
#define LINEMODE_H
#include "ColorMode.h"
#include "brush.h"
#include "sizeMode.h"
class lineMode:public iColorMode,public iSizeMode{
public:
	lineMode() = default;
	void update(const app&,sf::Texture&) override final;
	void draw(sf::RenderWindow&)override final;
private:
	slider m_sizeSlider = slider({700,10},{20,90},2,40,10);
	sf::Vector2f p1;
	sf::Vector2f p2;
	sf::Color m_c = sf::Color::Black;
	void drawLine(sf::Texture& t,sf::Vector2f p1,const sf::Vector2f p2);
	squareBrush m_b = squareBrush(10,sf::Color::Black);
};


#endif

