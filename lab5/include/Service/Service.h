#pragma once
#include <SFML/Audio.hpp>



class VisualEffcets
{
public:
	~VisualEffcets() {};
	virtual void playSound(const std::string &filename) = 0;
};

class SoundService : public VisualEffcets
{
public:

	virtual void playSound(const std::string& filename)
	{
		music1.openFromFile(filename);
		music1.setVolume(50);
		music1.play();
	}

private:
	sf::Music music1;
};
