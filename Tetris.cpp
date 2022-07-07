#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
using namespace sf;

const int M = 20;
const int N = 10;

int place[M][N] = { 0 };

struct Point
{
    int x, y;
}
a[4], b[4];

int figures[7][4] =
{
    1,3,5,7, // Прямая 
    2,4,5,7, // Зиг-заг 1
    3,5,4,6, // Зиг-заг 2
    3,5,4,7, // T
    2,3,5,7, // Угол 1
    3,5,7,6, // Угол 2
    2,3,4,5, // Квадрат
};

bool Check()
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M)
        {
            return 0;
        }
        else if (place[a[i].y][a[i].x])
        {
            return 0;
        }
    }
    return 1;
}

int CheckLine(int& score) 
{
    int k = M - 1;
    for (int i = M - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (place[i][j])
            {
                count++;
            }
            place[k][j] = place[i][j];
        }
        if (count < N)
        {
            k--;
        }
        else
        {
            score += 100;
        }
    }
    return score;
}


int main()
{
    srand(time(0));

    int dx = 0;
    bool f = 0;
    bool end = 0;
    int score = 0;
    int colorNum = 1;
    float timer = 0;
    float delay = 0.3;
    int sec = 0;
    int min = 0;
    float time = 0;

    Font font;
    font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

    RenderWindow window(VideoMode(380, 490), "Tetris!");

    Texture t1, t2, t3, t4, t5, t6, t7;
    t1.loadFromFile("resources/title.png");
    t2.loadFromFile("resources/back1.png");
    t3.loadFromFile("resources/rama.png");
    t4.loadFromFile("resources/over.png");
    t5.loadFromFile("resources/restart.png");
    t6.loadFromFile("resources/backover.png");
    t7.loadFromFile("resources/result.png");
    Sprite s(t1), background(t2), frame(t3), over(t4), restart(t5), backover(t6), result(t7);

    // Музыка
    Music music;
    music.openFromFile("resources/OST.ogg");
    music.setLoop(true);
    music.play();

    // Время
    Clock clock;
    Clock clock1;

    // Шрифт
    Text timeShow; // Время
    timeShow.setFont(font);
    Text timeText; // Надпись Time
    timeText.setFont(font);
    Text scoreText; // Счетчик очков
    scoreText.setFont(font);

    while (window.isOpen())
    {
        
        if(end == 0)
        {
            // Настройка вывода времени
            timeShow.setCharacterSize(30);
            timeShow.setFillColor(Color::White);
            timeShow.setStyle(Text::Bold);
            timeShow.setPosition(265, 100);

            // Настройка вывода надписи Time
            timeText.setCharacterSize(26);
            timeText.setFillColor(Color::White);
            timeText.setPosition(273, 63);

            // Настройка вывода очков
            scoreText.setCharacterSize(20);
            scoreText.setFillColor(Color::White);
            scoreText.setPosition(77, 420);

            window.clear(Color::White);
            time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            sec = clock1.getElapsedTime().asSeconds();

            // Вывод таймера
            std::string userTime = ((min < 10) ? "0" : "") + std::to_string(min) + ":" + ((sec < 10) ? "0" : "") + std::to_string(sec);
            timeShow.setString(userTime);
         
            if (sec == 60)
            {
                min += 1;
                clock1.restart();
            }

            // Вывод надписи Time
            std::string userTime1 = "Time";
            timeText.setString(userTime1);

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                }
                if (e.type == Event::KeyPressed)
                {
                    if (e.key.code == Keyboard::Up)
                    {
                        f = true;
                    }
                    else if (e.key.code == Keyboard::Left)
                    {
                        dx = -1;
                    }
                    else if (e.key.code == Keyboard::Right)
                    {
                        dx = 1;
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                delay = 0.05;
            }

            // Передвижение
            for (int i = 0; i < 4; i++)
            {
                b[i] = a[i];
                a[i].x += dx;
            }
            if (!Check())
            {
                for (int i = 0; i < 4; i++)
                {
                    a[i] = b[i];
                }
            }

            // Поворот
            if (f)
            {
                Point p = a[1];
                for (int i = 0; i < 4; i++)
                {
                    int x = a[i].y - p.y;
                    int y = a[i].x - p.x;
                    a[i].x = p.x - x;
                    a[i].y = p.y + y;
                }
                if (!Check())
                {
                    for (int i = 0; i < 4; i++)
                    {
                        a[i] = b[i];
                    }
                }

            }


            if (timer > delay)
            {
                for (int i = 0; i < 4; i++)
                {
                    b[i] = a[i];
                    a[i].y += 1;
                }
                if (!Check())
                {
                    for (int i = 0; i < 4; i++)
                    {
                        place[b[i].y][b[i].x] = colorNum;
                    }
                    colorNum = 1 + rand() % 7;
                    int n = rand() % 7;
                    for (int i = 0; i < 4; i++)
                    {
                        a[i].x = figures[n][i] % 2;
                        a[i].y = figures[n][i] / 2;
                    }
                }
                if (!Check()) // Завершение игры
                {
                    end = 1;
                }
                timer = 0;
            }

            CheckLine(score);

            dx = 0;
            f = 0;
            delay = 0.3;

            // Зарисовка
            window.clear(Color::White);
            window.draw(background);
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (place[i][j] == 0)
                    {
                        continue;
                    }
                    s.setTextureRect(IntRect(place[i][j] * 18, 0, 18, 18));
                    s.setPosition(j * 18, i * 18);
                    s.move(27, 31);
                    window.draw(s);
                }
                for (int i = 0; i < 4; i++)
                {
                    s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                    s.setPosition(a[i].x * 18, a[i].y * 18);
                    s.move(27, 31);
                    window.draw(s);
                }
            }

            // Вывод очков
            std::string userScore = "Score: " + std::to_string(score);
            scoreText.setString(userScore);

            window.draw(timeText);
            window.draw(scoreText);
            window.draw(timeShow);
            window.draw(frame);
        }
        else // Проигрыш 
        {
            music.pause();
            window.clear(Color::White);
            window.draw(backover);
            over.setPosition(90, 100);
            window.draw(over);
            restart.setPosition(20, 210);
            window.draw(restart);
            result.setPosition(65, 220);
            window.draw(result);
            std::string userTime1 = "Time: ";
            timeText.setCharacterSize(20);
            timeText.setString(userTime1);
            timeText.setPosition(130, 293);
            window.draw(timeText);
            timeShow.setCharacterSize(20);
            timeShow.setPosition(185, 295);
            timeShow.setStyle(Text::Bold == 0);
            window.draw(timeShow);
            scoreText.setCharacterSize(20);
            scoreText.setPosition(120, 323);
            window.draw(scoreText);
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                dx = 0;
                f = 0;
                score = 0;
                colorNum = 1;
                timer = 0;
                delay = 0.3;
                sec = 0;
                min = 0;
                time = 0;
                clock1.restart();
                for (int i = M - 1; i > 0; i--)
                {
                    for (int j = 0; j < N; j++)
                    {
                        place[i][j] = 0;
                    }
                }
                end = 0;
                music.play();
            }
        }
        window.display();
    }
    return 0;
}
