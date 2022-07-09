#include "../graphics/Window.h"
#include "../core/Board.h"
#include "../entities/Player.h"
#include "../core/InputHandler.h"
#include "../../include/Service/Service.h"
#include "../../include/Service/locator.h"

class Systems;
class Game
{
public:

	const int spriteWH = 50;
	const float tileScale = 2.0f;
	const float itemScale = 1.0f;

	Game();
	~Game();

	void init(std::vector<std::string> lines);
	void addEntity(std::shared_ptr<Entity> newEntity);

	void buildBoard(int width, int height);
	void initWindow(int width, int height);

	void handleInput();
	void update(float elapsed);
	void render(float elapsed);
	Window* getWindow() { return &window; }

	sf::Time getElapsed() const;
	void setFPS(int FPS);
	void togglePause() { paused = !paused; }
	bool isPaused() const { return paused; }



	std::shared_ptr<Player> getPlayer() { return player; }

	EntityID getIDCounter();
	std::shared_ptr<Entity> getEntity(unsigned int idx);

	template <typename T>
	std::shared_ptr<T> buildEntityAt(const std::string& filename, int col, int row);

	void bigArray(float elapsed);

private:

	Window window;
	bool paused;
	sf::Clock gameClock;
	sf::Time elapsed;

	std::unique_ptr<Board> board;
	
	EntityID entitieNo;
	std::shared_ptr<Player> player;
	std::unique_ptr<InputHandler> inputH;

	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Systems>> system;
};

