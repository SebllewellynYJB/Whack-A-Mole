
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  in_menu = true;
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  menu_text.setString("Welcome to Whack a mole");
  menu_text.setFont(font);
  menu_text.setCharacterSize(60);
  menu_text.setFillColor(sf::Color(100, 70, 0));
  menu_text.setPosition(140,50);

  play_option.setString("Play");
  play_option.setFont(font);
  play_option.setCharacterSize(40);
  play_option.setFillColor(sf::Color(0, 100, 0));
  play_option.setPosition(280,240);

  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(40);
  quit_option.setFillColor(sf::Color(100, 0, 0));
  quit_option.setPosition(680,240);

  // init sprite
  if (!background_texture.loadFromFile("Data/Images/background.png"))
  {
    std::cout << "background texture did not load \n";
  }
  background.setTexture(background_texture);
  if (!bird_texture.loadFromFile("Data/Images/bird.png"))
  {
    std::cout <<"Bird did not load \n";
  }
  bird.setTexture(bird_texture);
  bird.setPosition(100,200);
  bird.setScale(0.5,0.5);
  // init text
  title_text.setString("Whack-a-mole");
  title_text.setFont(font);
  title_text.setCharacterSize(100);
  title_text.setFillColor(sf::Color(255,255,255,128));
  title_text.setPosition(100,200);
  return true;
}

void Game::update(float dt)
{
  bird.move(1.0f * speed * dt, 0);
  // Detect whether the ball has hit the wall
  if ((bird.getPosition().x > (window.getSize().x - bird.getGlobalBounds().width)) ||
      (bird.getPosition().x < 0))
  {
    bird.setTextureRect(sf::IntRect(0, 0, bird.getLocalBounds().width, bird.getLocalBounds().height));
    reverse = !reverse;
  }
  if (reverse)
  {
    // reverse the movement of the ball
    bird.move(-2.0f * speed * dt,0);
    bird.setTextureRect(sf::IntRect(bird.getLocalBounds().width,
                                    0,-bird.getLocalBounds().width,bird.getLocalBounds().height));
  }

}


void Game::render()
{
  if (in_menu)
  {
    window.draw(menu_text);
    window.draw(play_option);
    window.draw(quit_option);
  }
  else
  {
    window.draw(background);
    window.draw(title_text);
    window.draw(bird);
  }
}

void Game::mouseClicked(sf::Event event)
{

  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    // left mouse button is pressed: shoot
  }
  // check if in bounds of bird Sprite
  if (collisionCheck(click, bird))
  {
   // update(event.mouseButton.button);
    bird.setPosition(100,200);
  }
}

void Game::keyPressed(sf::Event event)
{
  if (
    (event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play_option.setString("> Play <");
      quit_option.setString("Quit");
    }
    else
    {
      play_option.setString("Play");
      quit_option.setString("> Quit <");
    }
  }
  else if (event.key.code == sf::Keyboard::Enter)
{
  if (play_selected)
  {
    in_menu = false;
  }
  else
  {
    window.close();
  }
}
if (event.key.code == sf::Keyboard::Escape)
{
  window.close();
}
}


bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
sprite.getLocalBounds().width;


  if (click.x = true)
  {
    sprite.getPosition().x / 2 ,sprite.getGlobalBounds().width / 2;
  }
  if(click.y = true)
  {
    sprite.getPosition().y / 2,sprite.getGlobalBounds().height / 2;
  }
  return true;
}

void Game::spawn()
{
  return spawn();
}
