#include <iostream>
#include "view/MainInterface.h"
#include "view/UserInterface.h"

int main() {
    std::cout << "Sistema Iniciado!" << std::endl;

    MainInterface mainUI;
    mainUI.menu();

    return 0;
}

