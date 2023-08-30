#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include "nlohmann/json.hpp"

struct Actor
{
	std::string name;
	std::map<std::string, std::string> films;
};

Actor findActor(const nlohmann::json &films, std::string name)
{
	Actor actor;
	std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
		return std::tolower(c);
	});
	for(const auto& [filmName, filmInfo] : films.items())
	{
		for(auto& _actor : filmInfo["cast"])
		{
			std::string actorName = _actor["actor"];
			std::transform(actorName.begin(), actorName.end(), actorName.begin(), [](unsigned char c) {
				return std::tolower(c);
			});
			if(actorName.find(name) != std::string::npos)
			{
				if(actor.name.empty())
				{
					actor.name = _actor["actor"];
				}
				actor.films.insert({filmName, _actor["character"]});
				break;
			}
		}
	}
	return actor;
}

void describeActor(Actor &actor)
{
	if(actor.films.empty())
	{
		std::cout << "There are no films in which the actor would play any character" << std::endl;
	}else
	{
		std::cout << "Actor: " << actor.name << " played in this films: " << std::endl;
		for(auto& film : actor.films)
		{
			std::cout << film.first << " : " << film.second << std::endl;
		}
	}
}

int main()
{
	nlohmann::json films;
	std::ifstream file("films.json");
	file >> films;
	file.close();
	std::string name;
	std::cout << "Input actor's name: ";
	std::cin >> name;
	Actor actor = findActor(films, name);
	describeActor(actor);
	return 0;
}
