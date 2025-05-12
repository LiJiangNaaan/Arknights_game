#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Character.h"
#include "CharacterChongyue.h"
#include <optional>

using namespace sf;
using namespace std;




//int main() {
//    RenderWindow window(VideoMode({ 800, 600 }), "animation");
//
//    float groundY = 600.0f * 2.0f / 5.0f;
//
//    Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("graphics/background.png")) {
//        cerr << "Failed to load background!" << endl;
//    }
//    Sprite backgroundSprite(backgroundTexture);
//    backgroundSprite.setScale(
//        { 800.0f / backgroundTexture.getSize().x,
//          600.0f / backgroundTexture.getSize().y }
//    );
//
//    Character chenCharacter("graphics/jieyun_rightmove/images/jieyun",
//        "graphics/jieyun_leftmove/images/jieyun",
//        "graphics/jieyun_rightattack/images/jieyun","graphics/jieyun_leftattack/images/jieyun",
//        60, 60);
//    Vector2f chenPos(200.0f, groundY);
//
//    CharacterChongyue chongyue("graphics/chongyue_rightmove/images/chongyue",
//        "graphics/chongyue_leftmove/images/chongyue",
//        "graphics/chongyue_rightattack/images/chongyue","graphics/chongyue_rightattack/images/chongyue",
//        60, 60);
//    Vector2f chongyuePos(400.0f, groundY);
//
//    bool isMoving1 = false, isMoving2 = false;
//    bool moveLeft1 = false, moveLeft2 = false;
//    bool isAttacking1 = false, isAttacking2 = false;
//    bool attacked1 = false, attacked2 = false; // 是否已经造成一次伤害
//    bool isJumping1 = false, isJumping2 = false;
//    float velocityY1 = 0.0f, velocityY2 = 0.0f;
//    float jumpCooldown1 = 0.0f, jumpCooldown2 = 0.0f;
//
//    float gravity = 3000.0f; // 重力
//
//    int chenHP = 100;
//    int chongyueHP = 100;
//    const int hp_max = 100;
//    const int damage = 50;
//
//    RectangleShape chenHPBar(Vector2f(200, 20));
//    RectangleShape chongyueHPBar(Vector2f(200, 20));
//    chenHPBar.setFillColor(Color::Green);
//    chenHPBar.setPosition({ 10, 10 });
//    chongyueHPBar.setFillColor(Color::Green);
//    chongyueHPBar.setPosition({ 590, 10 });
//
//
//    Clock clock;
//
//    while (window.isOpen()) {
//        Time dt = clock.restart();
//        float deltaTime = dt.asSeconds();
//
//        while (const optional event = window.pollEvent()) {
//            if (event->is<Event::Closed>()) {
//                window.close();
//            }
//        }
//
//        // 玩家1 控制
//        Vector2f lastPos1 = chenPos;
//        isMoving1 = false;
//        if (!isAttacking1) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
//                chenPos.x -= 0.2f;
//                isMoving1 = true;
//                moveLeft1 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
//                chenPos.x += 0.2f;
//                isMoving1 = true;
//                moveLeft1 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::X)) {
//                isAttacking1 = true;
//            }
//        }
//        if (jumpCooldown1 > 0.0f) jumpCooldown1 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::Space) && !isJumping1 && jumpCooldown1 <= 0.0f) {
//            isJumping1 = true;
//            jumpCooldown1 = 0.6f;
//            float jumpHeight = chenCharacter.getSize().y * 0.9f;
//            velocityY1 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping1) {
//            velocityY1 += gravity * deltaTime;
//            chenPos.y += velocityY1 * deltaTime;
//            if (chenPos.y >= groundY) {
//                chenPos.y = groundY;
//                velocityY1 = 0.0f;
//                isJumping1 = false;
//            }
//        }
//
//        // 玩家2 控制
//        Vector2f lastPos2 = chongyuePos;
//        isMoving2 = false;
//        if (!isAttacking2) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
//                chongyuePos.x -= 0.2f;
//                isMoving2 = true;
//                moveLeft2 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
//                chongyuePos.x += 0.2f;
//                isMoving2 = true;
//                moveLeft2 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
//                isAttacking2 = true;
//            }
//        }
//        if (jumpCooldown2 > 0.0f) jumpCooldown2 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::W) && !isJumping2 && jumpCooldown2 <= 0.0f) {
//            isJumping2 = true;
//            jumpCooldown2 = 0.6f;
//            float jumpHeight = chongyue.getSize().y * 0.9f;
//            velocityY2 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping2) {
//            velocityY2 += gravity * deltaTime;
//            chongyuePos.y += velocityY2 * deltaTime;
//            if (chongyuePos.y >= groundY) {
//                chongyuePos.y = groundY;
//                velocityY2 = 0.0f;
//                isJumping2 = false;
//            }
//        }
//
//        // 边界限制
//        Vector2f size1 = chenCharacter.getSize();
//        Vector2f size2 = chongyue.getSize();
//        chenPos.x = std::clamp(chenPos.x, 0.0f, 800 - size1.x);
//        chongyuePos.x = std::clamp(chongyuePos.x, 0.0f, 800 - size2.x);
//
//        float speed1 = abs(chenPos.x - lastPos1.x);
//        float speed2 = abs(chongyuePos.x - lastPos2.x);
//
//        chenCharacter.update(deltaTime, isMoving1, moveLeft1, isAttacking1, speed1);
//        chongyue.update(deltaTime, isMoving2, moveLeft2, isAttacking2, speed2);
//
//        // 攻击判定与扣血
//        
//
//
//
//
//
//
//
//        chenCharacter.setPosition(chenPos.x, chenPos.y);
//        chongyue.setPosition(chongyuePos.x, chongyuePos.y);
//
//        // 渲染
//        window.clear();
//        window.draw(backgroundSprite);
//        chenCharacter.draw(window);
//        chongyue.draw(window);
//        window.display();
//    }
//}
//int main() {
//    RenderWindow window(VideoMode({ 800, 600 }), "animation");
//
//    float groundY = 600.0f * 2.0f / 5.0f;
//
//    Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("graphics/background.png")) {
//        cerr << "Failed to load background!" << endl;
//    }
//    Sprite backgroundSprite(backgroundTexture);
//    backgroundSprite.setScale(
//        { 800.0f / backgroundTexture.getSize().x,
//          600.0f / backgroundTexture.getSize().y }
//    );
//
//    Character chenCharacter("graphics/jieyun_rightmove/images/jieyun",
//        "graphics/jieyun_leftmove/images/jieyun",
//        "graphics/jieyun_rightattack/images/jieyun", "graphics/jieyun_leftattack/images/jieyun",
//        60, 60);
//    Vector2f chenPos(200.0f, groundY);
//
//    CharacterChongyue chongyue("graphics/chongyue_rightmove/images/chongyue",
//        "graphics/chongyue_leftmove/images/chongyue",
//        "graphics/chongyue_rightattack/images/chongyue", "graphics/chongyue_leftattack/images/chongyue",
//        60, 60);
//    Vector2f chongyuePos(400.0f, groundY);
//           
//    bool isMoving1 = false, isMoving2 = false;
//    bool moveLeft1 = false, moveLeft2 = false;
//    bool isAttacking1 = false, isAttacking2 = false;
//    bool isNormalAttacking1 = false, isNormalAttacking2 = false;
//    bool isJumping1 = false, isJumping2 = false;
//    float velocityY1 = 0.0f, velocityY2 = 0.0f;
//    float jumpCooldown1 = 0.0f, jumpCooldown2 = 0.0f;
//
//    float gravity = 3000.0f;
//
//    Clock clock;
//
//    while (window.isOpen()) {
//        Time dt = clock.restart();
//        float deltaTime = dt.asSeconds();
//
//        while (const optional event = window.pollEvent()) {
//            if (event->is<Event::Closed>()) {
//                window.close();
//            }
//        }
//
//        // 玩家1 控制
//        Vector2f lastPos1 = chenPos;
//        isMoving1 = false;
//        if (!isAttacking1 && !isNormalAttacking1) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
//                chenPos.x -= 0.2f;
//                isMoving1 = true;
//                moveLeft1 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
//                chenPos.x += 0.2f;
//                isMoving1 = true;
//                moveLeft1 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::X)) {
//                isAttacking1 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::C) && !isJumping1) {
//                isNormalAttacking1 = true;
//            }
//        }
//
//        if (jumpCooldown1 > 0.0f) jumpCooldown1 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::Space) && !isJumping1 && jumpCooldown1 <= 0.0f) {
//            isJumping1 = true;
//            jumpCooldown1 = 0.6f;
//            float jumpHeight = chenCharacter.getSize().y * 0.9f;
//            velocityY1 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping1) {
//            velocityY1 += gravity * deltaTime;
//            chenPos.y += velocityY1 * deltaTime;
//            if (chenPos.y >= groundY) {
//                chenPos.y = groundY;
//                velocityY1 = 0.0f;
//                isJumping1 = false;
//            }
//        }
//
//        // 玩家2 控制
//        Vector2f lastPos2 = chongyuePos;
//        isMoving2 = false;
//        if (!isAttacking2 && !isNormalAttacking2) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
//                chongyuePos.x -= 0.2f;
//                isMoving2 = true;
//                moveLeft2 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
//                chongyuePos.x += 0.2f;
//                isMoving2 = true;
//                moveLeft2 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
//                isAttacking2 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::E) && !isJumping2) {
//                isNormalAttacking2 = true;
//            }
//        }
//
//        if (jumpCooldown2 > 0.0f) jumpCooldown2 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::W) && !isJumping2 && jumpCooldown2 <= 0.0f) {
//            isJumping2 = true;
//            jumpCooldown2 = 0.6f;
//            float jumpHeight = chongyue.getSize().y * 0.9f;
//            velocityY2 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping2) {
//            velocityY2 += gravity * deltaTime;
//            chongyuePos.y += velocityY2 * deltaTime;
//            if (chongyuePos.y >= groundY) {
//                chongyuePos.y = groundY;
//                velocityY2 = 0.0f;
//                isJumping2 = false;
//            }
//        }
//        bool normalAttack1 = false, normalAttack2 = false;
//        if (Keyboard::isKeyPressed(Keyboard::Key::C)) {
//            normalAttack1 = true;
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
//            normalAttack2 = true;
//        }
//
//        chenCharacter.update(deltaTime, isMoving1, moveLeft1, isAttacking1, isNormalAttacking1, abs(chenPos.x - lastPos1.x));
//        chongyue.update(deltaTime, isMoving2, moveLeft2, isAttacking2, isNormalAttacking2, abs(chongyuePos.x - lastPos2.x));
//
//        chenCharacter.setPosition(chenPos.x, chenPos.y);
//        chongyue.setPosition(chongyuePos.x, chongyuePos.y);
//
//        window.clear();
//        window.draw(backgroundSprite);
//        chenCharacter.draw(window);
//        chongyue.draw(window);
//        window.display();
//    }
//}

//int main() {
//    RenderWindow window(VideoMode({ 800, 600 }), "animation");
//
//    float groundY = 600.0f * 2.0f / 5.0f;
//
//    Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("graphics/background.png")) {
//        cerr << "Failed to load background!" << endl;
//    }
//    Sprite backgroundSprite(backgroundTexture);
//    backgroundSprite.setScale(
//        { 800.0f / backgroundTexture.getSize().x,
//          600.0f / backgroundTexture.getSize().y }
//    );
//
//    Character chenCharacter(
//        "graphics/jieyun_rightmove/images/jieyun",
//        "graphics/jieyun_leftmove/images/jieyun",
//        "graphics/jieyun_rightattack/images/jieyun",
//        "graphics/jieyun_leftattack/images/jieyun",
//        "graphics/jieyun_na_right/jieyun",
//        "graphics/jieyun_na_left/jieyun",
//        60, 60, 7);
//
//    CharacterChongyue chongyue(
//        "graphics/chongyue_rightmove/images/chongyue",
//        "graphics/chongyue_leftmove/images/chongyue",
//        "graphics/chongyue_rightattack/images/chongyue",
//        "graphics/chongyue_leftattack/images/chongyue",
//        "graphics/chongyue_na_right/chongyue",
//        "graphics/chongyue_na_left/chongyue",
//        60, 60, 7);
//
//    Vector2f chenPos(200.0f, groundY);
//    Vector2f chongyuePos(400.0f, groundY);
//
//    bool isMoving1 = false, isMoving2 = false;
//    bool moveLeft1 = false, moveLeft2 = false;
//    bool isAttacking1 = false, isAttacking2 = false;
//    bool normalAttack1 = false, normalAttack2 = false;
//    bool isJumping1 = false, isJumping2 = false;
//    float velocityY1 = 0.0f, velocityY2 = 0.0f;
//    float jumpCooldown1 = 0.0f, jumpCooldown2 = 0.0f;
//    float gravity = 3000.0f;
//
//    Texture chenHeadTexture, chongyueHeadTexture;
//    if (!chenHeadTexture.loadFromFile("graphics/jieyun.jpg") ||
//        !chongyueHeadTexture.loadFromFile("graphics/chongyue.jpg")) {
//        cerr << "Failed to load head images!" << endl;
//        return 1;
//    }
//    Sprite chenHead(chenHeadTexture), chongyueHead(chongyueHeadTexture);
//    chenHead.setScale({ 0.6f, 0.6f });
//    chongyueHead.setScale({ 0.6f, 0.6f });
//    chenHead.setPosition({ 20.0f, 20.0f });
//    chongyueHead.setPosition({ 650.0f, 20.0f });
//
//    // 设置血条
//    RectangleShape chenHPBar(Vector2f(200.0f, 30.0f));
//    RectangleShape chongyueHPBar(Vector2f(200.0f, 30.0f));
//    chenHPBar.setFillColor(Color::Red);
//    chongyueHPBar.setFillColor(Color::Red);
//    chenHPBar.setPosition({ 104.0f, 20.0f });
//    chongyueHPBar.setPosition({ 430.0f, 20.0f });
//
//    // 设置中文名字
//    Font font;
//    if (!font.openFromFile("graphics/STXINGKA.ttf")) {
//        cerr << "Failed to load font!" << endl;
//        return 1;
//    }
//    Text chenName(font, "截云", 100);
//    Text chongyueName(font, "重岳", 100);
//    chenName.setFillColor(Color::White);
//    chongyueName.setFillColor(Color::White);
//    chenName.setPosition({ 120.0f, 100.0f });
//    chongyueName.setPosition({ 600.0f, 100.0f });
//
//    // 技能冷却指示
//    CircleShape chenSkillIndicator(15.0f), chongyueSkillIndicator(15.0f);
//    chenSkillIndicator.setPosition({ 120.0f, 60.0f });
//    chongyueSkillIndicator.setPosition({ 600.0f, 60.0f });
//    chenSkillIndicator.setFillColor(Color::Green);
//    chongyueSkillIndicator.setFillColor(Color::Green);
//
//    // 初始血量和冷却时间
//    int chenHP = 100, chongyueHP = 100;
//    float chenSkillCooldown = 0.0f, chongyueSkillCooldown = 0.0f;
//    float chenSkillMaxCooldown = 15.0f, chongyueSkillMaxCooldown = 20.0f;
//
//
//    Clock clock;
//
//    while (window.isOpen()) {
//        Time dt = clock.restart();
//        float deltaTime = dt.asSeconds();
//
//        while (const optional event = window.pollEvent()) {
//            if (event->is<Event::Closed>()) {
//                window.close();
//            }
//        }
//
//        // 玩家1 控制
//        Vector2f lastPos1 = chenPos;
//        isMoving1 = false;
//        if (!isAttacking1 && !normalAttack1) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
//                chenPos.x -= 0.2f;
//                isMoving1 = true;
//                moveLeft1 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
//                chenPos.x += 0.2f;
//                isMoving1 = true;
//                moveLeft1 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::X)) {
//                isAttacking1 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::C)) {
//                normalAttack1 = true;
//            }
//        }
//
//        if (jumpCooldown1 > 0.0f) jumpCooldown1 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::Space) && !isJumping1 && jumpCooldown1 <= 0.0f) {
//            isJumping1 = true;
//            jumpCooldown1 = 0.6f;
//            float jumpHeight = chenCharacter.getSize().y * 0.9f;
//            velocityY1 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping1) {
//            velocityY1 += gravity * deltaTime;
//            chenPos.y += velocityY1 * deltaTime;
//            if (chenPos.y >= groundY) {
//                chenPos.y = groundY;
//                velocityY1 = 0.0f;
//                isJumping1 = false;
//            }
//        }
//
//        // 玩家2 控制
//        Vector2f lastPos2 = chongyuePos;
//        isMoving2 = false;
//        if (!isAttacking2 && !normalAttack2) {
//            if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
//                chongyuePos.x -= 0.2f;
//                isMoving2 = true;
//                moveLeft2 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
//                chongyuePos.x += 0.2f;
//                isMoving2 = true;
//                moveLeft2 = false;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
//                isAttacking2 = true;
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
//                normalAttack2 = true;
//            }
//        }
//
//        if (jumpCooldown2 > 0.0f) jumpCooldown2 -= deltaTime;
//        if (Keyboard::isKeyPressed(Keyboard::Key::W) && !isJumping2 && jumpCooldown2 <= 0.0f) {
//            isJumping2 = true;
//            jumpCooldown2 = 0.6f;
//            float jumpHeight = chongyue.getSize().y * 0.9f;
//            velocityY2 = -std::sqrt(2.0f * gravity * jumpHeight);
//        }
//        if (isJumping2) {
//            velocityY2 += gravity * deltaTime;
//            chongyuePos.y += velocityY2 * deltaTime;
//            if (chongyuePos.y >= groundY) {
//                chongyuePos.y = groundY;
//                velocityY2 = 0.0f;
//                isJumping2 = false;
//            }
//        }
//
//
//        // 边界限制
//        Vector2f size1 = chenCharacter.getSize();
//        Vector2f size2 = chongyue.getSize();
//        chenPos.x = std::clamp(chenPos.x, 0.0f, 800 - size1.x);
//        chongyuePos.x = std::clamp(chongyuePos.x, 0.0f, 800 - size2.x);
//
//        float speed1 = abs(chenPos.x - lastPos1.x);
//        float speed2 = abs(chongyuePos.x - lastPos2.x);
//
//        chenCharacter.update(deltaTime, isMoving1, moveLeft1, isAttacking1, normalAttack1, speed1, isJumping1);
//        chongyue.update(deltaTime, isMoving2, moveLeft2, isAttacking2, normalAttack2, speed2, isJumping2);
//
//        chenCharacter.setPosition(chenPos.x, chenPos.y);
//        chongyue.setPosition(chongyuePos.x, chongyuePos.y);
//
//        if (chenSkillCooldown > 0.0f) chenSkillCooldown -= deltaTime;
//        if (chongyueSkillCooldown > 0.0f) chongyueSkillCooldown -= deltaTime;
//
//        // 更新技能指示器
//        chenSkillIndicator.setFillColor(chenSkillCooldown <= 0.0f ? Color::Green : Color::Red);
//        chongyueSkillIndicator.setFillColor(chongyueSkillCooldown <= 0.0f ? Color::Green : Color::Red);
//
//        // 渲染
//        window.clear();
//        window.draw(backgroundSprite);
//        chenCharacter.draw(window);
//        chongyue.draw(window);
//        window.draw(chenHead);
//        window.draw(chongyueHead);
//        window.draw(chenHPBar);
//        window.draw(chongyueHPBar);
//        window.draw(chenName);
//        window.draw(chongyueName);
//        window.draw(chenSkillIndicator);
//        window.draw(chongyueSkillIndicator);
//        window.display();
//    }
//}



// 碰撞检测函数
bool isColliding(const Character& a, const Character& b) {
    sf::Rect<float> aBounds = a.getGlobalBounds();
    sf::Rect<float> bBounds = b.getGlobalBounds();


    float collisionWidth = aBounds.size.x / 4.0f;
    float collisionHeight = aBounds.size.y;


    float aCollisionX = aBounds.position.x + (aBounds.size.x - collisionWidth) / 2.0f;
    float bCollisionX = bBounds.position.x + (bBounds.size.x - collisionWidth) / 2.0f;

    // 构建新的碰撞矩形
    sf::Rect<float> aCollisionBox(
        { aCollisionX, aBounds.position.y },
        { collisionWidth, collisionHeight }
    );

    sf::Rect<float> bCollisionBox(
        { bCollisionX, bBounds.position.y },
        { collisionWidth, collisionHeight }
    );

    // 检测是否相交
    bool xOverlap = aCollisionBox.position.x < bCollisionBox.position.x + bCollisionBox.size.x &&
        aCollisionBox.position.x + aCollisionBox.size.x > bCollisionBox.position.x;

    bool yOverlap = aCollisionBox.position.y < bCollisionBox.position.y + bCollisionBox.size.y &&
        aCollisionBox.position.y + aCollisionBox.size.y > bCollisionBox.position.y;

    return xOverlap && yOverlap;
}

bool isSkillColliding(const Character& a, const Character& b) {
    sf::Rect<float> aBounds = a.getGlobalBounds();
    sf::Rect<float> bBounds = b.getGlobalBounds();


    float collisionWidth = aBounds.size.x / 1.5f;
    float collisionHeight = aBounds.size.y;


    float aCollisionX = aBounds.position.x + (aBounds.size.x - collisionWidth) / 2.0f;
    float bCollisionX = bBounds.position.x + (bBounds.size.x - collisionWidth) / 2.0f;

    // 构建新的碰撞矩形
    sf::Rect<float> aCollisionBox(
        { aCollisionX, aBounds.position.y },
        { collisionWidth, collisionHeight }
    );

    sf::Rect<float> bCollisionBox(
        { bCollisionX, bBounds.position.y },
        { collisionWidth, collisionHeight }
    );

    // 检测是否相交
    bool xOverlap = aCollisionBox.position.x < bCollisionBox.position.x + bCollisionBox.size.x &&
        aCollisionBox.position.x + aCollisionBox.size.x > bCollisionBox.position.x;

    bool yOverlap = aCollisionBox.position.y < bCollisionBox.position.y + bCollisionBox.size.y &&
        aCollisionBox.position.y + aCollisionBox.size.y > bCollisionBox.position.y;

    return xOverlap && yOverlap;
}


int main() {
    RenderWindow window(VideoMode({ 800, 600 }), "animation");
    float groundY = 600.0f * 2.0f / 5.0f;

    //音效
    sf::SoundBuffer jieyunNaBuffer;
    sf::SoundBuffer jieyunAttackBuffer;

    if (!jieyunNaBuffer.loadFromFile("voice/jieyun_na.wav") ||
        !jieyunAttackBuffer.loadFromFile("voice/jieyun_attack.wav")) {
        std::cerr << "Failed to load sound effects!" << std::endl;
        return 1;
    }

    sf::Sound jieyunNaSound(jieyunNaBuffer);
    sf::Sound jieyunAttackSound(jieyunAttackBuffer);

    sf::Music backgroundMusic;
    sf::Music gameOverMusic;

    // 加载音乐
    if (!backgroundMusic.openFromFile("voice/浸春芜.wav") ||
        !gameOverMusic.openFromFile("voice/Eclipse.wav")) {
        std::cerr << "Failed to load music files!" << std::endl;
        return -1;
    }

    backgroundMusic.play();

    // 开始播放背景音乐
    backgroundMusic.play();


    // 中文
    Font font;
    if (!font.openFromFile("graphics/STXINGKA.ttf")) {
        cerr << "Failed to load font!" << endl;
        return 1;
    }

    // 加载背景和死亡图片
    Texture background1Texture;
    if (!background1Texture.loadFromFile("graphics/background1.jpg")) {
        cerr << "Failed to load game over images!" << endl;
        return 1;
    }

    Sprite background1Sprite(background1Texture);
    background1Sprite.setScale(
        { 800.0f / background1Texture.getSize().x,
          600.0f / background1Texture.getSize().y }
    );


    RectangleShape backButton(Vector2f(300.0f, 100.0f));
    backButton.setFillColor(Color::White);
    backButton.setOutlineColor(Color::Black);
    backButton.setOutlineThickness(2.0f);
    backButton.setPosition({ 250.0f, 70.0f });


    Text backText(font, "Arknights", 70);
    backText.setFillColor(Color::Blue);
    backText.setPosition({ 290.0f, 70.0f });

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("graphics/background.png")) {
        cerr << "Failed to load background!" << endl;
    }
    Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(
        { 800.0f / backgroundTexture.getSize().x,
          600.0f / backgroundTexture.getSize().y }
    );

    // 初始化角色
    Character chenCharacter(
        "graphics/jieyun_rightmove/images/jieyun",
        "graphics/jieyun_leftmove/images/jieyun",
        "graphics/jieyun_rightattack/images/jieyun",
        "graphics/jieyun_leftattack/images/jieyun",
        "graphics/jieyun_na_right/jieyun",
        "graphics/jieyun_na_left/jieyun",
        60, 60, 7);

    CharacterChongyue chongyue(
        "graphics/chongyue_rightmove/images/chongyue",
        "graphics/chongyue_leftmove/images/chongyue",
        "graphics/chongyue_rightattack/images/chongyue",
        "graphics/chongyue_leftattack/images/chongyue",
        "graphics/chongyue_na_right/chongyue",
        "graphics/chongyue_na_left/chongyue",
        60, 60, 7);

    Vector2f chenPos(200.0f, groundY);
    Vector2f chongyuePos(400.0f, groundY);

    bool isMoving1 = false, isMoving2 = false;
    bool moveLeft1 = false, moveLeft2 = false;
    bool isAttacking1 = false, isAttacking2 = false;
    bool normalAttack1 = false, normalAttack2 = false;
    bool isJumping1 = false, isJumping2 = false;
    // 游戏状态
    bool gameOver = false;
    bool waitingForRestart = false; 
    bool isChenDead = false, isChongyueDead = false;
    float gameOverTimer = 0.0f;


    float velocityY1 = 0.0f, velocityY2 = 0.0f;
    float jumpCooldown1 = 0.0f, jumpCooldown2 = 0.0f;
    float gravity = 4500.0f;

    // 加载头像
    Texture chenHeadTexture, chongyueHeadTexture;
    if (!chenHeadTexture.loadFromFile("graphics/jieyun.jpg") ||
        !chongyueHeadTexture.loadFromFile("graphics/chongyue.jpg")) {
        cerr << "Failed to load head images!" << endl;
        return 1;
    }

    Sprite chenHead(chenHeadTexture), chongyueHead(chongyueHeadTexture);
    chenHead.setScale({ 0.6f, 0.6f });
    chongyueHead.setScale({ 0.6f, 0.6f });
    chenHead.setPosition({ 20.0f, 20.0f });
    chongyueHead.setPosition({ 650.0f, 20.0f });


    

    // 血条
    RectangleShape chenHPBar(Vector2f(200.0f, 30.0f));
    RectangleShape chenHPBorder(Vector2f(200.0f, 30.0f));
    Text chenHPText(font, "100/100", 20);
    RectangleShape chongyueHPBar(Vector2f(200.0f, 30.0f));
    RectangleShape chongyueHPBorder(Vector2f(200.0f, 30.0f));
    Text chongyueHPText(font, "100/100", 20);
    chenHPBar.setFillColor(Color::Red);
    chongyueHPBar.setFillColor(Color::Red);
    chenHPBar.setPosition({ 110.0f, 20.0f });
    chongyueHPBar.setPosition({ 450.0f, 20.0f });

    // 初始化血条边框
    chenHPBorder.setPosition({ 110.0f, 20.0f });
    chenHPBorder.setFillColor(sf::Color::Transparent);
    chenHPBorder.setOutlineColor(sf::Color::White);
    chenHPBorder.setOutlineThickness(2.0f);

    chongyueHPBorder.setPosition({ 450.0f, 20.0f });
    chongyueHPBorder.setFillColor(sf::Color::Transparent);
    chongyueHPBorder.setOutlineColor(sf::Color::White);
    chongyueHPBorder.setOutlineThickness(2.0f);

    // 初始化血量文本
    chenHPText.setFillColor(sf::Color::White);
    chenHPText.setPosition({ 110.0f, 25.0f });

    chongyueHPText.setFillColor(sf::Color::White);
    chongyueHPText.setPosition({ 590.0f, 25.0f });

    sf::Text chenName(font,"截云", 100);
    chenName.setFillColor(sf::Color::White);
    chenName.setPosition({ 120.0f, 100.0f });

    sf::Text chongyueName(font,"重岳", 100);
    chongyueName.setFillColor(sf::Color::White);
    chongyueName.setPosition({ 600.0f, 100.0f });


    // 技能冷却指示器
    CircleShape chenSkillIndicator(15.0f), chongyueSkillIndicator(15.0f);
    chenSkillIndicator.setPosition({ 120.0f, 60.0f });
    chongyueSkillIndicator.setPosition({ 600.0f, 60.0f });
    chenSkillIndicator.setFillColor(Color::Green);
    chongyueSkillIndicator.setFillColor(Color::Green);

    // 初始血量和冷却时间
    int chenHP = 100, chongyueHP = 100;
    float chenSkillCooldown = 0.0f, chongyueSkillCooldown = 0.0f;
    float chenSkillMaxCooldown = 11.0f, chongyueSkillMaxCooldown = 20.0f;

    Clock clock;
    while (window.isOpen()) {
        Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        while (const optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
            if (gameOver && event->is<Event::MouseButtonPressed>()) {
                auto mousePos = Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);
                if (backButton.getGlobalBounds().contains(mouseWorldPos)) {
                    chenCharacter.reset();
                    chongyue.reset();

                    chenPos = { 200.0f, groundY };
                    chongyuePos = { 400.0f, groundY };

                    isMoving1 = false;
                    isMoving2 = false;
                    moveLeft1 = false;
                    moveLeft2 = false;
                    isAttacking1 = false;
                    isAttacking2 = false;
                    normalAttack1 = false;
                    normalAttack2 = false;
                    isJumping1 = false;
                    isJumping2 = false;

                    velocityY1 = 0.0f;
                    velocityY2 = 0.0f;
                    jumpCooldown1 = 0.0f;
                    jumpCooldown2 = 0.0f;

                    chenSkillCooldown = 0.0f;
                    chongyueSkillCooldown = 0.0f;
                    chongyue.setSkillDuration(0.0f);
                    chongyue.setDamageBuff(1.0f);
                    chongyue.setDamageReduction(0.0f);
                    chongyue.setIsStunned(false);

                    gameOver = false;
                    waitingForRestart = false;
                    isChenDead = false;
                    isChongyueDead = false;

                    gameOverMusic.stop();
                    backgroundMusic.play();
                }
            }
        }



        // 玩家1 控制
        Vector2f lastPos1 = chenPos;
        isMoving1 = false;

        if (!isAttacking1) {
            if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
                chenPos.x -= 0.3f;
                isMoving1 = !normalAttack1;
                moveLeft1 = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
                chenPos.x += 0.3f;
                isMoving1 = !normalAttack1;
                moveLeft1 = false;
            }
            
            if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !isJumping1 && jumpCooldown1 <= 0.0f) {
                isJumping1 = true;
                jumpCooldown1 = 0.6f;
                float jumpHeight = chenCharacter.getSize().y * 0.9f;
                velocityY1 = -std::sqrt(2.0f * gravity * jumpHeight);
            }
            
        }
        if (!isAttacking1 && !normalAttack1) {
            if (Keyboard::isKeyPressed(Keyboard::Key::M)) {
                normalAttack1 = true;
                chenCharacter.setHasDealtDamage(false);
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Key::N) && chenSkillCooldown <= 0.0f && !isJumping1) {
            chongyue.setDamageBuff(1.5f);         
            chongyue.setDamageReduction(0.0f);
            chongyue.setSkillDuration(6.0f);
            chenSkillCooldown = chenSkillMaxCooldown;
            isAttacking1 = true;
            chenCharacter.setHasDealtDamage(false); // 重置标志位
        }
        if (jumpCooldown1 > 0.0f) jumpCooldown1 -= deltaTime;
        

        if (isJumping1) {
            velocityY1 += gravity * deltaTime;
            chenPos.y += velocityY1 * deltaTime;
            if (chenPos.y >= groundY) {
                chenPos.y = groundY;
                velocityY1 = 0.0f;
                isJumping1 = false;
            }
        }


        // 玩家2 控制
        Vector2f lastPos2 = chongyuePos;
        isMoving2 = false;

        if (!chongyue.getIsStunned()) {
            if (!isAttacking2) {
                if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
                    chongyuePos.x -= 0.25f;
                    isMoving2 = !normalAttack2;
                    moveLeft2 = true;
                }
                if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                    chongyuePos.x += 0.25f;
                    isMoving2 = !normalAttack2;
                    moveLeft2 = false;
                }
                
                if (Keyboard::isKeyPressed(Keyboard::Key::W) && !isJumping2 && jumpCooldown2 <= 0.0f) {
                    isJumping2 = true;
                    jumpCooldown2 = 0.6f;
                    float jumpHeight = chongyue.getSize().y * 0.9f;
                    velocityY2 = -std::sqrt(2.0f * gravity * jumpHeight);
                }
                
            }
            if (!isAttacking2 && !normalAttack2) {
                if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
                    normalAttack2 = true;
                    chongyue.setHasDealtDamage(false);
                }
            }

            if (jumpCooldown2 > 0.0f) jumpCooldown2 -= deltaTime;
            if (Keyboard::isKeyPressed(Keyboard::Key::S) && chongyueSkillCooldown <= 0.0f) {
                chongyue.setSkillDuration(10.0f);
                chongyue.setDamageBuff(2.0f);
                chongyue.setDamageReduction(0.3f);
                chongyueSkillCooldown = chongyueSkillMaxCooldown;
                isAttacking2 = true;
                chongyue.setHasDealtDamage(false);
            }
            

        }
        else {
            moveLeft2 = moveLeft2;
        }

        // Q 键瞬移
        if (Keyboard::isKeyPressed(Keyboard::Key::Q) && chongyue.getSkillDuration() > 0.0f) {
            float teleportDistance = 0.6f;
            float newX = chongyuePos.x + (chongyue.isFacingRight() ? teleportDistance : -teleportDistance);
            newX = std::clamp(newX, 0.0f, 800.0f - chongyue.getSize().x);
            chongyuePos.x = newX;

            chongyue.setPosition(chongyuePos.x, chongyuePos.y);

            isMoving2 = false;
            lastPos2 = chongyuePos;
        }

        

        if (isJumping2) {
            velocityY2 += gravity * deltaTime;
            chongyuePos.y += velocityY2 * deltaTime;
            if (chongyuePos.y >= groundY) {
                chongyuePos.y = groundY;
                velocityY2 = 0.0f;
                isJumping2 = false;
            }
        }

        // 边界限制
        Vector2f size1 = chenCharacter.getSize();
        Vector2f size2 = chongyue.getSize();
        chenPos.x = clamp(chenPos.x, 0.0f, 800 - size1.x);
        chongyuePos.x = clamp(chongyuePos.x, 0.0f, 800 - size2.x);

        float speed1 = abs(chenPos.x - lastPos1.x);
        float speed2 = abs(chongyuePos.x - lastPos2.x);

        chenCharacter.update(deltaTime, isMoving1, moveLeft1, isAttacking1, normalAttack1, speed1, isJumping1);
        chongyue.update(deltaTime, isMoving2, moveLeft2, isAttacking2, normalAttack2, speed2, isJumping2);

        chenCharacter.setPosition(chenPos.x, chenPos.y);
        chongyue.setPosition(chongyuePos.x, chongyuePos.y);

        // 攻击判定（只在第一帧触发一次）
        if (isAttacking1) {
            if (chenCharacter.getCurrentFrame() == 0 && !chenCharacter.hasDealtDamage() && isSkillColliding(chenCharacter, chongyue)) {
                chongyue.takeDamage(20);
                chongyue.setDamageBuff(1.5f);
                chongyue.setDamageReduction(0.0f);
                chongyue.setIsStunned(true);
                chongyue.setStunDuration(3.0f);
                jieyunAttackSound.play();
                chenCharacter.setHasDealtDamage(true);
                
            }
        }

        if (normalAttack1) {
            if (chenCharacter.getCurrentFrame() == 0 && !chenCharacter.hasDealtDamage() && isColliding(chenCharacter, chongyue)) {
                chongyue.takeDamage(7);
                jieyunNaSound.play();
                chenCharacter.setHasDealtDamage(true);
                
            }
        }

        if (normalAttack2) {
            if (chongyue.getCurrentFrame() == 0 && !chongyue.hasDealtDamage() && isColliding(chongyue, chenCharacter)) {
                chenCharacter.takeDamage(5 * chongyue.getDamageBuff());
                chongyue.setHasDealtDamage(true);
            }
        }

        if (chenSkillCooldown > 0.0f) chenSkillCooldown -= deltaTime;
        if (chongyueSkillCooldown > 0.0f) chongyueSkillCooldown -= deltaTime;
        if (chongyue.getSkillDuration() > 0.0f) {
            chongyue.setSkillDuration(chongyue.getSkillDuration() - deltaTime);
        }
        else {
            chongyue.setDamageBuff(1.0f);
            chongyue.setDamageReduction(0.0f);
        }


        // 更新血条宽度
        chenHPBar.setSize({ static_cast<float>(chenCharacter.getCurrentHealth()) * 2.0f, 30.0f });
        chongyueHPBar.setSize({ static_cast<float>(chongyue.getCurrentHealth()) * 2.0f, 30.0f });

        int chenCurrentHP = chenCharacter.getCurrentHealth();
        int chongyueCurrentHP = chongyue.getCurrentHealth();
        if (!gameOver) {
            if (chenCurrentHP <= 0 || chongyueCurrentHP <= 0) {
                gameOver = true;
                waitingForRestart = true;
                gameOverTimer = 3.0f;
                isChenDead = (chenCurrentHP <= 0);
                isChongyueDead = (chongyueCurrentHP <= 0);

                backgroundMusic.stop();
                gameOverMusic.play();
            }
        }
        else if (waitingForRestart) {
            // 3秒倒计时
            gameOverTimer -= deltaTime;
            if (gameOverTimer <= 0.0f) {
                waitingForRestart = false;
            }
        }

        chenHPBar.setSize({ static_cast<float>(chenCurrentHP) * 2.0f, 30.0f });
        chongyueHPBar.setSize({ static_cast<float>(chongyueCurrentHP) * 2.0f, 30.0f });

        chenHPText.setString(std::to_string(chenCurrentHP) + "/100");
        chongyueHPText.setString(std::to_string(chongyueCurrentHP) + "/100");

        // 更新技能指示器颜色
        chenSkillIndicator.setFillColor(chenSkillCooldown <= 0.0f ? Color::Green : Color::Red);
        chongyueSkillIndicator.setFillColor(chongyueSkillCooldown <= 0.0f ? Color::Green : Color::Red);


        window.clear();

        window.draw(backgroundSprite);
        chenCharacter.draw(window);
        chongyue.draw(window);
        window.draw(chenHead);
        window.draw(chongyueHead);

        window.draw(chenHPBorder);    
        window.draw(chenHPBar);
        window.draw(chenHPText);
        window.draw(chongyueHPBorder);
        window.draw(chongyueHPBar);
        window.draw(chongyueHPText);

        window.draw(chenName);
        window.draw(chongyueName);

        window.draw(chenSkillIndicator);
        window.draw(chongyueSkillIndicator);

        if (gameOver) {
            window.draw(background1Sprite);
            window.draw(backButton);
            window.draw(backText);
        }
        else {
            // 正常游戏状态
            chenCharacter.setPosition(chenPos.x, chenPos.y);
            chongyue.setPosition(chongyuePos.x, chongyuePos.y);
            chenCharacter.draw(window);
            chongyue.draw(window);
        }
        window.display();
    }

    return 0;
}




