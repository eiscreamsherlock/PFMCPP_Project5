/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
#include <vector>
/*
 copied UDT 1:
 */
struct FountainPen
{
    FountainPen(std::string name);
    ~FountainPen();
    std::string inkColor = "black";
    std::string name;
    float inkRemaining, nibWidthInMm, feedCapacity;
    int daysSinceLastClean;

    struct Nib
    {
        Nib();
        ~Nib();
        std::string style = "extra fine";
        bool  needsCleaning, isPolished; 
        int lengthInMm = 25;
        double mmDistanceBetweenTines = 0.001;

        void cleanNib(bool toClean);
        void polishNib(std::string nibStyle, bool isPolished);
        void changeNib(std::string newNib);
        int grindNib(int amntToGrnd);
    };

    Nib currentInstalledNib;

    void writeCharacter(char userCharacter);
    void drawALine(int x_start, int y_start, int lengthOfLine);
    int getMmNibLength(Nib currentNib);
    int compareNibLength(Nib currentNib, Nib newNib);
};

FountainPen::FountainPen(std::string n) :
name(n),
inkRemaining(30.0f),
nibWidthInMm(10.5f),
feedCapacity(30.0f)
{
    daysSinceLastClean = 30;
    std::cout << "FountainPen is being constructed!\n";
}

FountainPen::~FountainPen()
{
    std::cout << "FountainPen is now destructorating.\n";
}

FountainPen::Nib::Nib() :
needsCleaning(false),        // New nibs are hopefully clean by default
isPolished(false)            // but not necessarily polished
{
    std::cout << "Nib is being constructed!\n";
}

FountainPen::Nib::~Nib()
{
    std::cout << "Your nib is destroyed!\n";
}

void FountainPen::Nib::cleanNib(bool needClean)
{
    if (needClean)
    {
        std::cout << "All clean!\n";
        needsCleaning = false;
    }
    else
    {
        std::cout << "Nothing to do, already clean!\n";
    }
}


void FountainPen::Nib::polishNib(std::string nStyle, bool alreadyPolished)
{
    if (alreadyPolished)
    {
        std::cout << "Already shiney and smooth.  Time to get writing!\n";
    }
    else
    {
        std::cout << "Let's get that " << nStyle << "nib ready for the page...\n";
        isPolished = true;
        std::cout << "All done!\n";
    }
}

void FountainPen::Nib::changeNib(std::string newNib)
{
    style = newNib;
}

int FountainPen::Nib::grindNib(int amnt)
{
    for(int i = 0; i < amnt; ++i)
    {
        if(lengthInMm <= 0)
        {
            std::cout << "We've run out of nib to grind. Better get a new one...\n";
            return lengthInMm;
        }
        std::cout << "Grinding... Pass: " << i+1 << std::endl;
        lengthInMm--;
    }
    std::cout << "Successfully removed " << amnt << "mm from " << style << std::endl;
    std::cout << style << " is now " << lengthInMm << "mm long.\n";
    return lengthInMm;
}

void FountainPen::writeCharacter(char userChar)
{
    std::cout << userChar << std::endl;
}

void FountainPen::drawALine(int x_start, int y_start, int lineLeng)
{
    std::cout << x_start << " x ";
    int i{};
    while (++i < lineLeng)
    {
        std::cout << "-";
    }
    std::cout << " y " << y_start << "\n";
}

int FountainPen::getMmNibLength(Nib currentNib)
{
    return currentNib.lengthInMm;
}

int FountainPen::compareNibLength(Nib currentNib, Nib newNib)
{
    if (currentNib.lengthInMm < newNib.lengthInMm)
    {
        std::cout << "The new nib is longer.\n";
        return newNib.lengthInMm;
    }
    std::cout << "The current nib is longer.\n";
    return currentNib.lengthInMm;
}


/*
 copied UDT 2:
 */
struct CdChanger
{
    CdChanger();
    ~CdChanger();
    int numDiscsInChanger, maxNumDiscsInChanger, currTrackNumber, currentDiscNumber;
    std::string currentTrackName;
    std::string currentDisc;

    struct Disc
    {
        Disc(std::string name);
        ~Disc();
        std::string albumName, firstTrack;
        int numOfTracks = 12;
        std::string trackList[12] {};

        void populateAlbumTrackNames();
        void displayAlbumName();
    };

    Disc activeDisk {"Midnight Madness"};

    void playCD(int newCdNumber, Disc discToPlay);
    void playCdTillEnd(int startingTrack);
    void changeTrack (int newTrackNumber, Disc currentDisc);
    void pausePlayback();

};

CdChanger::Disc::Disc(std::string n)
{
    albumName = n;
    std::cout << "Disc is being constructed!\n";
}

CdChanger::Disc::~Disc()
{
    std::cout << "CD Destroyed.\n";
}

void CdChanger::Disc::displayAlbumName()
{
    std::cout << "This album is called: " << albumName << std::endl;
}

CdChanger::CdChanger() :
numDiscsInChanger(0),
maxNumDiscsInChanger(32),
currTrackNumber(1),
currentDiscNumber(1)
{
    currentTrackName = "Sister Christian";
    currentDisc = "Midnight Madness";
    std::cout << "CdChanger is being constructed!\n";
}

CdChanger::~CdChanger()
{
    std::cout << "Your changer of CDs has now asplode.\n";
}

void CdChanger::playCD(int newCdNum, Disc disc)
{
    currentDisc = disc.albumName;
    currentDiscNumber = newCdNum;
    currentTrackName = disc.firstTrack;
    currTrackNumber = 1;
}

void CdChanger::playCdTillEnd(int start)
{
    while(start <= activeDisk.numOfTracks)
    {
        std::cout << "Now playing track: " << start << std::endl;
        ++start;
    }
    currTrackNumber = 1;        // Reset to start after finishing the disk
}

void CdChanger::changeTrack (int newTrackNum, Disc currDisc)
{
    currTrackNumber = newTrackNum;
    currentTrackName = currDisc.trackList[newTrackNum];
}
void CdChanger::pausePlayback()
{
    std::cout << "*SOUND OF SILENCE*\n";
}
/*
 copied UDT 3:
 */
struct GameBoy
{
    GameBoy();
    ~GameBoy();
    int screenSize, batteryPercentageRemain;
    double screenBrightness = 75.0;
    std::string nameOfInsertedGame = "Pokemon Yellow";
    float volume; 

    struct Cartridge
    {
        Cartridge(std::string name);
        ~Cartridge();
        std::string name;
        std::string cartridgeColor = "grey";
        bool isRumblePackEnabled, isBattleToads, isClean;
        int maxMemory, memoryUsed, currentLvl, maxLvl;

        void saveGameStateToRAM();
        void cleanCartridgeHead(Cartridge cName);
        bool doYouHaveBattleToads();
        void playTilLvl(int tgtLvl);
    };

    Cartridge currentGame {"Bust-a-Move"};

    void howBigIsScreen();
    float adjustVolume(float adjustAmount);
    double adjustBrightness(double adjustAmount);
    void insertNewCartridge(Cartridge newGame);
    void playGameTilOver();
};

GameBoy::Cartridge::Cartridge(std::string n) :
isRumblePackEnabled(false),
isBattleToads(false),
maxMemory(16),
memoryUsed(7),
currentLvl(1),
maxLvl(13)
{
    isClean = true;
    name = n;
    std::cout << "Cartridge is being constructed!\n";
}

GameBoy::Cartridge::~Cartridge()
{
    std::cout << "Shoulda called GameStop while you had the chance.  This cartridge is now destroyed.\n";
}
    
GameBoy::GameBoy() :
batteryPercentageRemain(25),
volume(15.0f)
{
    screenSize = 5;
    std::cout << "GameBoy is being constructed!\n";
}

GameBoy::~GameBoy()
{
    std::cout << "No more portable gaming for you.  GameBoy is now destroyed.\n";
}

float GameBoy::adjustVolume(float adjAmount)
{
    return volume += adjAmount;
}

double GameBoy::adjustBrightness(double adjAmount)
{
    return screenBrightness += adjAmount;
}

void GameBoy::insertNewCartridge(Cartridge nGame)
{
    currentGame = nGame;
}

void GameBoy::howBigIsScreen()
{
    std::cout << "This Gameboy has a " << screenSize << " sized screen.\n";
}

void::GameBoy::playGameTilOver()
{
    while (--batteryPercentageRemain > 0)
    {
        std::cout << "Doin some serious gaming!\n";
    }
    std::cout << "Powering dow-\n";
}

void GameBoy::Cartridge::saveGameStateToRAM()
{
    if (memoryUsed < maxMemory)
    {
        std::cout << "You have saved the game!\n";
        maxMemory += 1;
    }
    else
    {
        std::cout << "There is not space left for a new save...\n";
    }

}

void GameBoy::Cartridge::cleanCartridgeHead(Cartridge cN)
{
    if (cN.isClean)
    {
        std::cout << "Save your breath, this one's already clean!\n";
    }
    else
    {
        std::cout << "*wind noises...*\n";
        isClean = true;
        std::cout << cN.name << " is all clean!\n";
    }
}

bool GameBoy::Cartridge::doYouHaveBattleToads()
{
    return isBattleToads;
}

void GameBoy::Cartridge::playTilLvl(int tLvl)
{
    while (currentLvl < tLvl)
    {
        if (currentLvl >  maxLvl)
        {
            std::cout << "Max level reached!  Congratulations on finishing the game!\n";
            break;
        }
        std::cout << "Now playing level " << currentLvl << "...\n";
        std::cout << "Level complete!\n";
        ++currentLvl;
    }

}

/*
 new UDT 4:
 with 2 member functions
 */
struct PenCase
{
    
    PenCase();
    ~PenCase();
    FountainPen pen1 {"Falcon"};
    FountainPen pen2 {"Mont Blanc"};
    FountainPen pen3 {"Kaweco"};
    FountainPen pen4 {"Sailor"};

    void displayPen(FountainPen pen);
    void displayAllPens();
};

PenCase::PenCase()
{
    std::cout << "Wow! You got a new PenCase!\n";
}
    
PenCase::~PenCase()
{
    std::cout << "You'll need to find a new case to put your pens in...\n";
}

void PenCase::displayPen(FountainPen p)
{
    if (!p.name.empty())
    {
        std::cout << "This is your " << p.name << std::endl;
    }
}

void PenCase::displayAllPens()
{
    std::cout << "Let's have a look in here.  We've got...\n";
    std::cout << "A " << pen1.name << std::endl;
    std::cout << "A " << pen2.name << std::endl;
    std::cout << "A " << pen3.name << std::endl;
    std::cout << "And a " << pen4.name << std::endl;
    std::cout << "Time to get writing!\n";
}

/*
 new UDT 5:
 with 2 member functions
 */
struct RoadTripEntertainment
{
    RoadTripEntertainment();
    ~RoadTripEntertainment();
    GameBoy::Cartridge game1 {"Pokemon Red"};
    GameBoy::Cartridge game2 {"Castlevania: The Adventure"};
    GameBoy::Cartridge game3 {"Bomberman"};
    CdChanger::Disc disc1 {"Ride The Lighting"};
    CdChanger::Disc disc2 {"Kind of Blue"};
    CdChanger::Disc disc3 {"Convergences"};

    void displayTripCds();
    void displayGames();
};
    
RoadTripEntertainment::RoadTripEntertainment()
{
    std::cout << "Road Trip Entertainment is ready to go!\n";
}
    
RoadTripEntertainment::~RoadTripEntertainment()
{
    std::cout << "There will be no further entertainment on this roadtrip...\n";
}

void RoadTripEntertainment::displayTripCds()
{
    std::cout << "What're we groovin to?\n";
    std::cout << "First CD is " << disc1.albumName << std::endl;
    std::cout << "The second CD is " << disc2.albumName << std::endl;
    std::cout << "And the last one is " << disc3.albumName << std::endl;
}

void RoadTripEntertainment::displayGames()
{
    std::cout << "Ooh!  What did we bring to play?\n";
    std::cout << "Game number 1 is " << game1.name << std::endl;
    std::cout << "Game number 2 is " << game2.name << std::endl;
    std::cout << "And the last one is " << game3.name << std::endl;
    std::cout << "Looks like we've got some good fun lined up!\n";
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

//#include <iostream>    //moving this include above to resolve some error messages
int main()
{
    FountainPen platinum("Platinum 3776");
    std::cout << "--------------------------------------------------------------------\n";

    FountainPen::Nib flexyGold;
    flexyGold.style = "gold flexible";
    std::cout << "--------------------------------------------------------------------\n";

    FountainPen::Nib music;
    music.style = "music";
    std::cout << "--------------------------------------------------------------------\n";
    
    GameBoy gbColor;
    std::cout << "--------------------------------------------------------------------\n";

    GameBoy::Cartridge goldenSun {"Golden Sun"};
    std::cout << "This is " << goldenSun.name << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    GameBoy::Cartridge marioBros3 {"Mario Bros 3"};
    std::cout << "This is " << marioBros3.name << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    
    CdChanger phillips;
    std::cout << "--------------------------------------------------------------------\n";

    CdChanger::Disc vanHalen {"Van Halen"};
    std::cout << "--------------------------------------------------------------------\n";

    platinum.writeCharacter('q');
    platinum.drawALine(1, 5, 15);
    platinum.getMmNibLength(flexyGold);
    platinum.compareNibLength(platinum.currentInstalledNib, music);
    music.grindNib(5);
    flexyGold.grindNib(40);

    platinum.currentInstalledNib.cleanNib(false);
    platinum.currentInstalledNib.polishNib("italic", true);
    std::cout << "Currently installed nib type is: " << platinum.currentInstalledNib.style << std::endl;
    platinum.currentInstalledNib.changeNib("bold");
    std::cout << "Currently installed nib type is: " << platinum.currentInstalledNib.style << std::endl;

    gbColor.currentGame.saveGameStateToRAM();
    gbColor.currentGame.doYouHaveBattleToads();
    gbColor.howBigIsScreen();

    gbColor.adjustVolume(10.0f);
    gbColor.adjustBrightness(35.0);
    std::cout << "You are playing " << gbColor.currentGame.name << std::endl;
    goldenSun.isClean = false;
    gbColor.insertNewCartridge(goldenSun);
    std::cout << "You are playing " << gbColor.currentGame.name << std::endl;
    gbColor.currentGame.cleanCartridgeHead(gbColor.currentGame);
    gbColor.currentGame.playTilLvl(99);

    marioBros3.cleanCartridgeHead(marioBros3);
    marioBros3.playTilLvl(5);
    marioBros3.saveGameStateToRAM();
    marioBros3.doYouHaveBattleToads();

    vanHalen.displayAlbumName();
    phillips.playCD(2, vanHalen);
    phillips.changeTrack (2, vanHalen);
    phillips.playCdTillEnd(2);
    std::cout << "Hey, what does this button do?...\n";
    phillips.pausePlayback();

    PenCase fourHolster;
    fourHolster.displayAllPens();
    fourHolster.displayPen(fourHolster.pen2);

    RoadTripEntertainment goingToCalifornia;
    goingToCalifornia.displayTripCds();
    goingToCalifornia.displayGames();
    
    std::cout << "good to go!" << std::endl;
}
