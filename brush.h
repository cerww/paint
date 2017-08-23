#ifndef BRUSH_H
#define BRUSH_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <utility>

class iBrush{
public:
	iBrush() = default;
	iBrush(int,sf::Color);//size
	const sf::Image& getIm()const{return m_i;};
	int getSize()const{return m_size;};
	sf::Color getColor()const{return m_c;};
	void setColor(const sf::Color o) {
		m_c = o;
		update();
	}
	void setSize(const int newSize){
		m_size = newSize;
		update();
	}
	virtual void brush(sf::Texture&,const sf::Vector2f) = 0;
	virtual void brush(sf::Image&,const sf::Vector2f) = 0;
protected:
	virtual void update() = 0;
	int m_size;
	sf::Color m_c;
	sf::Image m_i;
};


class circleBrush:public iBrush{
public:
	circleBrush() = default;
	circleBrush(int a,sf::Color b):iBrush(a,b){update();};//size becomes the r;
	
	void brush(sf::Texture&,const sf::Vector2f)override final;
	void brush(sf::Image&,const sf::Vector2f)override final;
private:
	void update() override final;	
};


class squareBrush:public iBrush{
public:
	squareBrush() = default;
	squareBrush(int a,sf::Color b):iBrush(a,b){update();};//size is sideLength
	
	void brush(sf::Texture&,const sf::Vector2f)override final;
	void brush(sf::Image&,const sf::Vector2f)override final;
private:
	void update() override final;	
};

class bucketBrush{
public:
	bucketBrush() = default;
	bucketBrush(int a,sf::Color b){update();};
	void setColor(const sf::Color o) {
		m_c = o;
		update();
	}
	void setSize(const int newSize){
		m_size = newSize;
		update();
	}
	void brush(sf::Texture&,const sf::Vector2f);
	void brush(sf::Image&,const sf::Vector2f);
protected:
	void update();
	int m_size;
	sf::Color m_c;
};

#endif

