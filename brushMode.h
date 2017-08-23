#ifndef BRUSHMODE_H
#define BRUSHMODE_H
#include "iMode.h"
#include <array>
#include "slider.h"
#include "brush.h"
#include "button.h"
#include "ColorMode.h"
#include "sizeMode.h"

class brushMode:public iColorMode,public iSizeMode{
public:
	brushMode():iColorMode(){
		m_squareButtonText.loadFromFile("squareButton.png");
		m_squareButtonText2.loadFromFile("squareButton2.png");
		
		m_circleButtonText.loadFromFile("circleButton.png");
		m_circleButtonText2.loadFromFile("circleButton2.png");
				
		squareMode = std::unique_ptr<button>(
							new button({510.0f,350.0f},
									   {80,80},
									   {{m_squareButtonText,m_squareButtonText,m_squareButtonText2}},
									   [&](){m_brush = std::unique_ptr<squareBrush>(new squareBrush(m_brush->getSize(),m_currentColor));}));
						
		circleMode = std::unique_ptr<button>(
						new button({600.0f,350.0f},
								   {80,80},
								   {{m_circleButtonText,m_circleButtonText,m_circleButtonText2}},
								   [&](){m_brush = std::unique_ptr<circleBrush>(new circleBrush(m_brush->getSize(),m_currentColor));}));							
	};
	void draw(sf::RenderWindow&)override final;
	void update(const app&,sf::Texture&)override final;
private:
	//slider m_sizeSlider = slider({700,10},{20,90},2,40,10);
	
	sf::Texture m_squareButtonText;
	sf::Texture m_squareButtonText2;
	
	sf::Texture m_circleButtonText;
	sf::Texture m_circleButtonText2;
	
	std::unique_ptr<button> squareMode;
	std::unique_ptr<button> circleMode;
	
	std::unique_ptr<iBrush> m_brush =
									std::unique_ptr<circleBrush>(new circleBrush(10,sf::Color::Black));

};

#endif

