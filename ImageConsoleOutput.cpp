﻿#include <iostream>
#define SINGLE_THREAD_CONSOLE_IMAGE // If you want your image draw run in single thread
#include "TConsoleImage.h"

#include "PNGstConsoleIMage.h"


int main() {


    std::fstream logs("logs.txt", std::ios::app);
    size_t threads = 4;
    size_t tries = 50;
    
    std::chrono::steady_clock::time_point start{ std::chrono::steady_clock::now() };
    
    PNGstConsoleIMage test{"pngegg.png"};

    test.setPosition(100, 100);

    test.draw();
    
    std::chrono::steady_clock::time_point end{ std::chrono::steady_clock::now() };

    auto duration{ std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() };
#ifdef SINGLE_THREAD_CONSOLE_IMAGE
    logs << "Single thread : " << duration << " duration" << std::endl;
#else
    logs << threads << " threads : " << duration <<" duration : " <<tries <<" tries" << std::endl;
#endif 

    
    std::cin.get();
    logs.close();
    return 0;
}