#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <cstdlib>

class Track {
private:
    std::string name;
    std::time_t duration;
    std::tm creationDate;
public:
    void setName(std::string &trackName) {
        name = trackName;
    }

    void setDate(std::tm &date) {
        creationDate = date;
    }

    void setDuration(std::time_t &trackDuration) {
        duration = trackDuration;
    }

    std::string getName() {
        return name;
    }

    std::tm getDate() {
        return creationDate;
    }

    std::time_t getDuration() {
        return duration;
    }
};

class Player {
private:
    enum playerStatus {
        playing,
        stopped,
        paused
    };
    std::map<std::string, Track> tracks;
    int status = stopped;
public:
    void play(const std::string &trackName) {
        if (status != playing) {
            if (tracks.find(trackName) != tracks.end()) {
                status = playing;
                std::tm date = tracks[trackName].getDate();
                std::cout << "Name: " << tracks[trackName].getName() << std::endl;
                std::cout << "Creation date: " << std::asctime(&date) << std::endl;
                std::cout << "Duration: " << tracks[trackName].getDuration() << std::endl;
            } else {
                std::cout << "There is no such track in the player" << std::endl;
            }
        }
    }

    void pause() {
        if (status == playing) {
            status = paused;
            std::cout << "Playback paused" << std::endl;
        }
    }

    void next() {
        if (!tracks.empty()) {
            status = playing;
            auto iter = tracks.begin();
            std::advance(iter, std::rand() % tracks.size());
            play(iter->first);
        }
    }

    void stop() {
        if (status != stopped) {
            status = stopped;
            std::cout << "Playback stopped" << std::endl;
        }
    }
};

int main() {
    auto player = new Player;
    while (true) {
        std::string input;
        std::cout << "Input your command: ";
        std::cin >> input;
        if (input == "play") {
            std::cout << "Input track name: ";
            std::cin >> input;
            player->play(input);
        } else if (input == "stop") {
            player->stop();
        } else if (input == "pause") {
            player->pause();
        } else if (input == "next") {
            player->next();
        } else if (input == "exit") {
            std::cout << "Quitting the program" << std::endl;
            delete player;
            player = nullptr;
            return 0;
        } else {
            std::cout << "Wrong input" << std::endl;
            delete player;
            player = nullptr;
            return 1;
        }
    }
}