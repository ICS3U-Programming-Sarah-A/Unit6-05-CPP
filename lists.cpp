// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: June 1st, 2022
// This program calculates the average of the elements in a list. It then
// displays the content of the list, as well as, the average.
#include <iostream>
#include <iomanip>
#include <list>


// this function calculates the average of elements in the list.
float CalcAverage(std::list<float> listOfMarks) {
    float average;
    float sum;

    if (listOfMarks.size() == 0) {
        return -1;
    } else {
        sum = 0;
        for (int aNum : listOfMarks) {
            sum = sum + aNum;
        }
        average = sum / listOfMarks.size();
        return average;
    }
}


int main() {
    // declare variables
    std::string markString;
    std::list<float> listOfNum;
    float averageMarks;
    float sumList;
    int userMark;
    float sumFloat = 0;

    std::cout << "This program will calculate the average of all user mark's";
    std::cout << std::endl;

    while (markString != "-1") {
        // get user input
        std::cout << "Please enter a mark, or -1 to stop: ";
        std::cin >> markString;

        try {
            // converts from string to float
            userMark = std::stof(markString);

            // sets a range
            if (userMark < -1) {
                std::cout << "Please enter a positive integer.";
                std::cout << std::endl;
                continue;
            }
            listOfNum.push_back(userMark);

        // handles invalid case
        } catch (std::invalid_argument) {
            std::cout << markString << " is not a valid mark.";
            std::cout << std::endl;
        }
    }

    // removes -1 from the list
    listOfNum.pop_back();

    // calls function
    averageMarks = CalcAverage(listOfNum);

    // formats elements in the list
    std::cout << "\nFor the list of marks: ";
    for (int userMark : listOfNum) {
        std::cout << userMark << " ";
    }

    // displays average
    std::cout << std::endl;
    std::cout << "The average is: " << std::fixed;
    std::cout << std::setprecision(1) << averageMarks << "%";
}
