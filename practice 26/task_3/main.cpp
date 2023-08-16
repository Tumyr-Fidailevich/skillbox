#include <iostream>

struct vector {
    int x = 0;
    int y = 0;
};

class Window {
private:
    int height = 50;
    int width = 80;
    int x = 0;
    int y = 0;
    void setPos(vector vec) {
        x = vec.x;
        y = vec.y;
    }
public:
    void resize(vector vec) {
        if (vec.x <= 0 || vec.y <= 0) {
            std::cout << "Window size cannot be less than zero" << std::endl;
        } else {
            width = vec.x;
            height = vec.y;
        }
    }

    vector getSize() {
        vector vec = {x, y};
        return vec;
    }

    vector getPos() {
        vector vec = {width, height};
        return vec;
    }
    friend class Screen;
};

class Screen {
private:
    int height = 1080;
    int width = 1920;
public:
    Window window;
    // can be modified to move(vector vec, Window target_window), Window window -> std::map<name or id, Window> windows;
    void move(vector vec) {
        vector windowPos = window.getPos();
        if (windowPos.x + vec.x >= width || windowPos.x + vec.x < 0
            || windowPos.y + vec.y >= height || windowPos.y + vec.y < 0) {
            std::cout << "Window coordinates out of bounds" << std::endl;
        } else {
            window.setPos({windowPos.x + vec.x, windowPos.y + vec.y});
        }
    }

    void display() {
        vector windowPos = window.getPos();
        vector windowSize = window.getSize();
        for (int i = windowPos.y; i < windowPos.y + windowSize.y; i++) {
            for (int j = windowPos.x; j < windowPos.x + windowSize.x; j++) {
                if (i >= height || j > width) {
                    std::cout << "0";
                } else {
                    std::cout << "1";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::string input;
    auto screen = new Screen;
    while (true) {
        std::cout << "Input command: ";
        std::cin >> input;
        if (input == "move") {
            int x, y;
            std::cout << "Input coordinates: ";
            std::cin >> x >> y;
            screen->move({x, y});
        } else if (input == "resize") {
            int x, y;
            std::cout << "Input coordinates: ";
            std::cin >> x >> y;
            screen->window.resize({x, y});
        } else if (input == "display") {
            screen->display();
        } else if (input == "close") {
            std::cout << "Closing the window" << std::endl;
            delete screen;
            screen = nullptr;
            return 0;
        } else {
            std::cout << "Wrong input" << std::endl;
            delete screen;
            screen = nullptr;
            return 1;
        }
    }
}
