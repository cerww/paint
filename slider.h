#ifndef SLIDER_H
#define SLIDER_H
#include "app.h"
#include "dim.h"
#include <functional>
#include <tuple>

class slider{
public:

	slider() = default;
	slider(sf::Vector2f,dim2,int,int);
	slider(sf::Vector2f,dim2,int,int,int);
	int getVal()const{return m_current;};
	int getMax()const{return m_max;};
	int getMin()const{return m_min;};
	sf::Vector2f getPos()const{return m_pos;};
	dim2 getDimen()const{return m_dims;};
	void draw(sf::RenderWindow&)const;
	bool changeVal(const sf::Vector2f,bool);
private:

	static bool Loaded;
	static sf::Texture line;
	static sf::Texture bar;
	void updateVerts();
	sf::Vector2f m_pos;
	dim2 m_dims;
	int m_min;
	int m_max;
	int m_current;
	std::array<sf::Vertex,8> m_verts;
};

#endif

