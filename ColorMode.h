#ifndef COLORMODE_H
#define COLORMODE_H
#include "iMode.h"
#include <utility>
#include "slider.h"

class iColorMode:public virtual iMode{
public:
	iColorMode(){
		for(int i = 0;i<3;++i){
			m_rgbSliders[i] = slider({550.0f+i*40.0f,10},{30,257},0,255);
		}
		m_colorSample.create(1,1);
		changeSampleColorThingy();
	};
protected:
	void drawSliders(sf::RenderWindow&);
	std::pair<bool,sf::Color> updateSliders(const app&);
	sf::Color m_currentColor = sf::Color::Black;
private:
	std::array<slider,3> m_rgbSliders;
	
	sf::Texture m_colorSample;
	void changeSampleColorThingy();
};

#endif

