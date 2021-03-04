#include <iostream>
#include <ctime>

void PrintIntroduction(int GateNumber, int FinalGateNumber)
{
    std::cout << "\n\n***************************************************\n";
    std::cout << "Open all the " << FinalGateNumber << " gates to find the treasure!" << std::endl;
    std::cout << "You are opening Gate " << GateNumber << std::endl;
    std::cout << "Enter the correct three codes to open the gates..." << std::endl;
}

bool PlayGame(int GateNumber, int FinalGateNumber)
{
    PrintIntroduction(GateNumber, FinalGateNumber);

    int CodeA = rand() % GateNumber + GateNumber;
    int CodeC = rand() % GateNumber + GateNumber;
    int CodeB = rand() % GateNumber + GateNumber;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "The codes add up to give: " << CodeSum << std::endl;
    std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You have opened the gate " << GateNumber;
        return true;
    }
    else
    {
        std::cout << "Try Again";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int GateNumber = 1;
    int FinalGateNumber = 10;
    bool bLevelComplete;
    while (GateNumber <= FinalGateNumber)
    {
        bLevelComplete = PlayGame(GateNumber, FinalGateNumber);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            GateNumber++;
        }
    }

    std::cout << "\n\nCongrats! You have found the treasure";
    return 0;
}