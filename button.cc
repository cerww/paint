#include "button.h"

button::button(const sf::Vector2f& p,const dim2& d,std::array<const sf::Texture,3> t,std::function<void()> f):
m_pos(p),
m_dims(d),
m_normalText(t[0]),
m_hoverText(t[1]),
m_clickText(t[2]),
m_f(f){
	const auto temp = t[0].getSize();
	m_verts[0] = {p,sf::Color::White,{0,0}};
	m_verts[1] = {{p.x,p.y+d.length},sf::Color::White,{0,(float)temp.y}};
	m_verts[2] = {{p.x+d.width,p.y+d.length},sf::Color::White,{(float)temp.x,(float)temp.y}};
	m_verts[3] = {{p.x+d.width,p.y},sf::Color::White,{(float)temp.x,0}};
}

void button::draw(sf::RenderWindow& win)const{
	switch(state){
		case buttonState::NORMAL:
			win.draw(&m_verts[0],4,sf::Quads,&m_normalText);
			break;
		case buttonState::HOVER:
			win.draw(&m_verts[0],4,sf::Quads,&m_hoverText);
			break;
		case buttonState::CLICK:
			win.draw(&m_verts[0],4,sf::Quads,&m_clickText);
			break;
	}
}

void button::update(const app& window){
	if(pointInBox(m_pos,m_dims.width,m_dims.length,window.getMouseCoords("main"))){
		const auto temp = window.getMouseClick("main",mouseButton::LEFT);
		if(temp){
			state = buttonState::CLICK;
			if(temp==1){
				click();
			}
		}else{
			state = buttonState::HOVER;
		}
	}else{
		state = buttonState::NORMAL;
	}	
}

void button::click()const{
	m_f();
}

