#include "menu.hpp"

int main() {
    Menu* menu = new Menu;
    //if(menu->loadItems("items.txt")) menu->run();
    menu->loadRandomItemFile(100000);
    if(menu->loadItems(RANDOM_ITEM_FILE)) menu->run();
    return 0;
}
