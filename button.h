#ifndef BUTTON_H
#define BUTTON_H
#include "app.h"
#include "dim.h"
#include <functional>
class buttonO{
	public:
		buttonO() = default;
		virtual void draw(sf::RenderWindow&)const = 0;
		template<class ...Args>
		void click(Args... args)const;
		virtual const std::string& getText()const = 0;//{return m_text;};
};

class button{
public:
	button() = delete;
	button(const sf::Vector2f&,const dim2&,std::array<const sf::Texture,3> ,std::function<void()>);
	
	//void load(const sf::Vector2f&,const dim2&,std::array<const sf::Texture,3> ,std::function<void()>);
	
	sf::Vector2f getPos()const{return m_pos;};
	dim2 getDimen()const {return m_dims;};
	void draw(sf::RenderWindow&)const;
	void update(const app&);

	void click()const;
private:
	enum class buttonState{NORMAL,HOVER,CLICK};
	sf::Vector2f m_pos;
	dim2 m_dims;
	
	std::array<sf::Vertex,4> m_verts = {};
	//std::string m_text;
	
	const sf::Texture m_normalText;
	const sf::Texture m_hoverText;
	const sf::Texture m_clickText;
	
	buttonState state = buttonState::NORMAL;
	
	std::function<void()> m_f;
};
/*
template<typename fn>
inline button<fn> mkButton(const sf::Vector2f& p,const dim2& d,const sf::Texture& t,fn f){
	return button<fn>(p,d,t,f);
}*/
#endif

