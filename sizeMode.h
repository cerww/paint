#ifndef SIZEMODE_H
#define SIZEMODE_H
#include "iMode.h"
#include <utility>
#include "slider.h"

class iSizeMode:public virtual iMode{
public:
	iSizeMode() = default;
protected:
	int size = 10;
	std::pair<bool,int> updateSizeSlider(const app&);
	void drawSizeSlider(sf::RenderWindow&);
private:
	slider m_sizeSlider = slider({700,10},{20,90},2,40,10);
};

#endif

