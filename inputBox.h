#ifndef INPUTBOX_H
#define INPUTBOX_H

class inputBox{
public:
	inputBox() = default;
	inputBox(sf::Vector2f);
private:
	sf::Vector2f m_dims;
	int m_val;
}

#endif

