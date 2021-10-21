#include "physics.h"
#include <vector>
#include <string>
#include "Brick.h"
#include "Button.h"
#include "Food.h"
#include <math.h>

using namespace std;
using namespace sf; //for graphics


int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(1750,1750),"SFML Works");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second
    b2World world(b2Vec2(0.0, 0.0));

    ///Fonts
    Font f1;
    f1.loadFromFile("Stats.ttf");
    ///Fonts

    ///Texts
    Text Moneytext;
    Moneytext.setFont(f1);
    Moneytext.setScale(1.5, 1.5);
    Moneytext.setFillColor(Color::White);

    Text ButtonText;
    ButtonText.setFont(f1);
    ButtonText.setScale(2.0, 2.0);
    ButtonText.setFillColor(Color::Green);

    Text Yes;
    Yes.setFont(f1);
    Yes.setScale(2.0, 2.0);
    Yes.setFillColor(Color::Black);
    Yes.setString("Yes");

    Text No;
    No.setFont(f1);
    No.setScale(2.0, 2.0);
    No.setFillColor(Color::Black);
    No.setString("No");

    Text LemonsText;
    LemonsText.setFont(f1);
    LemonsText.setScale(.75, .75);
    LemonsText.setColor(Color::Black);

    Text SugarText;
    SugarText.setFont(f1);
    SugarText.setScale(.75, .75);
    SugarText.setColor(Color::Black);

    Text IceText;
    IceText.setFont(f1);
    IceText.setScale(.75, .75);
    IceText.setColor(Color::Black);

    Text LemonPriceText;
    LemonPriceText.setFont(f1);
    LemonPriceText.setScale(.75, .75);
    LemonPriceText.setColor(Color::Black);

    Text DayText;
    DayText.setFont(f1);
    DayText.setScale(1.5, 1.5);
    DayText.setFillColor(Color::White);

    Text StartingDay;
    StartingDay.setFont(f1);
    StartingDay.setScale(1.0, 1.0);
    StartingDay.setFillColor(Color::Black);
    StartingDay.setString("Start \n  Day");

    Text MarketText;
    MarketText.setFont(f1);
    MarketText.setScale(1.0, 1.0);
    MarketText.setFillColor(Color::Black);
    MarketText.setString("Market");

    Text Supplies;
    Supplies.setFont(f1);
    Supplies.setScale(1.5, 1.5);
    Supplies.setFillColor(Color::Black);

    Text Needmore;
    Needmore.setFont(f1);
    Needmore.setScale(2.0, 2.0);
    Needmore.setFillColor(Color::Red);

    Text Profit;
    Profit.setFont(f1);
    Profit.setScale(2.0, 2.0);
    Profit.setString("Hello");

    Text CustomersL;
    CustomersL.setFont(f1);
    CustomersL.setScale(1.5, 1.5);
    CustomersL.setFillColor(Color::Red);
    CustomersL.setString("Hello");

    Text CustomersS;
    CustomersS.setFont(f1);
    CustomersS.setScale(2.0, 2.0);
    CustomersS.setFillColor(Color::Green);
    CustomersS.setString("Hello");

    Text Karma;
    Karma.setFont(f1);
    Karma.setScale(2.0, 2.0);
    Karma.setString("Hello");

    Text ChickenText;
    ChickenText.setFont(f1);
    ChickenText.setScale(1.5, 1.5);
    ChickenText.setFillColor(Color::Black);

    Text HotDogText;
    HotDogText.setFont(f1);
    HotDogText.setScale(1.5, 1.5);
    HotDogText.setFillColor(Color::Black);

    Text BurgerText;
    BurgerText.setFont(f1);
    BurgerText.setScale(1.5, 1.5);
    BurgerText.setFillColor(Color::Black);

    Text PoutineText;
    PoutineText.setFont(f1);
    PoutineText.setScale(1.5, 1.5);
    PoutineText.setFillColor(Color::Black);

    Text ChickenPriceText;
    ChickenPriceText.setFont(f1);
    ChickenPriceText.setScale(1.5, 1.5);
    ChickenPriceText.setFillColor(Color::Black);

    Text HotDogPriceText;
    HotDogPriceText.setFont(f1);
    HotDogPriceText.setScale(1.5, 1.5);
    HotDogPriceText.setFillColor(Color::Black);

    Text BurgerPriceText;
    BurgerPriceText.setFont(f1);
    BurgerPriceText.setScale(1.5, 1.5);
    BurgerPriceText.setFillColor(Color::Black);

    Text PoutinePriceText;
    PoutinePriceText.setFont(f1);
    PoutinePriceText.setScale(1.5, 1.5);
    PoutinePriceText.setFillColor(Color::Black);

    Text HomeButtonText;
    HomeButtonText.setFont(f1);
    HomeButtonText.setScale(1.0, 1.0);
    HomeButtonText.setFillColor(Color::Black);
    HomeButtonText.setString("Home");

    vector<Text> MoneyMade;
    vector<Text> NoThanks;
    ///Texts

    ///Bools
    bool Lemonade = false;
    bool Truck = false;
    bool DayStart = false;
    bool UseOnce = false;
    bool LightingTimes = false;
    bool MarketOpen = false;
    bool ShowTycoons = false;
    bool SalesShow = false;
    bool Pick1 = false;
    bool Pick2 = false;
    bool Pick3 = false;
    bool Pick4 = false;
    bool Purchase = false;
    bool ReadyToOrder = false;
    bool Ordered = false;
    bool Purchased = false;
    ///Bools

    ///StartScreen
    bool StartScreen = true;
    bool OneUse = false;
    Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("Background.png");
    Texture BillionaireTexture;
    BillionaireTexture.loadFromFile("Billionaire.png");
    Texture TycoonWordTexture;
    TycoonWordTexture.loadFromFile("TycoonWord.png");
    Texture PlayButtonTexture;
    PlayButtonTexture.loadFromFile("PlayButton.png");

    RectangleShape Background;
    Background.setTexture(&BackgroundTexture);
    Background.setSize(Vector2f(1750, 1750));
    Background.setPosition(Vector2f(1750/2, 1750/2));
    Background.setOrigin(1750/2, 1750/2);

    RectangleShape Billionaire;
    Billionaire.setSize(Vector2f(600, 300));
    Billionaire.setPosition(Vector2f(-1000, 400));
    Billionaire.setOrigin(300, 150);
    Billionaire.setTexture(&BillionaireTexture);

    RectangleShape TycoonWord;
    TycoonWord.setSize(Vector2f(600, 300));
    TycoonWord.setPosition(Vector2f(2750, 650));
    TycoonWord.setOrigin(300, 150);
    TycoonWord.setTexture(&TycoonWordTexture);

    RectangleShape PlayButton;
    PlayButton.setTexture(&PlayButtonTexture);
    PlayButton.setSize(Vector2f(800, 200));
    PlayButton.setOrigin(400, 100);
    PlayButton.setPosition(Vector2f(875, 900));
    ///StartScreen

    ///Tycoons
    bool Home = false;
    bool LemonadeTycoon = false;
    bool FoodTruckTycoon = false;
    bool DinerTycoon = false;
    ///Tycoons

    ///Animations
    int Animations = 0;
    ///Animations

    ///Cook Book
    Texture CookbookInstructions;
    CookbookInstructions.loadFromFile("CookbookInstructions.png");
    Texture CookbookBreakfast;
    CookbookBreakfast.loadFromFile("CookbookBreakfast.png");
    Texture CookbookLunch;
    CookbookLunch.loadFromFile("CookbookLunch.png");
    Texture CookbookDinner;
    CookbookDinner.loadFromFile("CookbookDinner.png");
    Texture CookbookDessert;
    CookbookDessert.loadFromFile("CookbookDessert.png");

    Texture Crepe;
    Crepe.loadFromFile("Crepe.png");
    Texture Waffles;
    Waffles.loadFromFile("Waffles.png");
    Texture Pancakes;
    Pancakes.loadFromFile("Pancakes.png");
    Texture Pizza;
    Pizza.loadFromFile("Pizza.png");
    Texture Taco;
    Taco.loadFromFile("Taco.png");
    Texture Sub;
    Sub.loadFromFile("Sub.png");
    Texture Burger;
    Burger.loadFromFile("Burger.png");
    Texture Pasta;
    Pasta.loadFromFile("Pasta.png");
    Texture Steak;
    Steak.loadFromFile("Steak.png");
    Texture Creme;
    Creme.loadFromFile("Creme.png");
    Texture IceCream;
    IceCream.loadFromFile("IceCream.png");
    Texture Cookie;
    Cookie.loadFromFile("Cookie.png");

    RectangleShape CookbookClose;
    CookbookClose.setSize(Vector2f(65, 78));
    CookbookClose.setOrigin(CookbookClose.getSize().x/2, CookbookClose.getSize().y/2);

    RectangleShape FoodRight;
    FoodRight.setSize(Vector2f(50, 120));
    FoodRight.setOrigin(FoodRight.getSize().x/2, FoodRight.getSize().y/2);

    RectangleShape FoodLeft;
    FoodLeft.setSize(Vector2f(50, 120));
    FoodLeft.setOrigin(FoodLeft.getSize().x/2, FoodLeft.getSize().y/2);

    RectangleShape Item1; ///First Item
    Item1.setSize(Vector2f(250, 500));
    Item1.setOrigin(Item1.getSize().x/2, Item1.getSize().y/2);
    RectangleShape Item2; ///Second Item
    Item2.setSize(Vector2f(250, 500));
    Item2.setOrigin(Item2.getSize().x/2, Item2.getSize().y/2);
    RectangleShape Item3; ///Third Item
    Item3.setSize(Vector2f(250, 500));
    Item3.setOrigin(Item3.getSize().x/2, Item3.getSize().y/2);

    int Page = 1;

    vector<Food> Foods;

    ///Foods
    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Crepe);
    Foods.back().Price = 25;
    Foods.back().FoodNumber = 0;
    Foods.back().CookTime = 10;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Waffles);
    Foods.back().Price = 30;
    Foods.back().FoodNumber = 1;
    Foods.back().CookTime = 10;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Pancakes);
    Foods.back().Price = 35;
    Foods.back().FoodNumber = 2;
    Foods.back().CookTime = 10;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Pizza);
    Foods.back().Price = 40;
    Foods.back().FoodNumber = 3;
    Foods.back().CookTime = 20;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Taco);
    Foods.back().Price = 50;
    Foods.back().FoodNumber = 4;
    Foods.back().CookTime = 20;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Sub);
    Foods.back().Price = 60;
    Foods.back().FoodNumber = 5;
    Foods.back().CookTime = 20;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Burger);
    Foods.back().Price = 80;
    Foods.back().FoodNumber = 6;
    Foods.back().CookTime = 30;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Pasta);
    Foods.back().Price = 90;
    Foods.back().FoodNumber = 7;
    Foods.back().CookTime = 30;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Steak);
    Foods.back().Price = 100;
    Foods.back().FoodNumber = 8;
    Foods.back().CookTime = 30;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Creme);
    Foods.back().Price = 20;
    Foods.back().FoodNumber = 9;
    Foods.back().CookTime = 5;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&IceCream);
    Foods.back().Price = 20;
    Foods.back().FoodNumber = 10;
    Foods.back().CookTime = 5;

    Foods.push_back(Food(world, 0, 0, 100, 100));
    Foods.back().setTexture(&Cookie);
    Foods.back().Price = 20;
    Foods.back().FoodNumber = 11;
    Foods.back().CookTime = 5;
    ///Foods
    ///Cook Book

    ///Textures
    Texture MCTexture;
    MCTexture.loadFromFile("Fighter.png");

    Texture CustomerTexture;
    CustomerTexture.loadFromFile("Customers.png");

    Texture FountainTexture;
    FountainTexture.loadFromFile("Fountain.png");

    Texture DoorTexture;
    DoorTexture.loadFromFile("Door.png");

    Texture LemonadeStandTexture;
    LemonadeStandTexture.loadFromFile("LemonadeStand.png");

    Texture LemonadeStats;
    LemonadeStats.loadFromFile("LemonadeStats.png");

    Texture XButtonTexture;
    XButtonTexture.loadFromFile("XButton.png");

    Texture MouseTexture;
    MouseTexture.loadFromFile("Click.png");

    Texture MarketTexture;
    MarketTexture.loadFromFile("Market.png");

    Texture LemonadeTexture;
    LemonadeTexture.loadFromFile("LemonadeCup.png");

    Texture TycoonTexture;
    TycoonTexture.loadFromFile("TycoonImage.png");

    Texture TycoonsTexture;
    TycoonsTexture.loadFromFile("TycoonImages.png");

    Texture SalesTexture;
    SalesTexture.loadFromFile("Sales.png");

    Texture FoodTruckTexture;
    FoodTruckTexture.loadFromFile("FoodTruck.png");

    Texture Market2Texture;
    Market2Texture.loadFromFile("Market2.png");

    Texture FoodTruckStats;
    FoodTruckStats.loadFromFile("FoodTruckStats.png");

    Texture Orders;
    Orders.loadFromFile("");
    ///Textures

    ///Buttons and Stuff
    int ButtonTimer = 0;
    vector<Button> Buttons;
    Buttons.push_back(Button(world, 10000, 10000, 480, 400)); ///Purchasing
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setOutlineThickness(-1.0);
    Buttons.back().setFillColor(Color::Magenta);
    Buttons.back().Object = 0;

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Lemonade Stand
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&LemonadeStats);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Market Lemonade Stand
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&MarketTexture);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Tycoon Choosing
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&TycoonsTexture);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Sales
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&SalesTexture);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Market Food Truck
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&Market2Texture);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Food Truck
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&FoodTruckStats);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Diner
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&CookbookInstructions);

    Buttons.push_back(Button(world, 10000, 10000, 960, 960)); ///Orders
    Buttons.back().setOutlineColor(Color::Black);
    Buttons.back().setTexture(&Orders);

    RectangleShape ButtonYes; ///Click to Purchase
    ButtonYes.setFillColor(Color::Green);
    ButtonYes.setSize(Vector2f(125, 125));
    ButtonYes.setPosition(10000, 10000);
    ButtonYes.setOutlineColor(Color::Black);
    ButtonYes.setOutlineThickness(-1.0);

    RectangleShape ButtonNo;
    ButtonNo.setFillColor(Color::Red);
    ButtonNo.setSize(Vector2f(125, 125));
    ButtonNo.setPosition(10000, 10000);    ///For the Purchasing GUI
    ButtonNo.setOutlineColor(Color::Black);
    ButtonNo.setOutlineThickness(-1.0);

    RectangleShape XButton;
    XButton.setSize(Vector2f(40, 40));
    XButton.setOutlineColor(Color::Black); ///Closes the GUI that is open
    XButton.setOutlineThickness(-1.0);
    XButton.setTexture(&XButtonTexture);

    RectangleShape Addition;
    Addition.setSize(Vector2f(50, 40));
    Addition.setPosition(Vector2f(10000, 10000));

    RectangleShape Addition2;
    Addition2.setSize(Vector2f(50, 40));
    Addition2.setPosition(Vector2f(10000, 10000));

    RectangleShape Addition3;
    Addition3.setSize(Vector2f(50, 40));
    Addition3.setPosition(Vector2f(10000, 10000));

    RectangleShape Addition4;
    Addition4.setSize(Vector2f(50, 40));
    Addition4.setPosition(Vector2f(10000, 10000));

    RectangleShape Subtraction;
    Subtraction.setSize(Vector2f(50, 40));
    Subtraction.setPosition(Vector2f(10000, 10000));

    RectangleShape Subtraction2;
    Subtraction2.setSize(Vector2f(50, 40));
    Subtraction2.setPosition(Vector2f(10000, 10000));

    RectangleShape Subtraction3;
    Subtraction3.setSize(Vector2f(50, 40));
    Subtraction3.setPosition(Vector2f(10000, 10000));

    RectangleShape Subtraction4;
    Subtraction4.setSize(Vector2f(50, 40));
    Subtraction4.setPosition(Vector2f(10000, 10000));

    RectangleShape StartDay;
    StartDay.setSize(Vector2f(150, 100));
    StartDay.setOrigin(75, 50);
    StartDay.setOutlineColor(Color::Black);
    StartDay.setOutlineThickness(-4.0);

    RectangleShape Click;
    Click.setSize(Vector2f(32, 32));
    Click.setOrigin(16, 16);
    Click.setTexture(&MouseTexture);

    RectangleShape Market;
    Market.setSize(Vector2f(150, 100));
    Market.setOrigin(75, 50);
    Market.setOutlineColor(Color::Black);
    Market.setOutlineThickness(-4.0);

    RectangleShape Lemon5;
    Lemon5.setSize(Vector2f(180, 80));
    Lemon5.setOrigin(25, 25);
    Lemon5.setPosition(Vector2f(10000, 10000));

    RectangleShape Lemon10;
    Lemon10.setSize(Vector2f(180, 80));
    Lemon10.setOrigin(25, 25);
    Lemon10.setPosition(Vector2f(10000, 10000));

    RectangleShape Lemon20;
    Lemon20.setSize(Vector2f(180, 80));
    Lemon20.setOrigin(25, 25);
    Lemon20.setPosition(Vector2f(10000, 10000));

    RectangleShape Ice5;
    Ice5.setSize(Vector2f(180, 80));
    Ice5.setOrigin(25, 25);
    Ice5.setPosition(Vector2f(10000, 10000));

    RectangleShape Ice10;
    Ice10.setSize(Vector2f(180, 80));
    Ice10.setOrigin(25, 25);
    Ice10.setPosition(Vector2f(10000, 10000));

    RectangleShape Ice20;
    Ice20.setSize(Vector2f(180, 80));
    Ice20.setOrigin(25, 25);
    Ice20.setPosition(Vector2f(10000, 10000));

    RectangleShape Sugar5;
    Sugar5.setSize(Vector2f(180, 80));
    Sugar5.setOrigin(25, 25);
    Sugar5.setPosition(Vector2f(10000, 10000));

    RectangleShape Sugar10;
    Sugar10.setSize(Vector2f(180, 80));
    Sugar10.setOrigin(25, 25);
    Sugar10.setPosition(Vector2f(10000, 10000));

    RectangleShape Sugar20;
    Sugar20.setSize(Vector2f(180, 80));
    Sugar20.setOrigin(25, 25);
    Sugar20.setPosition(Vector2f(10000, 10000));

    RectangleShape CupBuy;
    CupBuy.setSize(Vector2f(105, 105));
    CupBuy.setOrigin(CupBuy.getSize().x, CupBuy.getSize().y);
    CupBuy.setPosition(Vector2f(10000, 10000));

    RectangleShape Tycoons;
    Tycoons.setSize(Vector2f(300, 300));
    Tycoons.setOrigin(150, 150);
    Tycoons.setTexture(&TycoonTexture);

    RectangleShape LemonadeTycoonPlay;
    LemonadeTycoonPlay.setSize(Vector2f(250, 250));
    LemonadeTycoonPlay.setOrigin(LemonadeTycoonPlay.getSize().x/2, LemonadeTycoonPlay.getSize().y/2);

    RectangleShape FoodTruckTycoonPlay;
    FoodTruckTycoonPlay.setSize(Vector2f(250, 250));
    FoodTruckTycoonPlay.setOrigin(125, 125);

    RectangleShape DinerTycoonPlay;
    DinerTycoonPlay.setSize(Vector2f(250, 250));
    DinerTycoonPlay.setOrigin(125, 125);

    RectangleShape FoodTruck;
    FoodTruck.setSize(Vector2f(300, 300));
    FoodTruck.setOrigin(150, 150);
    FoodTruck.setPosition(7000, -1450);
    FoodTruck.setTexture(&FoodTruckTexture);

    RectangleShape Plates10;
    Plates10.setSize(Vector2f(100, 120));
    RectangleShape Plates20;
    Plates20.setSize(Vector2f(100, 120));
    RectangleShape Plates40;
    Plates40.setSize(Vector2f(100, 120));

    RectangleShape Chicken10;
    Chicken10.setSize(Vector2f(100, 120));
    RectangleShape Chicken20;
    Chicken20.setSize(Vector2f(100, 120));
    RectangleShape Chicken40;
    Chicken40.setSize(Vector2f(100, 120));

    RectangleShape HotDog10;
    HotDog10.setSize(Vector2f(100, 120));
    RectangleShape HotDog20;
    HotDog20.setSize(Vector2f(100, 120));
    RectangleShape HotDog40;
    HotDog40.setSize(Vector2f(100, 120));

    RectangleShape Burger10;
    Burger10.setSize(Vector2f(100, 120));
    RectangleShape Burger20;
    Burger20.setSize(Vector2f(100, 120));
    RectangleShape Burger40;
    Burger40.setSize(Vector2f(100, 120));

    RectangleShape Poutine10;
    Poutine10.setSize(Vector2f(100, 120));
    RectangleShape Poutine20;
    Poutine20.setSize(Vector2f(100, 120));
    RectangleShape Poutine40;
    Poutine40.setSize(Vector2f(100, 120));

    RectangleShape MoreChicken;
    MoreChicken.setSize(Vector2f(65, 50));
    RectangleShape LessChicken;
    LessChicken.setSize(Vector2f(65, 50));

    RectangleShape MoreHotDogs;
    MoreHotDogs.setSize(Vector2f(65, 50));
    RectangleShape LessHotDogs;
    LessHotDogs.setSize(Vector2f(65, 50));

    RectangleShape MoreBurgers;
    MoreBurgers.setSize(Vector2f(65, 50));
    RectangleShape LessBurgers;
    LessBurgers.setSize(Vector2f(65, 50));

    RectangleShape MorePoutine;
    MorePoutine.setSize(Vector2f(65, 50));
    RectangleShape LessPoutine;
    LessPoutine.setSize(Vector2f(65, 50));

    RectangleShape MoreChickenPrice;
    MoreChickenPrice.setSize(Vector2f(65, 50));
    RectangleShape LessChickenPrice;
    LessChickenPrice.setSize(Vector2f(65, 50));

    RectangleShape MoreHotDogsPrice;
    MoreHotDogsPrice.setSize(Vector2f(65, 50));
    RectangleShape LessHotDogsPrice;
    LessHotDogsPrice.setSize(Vector2f(65, 50));

    RectangleShape MoreBurgersPrice;
    MoreBurgersPrice.setSize(Vector2f(65, 50));
    RectangleShape LessBurgersPrice;
    LessBurgersPrice.setSize(Vector2f(65, 50));

    RectangleShape MorePoutinePrice;
    MorePoutinePrice.setSize(Vector2f(65, 50));
    RectangleShape LessPoutinePrice;
    LessPoutinePrice.setSize(Vector2f(65, 50));

    RectangleShape HomeButton;
    HomeButton.setSize(Vector2f(150, 100));
    HomeButton.setOrigin(75, 50);
    HomeButton.setOutlineColor(Color::Black);
    HomeButton.setOutlineThickness(-4.0);
    ///Buttons and Stuff

    ///Market Stuff
    int Marketcounter = 0;
    int Moneyspent = 0;
    ///Market Stuff

    ///Currency and Stats for Tycoon
    int Money = 50;
    int MoneyBefore = 50;
    int Profits;
    int KarmaMeter;

    int Cups = 0;
    int Sugar = 0;
    int Ice = 0;
    int Lemons = 0;
    int LemonadeCost = 0;

    int Plates = 0;
    int HotDogs = 0;
    int Burgers = 0;
    int Chicken = 0;
    int Poutine = 0;

    int Day = 0;
    int Day2 = 0;
    int Day3 = 0;

    int SugarDiff;
    int IceDiff;
    int LemonsDiff;
    float PriceDiff;

    int TotalLemon = 0;
    int TotalIce = 0;
    int TotalSugar = 0;

    int TotalHotDogs = 0;
    int TotalBurgers = 0;
    int TotalChicken = 0;
    int TotalPoutine = 0;

    int ChickenPrice = 0;
    int HotDogPrice = 0;
    int BurgerPrice = 0;
    int PoutinePrice = 0;

    int FoodTypeChance;
    int FoodType;

    int PriceDiffChicken;
    int PriceDiffHotDogs;
    int PriceDiffBurgers;
    int PriceDiffPoutine;

    vector<int> FoodOrder;
    ///Currency and Stats for Tycoon

    ///Map Stuff
    bool MapBool = true;
    bool Map2Bool = false;
    int DoorCounter = 0;
    View camera(Vector2f(850, 850), Vector2f(1750, 1750));
    ///Map Stuff

    ///Maps
    RectangleShape Map; ///Starting Map
    Texture MapTexture;
    MapTexture.loadFromFile("Map.png"); ///Each tile 32x32
    Map.setTexture(&MapTexture);
    Map.setSize(Vector2f(3500, 3500));
    Map.setOrigin(1750, 1750);
    Map.setPosition(Vector2f(400, 10000));

    RectangleShape Map2; ///Lemonade Stand
    Texture Map2Texture;
    Map2Texture.loadFromFile("Lemonade.png");
    Map2.setTexture(&Map2Texture);
    Map2.setSize(Vector2f(3500, 1750));
    Map2.setOrigin(1750, 875);
    Map2.setPosition(Vector2f(400, -1450));

    RectangleShape Map3; ///Food Truck
    Texture Map3Texture;
    Map3Texture.loadFromFile("FoodTruckMap.png");
    Map3.setTexture(&Map3Texture);
    Map3.setSize(Vector2f(7000, 3400));
    Map3.setOrigin(3500, 1700);
    Map3.setPosition(Vector2f(7000, -1450));

    RectangleShape Map4; ///Diner
    Texture Map4Texture;
    Map4Texture.loadFromFile("Diner.png");
    Map4.setTexture(&Map4Texture);
    Map4.setSize(Vector2f(3000, 1200));
    Map4.setOrigin(1500, 600);
    Map4.setPosition(Vector2f(-7000, -1450));
    ///Maps

    ///Lighting
    RectangleShape Lighting;
    Lighting.setSize(Vector2f(3500, 1750));
    Lighting.setOrigin(1750, 875);
    Lighting.setPosition(Vector2f(Map2.getPosition().x, Map2.getPosition().y));
    Lighting.setFillColor(Color(0, 0, 0, 0));

    float LightingCounter = 0.0;
    ///Lighting

    ///Extra Stuff
    Brick Fountain(world, 10000, 10000, 32, 32);
    Fountain.setOrigin(16, 16);
    Fountain.setScale(6.6, 6.6);
    Fountain.setTexture(&FountainTexture);
    Fountain.Object = 1; ///Matches with the button
    Fountain.Bought = false; ///Checks if its bought
    Fountain.Item = "Fountain";

    Brick Door(world, 10000, 10000, 32, 32);
    Door.setOrigin(16, 16);
    Door.setScale(6.6, 6.6);
    Door.setTexture(&DoorTexture);
    Door.Object = 2; ///Matches with the button
    Door.Bought = false; ///Checks if its bought
    Door.Item = "Door";

    Brick LemonadeStand(world, Map2.getPosition().x - 220, Map2.getPosition().y - 200, 250, 250);
    LemonadeStand.setOrigin(125, 125);
    LemonadeStand.setTexture(&LemonadeStandTexture);
    ///Extra Stuff

    ///Player Stuff
    int MCX = 0;
    int MCY = 0;
    int movement = 10;
    ///Player Stuff

    ///Customer Stuff
    int CustX = 196;
    int CustY = 32;
    float PurchaseChance;
    int Buy;
    int BuyingTime = 0;
    int ClickingCount = 0;
    int People = rand()%20;
    int PeopleBought = 0;
    int PeopleMissed = 0;
    ///Customer Stuff

    ///Character Details
    Sprite MainCharacter(MCTexture, sf::IntRect(MCX, MCY, 32, 50));
    MainCharacter.setPosition(Vector2f(Map.getPosition().x, Map.getPosition().y));
    MainCharacter.setScale(3.0, 3.0);
    MainCharacter.setOrigin(16, 25);
    ///Character Details

    ///Customers
    vector<Sprite> Customers;
    vector<bool> Clicking;
    vector<RectangleShape> LemonadeCups;
    vector<int> Fading;
    ///Customers

    ///Top Bar with all stats
    RectangleShape Stats;
    Stats.setSize(Vector2f(1750, 150));
    Stats.setFillColor(Color::Black);
    Stats.setOrigin(875, 75);
    ///Top Bar with all stats

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        ///Animations for the MC and the Customers
        MainCharacter.setTextureRect(IntRect(MCX, MCY, 32, 50));

        for (int i = 0; i < Customers.size(); i++)
        {
            Customers[i].setTextureRect(IntRect(CustX, CustY, 32, 32));
        }
        ///Animations for the MC and the Customers

        window.clear(); //clears the screen

        if (Home == true || LemonadeTycoon == true || FoodTruckTycoon == true || DinerTycoon == true)
        {
            ///Moves the screen
            camera.setCenter(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
            window.setView(camera);
            ///Moves the screen
        }

        physics::displayWorld(world, window);


        if (StartScreen == true)
        {
            if (OneUse == false)
            {
                if (Billionaire.getPosition().x < 875)
                {
                    Billionaire.move(8, 0);
                }

                if (Billionaire.getPosition().x >= 875)
                {
                    TycoonWord.move(-8, 0);
                    if (TycoonWord.getPosition().x <= 875)
                    {
                        OneUse = true;
                    }
                }
            }

            window.draw(Background);
            window.draw(Billionaire);
            window.draw(TycoonWord);
            if (OneUse == true)
            {
                window.draw(PlayButton);
                if (PlayButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    StartScreen = false;
                    Home = true;
                    //MainCharacter.setPosition(-7000, -1450);
                }
            }
        }


        if (Home == true)
        {
            Tycoons.setPosition(MainCharacter.getPosition().x -750, MainCharacter.getPosition().y - 350);
            Buttons[3].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
            LemonadeTycoonPlay.setPosition(MainCharacter.getPosition().x - 230, MainCharacter.getPosition().y - 143);
            FoodTruckTycoonPlay.setPosition(MainCharacter.getPosition().x + 176, MainCharacter.getPosition().y - 143);
            DinerTycoonPlay.setPosition(MainCharacter.getPosition().x - 230, MainCharacter.getPosition().y + 220);
            Stats.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 570);
            Moneytext.setPosition(MainCharacter.getPosition().x - 105, MainCharacter.getPosition().y - 565);
            ///Updates the X Button
            XButton.setPosition(MainCharacter.getPosition().x + 440, MainCharacter.getPosition().y - 480);
            ///Updates the X Button

            Moneytext.setString("Money: $ " + to_string(Money));

            ///Character Controls
             if (Keyboard::isKeyPressed(Keyboard::Right) == false
                && Keyboard::isKeyPressed(Keyboard::Left) == false
                && Keyboard::isKeyPressed(Keyboard::Up) == false
                && Keyboard::isKeyPressed(Keyboard::Down) == false
                && Keyboard::isKeyPressed(Keyboard::A) == false
                && Keyboard::isKeyPressed(Keyboard::S) == false
                && Keyboard::isKeyPressed(Keyboard::D) == false
                && Keyboard::isKeyPressed(Keyboard::W) == false)
            {
                MCX = 0;
            }
            if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && MainCharacter.getPosition().x < Map.getPosition().x + Map.getSize().x/2 - 55) ///MOVES EVERYTHING TO THE RIGHT
            {
                    MCX = MCX + 32;
                    if (MCX >= 128)
                    {
                        MCX = 0;
                    }
                    MCY = 100;
                    MainCharacter.setPosition(MainCharacter.getPosition().x + 10, MainCharacter.getPosition().y);
            }

            else if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && MainCharacter.getPosition().x > Map.getPosition().x - Map.getSize().x/2 + 55) ///MOVES EVERYTHING TO THE LEFT
            {
                    MCX = MCX + 32;
                    if (MCX >= 128)
                    {
                        MCX = 0;
                    }
                    MCY = 50;
                    MainCharacter.setPosition(MainCharacter.getPosition().x - 10, MainCharacter.getPosition().y);
            }

            else if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && MainCharacter.getPosition().y > Map.getPosition().y - Map.getSize().y/2) ///MOVES EVERYTHING UP
            {
                    MCX = MCX + 32;
                    MCY = 150;
                    if (MCX >= 128)
                    {
                        MCX = 0;
                    }
                    MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 10);
            }
            else if ((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && MainCharacter.getPosition().y < Map.getPosition().y + Map.getSize().y/2 - 85) ///MOVES EVERYTHING DOWN
            {
                    MCX = MCX + 32;
                    MCY = 0;
                    if (MCX >= 128)
                    {
                        MCX = 0;
                    }
                    MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y + 10);
            }
            ///Character Controls


            window.draw(Map);
            window.draw(Tycoons);
            window.draw(MainCharacter);
            window.draw(Stats);
            window.draw(Moneytext);

            if (Tycoons.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && ShowTycoons == false)
            {
                window.setMouseCursorVisible(false);
                Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                window.draw(Click);

                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    ShowTycoons = true;
                }
            }

            else
            {
                window.setMouseCursorVisible(true);
            }

            if (ShowTycoons == true)
            {
                window.draw(Buttons[3]);
                window.draw(XButton);

                if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    ShowTycoons = false;
                }

                ///Lemonade
                if (LemonadeTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    window.setMouseCursorVisible(false);
                    Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                    window.draw(Click);
                    Pick1 = true;

                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        Home = false;
                        LemonadeTycoon = true;
                        MainCharacter.setPosition(330, -1080);
                        window.setMouseCursorVisible(true);

                    }
                }

                else if (LemonadeTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Pick2 == false && Pick3 == false && Pick4 == false)
                {
                    window.setMouseCursorVisible(true);
                }
                ///Lemonade

                ///FoodTruck
                if (FoodTruckTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    window.setMouseCursorVisible(false);
                    Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                    window.draw(Click);
                    Pick2 = true;

                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        Home = false;
                        FoodTruckTycoon = true;
                        MainCharacter.setPosition(7000, -1675);
                        window.setMouseCursorVisible(true);
                    }
                }

                else if (FoodTruckTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Pick1 == false && Pick3 == false && Pick4 == false)
                {
                    window.setMouseCursorVisible(true);
                }
                ///Food Truck

                ///Diner
                if (DinerTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    window.setMouseCursorVisible(false);
                    Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                    window.draw(Click);
                    Pick3 = true;

                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        Home = false;
                        DinerTycoon = true;
                        MainCharacter.setPosition(-7000, -1675);
                        window.setMouseCursorVisible(true);
                    }
                }

                else if (FoodTruckTycoonPlay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Pick1 == false && Pick2 == false && Pick4 == false)
                {
                    window.setMouseCursorVisible(true);
                }
                ///Diner
            }
        }

        //////////////////////////////////////////////////////
        //////////////////////////////////////////////////////
        //////////////////////////////////////////////////////

        if (LemonadeTycoon == true)
        {
            ///Updates Positions
            Stats.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 570);
            StartDay.setPosition(MainCharacter.getPosition().x - 790, MainCharacter.getPosition().y - 545); ///790
            Market.setPosition(MainCharacter.getPosition().x + 790, MainCharacter.getPosition().y - 545); ///790
            MarketText.setPosition(MainCharacter.getPosition().x + 734, MainCharacter.getPosition().y - 555); ///734
            StartingDay.setPosition(MainCharacter.getPosition().x - 834, MainCharacter.getPosition().y - 575); ///834
            Moneytext.setPosition(MainCharacter.getPosition().x - 105, MainCharacter.getPosition().y - 565);
            DayText.setPosition(MainCharacter.getPosition().x - 700, MainCharacter.getPosition().y - 565);

            if (Lemonade == true) ///For the Lemonade Tycoon
            {
                Buttons[1].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                Addition.setPosition(Vector2f(MainCharacter.getPosition().x - 270, MainCharacter.getPosition().y - 139));
                Addition2.setPosition(Vector2f(MainCharacter.getPosition().x + 67, MainCharacter.getPosition().y - 140));
                Addition3.setPosition(Vector2f(MainCharacter.getPosition().x + 343, MainCharacter.getPosition().y - 142));
                Addition4.setPosition(Vector2f(MainCharacter.getPosition().x + 53, MainCharacter.getPosition().y + 53));
                Subtraction.setPosition(Vector2f(MainCharacter.getPosition().x - 397.5, MainCharacter.getPosition().y - 140));
                Subtraction2.setPosition(Vector2f(MainCharacter.getPosition().x - 61, MainCharacter.getPosition().y - 141));
                Subtraction3.setPosition(Vector2f(MainCharacter.getPosition().x + 216.5, MainCharacter.getPosition().y - 141));
                Subtraction4.setPosition(Vector2f(MainCharacter.getPosition().x - 75, MainCharacter.getPosition().y + 53));
                LemonsText.setPosition(Vector2f(MainCharacter.getPosition().x - 315, MainCharacter.getPosition().y - 130));
                SugarText.setPosition(Vector2f(MainCharacter.getPosition().x + 25, MainCharacter.getPosition().y - 131));
                IceText.setPosition(Vector2f(MainCharacter.getPosition().x + 300, MainCharacter.getPosition().y - 132));
                LemonPriceText.setPosition(Vector2f(MainCharacter.getPosition().x + 3, MainCharacter.getPosition().y + 65));
                Supplies.setPosition(Vector2f(MainCharacter.getPosition().x - 430, MainCharacter.getPosition().y + 110));
            }

            if (SalesShow == true)
            {
                Buttons[4].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                CustomersS.setPosition(MainCharacter.getPosition().x - 80, MainCharacter.getPosition().y - 240);
                CustomersL.setPosition(MainCharacter.getPosition().x + 110, MainCharacter.getPosition().y - 80);
                Profit.setPosition(MainCharacter.getPosition().x - 60, MainCharacter.getPosition().y + 240);
                Karma.setPosition(MainCharacter.getPosition().x - 200, MainCharacter.getPosition().y + 82);
            }

            if (MarketOpen == true)
            {
                Buttons[2].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
            }
            ///Updates Positions

            ///Updates Stats
            Moneytext.setString("Money: $ " + to_string(Money));
            MarketText.setString("Market");
            DayText.setString("Day: " + to_string(Day));
            LemonsText.setString(to_string(Lemons));
            IceText.setString(to_string(Ice));
            SugarText.setString(to_string(Sugar));
            LemonPriceText.setString("$" + to_string(LemonadeCost));
            Supplies.setString("You have " + to_string(TotalLemon) + " Lemons, " + to_string(TotalSugar) + " Sugar, and " + to_string(TotalIce) + " Ice! \n \n \n \n \n You have " + to_string(Cups) + " Cups");
            ///Updates Stats

            if (Money == 100)
            {
                Buttons[0].Object = Buttons[0].Object + 1;
            }

            ///Updates the X Button
            XButton.setPosition(MainCharacter.getPosition().x + 440, MainCharacter.getPosition().y - 480);
            ///Updates the X Button

            if (Keyboard::isKeyPressed(Keyboard::Right) == false
                && Keyboard::isKeyPressed(Keyboard::Left) == false
                && Keyboard::isKeyPressed(Keyboard::Up) == false
                && Keyboard::isKeyPressed(Keyboard::Down) == false
                && Keyboard::isKeyPressed(Keyboard::A) == false
                && Keyboard::isKeyPressed(Keyboard::S) == false
                && Keyboard::isKeyPressed(Keyboard::D) == false
                && Keyboard::isKeyPressed(Keyboard::W) == false)
            {
                MCX = 0;
            }
                ///Character Controls
                if (((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && MainCharacter.getPosition().x < Map2.getPosition().x + Map2.getSize().x/2 - 55)) ///MOVES EVERYTHING TO THE RIGHT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 100;
                        MainCharacter.setPosition(MainCharacter.getPosition().x + 10, MainCharacter.getPosition().y);
                }

                else if (((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && MainCharacter.getPosition().x > Map2.getPosition().x - Map2.getSize().x/2 + 55)) ///MOVES EVERYTHING TO THE LEFT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 50;
                        MainCharacter.setPosition(MainCharacter.getPosition().x - 10, MainCharacter.getPosition().y);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && MainCharacter.getPosition().y > Map2.getPosition().y - Map2.getSize().y/2)) ///MOVES EVERYTHING UP
                {
                        MCX = MCX + 32;
                        MCY = 150;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 10);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && MainCharacter.getPosition().y < Map2.getPosition().y + Map2.getSize().y/2 - 85)) ///MOVES EVERYTHING DOWN
                {
                        MCX = MCX + 32;
                        MCY = 0;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y + 10);

                }
                ///Character Controls

            ///Drawings
            window.draw(Map);
            window.draw(Map2);
            window.draw(Lighting);
            ///Drawings

            ///Drawing Character
            if (MainCharacter.getPosition().y < LemonadeStand.getPosition().y)
            {
                window.draw(MainCharacter);
                window.draw(LemonadeStand);
            }

            if (MainCharacter.getPosition().y > LemonadeStand.getPosition().y)
            {
                window.draw(LemonadeStand);
                window.draw(MainCharacter);
            }
            ///Drawing Character

            ///Drawing Customers
            for (int i = 0; i < Customers.size(); i++)
            {
                if (Customers[i].getPosition().x < 1700)
                {
                    window.draw(Customers[i]);
                }
            }

            for (int i = 0; i < LemonadeCups.size(); i++)
            {
                window.draw(LemonadeCups[i]);
                LemonadeCups[i].move(-3, 0);
            }

            ///Drawing Customers

            ///Drawing Lemonade Stand Stats
            if (Lemonade == false)
            {
                Buttons[1].setPosition(Vector2f(10000, 10000));
                Addition.setPosition(Vector2f(10000, 10000));
                Addition2.setPosition(Vector2f(10000, 10000));
                Addition3.setPosition(Vector2f(10000, 10000));
                Addition4.setPosition(Vector2f(10000, 10000));
                Subtraction.setPosition(Vector2f(10000, 10000));
                Subtraction2.setPosition(Vector2f(10000, 10000));
                Subtraction3.setPosition(Vector2f(10000, 10000));
                Subtraction4.setPosition(Vector2f(10000, 10000));
                IceText.setPosition(Vector2f(10000, 10000));
                LemonsText.setPosition(Vector2f(10000, 10000));
                SugarText.setPosition(Vector2f(10000, 10000));
                LemonPriceText.setPosition(Vector2f(10000, 10000));
                Supplies.setPosition(Vector2f(10000, 10000));
            }

            if (LemonadeStand.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && DayStart == false && Lemonade == false && MarketOpen == false)
            {
                window.setMouseCursorVisible(false);
                Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                window.draw(Click);
            }

            else
            {
                window.setMouseCursorVisible(true);
            }

            if (LemonadeStand.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Lemonade == false && DayStart == false && MarketOpen == false)
            {
                Lemonade = true;
            }

            if (Market.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Lemonade == false && DayStart == false && MarketOpen == false)
            {
                MarketOpen = true;
            }

            if (MarketOpen == true)
            {
                Marketcounter++;

                Lemon5.setPosition(Vector2f(MainCharacter.getPosition().x - 364, MainCharacter.getPosition().y - 25));

                Lemon10.setPosition(Vector2f(MainCharacter.getPosition().x - 364, MainCharacter.getPosition().y + 130));

                Lemon20.setPosition(Vector2f(MainCharacter.getPosition().x - 364, MainCharacter.getPosition().y + 285));

                Ice5.setPosition(Vector2f(MainCharacter.getPosition().x - 40, MainCharacter.getPosition().y - 25));

                Ice10.setPosition(Vector2f(MainCharacter.getPosition().x - 40, MainCharacter.getPosition().y + 130));

                Ice20.setPosition(Vector2f(MainCharacter.getPosition().x - 40, MainCharacter.getPosition().y + 280));

                Sugar5.setPosition(Vector2f(MainCharacter.getPosition().x + 255, MainCharacter.getPosition().y - 25));

                Sugar10.setPosition(Vector2f(MainCharacter.getPosition().x + 255, MainCharacter.getPosition().y + 130));

                Sugar20.setPosition(Vector2f(MainCharacter.getPosition().x + 255, MainCharacter.getPosition().y + 280));

                CupBuy.setPosition(Vector2f(MainCharacter.getPosition().x  - 240, MainCharacter.getPosition().y - 323));

                window.draw(Buttons[2]);
                window.draw(XButton);

                if (Lemon5.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 5)
                {
                    TotalLemon = TotalLemon + 5;
                    Marketcounter = 0;
                    Money = Money - 5;
                    Moneyspent = Moneyspent + 5;
                }
                /////////
                if (Lemon10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 10)
                {
                    TotalLemon = TotalLemon + 10;
                    Marketcounter = 0;
                    Money = Money - 10;
                    Moneyspent = Moneyspent + 10;
                }
                ///////////
                if (Lemon20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 18)
                {
                    TotalLemon = TotalLemon + 20;
                    Marketcounter = 0;
                    Money = Money - 18;
                    Moneyspent = Moneyspent + 18;
                }
                //////////
                if (Ice5.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 3)
                {
                    TotalIce = TotalIce + 5;
                    Marketcounter = 0;
                    Money = Money - 3;
                    Moneyspent = Moneyspent + 3;
                }
                ///////////
                if (Ice10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 6)
                {
                    TotalIce = TotalIce + 10;
                    Marketcounter = 0;
                    Money = Money - 6;
                    Moneyspent = Moneyspent + 6;
                }
                ////////////
                if (Ice20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 10)
                {
                    TotalIce = TotalIce + 20;
                    Marketcounter = 0;
                    Money = Money - 10;
                    Moneyspent = Moneyspent + 10;
                }
                /////////////
                if (Sugar5.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 4)
                {
                    TotalSugar = TotalSugar + 5;
                    Marketcounter = 0;
                    Money = Money - 4;
                    Moneyspent = Moneyspent + 4;
                }
                /////////////
                if (Sugar10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 8)
                {
                    TotalSugar = TotalSugar + 10;
                    Marketcounter = 0;
                    Money = Money - 8;
                    Moneyspent = Moneyspent + 8;
                }
                /////////
                if (Sugar20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 15)
                {
                    TotalSugar = TotalSugar + 20;
                    Marketcounter = 0;
                    Money = Money - 15;
                    Moneyspent = Moneyspent + 15;
                }

                if (CupBuy.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 1)
                {
                    Cups = Cups + 10;
                    Money = Money - 1;
                    Moneyspent = Moneyspent + 1;
                    Marketcounter = 0;
                }

                if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20)
                {
                    MarketOpen = false;
                }

            }

            if (MarketOpen == false)
            {
                Buttons[2].setPosition(10000, 10000);
            }

            if (Lemonade == true)
            {
                ButtonTimer++;
                window.draw(Addition);
                window.draw(Addition2);
                window.draw(Addition3);
                window.draw(Addition4);
                window.draw(Subtraction);
                window.draw(Subtraction2);
                window.draw(Subtraction3);
                window.draw(Subtraction4);
                window.draw(Buttons[1]);
                window.draw(XButton);
                window.draw(LemonsText);
                window.draw(IceText);
                window.draw(SugarText);
                window.draw(LemonPriceText);
                window.draw(Supplies);

                if (Addition.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Lemons < 10 && Lemons >= 0 && ButtonTimer > 20 && Lemons < TotalLemon)
                {
                    Lemons = Lemons + 1;
                    ButtonTimer = 0;
                }
                //
                if (Addition2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Sugar < 10 && Sugar >= 0 && ButtonTimer > 20 && Sugar < TotalSugar)
                {
                    Sugar = Sugar + 1;
                    ButtonTimer = 0;
                }
                //
                if (Addition3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Ice < 10 && Ice >= 0 && ButtonTimer > 20 && Ice < TotalIce)
                {
                    Ice = Ice + 1;
                    ButtonTimer = 0;
                }
                //
                if (Addition4.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && LemonadeCost < 50 && LemonadeCost >= 0 && ButtonTimer > 20)
                {
                    LemonadeCost = LemonadeCost + 1;
                    ButtonTimer = 0;
                }
                //
                if (Subtraction.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Lemons <= 10 && Lemons > 0 && ButtonTimer > 20 && Lemons <= TotalLemon)
                {
                    Lemons = Lemons - 1;
                    ButtonTimer = 0;
                }
                //
                if (Subtraction2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Sugar <= 10 && Sugar > 0 && ButtonTimer > 20 && Sugar <= TotalSugar)
                {
                    Sugar = Sugar - 1;
                    ButtonTimer = 0;
                }
                //
                if (Subtraction3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Ice <= 10 && Ice > 0 && ButtonTimer > 20 && Ice <= TotalIce)
                {
                    Ice = Ice - 1;
                    ButtonTimer = 0;
                }
                //
                if (Subtraction4.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && LemonadeCost <= 50 && LemonadeCost > 0 && ButtonTimer > 20)
                {
                    LemonadeCost = LemonadeCost - 1;
                    ButtonTimer = 0;
                }
            }

            if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
            {
                Lemonade = false;
            }
            ///Drawing Lemonade Stand Stats

            ///Starting and ending the day
            if (StartDay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && DayStart == false && Lemonade == false && MarketOpen == false && Lemons > 0 && Ice > 0 && Sugar > 0 && LemonadeCost > 0 && Cups > 0)
            {
                DayStart = true;
            }

            if (StartDay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && DayStart == false && Lemonade == false && MarketOpen == false && (Lemons == 0 || Ice == 0 || Sugar == 0 || LemonadeCost == 0 || Cups == 0))
            {
                Needmore.setString("You are missing something from your lemonade stand!");
                Needmore.setPosition(MainCharacter.getPosition().x - 850, MainCharacter.getPosition().y - 50);
                window.draw(Needmore);
            }

            if (DayStart == true)
            {
                Lemonade = false;
                if (UseOnce == false)
                {
                    MoneyBefore = Money;
                    People = rand()%10 + 7;
                    LightingCounter = 0;
                    for (int i = 0; i < People; i++)
                    {
                        Customers.push_back(Sprite(CustomerTexture, sf::IntRect(CustX, CustY, 32, 32)));
                        Customers.back().setScale(3.75, 3.75);
                        Customers.back().setPosition(rand()%5000 + 2000, rand()%500 - 1300);
                        Customers.back().setOrigin(16, 25);
                        Clicking.push_back(bool(false));
                    }
                    Day = Day + 1;
                    TotalLemon = TotalLemon - Lemons;
                    TotalIce = TotalIce - Ice;
                    TotalSugar = TotalSugar - Sugar;
                    UseOnce = true;
                }
                if (Animations%2 == 0)
                {
                    CustX = CustX + 32;
                }
                Animations++;
                if (CustX >= 292)
                {
                    CustX = 196;
                }
                CustY = 32;

                BuyingTime++;

                for (int i = 0; i < Customers.size(); i++)
                {
                    Customers[i].move(-3, 0);
                    if (Customers[i].getPosition().x <= -1000)
                    {
                        Customers.erase(Customers.begin() + i);
                        Clicking.erase(Clicking.begin() + i);
                    }

                    for (int i = 0; i < LemonadeCups.size(); i++)
                    {
                        if (LemonadeCups[i].getPosition().x <= -1000)
                        {
                            LemonadeCups.erase(LemonadeCups.begin() + i);
                        }
                    }

                    ///Buying Lemonade
                    if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                    {
                        window.setMouseCursorVisible(false);
                        Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                        window.draw(Click);
                        ClickingCount = ClickingCount + 1;
                    }
                    if (ClickingCount == 0)
                    {
                        window.setMouseCursorVisible(true);
                    }

                    if (Clicking[i] == false)
                    {
                        if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && BuyingTime > 20)
                        {
                            if (Sugar >= 2)
                            {
                                SugarDiff = Sugar - 2;
                            }
                            if (Sugar < 2)
                            {
                                SugarDiff = 2 - Sugar;
                            }
                            ////////////////////////////////////
                            if (Ice >= 6)
                            {
                                IceDiff = Ice - 6;
                            }
                            if (Ice < 6)
                            {
                                IceDiff = 6 - Sugar;
                            }
                            ////////////////////////////////////
                            if (Lemons >= 3)
                            {
                                LemonsDiff = Lemons - 3;
                            }
                            if (Lemons < 3)
                            {
                                LemonsDiff = 3 - Lemons;
                            }
                            ////////////////////////////////////
                            if (LemonadeCost >= 7)
                            {
                                PriceDiff = LemonadeCost - 7;
                            }
                            PurchaseChance = (19 - LemonsDiff - IceDiff - SugarDiff)/(19*(PriceDiff + 1)) + .15;
                            if (LemonadeCost < 7)
                            {
                                PurchaseChance = PurchaseChance + .1/LemonadeCost;
                            }
                            if (rand()%100 <= 100*PurchaseChance)
                            {
                                Buy = 1;
                            }
                            else
                            {
                                Buy = 0;
                            }

                            if (Buy == 1 && Cups > 0)
                            {
                                Cups = Cups - 1;
                                Money = Money + LemonadeCost;
                                LemonadeCups.push_back(RectangleShape(Vector2f(50, 50)));
                                LemonadeCups.back().setPosition(Vector2f(Customers[i].getPosition().x - 5, Customers[i].getPosition().y - 15));
                                LemonadeCups.back().setOrigin(25, 25);
                                LemonadeCups.back().setTexture(&LemonadeTexture);

                                MoneyMade.push_back(Text("+ $" + to_string(LemonadeCost), f1, 30));
                                MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                MoneyMade.back().setScale(1.4, 1.4);

                                Fading.push_back(int(255));
                                PeopleBought = PeopleBought + 1;

                                Buy = 2;
                            }

                            if (Buy == 0)
                            {
                                MoneyMade.push_back(Text("No Thanks", f1, 30));
                                MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                MoneyMade.back().setScale(1.4, 1.4);

                                Fading.push_back(int(255));
                                PeopleMissed = PeopleMissed + 1;
                            }


                            BuyingTime = 0;
                            Clicking[i] = true;
                        }
                    }
                    ///Buying Lemonade
                }
                ClickingCount = 0;

                for (int i = 0; i < MoneyMade.size(); i++)
                {
                    MoneyMade[i].setPosition(MoneyMade[i].getPosition().x - 3, MoneyMade[i].getPosition().y - 1);
                    MoneyMade[i].setFillColor(Color(0, 255, 0, Fading[i]));
                    window.draw(MoneyMade[i]);
                    Fading[i] = Fading[i] - 5;

                    if (Fading[i] == 0)
                    {
                        MoneyMade.erase(MoneyMade.begin() + i);
                        Fading.erase(Fading.begin() + i);
                    }
                }

                Lighting.setFillColor(Color(0, 0, 0, LightingCounter));

                if (LightingCounter >= 0 && LightingCounter <= 100 && LightingTimes == false)
                {
                    LightingCounter = LightingCounter + 0.05;

                }

                if (LightingCounter >= 100)
                {
                    LightingTimes = true;
                }

                if (LightingTimes == true)
                {
                    LightingCounter = LightingCounter - 0.05;

                    if (LightingCounter <= 0)
                    {
                        LightingTimes = false;
                    }
                }

                if (Customers.size() <= 0)
                {
                    SalesShow = true;
                    Profits = Money - MoneyBefore;
                    CustomersS.setString(to_string(PeopleBought) + " Customers");
                    CustomersL.setString(to_string(PeopleMissed) + " Customers");
                    Profit.setString("$" + to_string(Profits));
                    KarmaMeter = ((PeopleBought - PeopleMissed)/2);
                    Karma.setString(to_string(KarmaMeter));
                    if (Profits < 0)
                    {
                        Profit.setFillColor(Color::Red);
                    }

                    if (Profits > 0)
                    {
                        Profit.setFillColor(Color::Green);
                    }

                    if (KarmaMeter < 0)
                    {
                        Karma.setFillColor(Color::Red);
                    }

                    if (KarmaMeter > 0)
                    {
                        Karma.setFillColor(Color::Green);
                        Karma.setString("+ " + to_string(KarmaMeter));
                    }

                    if (KarmaMeter == 0)
                    {
                        Karma.setFillColor(Color::Blue);
                    }
                }
            }
            ///Starting and ending the day

            ///Draws Character in front of the people
            for (int i = 0; i < Customers.size(); i++)
            {
                if (MainCharacter.getPosition().y > Customers[i].getPosition().y + 10)
                {
                    window.draw(MainCharacter);
                }
            }
            ///Draws Character in front of the people

            if (SalesShow == true)
            {
                window.draw(Buttons[4]);
                window.draw(Profit);
                window.draw(CustomersL);
                window.draw(CustomersS);
                window.draw(Karma);
                window.draw(XButton);
                if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    SalesShow = false;
                    Lemons = 0;
                    Ice = 0;
                    Sugar = 0;
                    PeopleBought = 0;
                    PeopleMissed = 0;
                    DayStart = false;
                    UseOnce = false;
                    LightingCounter = 0;
                    Lighting.setFillColor(Color(0, 0, 0, LightingCounter));
                }
            }

            ///Draws Player Stats
            window.draw(Stats);
            window.draw(Moneytext);
            window.draw(DayText);
            window.draw(Market);
            window.draw(MarketText);
            window.draw(StartDay);
            window.draw(StartingDay);
            ///Draws Player Stats
        }

        if (FoodTruckTycoon == true)
        {
            ///Updates Positions
            Stats.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 570);
            Moneytext.setPosition(MainCharacter.getPosition().x - 105, MainCharacter.getPosition().y - 565);
            Market.setPosition(MainCharacter.getPosition().x + 790, MainCharacter.getPosition().y - 545); ///790
            MarketText.setPosition(MainCharacter.getPosition().x + 734, MainCharacter.getPosition().y - 555); ///734
            StartDay.setPosition(MainCharacter.getPosition().x - 790, MainCharacter.getPosition().y - 545); ///790
            DayText.setPosition(MainCharacter.getPosition().x - 700, MainCharacter.getPosition().y - 565);
            StartingDay.setPosition(MainCharacter.getPosition().x - 834, MainCharacter.getPosition().y - 575); ///834

            if (SalesShow == true)
            {
                Buttons[4].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                CustomersS.setPosition(MainCharacter.getPosition().x - 80, MainCharacter.getPosition().y - 240);
                CustomersL.setPosition(MainCharacter.getPosition().x + 110, MainCharacter.getPosition().y - 80);
                Profit.setPosition(MainCharacter.getPosition().x - 60, MainCharacter.getPosition().y + 240);
                Karma.setPosition(MainCharacter.getPosition().x - 200, MainCharacter.getPosition().y + 82);
            }

            if (MarketOpen == true)
            {
                Marketcounter++;

                Buttons[5].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                Plates10.setPosition(MainCharacter.getPosition().x - 440, MainCharacter.getPosition().y - 130);
                Plates20.setPosition(MainCharacter.getPosition().x - 440, MainCharacter.getPosition().y + 55);
                Plates40.setPosition(MainCharacter.getPosition().x - 440, MainCharacter.getPosition().y + 245);
                Chicken10.setPosition(MainCharacter.getPosition().x - 280, MainCharacter.getPosition().y - 130);
                Chicken20.setPosition(MainCharacter.getPosition().x - 280, MainCharacter.getPosition().y + 55);
                Chicken40.setPosition(MainCharacter.getPosition().x - 280, MainCharacter.getPosition().y + 245);
                HotDog10.setPosition(MainCharacter.getPosition().x  - 100, MainCharacter.getPosition().y - 130);
                HotDog20.setPosition(MainCharacter.getPosition().x - 100, MainCharacter.getPosition().y + 60);
                HotDog40.setPosition(MainCharacter.getPosition().x - 100, MainCharacter.getPosition().y + 245);
                Burger10.setPosition(MainCharacter.getPosition().x + 88, MainCharacter.getPosition().y - 130);
                Burger20.setPosition(MainCharacter.getPosition().x + 88, MainCharacter.getPosition().y + 55);
                Burger40.setPosition(MainCharacter.getPosition().x + 88, MainCharacter.getPosition().y + 245);
                Poutine10.setPosition(MainCharacter.getPosition().x + 285, MainCharacter.getPosition().y - 130);
                Poutine20.setPosition(MainCharacter.getPosition().x + 285, MainCharacter.getPosition().y + 55);
                Poutine40.setPosition(MainCharacter.getPosition().x + 285, MainCharacter.getPosition().y + 245);

                ///Buying Plates
                if (Plates10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 5)
                {
                    Money = Money - 5;
                    Marketcounter = 0;
                    Plates = Plates + 10;
                }
                if (Plates20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 9)
                {
                    Money = Money - 9;
                    Marketcounter = 0;
                    Plates = Plates + 20;
                }
                if (Plates40.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 15)
                {
                    Money = Money - 15;
                    Marketcounter = 0;
                    Plates = Plates + 40;
                }
                ///Buying Plates

                ///Buying Chicken
                if (Chicken10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 40)
                {
                    Money = Money - 40;
                    Marketcounter = 0;
                    TotalChicken = TotalChicken + 10;
                }
                if (Chicken20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 75)
                {
                    Money = Money - 75;
                    Marketcounter = 0;
                    TotalChicken = TotalChicken + 20;
                }
                if (Chicken40.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 140)
                {
                    Money = Money - 140;
                    Marketcounter = 0;
                    TotalChicken = TotalChicken + 40;
                }
                ///Buying Chicken

                ///Buying HotDogs
                if (HotDog10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 60)
                {
                    Money = Money - 60;
                    Marketcounter = 0;
                    TotalHotDogs = TotalHotDogs + 10;
                }
                if (HotDog20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 115)
                {
                    Money = Money - 115;
                    Marketcounter = 0;
                    TotalHotDogs = TotalHotDogs + 20;
                }
                if (HotDog40.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 220)
                {
                    Money = Money - 220;
                    Marketcounter = 0;
                    TotalHotDogs = TotalHotDogs + 40;
                }
                ///Buying HotDogs

                ///Buying Burgers
                if (Burger10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 80)
                {
                    Money = Money - 80;
                    Marketcounter = 0;
                    TotalBurgers = TotalBurgers + 10;
                }
                if (Burger20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 150)
                {
                    Money = Money - 150;
                    Marketcounter = 0;
                    TotalBurgers = TotalBurgers + 20;
                }
                if (Burger40.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 290)
                {
                    Money = Money - 290;
                    Marketcounter = 0;
                    TotalBurgers = TotalBurgers + 40;
                }
                ///Buying Burgers

                ///Buying Poutine
                if (Poutine10.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 20)
                {
                    Money = Money - 20;
                    Marketcounter = 0;
                    TotalPoutine = TotalPoutine + 10;
                }
                if (Poutine20.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 35)
                {
                    Money = Money - 35;
                    Marketcounter = 0;
                    TotalPoutine = TotalPoutine + 20;
                }
                if (Poutine40.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Money >= 60)
                {
                    Money = Money - 60;
                    Marketcounter = 0;
                    TotalPoutine = TotalPoutine + 40;
                }
                ///Buying Poutine

                if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MarketOpen = false;
                    Buttons[5].setPosition(10000, 10000);
                }
            }

            if (Truck == true)
            {
                Marketcounter++;

                Buttons[6].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                Supplies.setPosition(Vector2f(MainCharacter.getPosition().x - 415, MainCharacter.getPosition().y + 310));
                MoreChicken.setPosition(MainCharacter.getPosition().x - 400, MainCharacter.getPosition().y - 270);
                LessChicken.setPosition(MainCharacter.getPosition().x - 400, MainCharacter.getPosition().y - 140);
                MoreHotDogs.setPosition(MainCharacter.getPosition().x - 147, MainCharacter.getPosition().y - 275);
                LessHotDogs.setPosition(MainCharacter.getPosition().x - 147, MainCharacter.getPosition().y - 145);
                MoreBurgers.setPosition(MainCharacter.getPosition().x + 93, MainCharacter.getPosition().y - 275);
                LessBurgers.setPosition(MainCharacter.getPosition().x + 93, MainCharacter.getPosition().y - 145);
                MorePoutine.setPosition(MainCharacter.getPosition().x + 316, MainCharacter.getPosition().y - 275);
                LessPoutine.setPosition(MainCharacter.getPosition().x + 316, MainCharacter.getPosition().y - 145);
                MoreChickenPrice.setPosition(MainCharacter.getPosition().x - 400, MainCharacter.getPosition().y + 10);
                LessChickenPrice.setPosition(MainCharacter.getPosition().x - 400, MainCharacter.getPosition().y + 140);
                MoreHotDogsPrice.setPosition(MainCharacter.getPosition().x - 152, MainCharacter.getPosition().y + 15);
                LessHotDogsPrice.setPosition(MainCharacter.getPosition().x - 154, MainCharacter.getPosition().y + 145);
                MoreBurgersPrice.setPosition(MainCharacter.getPosition().x + 93, MainCharacter.getPosition().y + 15);
                LessBurgersPrice.setPosition(MainCharacter.getPosition().x + 93, MainCharacter.getPosition().y + 145);
                MorePoutinePrice.setPosition(MainCharacter.getPosition().x + 316, MainCharacter.getPosition().y + 15);
                LessPoutinePrice.setPosition(MainCharacter.getPosition().x + 316, MainCharacter.getPosition().y + 145);
                ChickenText.setPosition(MainCharacter.getPosition().x - 380, MainCharacter.getPosition().y - 205);
                HotDogText.setPosition(MainCharacter.getPosition().x - 130, MainCharacter.getPosition().y - 210);
                BurgerText.setPosition(MainCharacter.getPosition().x + 115, MainCharacter.getPosition().y - 210);
                PoutineText.setPosition(MainCharacter.getPosition().x + 340, MainCharacter.getPosition().y - 210);
                ChickenPriceText.setPosition(MainCharacter.getPosition().x - 400, MainCharacter.getPosition().y + 75);
                HotDogPriceText.setPosition(MainCharacter.getPosition().x - 152, MainCharacter.getPosition().y + 75);
                BurgerPriceText.setPosition(MainCharacter.getPosition().x + 93, MainCharacter.getPosition().y + 75);
                PoutinePriceText.setPosition(MainCharacter.getPosition().x + 316, MainCharacter.getPosition().y + 75);

                ///Increasing Chicken
                if (MoreChicken.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Chicken >= 0 && Chicken < TotalChicken)
                {
                    Chicken = Chicken + 1;
                    Marketcounter = 0;
                }
                if (LessChicken.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Chicken > 0)
                {
                    Chicken = Chicken - 1;
                    Marketcounter = 0;
                }
                if (MoreChickenPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && ChickenPrice >= 0 && ChickenPrice < 50)
                {
                    ChickenPrice = ChickenPrice + 1;
                    Marketcounter = 0;
                }
                if (LessChickenPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && ChickenPrice > 0)
                {
                    ChickenPrice = ChickenPrice - 1;
                    Marketcounter = 0;
                }
                ///Increasing Chicken

                ///Increasing HotDogs
                if (MoreHotDogs.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && HotDogs >= 0 && HotDogs < TotalHotDogs)
                {
                    HotDogs = HotDogs + 1;
                    Marketcounter = 0;
                }
                if (LessHotDogs.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && HotDogs > 0)
                {
                    HotDogs = HotDogs - 1;
                    Marketcounter = 0;
                }
                if (MoreHotDogsPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && HotDogPrice >= 0 && HotDogPrice < 50)
                {
                    HotDogPrice = HotDogPrice + 1;
                    Marketcounter = 0;
                }
                if (LessHotDogsPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && HotDogPrice > 0)
                {
                    HotDogPrice = HotDogPrice - 1;
                    Marketcounter = 0;
                }
                ///Increasing HotDogs

                ///Increasing Burgers
                if (MoreBurgers.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Burgers >= 0 && Burgers < TotalBurgers)
                {
                    Burgers = Burgers + 1;
                    Marketcounter = 0;
                }
                if (LessBurgers.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Burgers > 0)
                {
                    Burgers = Burgers - 1;
                    Marketcounter = 0;
                }
                if (MoreBurgersPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && BurgerPrice >= 0 && BurgerPrice < 50)
                {
                    BurgerPrice = BurgerPrice + 1;
                    Marketcounter = 0;
                }
                if (LessBurgersPrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && BurgerPrice > 0)
                {
                    BurgerPrice = BurgerPrice - 1;
                    Marketcounter = 0;
                }
                ///Increasing Burgers

                ///Increasing Poutine
                if (MorePoutine.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Poutine >= 0 && Poutine < TotalPoutine)
                {
                    Poutine = Poutine + 1;
                    Marketcounter = 0;
                }
                if (LessPoutine.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && Poutine > 0)
                {
                    Poutine = Poutine - 1;
                    Marketcounter = 0;
                }
                if (MorePoutinePrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && PoutinePrice >= 0 && PoutinePrice < 50)
                {
                    PoutinePrice = PoutinePrice + 1;
                    Marketcounter = 0;
                }
                if (LessPoutinePrice.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Marketcounter > 20 && PoutinePrice > 0)
                {
                    PoutinePrice = PoutinePrice - 1;
                    Marketcounter = 0;
                }
                ///Increasing Poutine


                if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    Truck = false;
                    Buttons[6].setPosition(10000, 10000);
                    Supplies.setPosition(10000, 10000);
                }

            }
            ///Updates Positions

            ///Updates the X Button
            XButton.setPosition(MainCharacter.getPosition().x + 440, MainCharacter.getPosition().y - 480);
            ///Updates the X Button

            ///Updates Stats
            Moneytext.setString("Money: $ " + to_string(Money));
            MarketText.setString("Market");
            DayText.setString("Day: " + to_string(Day2));
            Supplies.setString("   You have " + to_string(TotalChicken) + " Chicken, " + to_string(TotalHotDogs) + " Hot Dog(s), \n" + to_string(TotalBurgers) + " Burger(s), " + to_string(TotalPoutine) + " Poutine and " + to_string(Plates) + " Plate(s)");
            ChickenText.setString(to_string(Chicken));
            HotDogText.setString(to_string(HotDogs));
            BurgerText.setString(to_string(Burgers));
            PoutineText.setString(to_string(Poutine));
            ChickenPriceText.setString("$" + to_string(ChickenPrice));
            HotDogPriceText.setString("$" + to_string(HotDogPrice));
            BurgerPriceText.setString("$" + to_string(BurgerPrice));
            PoutinePriceText.setString("$" + to_string(PoutinePrice));
            ///Updates Stats

            if (Keyboard::isKeyPressed(Keyboard::Right) == false
                && Keyboard::isKeyPressed(Keyboard::Left) == false
                && Keyboard::isKeyPressed(Keyboard::Up) == false
                && Keyboard::isKeyPressed(Keyboard::Down) == false
                && Keyboard::isKeyPressed(Keyboard::A) == false
                && Keyboard::isKeyPressed(Keyboard::S) == false
                && Keyboard::isKeyPressed(Keyboard::D) == false
                && Keyboard::isKeyPressed(Keyboard::W) == false)
            {
                MCX = 0;
            }
                ///Character Controls
                if (((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && MainCharacter.getPosition().x < 7950)) ///MOVES EVERYTHING TO THE RIGHT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 100;
                        MainCharacter.setPosition(MainCharacter.getPosition().x + 10, MainCharacter.getPosition().y);
                }

                else if (((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && MainCharacter.getPosition().x > 6010 )) ///MOVES EVERYTHING TO THE LEFT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 50;
                        MainCharacter.setPosition(MainCharacter.getPosition().x - 10, MainCharacter.getPosition().y);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && MainCharacter.getPosition().y > -1860)) ///MOVES EVERYTHING UP
                {
                        MCX = MCX + 32;
                        MCY = 150;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 10);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && MainCharacter.getPosition().y < -1150)) ///MOVES EVERYTHING DOWN
                {
                        MCX = MCX + 32;
                        MCY = 0;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y + 10);

                }
                ///Character Controls

            ///Drawing Stuff
            window.draw(Map3);
            window.draw(Stats);
            window.draw(Market);
            window.draw(MarketText);
            window.draw(Moneytext);
            window.draw(StartDay);
            window.draw(StartingDay);
            window.draw(DayText);

            if (MainCharacter.getPosition().y > FoodTruck.getPosition().y)
            {
                window.draw(FoodTruck);
                window.draw(MainCharacter);
            }

            if (MainCharacter.getPosition().y < FoodTruck.getPosition().y)
            {
                window.draw(MainCharacter);
                window.draw(FoodTruck);
            }

            for (int i = 0; i < Customers.size(); i++)
            {
                Customers[i].move(-3, 0);
                if (Customers[i].getPosition().x <= 8500)
                {
                    window.draw(Customers[i]);
                }
                if (Customers[i].getPosition().x <= 6000)
                {
                    Customers.erase(Customers.begin() + i);
                    Clicking.erase(Clicking.begin() + i);
                }
            }
            ///Drawing Stuff

            if (Market.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Truck == false && DayStart == false)
            {
                MarketOpen = true;
            }

            if (FoodTruck.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && MarketOpen == false && Truck == false && DayStart == false)
            {
                window.setMouseCursorVisible(false);
                Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                window.draw(Click);
            }

            else
            {
                window.setMouseCursorVisible(true);
            }

            if (FoodTruck.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && MarketOpen == false && DayStart == false)
            {
                Truck = true;
            }

            if (StartDay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Plates > 0 && MarketOpen == false && Truck == false && DayStart == false)
            {
                Day2 = Day2 + 1;
                DayStart = true;
            }

            if (MarketOpen == true)
            {
                window.draw(Buttons[5]);
                window.draw(XButton);
            }

            if (Truck == true)
            {
                window.draw(Buttons[6]);
                window.draw(XButton);
                window.draw(Supplies);
                window.draw(ChickenText);
                window.draw(HotDogText);
                window.draw(BurgerText);
                window.draw(PoutineText);
                window.draw(ChickenPriceText);
                window.draw(HotDogPriceText);
                window.draw(BurgerPriceText);
                window.draw(PoutinePriceText);
            }

            if (DayStart == true)
            {
                BuyingTime++;
                if (UseOnce == false)
                {
                    MoneyBefore = Money;
                    People = rand()%10 + 7;
                    LightingCounter = 0;
                    for (int i = 0; i < People; i++)
                    {
                        Customers.push_back(Sprite(CustomerTexture, sf::IntRect(CustX, CustY, 32, 32)));
                        Customers.back().setScale(3.75, 3.75);
                        Customers.back().setPosition(9000 + rand()%2000, -1425 + rand()%280);
                        Customers.back().setOrigin(16, 25);
                        Clicking.push_back(bool(false));
                    }
                    UseOnce = true;
                }

                if (Animations%2 == 0)
                {
                    CustX = CustX + 32;
                }
                Animations++;
                if (CustX >= 292)
                {
                    CustX = 196;
                }
                CustY = 32;

                for (int i = 0; i < Customers.size(); i++)
                {
                    ///Buying Food
                    if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                    {
                        window.setMouseCursorVisible(false);
                        Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                        window.draw(Click);
                        ClickingCount = ClickingCount + 1;
                    }
                    if (ClickingCount == 0)
                    {
                        window.setMouseCursorVisible(true);
                    }

                    if (Clicking[i] == false)
                    {
                        if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && BuyingTime > 20)
                        {
                            PriceDiffPoutine = PoutinePrice - 8;
                            PriceDiffChicken = ChickenPrice - 13;
                            PriceDiffHotDogs = HotDogPrice - 16;
                            PriceDiffBurgers = BurgerPrice - 20;
                            FoodTypeChance = rand()%100;
                            ///Poutine
                            if (FoodTypeChance >= 0 && FoodTypeChance < 10)
                            {
                                FoodType = 1;
                            }
                            ///Chicken
                            if (FoodTypeChance >= 10 && FoodTypeChance < 30)
                            {
                                FoodType = 2;
                            }
                            ///HotDog
                            if (FoodTypeChance >= 30 && FoodTypeChance < 60)
                            {
                                FoodType = 3;
                            }
                            ///Burger
                            if (FoodTypeChance >= 60 && FoodType <= 100)
                            {
                                FoodType = 4;
                            }

                            if (FoodType == 1)
                            {
                                if (Poutine >= 1 && Plates >= 1)
                                {
                                    if (PoutinePrice >= 8)
                                    {
                                        if (rand()%100 <= (20 + 100/(1 + PriceDiffPoutine)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (PoutinePrice < 8)
                                    {
                                        if (rand()%100 <= (100 - (10 + 4*PoutinePrice)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (Purchase == true)
                                    {
                                        Money = Money + PoutinePrice;
                                        MoneyMade.push_back(Text("+ $" + to_string(PoutinePrice), f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);

                                        Fading.push_back(int(255));
                                        PeopleBought = PeopleBought + 1;
                                        Plates = Plates - 1;
                                        TotalPoutine = TotalPoutine - 1;
                                    }

                                    if (Purchase == false)
                                    {
                                        MoneyMade.push_back(Text("No Thanks", f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);
                                        Fading.push_back(int(255));
                                    }

                                }

                                else
                                {
                                    MoneyMade.push_back(Text("No Thanks", f1, 30));
                                    MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                    MoneyMade.back().setScale(1.4, 1.4);
                                    Fading.push_back(int(255));
                                }
                            }

                            if (FoodType == 2)
                            {
                                if (Chicken >= 1 && Plates >= 1)
                                {
                                    if (ChickenPrice >= 8)
                                    {
                                        if (rand()%100 <= (20 + 100/(1 + PriceDiffChicken)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (ChickenPrice < 8)
                                    {
                                        if (rand()%100 <= (100 - (10 + 4*ChickenPrice)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (Purchase == true)
                                    {
                                        Money = Money + ChickenPrice;
                                        MoneyMade.push_back(Text("+ $" + to_string(ChickenPrice), f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);

                                        Fading.push_back(int(255));
                                        PeopleBought = PeopleBought + 1;
                                        Plates = Plates - 1;
                                        TotalChicken = TotalChicken - 1;
                                    }

                                    if (Purchase == false)
                                    {
                                        MoneyMade.push_back(Text("No Thanks", f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);
                                        Fading.push_back(int(255));
                                    }
                                }

                                else
                                {
                                    MoneyMade.push_back(Text("No Thanks", f1, 30));
                                    MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                    MoneyMade.back().setScale(1.4, 1.4);
                                    Fading.push_back(int(255));
                                }
                            }

                            if (FoodType == 3)
                            {
                                if (HotDogs >= 1 && Plates >= 1)
                                {
                                    if (HotDogPrice >= 8)
                                    {
                                        if (rand()%100 <= (20 + 100/(1 + PriceDiffHotDogs)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (HotDogPrice < 8)
                                    {
                                        if (rand()%100 <= (100 - (10 + 4*HotDogPrice)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (Purchase == true)
                                    {
                                        Money = Money + HotDogPrice;
                                        MoneyMade.push_back(Text("+ $" + to_string(HotDogPrice), f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);

                                        Fading.push_back(int(255));
                                        PeopleBought = PeopleBought + 1;
                                        Plates = Plates - 1;
                                        TotalHotDogs = TotalHotDogs - 1;
                                    }

                                    if (Purchase == false)
                                    {
                                        MoneyMade.push_back(Text("No Thanks", f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);
                                        Fading.push_back(int(255));
                                    }
                                }

                                else
                                {
                                    MoneyMade.push_back(Text("No Thanks", f1, 30));
                                    MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                    MoneyMade.back().setScale(1.4, 1.4);
                                    Fading.push_back(int(255));
                                }
                            }

                            if (FoodType == 4)
                            {
                                if (Burgers >= 1 && Plates >= 1)
                                {
                                    if (BurgerPrice >= 8)
                                    {
                                        if (rand()%100 <= (20 + 100/(1 + PriceDiffBurgers)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (BurgerPrice < 8)
                                    {
                                        if (rand()%100 <= (100 - (10 + 4*BurgerPrice)))
                                        {
                                            Purchase = true;
                                        }
                                    }
                                    if (Purchase == true)
                                    {
                                        Money = Money + BurgerPrice;
                                        MoneyMade.push_back(Text("+ $" + to_string(BurgerPrice), f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);

                                        Fading.push_back(int(255));
                                        PeopleBought = PeopleBought + 1;
                                        Plates = Plates - 1;
                                        TotalBurgers = TotalBurgers - 1;
                                    }

                                    if (Purchase == false)
                                    {
                                        MoneyMade.push_back(Text("No Thanks", f1, 30));
                                        MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                        MoneyMade.back().setScale(1.4, 1.4);
                                        Fading.push_back(int(255));
                                    }
                                }

                                else
                                {
                                    MoneyMade.push_back(Text("No Thanks", f1, 30));
                                    MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                                    MoneyMade.back().setScale(1.4, 1.4);
                                    Fading.push_back(int(255));
                                }
                            }

                            BuyingTime = 0;
                            Clicking[i] = true;
                            Purchase = false;
                        }
                    }
                    ///Buying Food
                }

                for (int i = 0; i < MoneyMade.size(); i++)
                {
                    MoneyMade[i].setPosition(MoneyMade[i].getPosition().x - 3, MoneyMade[i].getPosition().y - 1);
                    MoneyMade[i].setFillColor(Color(0, 255, 0, Fading[i]));
                    window.draw(MoneyMade[i]);
                    Fading[i] = Fading[i] - 5;

                    if (Fading[i] == 0)
                    {
                        MoneyMade.erase(MoneyMade.begin() + i);
                        Fading.erase(Fading.begin() + i);
                    }
                }

                Lighting.setFillColor(Color(0, 0, 0, LightingCounter));

                if (LightingCounter >= 0 && LightingCounter <= 100 && LightingTimes == false)
                {
                    LightingCounter = LightingCounter + 0.1;

                }

                if (LightingCounter >= 100)
                {
                    LightingTimes = true;
                }

                if (LightingTimes == true)
                {
                    LightingCounter = LightingCounter - 0.1;

                    if (LightingCounter <= 0)
                    {
                        LightingTimes = false;
                    }
                }

                if (Customers.size() <= 0)
                {
                    SalesShow = true;
                    Profits = Money - MoneyBefore;
                    PeopleMissed = People - PeopleBought;
                    CustomersS.setString(to_string(PeopleBought) + " Customers");
                    CustomersL.setString(to_string(PeopleMissed) + " Customers");
                    Profit.setString("$" + to_string(Profits));
                    KarmaMeter = ((PeopleBought - PeopleMissed)/2);
                    Karma.setString(to_string(KarmaMeter));
                    if (Profits < 0)
                    {
                        Profit.setFillColor(Color::Red);
                    }

                    if (Profits > 0)
                    {
                        Profit.setFillColor(Color::Green);
                    }

                    if (KarmaMeter < 0)
                    {
                        Karma.setFillColor(Color::Red);
                    }

                    if (KarmaMeter > 0)
                    {
                        Karma.setFillColor(Color::Green);
                        Karma.setString("+ " + to_string(KarmaMeter));
                    }

                    if (KarmaMeter == 0)
                    {
                        Karma.setFillColor(Color::Blue);
                    }
                }

                if (SalesShow == true)
                {
                    window.draw(Buttons[4]);
                    window.draw(Profit);
                    window.draw(CustomersL);
                    window.draw(CustomersS);
                    window.draw(Karma);
                    window.draw(XButton);
                    if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                    {
                        SalesShow = false;
                        Chicken = 0;
                        HotDogs = 0;
                        Burgers = 0;
                        Poutine = 0;
                        PeopleMissed = 0;
                        PeopleBought = 0;
                        DayStart = false;
                        UseOnce = false;
                        LightingCounter = 0;
                        Lighting.setFillColor(Color(0, 0, 0, LightingCounter));
                    }
                }
            }
        }

        if (DinerTycoon == true)
        {
            ///Updates Positions
            Stats.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 570);
            StartDay.setPosition(MainCharacter.getPosition().x - 790, MainCharacter.getPosition().y - 545); ///790
            Market.setPosition(MainCharacter.getPosition().x + 790, MainCharacter.getPosition().y - 545); ///790
            MarketText.setPosition(MainCharacter.getPosition().x + 750, MainCharacter.getPosition().y - 555); ///734
            StartingDay.setPosition(MainCharacter.getPosition().x - 834, MainCharacter.getPosition().y - 575); ///834
            Moneytext.setPosition(MainCharacter.getPosition().x - 105, MainCharacter.getPosition().y - 565);
            DayText.setPosition(MainCharacter.getPosition().x - 700, MainCharacter.getPosition().y - 565);
            HomeButton.setPosition(MainCharacter.getPosition().x + 630, MainCharacter.getPosition().y - 545);
            HomeButtonText.setPosition(MainCharacter.getPosition().x + 584, MainCharacter.getPosition().y - 555);

            if (MarketOpen == true)
            {
                Buttons[7].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                Item1.setPosition(MainCharacter.getPosition().x - 280, MainCharacter.getPosition().y + 75);
                Item2.setPosition(MainCharacter.getPosition().x + 00, MainCharacter.getPosition().y + 75);
                Item3.setPosition(MainCharacter.getPosition().x + 280, MainCharacter.getPosition().y + 75);
                CookbookClose.setPosition(MainCharacter.getPosition().x + 340, MainCharacter.getPosition().y - 390);
                FoodRight.setPosition(MainCharacter.getPosition().x + 450, MainCharacter.getPosition().y + 20);
                FoodLeft.setPosition(MainCharacter.getPosition().x - 450, MainCharacter.getPosition().y + 20);
            }

            if (SalesShow == true)
            {
                Buttons[4].setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y);
                CustomersS.setPosition(MainCharacter.getPosition().x - 80, MainCharacter.getPosition().y - 240);
                CustomersL.setPosition(MainCharacter.getPosition().x + 110, MainCharacter.getPosition().y - 80);
                Profit.setPosition(MainCharacter.getPosition().x - 60, MainCharacter.getPosition().y + 240);
                Karma.setPosition(MainCharacter.getPosition().x - 200, MainCharacter.getPosition().y + 82);
            }

            ///Updates the X Button
            XButton.setPosition(MainCharacter.getPosition().x + 440, MainCharacter.getPosition().y - 480);
            ///Updates the X Button

            window.setMouseCursorVisible(true);


            for (int i = 0; i < Customers.size(); i++)
            {

            }

            ///Updates Positions

            ///Updates Stats
            Moneytext.setString("Money: $ " + to_string(Money));
            DayText.setString("Day: " + to_string(Day3));
            MarketText.setString("Cook");
            ///Updates Stats

            window.draw(Map4);

            if (Keyboard::isKeyPressed(Keyboard::Right) == false
                && Keyboard::isKeyPressed(Keyboard::Left) == false
                && Keyboard::isKeyPressed(Keyboard::Up) == false
                && Keyboard::isKeyPressed(Keyboard::Down) == false
                && Keyboard::isKeyPressed(Keyboard::A) == false
                && Keyboard::isKeyPressed(Keyboard::S) == false
                && Keyboard::isKeyPressed(Keyboard::D) == false
                && Keyboard::isKeyPressed(Keyboard::W) == false)
            {
                MCX = 0;
            }
                ///Character Controls
                if (((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && MainCharacter.getPosition().x < -6800)) ///MOVES EVERYTHING TO THE RIGHT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 100;
                        MainCharacter.setPosition(MainCharacter.getPosition().x + 10, MainCharacter.getPosition().y);
                }

                else if (((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && MainCharacter.getPosition().x > -7210 )) ///MOVES EVERYTHING TO THE LEFT
                {
                        MCX = MCX + 32;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MCY = 50;
                        MainCharacter.setPosition(MainCharacter.getPosition().x - 10, MainCharacter.getPosition().y);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && MainCharacter.getPosition().y > -1860)) ///MOVES EVERYTHING UP
                {
                        MCX = MCX + 32;
                        MCY = 150;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y - 10);

                }

                else if (((Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) && MainCharacter.getPosition().y < -1480)) ///MOVES EVERYTHING DOWN
                {
                        MCX = MCX + 32;
                        MCY = 0;
                        if (MCX >= 128)
                        {
                            MCX = 0;
                        }
                        MainCharacter.setPosition(MainCharacter.getPosition().x, MainCharacter.getPosition().y + 10);

                }
                ///Character Controls

            window.draw(MainCharacter);
            window.draw(Stats);
            window.draw(Moneytext);
            window.draw(DayText);
            window.draw(StartDay);
            window.draw(StartingDay);
            window.draw(Market);
            window.draw(MarketText);
            window.draw(HomeButton);
            window.draw(HomeButtonText);

            if (Market.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
            {
                MarketOpen = true;
            }

            if (StartDay.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
            {
                DayStart = true;
            }

            if (DayStart == true)
            {
                if (UseOnce == false)
                {
                    MoneyBefore = Money;
                    People = 1;
                    Day3 = Day3 + 1;
                    for (int i = 0; i < People; i++)
                    {
                        Customers.push_back(Sprite(CustomerTexture, sf::IntRect(CustX, CustY, 32, 32)));
                        Customers.back().setScale(3.75, 3.75);
                        Customers.back().setPosition(-7000, -800);
                        Customers.back().setOrigin(16, 25);
                        Clicking.push_back(bool(false));
                        FoodOrder.push_back(int(rand()%11));
                    }
                    UseOnce = true;
                }

            ///Customers
            for (int i = 0; i < Customers.size(); i++)
            {
                window.draw(Customers[i]);
                if (Ordered == false)
                {
                    if (Customers[i].getPosition().y > -1200)
                    {
                        Customers[i].move(0, -2);
                        if (Animations%2 == 0)
                        {
                            CustX = CustX + 32;
                        }
                        Animations++;
                        if (CustX >= 292)
                        {
                            CustX = 196;
                        }
                        CustY = 96;
                    }
                }

                if (Customers[i].getPosition().y <= -1200)
                {
                    ReadyToOrder = true;
                }

                if (ReadyToOrder == true)
                {
                    if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                    {
                        window.setMouseCursorVisible(false);
                        Click.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                        window.draw(Click);
                        ClickingCount = ClickingCount + 1;
                    }
                    if (ClickingCount == 0)
                    {
                        window.setMouseCursorVisible(true);
                    }

                    if (Clicking[i] == false)
                    {
                        BuyingTime++;
                        if (Customers[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && BuyingTime > 20)
                        {
                            Ordered = true;
                            BuyingTime = 0;
                        }

                        Clicking[i] == true;
                    }
                    ///Buying Food

                    if (Ordered == true)
                    {
                        if (Customers[i].getPosition().y <= -1200 && Customers[i].getPosition().x > -7700)
                        {
                            Customers[i].move(-2, 0);
                            if (Animations%2 == 0)
                            {
                                CustX = CustX + 32;
                            }
                            Animations++;
                            if (CustX >= 292)
                            {
                                CustX = 196;
                            }
                            CustY = 32;
                        }

                        if (Foods[FoodOrder[i]].Stock > 0 && Customers[i].getPosition().x <= -7700)
                        {
                            Foods[FoodOrder[i]].Stock = Foods[FoodOrder[i]].Stock - 1;
                            Ordered = false;
                            Purchased = true;
                            MoneyMade.push_back(Text("+ $" + to_string(Foods[FoodOrder[i]].Price), f1, 30));
                            MoneyMade.back().setPosition(Customers[i].getPosition().x, Customers[i].getPosition().y);
                            MoneyMade.back().setScale(1.4, 1.4);

                            Fading.push_back(int(255));
                            PeopleBought = PeopleBought + 1;
                            Money = Money + Foods[FoodOrder[i]].Price;
                        }
                    }

                    if (Purchased == true)
                    {
                        Customers[i].move(0, -2);
                        if (Animations%2 == 0)
                        {
                            CustX = CustX + 32;
                        }
                        Animations++;
                        if (CustX >= 292)
                        {
                            CustX = 196;
                        }
                        CustY = 96;

                        if (Customers[i].getPosition().y < -1800)
                        {
                            Customers.erase(Customers.begin() + i);
                        }
                    }
                }

                ///When the Day Ends
                if (Customers.size() <= 0)
                {
                    SalesShow = true;
                    Profits = Money - MoneyBefore;
                    PeopleMissed = People - PeopleBought;
                    CustomersS.setString(to_string(PeopleBought) + " Customers");
                    CustomersL.setString(to_string(PeopleMissed) + " Customers");
                    Profit.setString("$" + to_string(Profits));
                    KarmaMeter = ((PeopleBought - PeopleMissed)/2);
                    Karma.setString(to_string(KarmaMeter));
                    if (Profits < 0)
                    {
                        Profit.setFillColor(Color::Red);
                    }

                    if (Profits > 0)
                    {
                        Profit.setFillColor(Color::Green);
                    }

                    if (KarmaMeter < 0)
                    {
                        Karma.setFillColor(Color::Red);
                    }

                    if (KarmaMeter > 0)
                    {
                        Karma.setFillColor(Color::Green);
                        Karma.setString("+ " + to_string(KarmaMeter));
                    }

                    if (KarmaMeter == 0)
                    {
                        Karma.setFillColor(Color::Blue);
                    }
                }

                if (SalesShow == true)
                {
                    window.draw(Buttons[4]);
                    window.draw(Profit);
                    window.draw(CustomersL);
                    window.draw(CustomersS);
                    window.draw(Karma);
                    window.draw(XButton);
                    if (XButton.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                    {
                        SalesShow = false;
                        PeopleMissed = 0;
                        PeopleBought = 0;
                        DayStart = false;
                        UseOnce = false;

                        for (int i = 0; i < Foods.size(); i++)
                        {
                            Foods[i].Stock = 0;
                        }
                    }
                }
                ///When the Day Ends
            }
            ///Customers
            }

            ///Cookbook
            if (MarketOpen == true)
            {
                Marketcounter++;
                window.draw(Buttons[7]);

                if (CookbookClose.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
                {
                    MarketOpen = false;
                }

                if (FoodRight.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page < 5 && Marketcounter > 20)
                {
                    Page = Page + 1;
                    Marketcounter = 0;
                }
                if (FoodLeft.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20)
                {
                    Page = Page - 1;
                    Marketcounter = 0;
                }

                ///Switches the pages
                if (Page == 1)
                {
                    Buttons[7].setTexture(&CookbookInstructions);
                }

                if (Page == 2)
                {
                    Buttons[7].setTexture(&CookbookBreakfast);
                    ///Crepe
                    if (Item1.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[0].StartCooking == false)
                    {
                        Foods[0].StartCooking = true;
                    }
                    ///Crepe

                    ///Waffles
                    if (Item2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[1].StartCooking == false)
                    {
                        Foods[1].StartCooking = true;

                    }
                    ///Waffles

                    ///Pancakes
                    if (Item3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[2].StartCooking == false)
                    {
                        Foods[2].StartCooking = true;

                    }
                    ///Pancakes
                }

                if (Page == 3)
                {
                    Buttons[7].setTexture(&CookbookLunch);
                    ///Pizza
                    if (Item1.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[3].StartCooking == false)
                    {
                        Foods[3].StartCooking = true;

                    }
                    ///Pizza

                    ///Taco
                    if (Item2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[4].StartCooking == false)
                    {
                        Foods[4].StartCooking = true;

                    }
                    ///Taco

                    ///Sub
                    if (Item3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[5].StartCooking == false)
                    {
                        Foods[5].StartCooking = true;

                    }
                    ///Sub
                }

                if (Page == 4)
                {
                    Buttons[7].setTexture(&CookbookDinner);
                    ///Burger
                    if (Item1.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[6].StartCooking == false)
                    {
                        Foods[6].StartCooking = true;

                    }
                    ///Burger

                    ///Pasta
                    if (Item2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[7].StartCooking == false)
                    {
                        Foods[7].StartCooking = true;

                    }
                    ///Pasta

                    ///Steak
                    if (Item3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[8].StartCooking == false)
                    {
                        Foods[8].StartCooking = true;

                    }
                    ///Steak
                }

                if (Page == 5)
                {
                    Buttons[7].setTexture(&CookbookDessert);
                    ///Creme
                    if (Item1.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[9].StartCooking == false)
                    {
                        Foods[9].StartCooking = true;

                    }
                    ///Creme

                    ///IceCream
                    if (Item2.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[10].StartCooking == false)
                    {
                        Foods[10].StartCooking = true;

                    }
                    ///IceCream

                    ///Cookie
                    if (Item3.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left) && Page > 1 && Marketcounter > 20 && Foods[11].StartCooking == false)
                    {
                        Foods[11].StartCooking = true;

                    }
                    ///Cookie
                }
                ///Switches the pages
            }
            ///Cookbook

            ///Makes The Food
            for (int i = 0; i < Foods.size(); i++)
            {
                if (Foods[i].StartCooking == true)
                {
                    Foods[i].CookTime = Foods[i].CookTime - 0.016666666;
                    cout << Foods[i].CookTime << endl;
                    if (Foods[i].CookTime <= 0)
                    {
                        Foods[i].Stock = Foods[i].Stock + 1;
                        Foods[i].StartCooking = false;
                    }
                }

            }
            ///Makes the Food


            ///Makes the Money
            for (int i = 0; i < MoneyMade.size(); i++)
            {
                MoneyMade[i].setPosition(MoneyMade[i].getPosition().x - 3, MoneyMade[i].getPosition().y - 1);
                MoneyMade[i].setFillColor(Color(0, 255, 0, Fading[i]));
                window.draw(MoneyMade[i]);
                Fading[i] = Fading[i] - 3;

                if (Fading[i] == 0)
                {
                    MoneyMade.erase(MoneyMade.begin() + i);
                    Fading.erase(Fading.begin() + i);
                }
            }
            ///Makes the Money

        }

        for (int i = 0; i < FoodOrder.size(); i++)
        {
            cout << FoodOrder[i] << endl;
        }
        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
