#include "menu.hpp"

int main() {
    Menu* menu = new Menu;
    int n = 50;
    if(menu->loadItems("items.txt")) menu->run();
    //menu->loadRandomItemFile(n);
    //if(menu->loadItems(RANDOM_ITEM_FILE)) menu->run();
    return 0;
}
