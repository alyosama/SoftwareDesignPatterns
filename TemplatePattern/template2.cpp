#include <ctime>
#include <assert.h>
#include <cstdlib>
#include <iostream>


class Game {

public:
   Game(): playersCount(0), movesCount(0), playerWon(-1)
   {
    srand( (unsigned)time( NULL));
   }

    // A template method
    void playOneGame(const int playersCount = 0) {

    if (playersCount)
          this->playersCount = playersCount;

        InitializeGame();
    assert(this->playersCount);

        int j = 0;
        while (!endOfGame()) {
            makePlay(j);
            j = (j + 1) % this->playersCount;
        if (!j) {
            ++movesCount;
        }
        }
        printWinner();
    }

protected:
    virtual void initializeGame() = 0;
    virtual void makePlay(int player) = 0;
    virtual bool endOfGame() = 0;
    virtual void printWinner() = 0;

private:
    void InitializeGame()
    {
    movesCount = 0;
    playerWon = -1;

    initializeGame();
    }

protected:
    int playersCount;
    int movesCount;
    int playerWon;
};


class Monopoly: public Game {

    void initializeGame() {
    playersCount = rand() * 7 / RAND_MAX + 2;
    }
    void makePlay(int player) {

    if (movesCount < 20)
        return;
    const int chances = (movesCount > 199) ? 199 : movesCount;
    const int random = MOVES_WIN_CORRECTION * rand() * 200 / RAND_MAX;
    if (random < chances)
        playerWon = player;
    }
    bool endOfGame() {
    return (-1 != playerWon);
    }
    void printWinner() {
    assert(playerWon >= 0);
    assert(playerWon < playersCount);


    std::cout<<"Monopoly, player "<<playerWon<<" won in "<<movesCount<<" moves."<<std::endl;
    }

private:
    enum
    {
        MOVES_WIN_CORRECTION = 20,
    };
};

class Chess: public Game {

    void initializeGame() {
    playersCount = 2;
    }

    void makePlay(int player) {
    assert(player < playersCount);


    //	decide winner
    if (movesCount < 2)
        return;
    const int chances = (movesCount > 99) ? 99 : movesCount;
    const int random = MOVES_WIN_CORRECTION * rand() * 100 / RAND_MAX;
    std::cout<<random<<" : "<<chances<<std::endl;
    if (random < chances)
        playerWon = player;
    }
    bool endOfGame() {
    return (-1 != playerWon);
    }
    void printWinner() {
    assert(playerWon >= 0);
    assert(playerWon < playersCount);

    std::cout<<"Player "<<playerWon<<" won in "<<movesCount<<" moves."<<std::endl;
    }

private:
    enum
    {
    MOVES_WIN_CORRECTION = 7,
    };
};



//int main()
//{


//    Game* game = NULL;

//    Chess chess;
//    game = &chess;
//    for (unsigned i = 0; i < 100; ++i)
//     game->playOneGame();

//    Monopoly monopoly;
//    game = &monopoly;
//    for (unsigned i = 0; i < 100; ++i)
//    game->playOneGame();

//    return 0;
//}
