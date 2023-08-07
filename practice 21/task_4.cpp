#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <filesystem>

enum entityState
{
    not_init,
    init
};

enum gameState
{
    win,
    lose,
    draw
};

bool isNumber(std::string &number)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false;
        }
    }
    return true;
}

struct character
{
    std::string name = "unknown";
    int status = not_init;
    int health = 0;
    int armor = 0;
    int damage = 0;
    int pos_x = 0;
    int pos_y = 0;
};

bool intersect(character &person, character &target)
{
    return person.pos_x == target.pos_x && person.pos_y == target.pos_y;
}

void attack(character &person, character &target)
{
    std::cout << target.name << " took damage " << person.damage << std::endl;
    target.armor -= person.damage;
    if (target.armor < 0)
    {
        target.health += target.armor;
        target.armor = 0;
    }
}

int getRandomNumber(int min, int max)
{
    return min + std::rand() % (max - min + 1);
}

void getRandomMove(int &shift_x, int &shift_y)
{
    int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int index = getRandomNumber(0, 3);
    shift_x = moves[index][0];
    shift_y = moves[index][1];
}

void printGameField(std::vector<std::vector<char>> &gameField)
{
    for (int i = 0; i < gameField.size(); i++)
    {
        for (int j = 0; j < gameField.size(); j++)
        {
            std::cout << gameField[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool coordValidation(int x, int y)
{
    if (x < 0 || x > 20 || y < 0 || y > 20)
    {
        return false;
    }
    return true;
}

void save(character &player, std::vector<character> &enemies)
{
    std::ofstream file("save.bin", std::ios::binary);
    if (file.is_open())
    {
        int len = player.name.length();
        file.write((char *)&len, sizeof(len));
        file.write(player.name.c_str(), len);
        file.write((char *)&player.status, sizeof(player.status));
        file.write((char *)&player.health, sizeof(player.health));
        file.write((char *)&player.armor, sizeof(player.armor));
        file.write((char *)&player.damage, sizeof(player.damage));
        file.write((char *)&player.pos_x, sizeof(player.pos_x));
        file.write((char *)&player.pos_y, sizeof(player.pos_y));
        for (int i = 0; i < enemies.size(); i++)
        {
            len = enemies[i].name.length();
            file.write((char *)&len, sizeof(len));
            file.write(enemies[i].name.c_str(), len);
            file.write((char *)&enemies[i].status, sizeof(enemies[i].status));
            file.write((char *)&enemies[i].health, sizeof(enemies[i].health));
            file.write((char *)&enemies[i].armor, sizeof(enemies[i].armor));
            file.write((char *)&enemies[i].damage, sizeof(enemies[i].damage));
            file.write((char *)&enemies[i].pos_x, sizeof(enemies[i].pos_x));
            file.write((char *)&enemies[i].pos_y, sizeof(enemies[i].pos_y));
        }
    }
    file.close();
}

void load(character &player, std::vector<character> &enemies)
{
    std::ifstream file("save.bin", std::ios::binary);
    if (file.is_open())
    {
        int len;
        file.read((char *)&len, sizeof(len));
        player.name.resize(len);
        file.read((char *)player.name.c_str(), len);
        file.read((char *)&player.status, sizeof(player.status));
        file.read((char *)&player.health, sizeof(player.health));
        file.read((char *)&player.armor, sizeof(player.armor));
        file.read((char *)&player.damage, sizeof(player.damage));
        file.read((char *)&player.pos_x, sizeof(player.pos_x));
        file.read((char *)&player.pos_y, sizeof(player.pos_y));
        while (file.read((char *)&len, sizeof(len)) && len != -1)
        {
            character enemy;
            enemy.name.resize(len);
            file.read((char *)enemy.name.c_str(), len);
            file.read((char *)&enemy.status, sizeof(enemy.status));
            file.read((char *)&enemy.health, sizeof(enemy.health));
            file.read((char *)&enemy.armor, sizeof(enemy.armor));
            file.read((char *)&enemy.damage, sizeof(enemy.damage));
            file.read((char *)&enemy.pos_x, sizeof(enemy.pos_x));
            file.read((char *)&enemy.pos_y, sizeof(enemy.pos_y));
            enemies.push_back(enemy);
        }
    }
    file.close();
}

void deleteSave()
{
    try
    {
        std::filesystem::remove("save.bin");
    }
    catch (const std::filesystem::filesystem_error &e)
    {
    }
}

void updGame(std::vector<std::vector<char>> &gameField, character &player, std::vector<character> &enemies, int shift_x, int shift_y)
{
    gameField[player.pos_x][player.pos_y] = '.';
    for (int i = 0; i < enemies.size(); i++)
    {
        gameField[enemies[i].pos_x][enemies[i].pos_y] = '.';
    }
    if (coordValidation(player.pos_x + shift_x, player.pos_y + shift_y))
    {
        player.pos_x += shift_x;
        player.pos_y += shift_y;
        for (int i = 0; i < enemies.size(); i++)
        {
            if (intersect(player, enemies[i]))
            {
                attack(player, enemies[i]);
                if (enemies[i].health <= 0)
                {
                    enemies.erase(enemies.begin() + i);
                }
                player.pos_x -= shift_x;
                player.pos_y -= shift_y;
                break;
            }
        }
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        int enemy_shift_x, enemy_shift_y;
        getRandomMove(enemy_shift_x, enemy_shift_y);
        if (coordValidation(enemies[i].pos_x + enemy_shift_x, enemies[i].pos_y + enemy_shift_y))
        {
            enemies[i].pos_x += enemy_shift_x;
            enemies[i].pos_y += enemy_shift_y;
            bool intersected = false;
            for (int j = 0; j < enemies.size(); j++)
            {
                if (j != i && intersect(enemies[i], enemies[j]))
                {
                    intersected = true;
                    break;
                }
            }
            if (intersected)
            {
                enemies[i].pos_x -= enemy_shift_x;
                enemies[i].pos_y -= enemy_shift_y;
            }
            else
            {
                if (intersect(enemies[i], player))
                {
                    attack(enemies[i], player);
                    enemies[i].pos_x -= enemy_shift_x;
                    enemies[i].pos_y -= enemy_shift_y;
                }
            }
        }
    }
    gameField[player.pos_x][player.pos_y] = 'P';
    for (int i = 0; i < enemies.size(); i++)
    {
        gameField[enemies[i].pos_x][enemies[i].pos_y] = 'E';
    }
}

int statValidation(std::string &st, int start, int end, const char *st_name)
{
    std::cout << "Input player " << st_name << ": (" << start << ", " << end << ")";
    std::cin >> st;
    while (!isNumber(st) && std::stoi(st) < start && std::stoi(st) > end)
    {
        std::cout << "Wrong number";
        std::cin >> st;
    }
    return std::stoi(st);
}

void initEntities(character &player, std::vector<character> &enemies)
{
    std::vector<int> global_x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    std::vector<int> global_y = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    player.status = init;
    int pos_x_index = getRandomNumber(0, 19);
    int pos_y_index = getRandomNumber(0, 19);
    player.pos_x = global_x[pos_x_index];
    player.pos_y = global_y[pos_y_index];
    global_x.erase(global_x.begin() + pos_x_index);
    global_y.erase(global_y.begin() + pos_y_index);
    std::string health = "a", armor = "a", damage = "a";
    std::cout << "Input player name: ";
    std::cin >> player.name;
    player.health = statValidation(health, 50, 150, "health");
    player.armor = statValidation(armor, 0, 50, "armor");
    player.damage = statValidation(damage, 15, 30, "damage");
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].name = "Enemy #" + std::to_string(i + 1);
        enemies[i].status = init;
        enemies[i].health = getRandomNumber(50, 150);
        enemies[i].armor = getRandomNumber(0, 50);
        enemies[i].damage = getRandomNumber(15, 30);
        int pos_x_index = getRandomNumber(0, 19);
        int pos_y_index = getRandomNumber(0, 19);
        enemies[i].pos_x = global_x[pos_x_index];
        enemies[i].pos_y = global_y[pos_y_index];
        global_x.erase(global_x.begin() + pos_x_index);
        global_y.erase(global_y.begin() + pos_y_index);
    }
}

std::vector<std::vector<char>> initGame(character &player, std::vector<character> &enemies)
{
    load(player, enemies);
    std::vector<std::vector<char>> gameField(20, std::vector<char>(20, '.'));
    if (player.status == not_init)
    {
        initEntities(player, enemies);
    }
    gameField[player.pos_x][player.pos_y] = 'P';
    for (int i = 0; i < enemies.size(); i++)
    {
        gameField[enemies[i].pos_x][enemies[i].pos_y] = 'E';
    }
    return gameField;
}

int updGameState(character &player, std::vector<character> enemies)
{
    if (player.health <= 0)
    {
        return lose;
    }
    else if (enemies.size() == 0)
    {
        return win;
    }
    return draw;
}

void clearCharacters(character &player, std::vector<character> &enemies)
{
    player = {};
    enemies.clear();
    deleteSave();
}

int main()
{
    character player;
    std::vector<character> enemies;
    std::vector<std::vector<char>> gameField = initGame(player, enemies);
    std::string turn;
    int game_state = draw;
    while (game_state == draw)
    {
        printGameField(gameField);
        std::cout << "Your turn: ";
        std::cin >> turn;
        if (turn == "L")
        {
            updGame(gameField, player, enemies, -1, 0);
        }
        else if (turn == "R")
        {
            updGame(gameField, player, enemies, 1, 0);
        }
        else if (turn == "U")
        {
            updGame(gameField, player, enemies, 0, 1);
        }
        else if (turn == "D")
        {
            updGame(gameField, player, enemies, 0, -1);
        }
        else if (turn == "load")
        {
            load(player, enemies);
        }
        else if (turn == "save")
        {
            save(player, enemies);
        }
        else if (turn == "quit")
        {
            std::string question;
            std::cout << "You want to save the game before quit? (yes): ";
            std::cin >> question;
            if (question == "yes")
            {
                save(player, enemies);
            }
            return 0;
        }
        else if (turn == "new game")
        {
            clearCharacters(player, enemies);
            gameField = initGame(player, enemies);
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
        game_state = updGameState(player, enemies);
    }
    if (game_state == win)
    {
        std::cout << "Congratulations, you won!" << std::endl;
        deleteSave();
    }
    else if (game_state == lose)
    {
        std::cout << "You lose!" << std::endl;
        deleteSave();
    }
    return 0;
}