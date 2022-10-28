#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <fstream>



//initialize matrix/vector with dimensions (6, 7) with each element to 0
std::vector<std::vector<int>> matrix(6, std::vector<int>(7, 0));


// addToMatrix(matrix, move, userBool)
void addToMatrix(int move, bool userBool) {
    //matrix[5][1] = 1;
    int moveValue = 0;
    if (userBool == true) {
        moveValue = 1;
    }
    else {
        moveValue = 2;
    }

    if (matrix[0][move - 1] == 0) {
        for (int i = 0; i < 6; i++) {
            //gravity
            if (matrix[i][move - 1] != 0) {
                matrix[i - 1][move - 1] = moveValue;
                break;
            }
            if (i == 5) {

                matrix[5][move - 1] = moveValue;
                //matrix[5][1] = 1;
            }


        }

    }
    else {
        std::cout << "Error, please move again\n";

    }
    return;
}

int check1Above(int matrixIndex1, int matrixIndex2) {
    if (matrixIndex1 == 0) {
        return 0;
    }
    else {
        if (matrix[matrixIndex1][matrixIndex2] == matrix[matrixIndex1 - 1][matrixIndex2]) {
            return matrix[matrixIndex1][matrixIndex2];
        }
    }
}
int check1Right(int matrixIndex1, int matrixIndex2) {
    if (matrixIndex2 == 6) {
        return 0;
    }
    else {
        if (matrix[matrixIndex1][matrixIndex2] == matrix[matrixIndex1][matrixIndex2 + 1]) {
            return matrix[matrixIndex1][matrixIndex2];
        }
    }
}
int check1UpLeft(int matrixIndex1, int matrixIndex2) {
    if (matrixIndex2 == 0 || matrixIndex1 == 0) {
        return 0;
    }
    else {
        if (matrix[matrixIndex1][matrixIndex2] == matrix[matrixIndex1 - 1][matrixIndex2 - 1]) {
            return matrix[matrixIndex1][matrixIndex2];
        }
    }
}
int check1UpRight(int matrixIndex1, int matrixIndex2) {
    if (matrixIndex1 == 0 || matrixIndex2 == 6) {
        return 0;
    }
    else {
        if (matrix[matrixIndex1][matrixIndex2] == matrix[matrixIndex1 - 1][matrixIndex2 + 1]) {
            return matrix[matrixIndex1][matrixIndex2];
        }
    }
}


void displayBoard() {
    //Printing 2D vector
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkboard() {
    bool hasZero = false;
    for (int i = 0; i < 6; i++) {
        for (int l = 0; l < 7; l++) {
            if (matrix[i][l] == 0) {
                hasZero = true;
            }
        }
    }

    if (hasZero == false) {
        std::cout << "The board was completely full and has been reset!\n";
        for (size_t i = 0; i < matrix.size(); i++) {
            std::fill(matrix[i].begin(), matrix[i].end(), 0);
        }

        displayBoard();
    }

    for (int i = 0; i < 6; i++) {
        for (int l = 0; l < 7; l++) {
            if (i > 2) {
                if ((matrix[i][l] != 0) && (matrix[i][l] == 1) && (check1Above(i, l) == 1)) {
                    if (check1Above(i - 1, l) == 1) {
                        if (check1Above(i - 2, l) == 1) {
                            std::cout << "You win\n";
                            return true;
                        }
                    }
                }
                else if ((matrix[i][l] != 0) && (matrix[i][l] == 2) && (check1Above(i, l) == 2)) {
                    if (check1Above(i - 1, l) == 2) {
                        if (check1Above(i - 2, l) == 2) {
                            std::cout << "Computer wins, you lose\n";
                            return true;
                        }
                    }
                }
            }
            if (l < 4) {
                if ((matrix[i][l] != 0) && (matrix[i][l] == 1) && (check1Right(i, l) == 1)) {
                    if (check1Right(i, l + 1) == 1) {
                        if (check1Right(i, l + 2) == 1) {
                            std::cout << "You win\n";
                            return true;
                        }
                    }
                }

                else if ((matrix[i][l] != 0) && (matrix[i][l] == 2) && (check1Right(i, l) == 2)) {
                    if (check1Right(i, l + 1) == 2) {
                        if (check1Right(i, l + 2) == 2) {
                            std::cout << "Computer wins, you lose\n";
                            return true;
                        }
                    }
                }
            }
            if ((i > 2) && (l > 2)) {
                if ((matrix[i][l] != 0) && (matrix[i][l] == 1) && (check1UpLeft(i, l) == 1)) {
                    if (check1UpLeft(i - 1, l - 1) == 1) {
                        if (check1UpLeft(i - 2, l - 2) == 1) {
                            std::cout << "You win\n";
                            return true;
                        }
                    }
                }
                else if ((matrix[i][l] != 0) && (matrix[i][l] == 2) && (check1UpLeft(i, l) == 2)) {
                    if (check1UpLeft(i - 1, l - 1) == 2) {
                        if (check1UpLeft(i - 2, l - 2) == 2) {
                            std::cout << "Computer wins, you lose\n";
                            return true;
                        }
                    }
                }
            }
            if ((i > 2) && (l < 4)) {
                if ((matrix[i][l] != 0) && (matrix[i][l] == 1) && (check1UpRight(i, l) == 1)) {
                    if (check1UpRight(i - 1, l + 1) == 1) {
                        if (check1UpRight(i - 2, l + 2) == 1) {
                            std::cout << "You win\n";
                            return true;
                        }
                    }
                }
                else if ((matrix[i][l] != 0) && (matrix[i][l] == 2) && (check1UpRight(i, l) == 2)) {
                    if (check1UpRight(i - 1, l + 1) == 2) {
                        if (check1UpRight(i - 2, l + 2) == 2) {
                            std::cout << "Computer wins, you lose\n";
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}



//learning rate
double lr = 0.1;
//discount factor
double gamma_ = 0.9;

//q-table for computer1
std::vector<std::vector<double>> Q1(999999, std::vector<double>(7, 0));
//q-table for computer2
std::vector<std::vector<double>> Q2(999999, std::vector<double>(7, 0));
//matrix with all unique states that have been experienced
std::vector<std::vector<std::vector<int>>> matrixOfExperiencedStates1(1, std::vector<std::vector<int>>(6, std::vector<int>(7, 0)));
std::vector<std::vector<std::vector<int>>> matrixOfExperiencedStates2(1, std::vector<std::vector<int>>(6, std::vector<int>(7, 0)));



int computer1Move = 1;
int computer2Move = 1;

//assign value to each state in q-table/matrix
int assignStateToValue1(std::vector<std::vector<int>> state) {
    //index of state in matrixOfExperiencedStates
    int stateValue = 0;
    //Check if state is in matrixOfExperiendStates
    //If state is new and has never been experiened, add to matrixOfExperiencedStates
    bool stateExperienced = false;
    for (size_t i = 0; i < matrixOfExperiencedStates1.size(); i++) {
        if (matrixOfExperiencedStates1[i] == state) {
            stateExperienced = true;
            stateValue = i;
            break;
        }
    }
    if (stateExperienced == false) {
        matrixOfExperiencedStates1.push_back(state);
        stateValue = matrixOfExperiencedStates1.size() - 1;
    }
    return (stateValue);

}
int assignStateToValue2(std::vector<std::vector<int>> state) {
    //index of state in matrixOfExperiencedStates
    int stateValue = 0;
    //Check if state is in matrixOfExperiendStates
    //If state is new and has never been experiened, add to matrixOfExperiencedStates
    bool stateExperienced = false;

    for (size_t i = 0; i < matrixOfExperiencedStates2.size(); i++) {
        if (matrixOfExperiencedStates2[i] == state) {
            stateExperienced = true;
            stateValue = i;
            break;
        }
    }
    if (stateExperienced == false) {
        matrixOfExperiencedStates2.push_back(state);
        stateValue = matrixOfExperiencedStates2.size() - 1;
    }
    return (stateValue);

}
//getComputer1Move
void getComputer1Move() {
    //exploration percentage
    float epsilon = 20;


    if ((rand() % 100 + 1) < epsilon) {
        //explore
        computer1Move = rand() % 7 + 1;

    }
    else {
        //exploit
        int index = assignStateToValue1(matrix);
        bool allEqual = true;
        for (int i = 0; i < 6; i++) {
            if (Q1[index][i + 1] > Q1[index][i]) {
                computer1Move = i + 2;
                allEqual = false;
            }
        }
        if (allEqual == true) {
            computer1Move = rand() % 7 + 1;
        }
    }
    return;
}
//getComputer2Move
void getComputer2Move() {
    //exploration percentage
    float epsilon = 20;


    if ((rand() % 100 + 1) < epsilon) {
        //explore
        computer2Move = rand() % 7 + 1;

    }
    else {
        //exploit
        int index = assignStateToValue2(matrix);
        bool allEqual = true;
        for (int i = 0; i < 6; i++) {
            if (Q2[index][i + 1] > Q2[index][i]) {
                computer2Move = i + 2;
                allEqual = false;
            }
        }
        if (allEqual == true) {
            computer2Move = rand() % 7 + 1;
        }
    }
    return;
}

int main()
{
    bool train = true;
    std::srand(std::time(nullptr));

    if (train == true) {
        //num training games
        int games = 1000;

        for (int i = 0; i < games; i++) {
            std::cout << i << " games of " << games << " games" << std::endl;
            std::vector<std::vector<std::vector<int>>> stateHistoryMatrix;
            std::vector<int> computer1ActionHistoryList;
            std::vector<int> computer2ActionHistoryList;

            float computer1Reward = 0;
            float computer2Reward = 0;

            for (size_t i = 0; i < matrix.size(); i++) {
                std::fill(matrix[i].begin(), matrix[i].end(), 0);
            }
            while (true) {
                //add to statehistory
                stateHistoryMatrix.push_back(matrix);


                getComputer1Move();

                //add to action history
                computer1ActionHistoryList.push_back(computer1Move);

                //displayBoard();
                //add to matrix
                addToMatrix(computer1Move, true);

                if (checkboard() == true) {
                    computer1Reward = 1;
                    break;
                }
                //add to statehistory
                stateHistoryMatrix.push_back(matrix);


                getComputer2Move();

                //add to action history
                computer2ActionHistoryList.push_back(computer2Move);

                //add to matrix
                addToMatrix(computer2Move, false);

                if (checkboard() == true) {
                    computer2Reward = 1;
                    break;
                }
            }

            //Update Q-values
            for (size_t i = 0; i < computer1ActionHistoryList.size(); i++) {
                Q1[assignStateToValue1(stateHistoryMatrix[i * 2])][computer1ActionHistoryList[i] - 1] = Q1[assignStateToValue1(stateHistoryMatrix[i * 2])][computer1ActionHistoryList[i] - 1] + lr * (gamma_ * computer1Reward);
            }
            for (size_t i = 0; i < computer2ActionHistoryList.size(); i++) {
                Q2[assignStateToValue2(stateHistoryMatrix[(i * 2) + 1])][computer2ActionHistoryList[i] - 1] = Q1[assignStateToValue2(stateHistoryMatrix[(i * 2) + 1])][computer2ActionHistoryList[i] - 1] + lr * (gamma_ * computer2Reward);
            }
        }
        /*
        //print Q-values for initial state
        std::vector<std::vector<int>> initialMatrix(6, std::vector<int>(7, 0));
        for (int i = 0; i < 7; i++) {
            std::cout << "Q1 \n";
            std::cout << i << ": " << Q1[assignStateToValue1(initialMatrix)][i] << std::endl;
        }
        */
        //show last game
        for (int i = 0; i < matrix.size(); i++) {
            std::fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        displayBoard();
        while (true) {

            getComputer1Move();
            addToMatrix(computer1Move, true);
            displayBoard();
            if (checkboard() == true) {
                break;
            }

            getComputer2Move();
            addToMatrix(computer2Move, false);
            displayBoard();
            if (checkboard() == true) {
                break;
            }
        }
    }
    else {
        while (true) {
            displayBoard();
            int b;
            std::cout << "Your move: ";
            std::cin >> b;
            addToMatrix(b, true);
            displayBoard();

            if (checkboard() == true) {
                break;
            }
            int c;
            std::cout << "Player2 move: ";
            std::cin >> c;
            addToMatrix(c, false);
            if (checkboard() == true) {
                break;
            }
        }
    }
    return 0;
}
