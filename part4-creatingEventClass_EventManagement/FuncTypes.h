#pragma once
#include <functional>
#include <SFML/Window/Event.hpp>
#include <vector>


typedef std::function<void(sf::Keyboard::Key)> keyboardFunc;
typedef std::vector<keyboardFunc> keyboardFuncList;
typedef std::function <void(sf::Event::MouseMoveEvent)> mouseMoveFunc;
typedef std::vector<mouseMoveFunc> mouseMoveFuncList;



