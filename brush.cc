#include "brush.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include "sfVectorHashThing.h"
#include <array>

iBrush::iBrush(int a,sf::Color b):m_size(a),m_c(b){}

void squareBrush::update(){
	m_i.create(m_size,m_size,m_c);
}

void circleBrush::update(){
	m_i.create(m_size,m_size,m_c);
	
	for(int x = m_size/2;x<m_size;++x){
		for(int y = m_size/2;y<m_size;++y){
			if(x*x+y*y>m_size*m_size){
				m_i.setPixel(x,y,{0,0,0,0});
				m_i.setPixel(m_size-x,y,{0,0,0,0});
				m_i.setPixel(m_size-x,m_size-y,{0,0,0,0});
				m_i.setPixel(x,m_size-y,{0,0,0,0});
			}
		}
	}
	for(int i = 0;i<m_size;++i){
		m_i.setPixel(i,0,{0,0,0,0});
		m_i.setPixel(0,i,{0,0,0,0});
	}
}

void bucketBrush::update(){
	//do nothing
}

void circleBrush::brush(sf::Texture& t,const sf::Vector2f mouseCoords){
	const auto ptr = m_i.getPixelsPtr();
	sf::Image temp;
	temp.create(1,1,m_c);
	if(!ptr) return;
	for(int y = 0;y<m_size;++y){
		bool c = 0;
		for(int x = 0;x<m_size;++x){
			if(ptr[y*m_size*4+x*4+3]){
				c = 1;
				t.update(temp,mouseCoords.x+x-m_size/2,mouseCoords.y+y-m_size/2);
			}else{
				if(c) break;
			}
		}
	}
}

void circleBrush::brush(sf::Image& t,const sf::Vector2f mouseCoords){
	//nothing! XD
}

void squareBrush::brush(sf::Texture& t,const sf::Vector2f mouseCoords){
	t.update(m_i,mouseCoords.x-m_size/2,mouseCoords.y-m_size/2);
}

void squareBrush::brush(sf::Image& t,const sf::Vector2f mouseCoords){
	//t.update(m_i,mouseCoords.x-m_size/2,mouseCoords.y-m_size/2);
}

void bucketBrush::brush(sf::Texture& t,const sf::Vector2f mouseCoords){
	sf::Image t1 = t.copyToImage();
	
	const auto ptr = t1.getPixelsPtr();
	
	const std::array<uint8_t,4> start {{(uint8_t)ptr[(int)mouseCoords.x*4+(int)mouseCoords.y*500*4+0],
										(uint8_t)ptr[(int)mouseCoords.x*4+(int)mouseCoords.y*500*4+1],
										(uint8_t)ptr[(int)mouseCoords.x*4+(int)mouseCoords.y*500*4+2],
										(uint8_t)ptr[(int)mouseCoords.x*4+(int)mouseCoords.y*500*4+3]}};
	
	static const auto compFunc = [&](uint8_t r,uint8_t g,uint8_t b,uint8_t a)->bool{
			return r==start[0]&&g==start[1]&&b==start[2]&&a==start[3];//std::abs(r-start[0])+std::abs(g-start[1])+std::abs(b-start[2])+std::abs(a-start[3])<=30;
		};
	
	std::unordered_set<sf::Vector2f> visited;
	std::vector<sf::Vector2f> que(1,mouseCoords);
	
	visited.reserve(25000);
	
	static const std::array<sf::Vector2f,4> adj{{{0,1},{1,0},{-1,0},{0,-1}}};
	
	while(que.size()){
		const auto current = std::move(que.back());
		que.pop_back();

		t1.setPixel(current.x,current.y,m_c);
		
		for(int i = 0;i<4;++i){
			const sf::Vector2f temp = current+adj[i];
			if(temp.x>=500||temp.x<0||temp.y>=500||temp.y<0||visited.find(temp)!=visited.end()){}
			else if(compFunc(ptr[(int)temp.x*4+(int)temp.y*500*4+0],
							 ptr[(int)temp.x*4+(int)temp.y*500*4+1],
							 ptr[(int)temp.x*4+(int)temp.y*500*4+2],
							 ptr[(int)temp.x*4+(int)temp.y*500*4+3])){
				que.push_back(temp);
				visited.insert(temp);
			}
		}
	}
	t.update(t1);
}

void bucketBrush::brush(sf::Image& t,const sf::Vector2f mouseCoords){\
	
}

