#include <iostream>
#include "Windows.h"
#include <chrono>
#include <thread>


int getCurrentMouseSpeed() {
    int currentMouseSpeed = 0;
    SystemParametersInfo(SPI_GETMOUSESPEED, 0, &currentMouseSpeed, 0);

    return currentMouseSpeed;
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

int main() {
    const int targetSpeed = 18;

    std::cout << "Starting Torbilicious' Mouse Speed Adjuster." << std::endl;
    std::cout << "Target Mouse Speed: " << targetSpeed << std::endl;


    for (;;) {
        if (getCurrentMouseSpeed() != targetSpeed) {
            std::cout << "Setting speed to: " << targetSpeed << std::endl;
            SystemParametersInfo(
                    SPI_SETMOUSESPEED,
                    0,
                    (LPVOID) targetSpeed,
                    SPIF_UPDATEINIFILE |
                    SPIF_SENDCHANGE |
                    SPIF_SENDWININICHANGE
            );
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }


    return 0;
}

#pragma clang diagnostic pop