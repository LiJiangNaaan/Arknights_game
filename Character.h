#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <optional>

//class Character {
//public:
//    Character(const std::string& folderRight, const std::string& folderLeft,
//        const std::string& folderAttackRight, const std::string& folderAttackLeft,
//        int totalFrames, int attackFrames);
//
//    void update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, float speed);
//    void setPosition(float x, float y);
//    sf::Vector2f getSize() const;
//    void draw(sf::RenderWindow& window);
//
//protected:
//    std::vector<std::unique_ptr<sf::Texture>> rightTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftTextures;
//    std::vector<std::unique_ptr<sf::Texture>> rightAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftAttackTextures;
//    std::optional<sf::Sprite> sprite;
//
//    int currentFrame;
//    float baseFrameRate;
//    float frameRate;
//    float timeSinceLastFrame;
//    float scaleX, scaleY;
//
//    bool isFacingRight;
//    bool isAttacking;
//    float attackCooldown;
//
//    void loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames);
//    void updateAttackAnimation(float deltaTime, bool& attack);
//};
//class Character {
//public:
//    Character(const std::string& folderRight, const std::string& folderLeft,
//        const std::string& folderAttackRight, const std::string& folderAttackLeft,
//        int totalFrames, int attackFrames);
//
//    void update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed);
//    void setPosition(float x, float y);
//    sf::Vector2f getSize() const;
//    void draw(sf::RenderWindow& window);
//
//protected:
//    std::vector<std::unique_ptr<sf::Texture>> rightTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftTextures;
//    std::vector<std::unique_ptr<sf::Texture>> rightAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> rightNormalAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftNormalAttackTextures;
//    std::optional<sf::Sprite> sprite;
//
//    int currentFrame;
//    float baseFrameRate;
//    float frameRate;
//    float timeSinceLastFrame;
//    float scaleX, scaleY;
//
//    bool isFacingRight;
//    bool isAttacking;
//    bool isNormalAttacking;
//    float attackCooldown;
//    float normalAttackCooldown;
//
//    void loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames);
//    void updateAttackAnimation(float deltaTime, bool& attack);
//    void updateNormalAttackAnimation(float deltaTime, bool& normalAttack);
//};
//class Character {
//public:
//    Character(const std::string& folderRight, const std::string& folderLeft,
//        const std::string& folderAttackRight, const std::string& folderAttackLeft,
//        const std::string& folderNARight, const std::string& folderNALeft,
//        int totalFrames, int attackFrames, int naFrames);
//
//    void update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed, bool isJumping);
//    void setPosition(float x, float y);
//    sf::Vector2f getSize() const;
//    void draw(sf::RenderWindow& window);
//
//protected:
//    std::vector<std::unique_ptr<sf::Texture>> rightTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftTextures;
//    std::vector<std::unique_ptr<sf::Texture>> rightAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftAttackTextures;
//    std::vector<std::unique_ptr<sf::Texture>> rightNATextures;
//    std::vector<std::unique_ptr<sf::Texture>> leftNATextures;
//    std::optional<sf::Sprite> sprite;
//
//    int currentFrame;
//    float baseFrameRate;
//    float frameRate;
//    float timeSinceLastFrame;
//    float scaleX, scaleY;
//
//    bool isFacingRight;
//    bool isAttacking;
//    bool isNormalAttacking;
//    float attackCooldown;
//    float naCooldown;
//    float normalAttackFrameRate;
//
//    void loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames);
//    void updateAttackAnimation(float deltaTime, bool& attack);
//    void updateNormalAttackAnimation(float deltaTime, bool& normalAttack);
//};



class Character {
public:
    Character(const std::string& folderRight, const std::string& folderLeft,
        const std::string& folderAttackRight, const std::string& folderAttackLeft,
        const std::string& folderNARight, const std::string& folderNALeft,
        int totalFrames, int attackFrames, int naFrames);

    void update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed, bool isJumping);
    void setPosition(float x, float y);
    sf::Vector2f getSize() const;
    void draw(sf::RenderWindow& window);
    int getCurrentHealth() const;
    void takeDamage(int damage);
    void heal(int amount);

    void setDamageBuff(float buff);
    void setDamageReduction(float reduction);
    void setSkillDuration(float duration);
    float getDamageBuff() const;
    float getDamageReduction() const;
    float getSkillDuration() const;
    bool isFacingRight() const;
    bool isNormalAttacking() const;
    int getCurrentFrame() const;
    bool hasDealtDamage() const;
    void setHasDealtDamage(bool value);
    void setStunDuration(float duration);
    float getStunDuration() const;
    void setIsStunned(bool value);
    bool getIsStunned() const;
    void reset();

    sf::Rect<float> getGlobalBounds() const; // ¸ÄÎª Rect<float>


private:
    void loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames);
    void updateAttackAnimation(float deltaTime, bool& attack);
    void updateNormalAttackAnimation(float deltaTime, bool& normalAttack);
    

    std::vector<std::unique_ptr<sf::Texture>> rightTextures;
    std::vector<std::unique_ptr<sf::Texture>> leftTextures;
    std::vector<std::unique_ptr<sf::Texture>> rightAttackTextures;
    std::vector<std::unique_ptr<sf::Texture>> leftAttackTextures;
    std::vector<std::unique_ptr<sf::Texture>> rightNATextures;
    std::vector<std::unique_ptr<sf::Texture>> leftNATextures;

    std::unique_ptr<sf::Sprite> sprite;
    int currentFrame;
    float timeSinceLastFrame;
    float frameRate;
    float baseFrameRate;
    float normalAttackFrameRate;
    float scaleX;
    float scaleY;
    bool isAttacking;
    bool normalAttacking;
    float attackCooldown;
    float naCooldown;
    int maxHealth;
    int currentHealth;
    float damageBuff;
    float damageReduction;
    float skillCooldown;
    float skillDuration;
    bool facingRight;
    bool m_hasDealtDamage;
    float stunDuration;
    bool isStunned;
};