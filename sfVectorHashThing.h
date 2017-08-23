#ifndef sfVectorHash_H
#define sfVectorHash_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>

namespace std{
	template<>
	class hash<sf::Vector2f>{
		public:
		size_t operator()(const sf::Vector2f& a)const{
			return int(a.x+a.y)^int(a.x*a.y);
		}
	};
};

#endif


