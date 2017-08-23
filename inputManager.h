#ifndef KEYS_H
#define KEYS_H

#include <array>
#include <cstdint>
enum class keyIDs:char{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,INSERT,HOME,END,UP,DOWN,LEFT,RIGHT,NUM1,NUM2,NUM3,NUM4,NUM5,NUM6,NUM7,NUM8,NUM9,NUM0,LCTRL,RCTRL,LALT,RALT,LSHIFT,RSHIFT,MAX};
enum class mouseButton{RIGHT,LEFT,MIDDLE,MAX};

class inputManager{
public:
	inputManager() = default;
	int getKey(keyIDs key)const{return keys[(int)key];};
	int getMouse(mouseButton key)const{return mouse[(int)key];};
	uint16_t x = 0;
	uint16_t y = 0;
	std::array<uint16_t,(unsigned long int)keyIDs::MAX> keys = {};
	std::array<uint16_t,(unsigned long int)mouseButton::MAX > mouse = {};

};
#endif

