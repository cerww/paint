#include "slider.h"


bool slider::Loaded = 0;
sf::Texture slider::line;
sf::Texture slider::bar;

slider::slider(sf::Vector2f pos,dim2 d,int min,int max):
m_pos(pos),
m_dims(d),
m_min(min),
m_max(max),
m_current(min){
	if(!Loaded){
		Loaded = 1;
		bar.loadFromFile("sliderThing.png");
		line.loadFromFile("sliderBar.png");
	}updateVerts();
}

slider::slider(sf::Vector2f pos,dim2 d,int min,int max,int cur):
m_pos(pos),
m_dims(d),
m_min(min),
m_max(max),
m_current(cur){
	if(!Loaded){
		Loaded = 1;
		bar.loadFromFile("sliderThing.png");
		line.loadFromFile("sliderBar.png");
	}updateVerts();
}

void slider::draw(sf::RenderWindow& win)const{
	win.draw(&m_verts[0],4,sf::Quads,&line);
	win.draw(&m_verts[4],4,sf::Quads,&bar);
}

void slider::updateVerts(){
	
	const float percentToTop = (float)(m_current-m_min)/(float)(m_max-m_min);

	m_verts[0] = sf::Vertex({m_pos.x+5,m_pos.y},{255,255,255,255},{0,0});
	m_verts[1] = sf::Vertex({m_pos.x+5,m_pos.y+m_dims.length},{255,255,255,255},{0,26});
	m_verts[2] = sf::Vertex({m_pos.x+m_dims.width-5,m_pos.y+m_dims.length},{255,255,255,255},{5,26});
	m_verts[3] = sf::Vertex({m_pos.x+m_dims.width-5,m_pos.y},{255,255,255,255},{5,0});
	
	m_verts[4] = sf::Vertex({m_pos.x,m_pos.y+percentToTop*m_dims.length-10},{255,255,255,255},{0,0});
	m_verts[5] = sf::Vertex({m_pos.x,m_pos.y+percentToTop*m_dims.length+10},{255,255,255,255},{0,8});
	m_verts[6] = sf::Vertex({m_pos.x+m_dims.width,m_pos.y+percentToTop*m_dims.length+10},{255,255,255,255},{10,8});
	m_verts[7] = sf::Vertex({m_pos.x+m_dims.width,m_pos.y+percentToTop*m_dims.length-10},{255,255,255,255},{10,0});

}

bool slider::changeVal(const sf::Vector2f mouseCoords,bool clicked){
	static float prevY = -1.0f;//so i don't update verts again
	if(mouseCoords.y==prevY||
	   !clicked||
	   !pointInBox(m_pos,m_dims.width,m_dims.length,mouseCoords)){
		return false;
	}
	/* k = (mouseCoords.y-m_pos.y);
	 * ((mouseCoords.y-m_pos.y)/m_dims.length)*(m_max-m_min)+m_min
	 * 
	*/
	m_current = ((mouseCoords.y-m_pos.y)/m_dims.length)*(m_max-m_min)+m_min;
	prevY = mouseCoords.y;
	updateVerts();
	return true;
}

