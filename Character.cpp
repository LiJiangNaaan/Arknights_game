#include "Character.h"
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;

//Character::Character(const std::string& folderRight, const std::string& folderLeft,
//    const std::string& folderAttackRight, const std::string& folderAttackLeft,
//    int totalFrames, int attackFrames)
//    : currentFrame(0), timeSinceLastFrame(0.0f), scaleX(0.5f), scaleY(0.5f),
//    isAttacking(false), attackCooldown(0.0f) {
//
//    loadTextures(folderRight, rightTextures, totalFrames);
//    loadTextures(folderLeft, leftTextures, totalFrames);
//    loadTextures(folderAttackRight, rightAttackTextures, attackFrames);
//    loadTextures(folderAttackLeft, leftAttackTextures, attackFrames);
//
//    if (rightTextures.empty() || leftTextures.empty() || rightAttackTextures.empty() || leftAttackTextures.empty()) {
//        throw runtime_error("Failed to load character animations!");
//    }
//
//    // 使用 std::optional 进行初始化
//    sprite.emplace(*rightTextures[0]);
//    sprite->setScale({ scaleX, scaleY });
//    baseFrameRate = 0.03f;
//    frameRate = baseFrameRate;
//    isFacingRight = true;
//}
//
//void Character::loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames) {
//    for (int i = 1; i <= totalFrames; ++i) {
//        auto texture = std::make_unique<sf::Texture>();
//        string filePath = folder + " (" + to_string(i) + ").png";
//        if (texture->loadFromFile(filePath)) {
//            texture->setSmooth(true);
//            textures.push_back(move(texture));
//        }
//        else {
//            cerr << "Failed to load texture: " << filePath << endl;
//        }
//    }
//}
//
//void Character::update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, float speed) {
//    if (attack && attackCooldown <= 0.0f) {
//        if (!isAttacking) {
//            isAttacking = true;
//            currentFrame = 0;
//        }
//        updateAttackAnimation(deltaTime, attack);
//        return;
//    }
//
//    if (attackCooldown > 0.0f) attackCooldown -= deltaTime;
//
//    if (isMoving && !isAttacking) {
//        isFacingRight = !moveLeft;
//        frameRate = baseFrameRate;
//        timeSinceLastFrame += deltaTime;
//
//        if (timeSinceLastFrame >= frameRate) {
//            timeSinceLastFrame = 0.0f;
//            currentFrame = (currentFrame + 1) % rightTextures.size();
//            // 使用 std::optional 来设置纹理
//            if (sprite) {
//                sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[currentFrame]);
//            }
//        }
//    }
//    else if (!isAttacking) {
//        if (sprite) {
//            sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[0]);
//        }
//    }
//}
//
//void Character::updateAttackAnimation(float deltaTime, bool& attack) {
//    frameRate = 0.05f;
//    timeSinceLastFrame += deltaTime;
//    auto& attackTex = isFacingRight ? rightAttackTextures : leftAttackTextures;
//
//    if (timeSinceLastFrame >= frameRate) {
//        timeSinceLastFrame = 0.0f;
//        currentFrame++;
//
//        if (currentFrame < attackTex.size()) {
//            if (sprite) {
//                sprite->setTexture(*attackTex[currentFrame]);
//                sprite->setScale({ scaleX, scaleY });
//            }
//        }
//        else {
//            attackCooldown = 0.3f;
//            if (sprite) {
//                sprite->setTexture(*attackTex.back());
//            }
//            isAttacking = false;
//            attack = false;
//            currentFrame = 0;
//        }
//    }
//}
//
//void Character::setPosition(float x, float y) {
//    if (sprite) {
//        sprite->setPosition({ x, y });
//    }
//}
//
//Vector2f Character::getSize() const {
//    if (sprite) {
//        return { sprite->getGlobalBounds().size.x, sprite->getGlobalBounds().size.y };
//    }
//    return { 0.f, 0.f };
//}
//
//void Character::draw(RenderWindow& window) {
//    if (sprite) {
//        window.draw(*sprite);
//    }
//}
// 
// 
// 
// 
//Character::Character(const std::string& folderRight, const std::string& folderLeft,
//    const std::string& folderAttackRight, const std::string& folderAttackLeft,
//    int totalFrames, int attackFrames)
//    : currentFrame(0), timeSinceLastFrame(0.0f), scaleX(0.5f), scaleY(0.5f),
//    isAttacking(false), attackCooldown(0.0f), isNormalAttacking(false), normalAttackCooldown(0.0f) {
//
//    loadTextures(folderRight, rightTextures, totalFrames);
//    loadTextures(folderLeft, leftTextures, totalFrames);
//    loadTextures(folderAttackRight, rightAttackTextures, attackFrames);
//    loadTextures(folderAttackLeft, leftAttackTextures, attackFrames);
//
//    // 普攻纹理加载
//    loadTextures("graphics/jieyun_na_right/", rightNormalAttackTextures, 7);
//    loadTextures("graphics/jieyun_na_left/", leftNormalAttackTextures, 7);
//    loadTextures("graphics/chongyue_na_right/", rightNormalAttackTextures, 7);
//    loadTextures("graphics/chongyue_na_left/", leftNormalAttackTextures, 7);
//
//    if (rightTextures.empty() || leftTextures.empty() || rightAttackTextures.empty() || leftAttackTextures.empty()) {
//        throw runtime_error("Failed to load character animations!");
//    }
//
//    sprite.emplace(*rightTextures[0]);
//    sprite->setScale({ scaleX, scaleY });
//    baseFrameRate = 0.02f;
//    frameRate = baseFrameRate;
//    normalAttackFrameRate = 0.04f;
//    isFacingRight = true;
//}
//
//void Character::loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames) {
//    for (int i = 1; i <= totalFrames; ++i) {
//        auto texture = std::make_unique<sf::Texture>();
//        string filePath = folder + " (" + to_string(i) + ").png";
//        if (texture->loadFromFile(filePath)) {
//            texture->setSmooth(true);
//            textures.push_back(move(texture));
//        }
//        else {
//            cerr << "Failed to load texture: " << filePath << endl;
//        }
//    }
//}
//
//void Character::update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed) {
//    if (attack && attackCooldown <= 0.0f) {
//        if (!isAttacking) {
//            isAttacking = true;
//            currentFrame = 0;
//        }
//        updateAttackAnimation(deltaTime, attack);
//        return;
//    }
//    if (attackCooldown > 0.0f) attackCooldown -= deltaTime;
//
//    if (normalAttack && normalAttackCooldown <= 0.0f) {
//        if (!isNormalAttacking) {
//            isNormalAttacking = true;
//            currentFrame = 0;
//        }
//        updateNormalAttackAnimation(deltaTime, normalAttack);
//        return;
//    }
//    if (normalAttackCooldown > 0.0f) normalAttackCooldown -= deltaTime;
//
//    if (isMoving && !isAttacking && !isNormalAttacking) {
//        isFacingRight = !moveLeft;
//        frameRate = baseFrameRate;
//        timeSinceLastFrame += deltaTime;
//
//        if (timeSinceLastFrame >= frameRate) {
//            timeSinceLastFrame = 0.0f;
//            currentFrame = (currentFrame + 1) % rightTextures.size();
//            if (sprite) {
//                sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[currentFrame]);
//            }
//        }
//    }
//    else if (!isAttacking && !isNormalAttacking) {
//        if (sprite) {
//            sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[0]);
//        }
//    }
//}
//
//void Character::updateAttackAnimation(float deltaTime, bool& attack) {
//    frameRate = 0.05f;
//    timeSinceLastFrame += deltaTime;
//    auto& attackTex = isFacingRight ? rightAttackTextures : leftAttackTextures;
//
//    if (timeSinceLastFrame >= frameRate) {
//        timeSinceLastFrame = 0.0f;
//        currentFrame++;
//
//        if (currentFrame < attackTex.size()) {
//            if (sprite) {
//                sprite->setTexture(*attackTex[currentFrame]);
//                sprite->setScale({ scaleX, scaleY });
//            }
//        }
//        else {
//            attackCooldown = 0.3f;
//            if (sprite) {
//                sprite->setTexture(*attackTex.back());
//            }
//            isAttacking = false;
//            attack = false;
//            currentFrame = 0;
//        }
//    }
//}
//
//void Character::updateNormalAttackAnimation(float deltaTime, bool& normalAttack) {
//    frameRate = normalAttackFrameRate;
//    timeSinceLastFrame += deltaTime;
//    auto& naTex = isFacingRight ? rightNormalAttackTextures : leftNormalAttackTextures;
//
//    if (timeSinceLastFrame >= frameRate) {
//        timeSinceLastFrame = 0.0f;
//        currentFrame++;
//
//        if (currentFrame < naTex.size()) {
//            if (sprite) {
//                sprite->setTexture(*naTex[currentFrame]);
//                sprite->setScale({ scaleX, scaleY });
//            }
//        }
//        else {
//            normalAttackCooldown = 0.15f;
//            if (sprite) {
//                sprite->setTexture(*naTex.back());
//            }
//            isNormalAttacking = false;
//            normalAttack = false;
//            currentFrame = 0;
//        }
//    }
//}
//
//void Character::setPosition(float x, float y) {
//    if (sprite) {
//        sprite->setPosition({ x, y });
//    }
//}
//
//Vector2f Character::getSize() const {
//    if (sprite) {
//        return { sprite->getGlobalBounds().size.x, sprite->getGlobalBounds().size.y };
//    }
//    return { 0.f, 0.f };
//}
//
//void Character::draw(RenderWindow& window) {
//    if (sprite) {
//        window.draw(*sprite);
//    }
//}
//Character::Character(const std::string& folderRight, const std::string& folderLeft,
//    const std::string& folderAttackRight, const std::string& folderAttackLeft,
//    const std::string& folderNARight, const std::string& folderNALeft,
//    int totalFrames, int attackFrames, int naFrames)
//    : currentFrame(0), timeSinceLastFrame(0.0f), scaleX(0.5f), scaleY(0.5f),
//    isAttacking(false), isNormalAttacking(false), attackCooldown(0.0f), naCooldown(0.0f) {
//
//    loadTextures(folderRight, rightTextures, totalFrames);
//    loadTextures(folderLeft, leftTextures, totalFrames);
//    loadTextures(folderAttackRight, rightAttackTextures, attackFrames);
//    loadTextures(folderAttackLeft, leftAttackTextures, attackFrames);
//    loadTextures(folderNARight, rightNATextures, naFrames);
//    loadTextures(folderNALeft, leftNATextures, naFrames);
//
//    if (rightTextures.empty() || leftTextures.empty() || rightAttackTextures.empty() ||
//        leftAttackTextures.empty() || rightNATextures.empty() || leftNATextures.empty()) {
//        throw runtime_error("Failed to load character animations!");
//    }
//
//    sprite.emplace(*rightTextures[0]);
//    sprite->setScale({ scaleX, scaleY });
//    baseFrameRate = 0.03f;
//    frameRate = baseFrameRate;
//    normalAttackFrameRate = 0.04f;
//    isFacingRight = true;
//}
//
//void Character::loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames) {
//    for (int i = 1; i <= totalFrames; ++i) {
//        auto texture = std::make_unique<sf::Texture>();
//        string filePath = folder + " (" + to_string(i) + ").png";
//        if (texture->loadFromFile(filePath)) {
//            texture->setSmooth(true);
//            textures.push_back(move(texture));
//        }
//        else {
//            cerr << "Failed to load texture: " << filePath << endl;
//        }
//    }
//}
//
//void Character::update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed, bool isJumping) {
//    if (attack && attackCooldown <= 0.0f) {
//        if (!isAttacking) {
//            isAttacking = true;
//            currentFrame = 0;
//        }
//        updateAttackAnimation(deltaTime, attack);
//        return;
//    }
//
//    if (normalAttack && naCooldown <= 0.0f && !isAttacking && !isJumping) {
//        if (!isNormalAttacking) {
//            isNormalAttacking = true;
//            currentFrame = 0;
//        }
//        updateNormalAttackAnimation(deltaTime, normalAttack);
//        return;
//    }
//
//    if (attackCooldown > 0.0f) attackCooldown -= deltaTime;
//    if (naCooldown > 0.0f) naCooldown -= deltaTime;
//
//    if (isMoving && !isAttacking && !isNormalAttacking) {
//        isFacingRight = !moveLeft;
//        frameRate = baseFrameRate;
//        timeSinceLastFrame += deltaTime;
//
//        if (timeSinceLastFrame >= frameRate) {
//            timeSinceLastFrame = 0.0f;
//            currentFrame = (currentFrame + 1) % rightTextures.size();
//            if (sprite) {
//                sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[currentFrame]);
//            }
//        }
//    }
//    else if (!isAttacking && !isNormalAttacking) {
//        if (sprite) {
//            sprite->setTexture(*(isFacingRight ? rightTextures : leftTextures)[0]);
//        }
//    }
//}
//
//void Character::updateAttackAnimation(float deltaTime, bool& attack) {
//    frameRate = 0.05f;
//    timeSinceLastFrame += deltaTime;
//    auto& attackTex = isFacingRight ? rightAttackTextures : leftAttackTextures;
//
//    if (timeSinceLastFrame >= frameRate) {
//        timeSinceLastFrame = 0.0f;
//        currentFrame++;
//
//        if (currentFrame < attackTex.size()) {
//            if (sprite) {
//                sprite->setTexture(*attackTex[currentFrame]);
//                sprite->setScale({ scaleX, scaleY });
//            }
//        }
//        else {
//            attackCooldown = 0.3f;
//            isAttacking = false;
//            attack = false;
//            currentFrame = 0;
//        }
//    }
//}
//
//void Character::updateNormalAttackAnimation(float deltaTime, bool& normalAttack) {
//    frameRate = normalAttackFrameRate;
//    timeSinceLastFrame += deltaTime;
//    auto& naTex = isFacingRight ? rightNATextures : leftNATextures;
//
//    if (timeSinceLastFrame >= frameRate) {
//        timeSinceLastFrame = 0.0f;
//        currentFrame++;
//
//        if (currentFrame < naTex.size()) {
//            if (sprite) {
//                sprite->setTexture(*naTex[currentFrame]);
//                sprite->setScale({ scaleX, scaleY });
//            }
//        }
//        else {
//            naCooldown = 0.2f;
//            isNormalAttacking = false;
//            normalAttack = false;
//            currentFrame = 0;
//        }
//    }
//}
//
//void Character::setPosition(float x, float y) {
//    if (sprite) {
//        sprite->setPosition({ x, y });
//    }
//}
//
//sf::Vector2f Character::getSize() const {
//    if (sprite) {
//        return { sprite->getGlobalBounds().size.x, sprite->getGlobalBounds().size.y };
//    }
//    return { 0.f, 0.f };
//}
//
//void Character::draw(RenderWindow& window) {
//    if (sprite) {
//        window.draw(*sprite);
//    }
//}


Character::Character(const std::string& folderRight, const std::string& folderLeft,
    const std::string& folderAttackRight, const std::string& folderAttackLeft,
    const std::string& folderNARight, const std::string& folderNALeft,
    int totalFrames, int attackFrames, int naFrames)
    : currentFrame(0), timeSinceLastFrame(0.0f), scaleX(0.5f), scaleY(0.5f),
    isAttacking(false), normalAttacking(false), attackCooldown(0.0f), naCooldown(0.0f),
    maxHealth(100), currentHealth(100), damageBuff(1.0f), damageReduction(0.0f),
    skillCooldown(0.0f), skillDuration(0.0f), facingRight(true), m_hasDealtDamage(false),
    isStunned(false) {

    loadTextures(folderRight, rightTextures, totalFrames);
    loadTextures(folderLeft, leftTextures, totalFrames);
    loadTextures(folderAttackRight, rightAttackTextures, attackFrames);
    loadTextures(folderAttackLeft, leftAttackTextures, attackFrames);
    loadTextures(folderNARight, rightNATextures, naFrames);
    loadTextures(folderNALeft, leftNATextures, naFrames);

    if (rightTextures.empty() || leftTextures.empty() || rightAttackTextures.empty() ||
        leftAttackTextures.empty() || rightNATextures.empty()) {
        throw runtime_error("Failed to load character animations!");
    }

    sprite = std::make_unique<sf::Sprite>(*rightTextures[0]);
    sprite->setScale({ scaleX, scaleY });
    baseFrameRate = 0.03f;
    frameRate = baseFrameRate;
    normalAttackFrameRate = 0.04f;
}

void Character::loadTextures(const std::string& folder, std::vector<std::unique_ptr<sf::Texture>>& textures, int totalFrames) {
    for (int i = 1; i <= totalFrames; ++i) {
        auto texture = std::make_unique<sf::Texture>();
        string filePath = folder + " (" + to_string(i) + ").png";
        if (texture->loadFromFile(filePath)) {
            texture->setSmooth(true);
            textures.push_back(move(texture));
        }
        else {
            cerr << "Failed to load texture: " << filePath << endl;
        }
    }
}

void Character::update(float deltaTime, bool isMoving, bool moveLeft, bool& attack, bool& normalAttack, float speed, bool isJumping) {
    // 更新技能状态
    if (skillCooldown > 0.0f) skillCooldown -= deltaTime;
    if (skillDuration > 0.0f) {
        skillDuration -= deltaTime;
        if (skillDuration <= 0.0f) {
            damageBuff = 1.0f;
            damageReduction = 0.0f;
        }
    }
    if(stunDuration > 0.0f) {
        stunDuration -= deltaTime;
        if (stunDuration <= 0.0f) {
            isStunned = false;
        }
    }

    if (attack && attackCooldown <= 0.0f && !isJumping) {
        if (!isAttacking) {
            isAttacking = true;
            currentFrame = 0;
        }
        updateAttackAnimation(deltaTime, attack);
        return;
    }

    if (normalAttack && naCooldown <= 0.0f && !isAttacking) {
        if (!isNormalAttacking()) {
            normalAttacking = true;
            currentFrame = 0;
        }
        updateNormalAttackAnimation(deltaTime, normalAttack);
        return;
    }

    if (attackCooldown > 0.0f) attackCooldown -= deltaTime;
    if (naCooldown > 0.0f) naCooldown -= deltaTime;

    if (isMoving && !isAttacking && !isNormalAttacking()) {
        facingRight = !moveLeft;
        frameRate = baseFrameRate;
        timeSinceLastFrame += deltaTime;

        if (timeSinceLastFrame >= frameRate) {
            timeSinceLastFrame = 0.0f;
            currentFrame = (currentFrame + 1) % rightTextures.size();
            if (sprite) {
                sprite->setTexture(*(isFacingRight() ? rightTextures : leftTextures)[currentFrame]);
            }
        }
    }
    else if (!isAttacking && !isNormalAttacking()) {
        if (sprite) {
            sprite->setTexture(*(isFacingRight() ? rightTextures : leftTextures)[0]);
        }
    }
}

void Character::updateAttackAnimation(float deltaTime, bool& attack) {
    frameRate = 0.05f;
    timeSinceLastFrame += deltaTime;
    auto& attackTex = isFacingRight() ? rightAttackTextures : leftAttackTextures;

    if (timeSinceLastFrame >= frameRate) {
        timeSinceLastFrame = 0.0f;
        currentFrame++;

        if (currentFrame < attackTex.size()) {
            if (sprite) {
                sprite->setTexture(*attackTex[currentFrame]);
                sprite->setScale({ scaleX, scaleY });
            }
        }
        else {
            attackCooldown = 0.3f;
            isAttacking = false;
            attack = false;
            currentFrame = 0;
        }
    }
}

void Character::updateNormalAttackAnimation(float deltaTime, bool& normalAttack) {
    frameRate = normalAttackFrameRate;
    timeSinceLastFrame += deltaTime;
    auto& naTex = isFacingRight() ? rightNATextures : leftNATextures;

    if (timeSinceLastFrame >= frameRate) {
        timeSinceLastFrame = 0.0f;
        currentFrame++;

        if (currentFrame < naTex.size()) {
            if (sprite) {
                sprite->setTexture(*naTex[currentFrame]);
                sprite->setScale({ scaleX, scaleY });
            }
        }
        else {
            naCooldown = 0.2f;
            normalAttacking = false;
            normalAttack = false;
            currentFrame = 0;
        }
    }
}

void Character::setPosition(float x, float y) {
    if (sprite) {
        sprite->setPosition({ x, y });
    }
}

sf::Vector2f Character::getSize() const {
    if (sprite) {
        return { sprite->getGlobalBounds().size.x, sprite->getGlobalBounds().size.y };
    }
    return { 0.f, 0.f };
}

void Character::draw(RenderWindow& window) {
    if (sprite) {
        window.draw(*sprite);
    }
}

int Character::getCurrentHealth() const {
    return currentHealth;
}

void Character::takeDamage(int damage) {
    currentHealth -= static_cast<int>(damage * (1.0f - damageReduction));
    if (currentHealth < 0) currentHealth = 0;
}

void Character::heal(int amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) currentHealth = maxHealth;
}




void Character::setDamageBuff(float buff) {
    this->damageBuff = buff;
}

void Character::setDamageReduction(float reduction) {
    this->damageReduction = reduction;
}

void Character::setSkillDuration(float duration) {
    this->skillDuration = duration;
}

float Character::getDamageBuff() const {
    return damageBuff;
}

float Character::getDamageReduction() const {
    return damageReduction;
}

float Character::getSkillDuration() const {
    return skillDuration;
}

bool Character::isFacingRight() const {
    return facingRight;
}


sf::Rect<float> Character::getGlobalBounds() const {
    if (sprite) {
        return sprite->getGlobalBounds();
    }
    return sf::Rect<float>({ 0.f, 0.f }, { 0.f, 0.f });
}

bool Character::isNormalAttacking() const {
    return normalAttacking;
}

int Character::getCurrentFrame() const {
    return currentFrame;
}

bool Character::hasDealtDamage() const {
    return m_hasDealtDamage;
}

void Character::setHasDealtDamage(bool value) {
    m_hasDealtDamage = value;
}

void Character::setStunDuration(float duration) {
    this->stunDuration = duration;
}

float Character::getStunDuration() const {
    return this->stunDuration;
}

void Character::setIsStunned(bool value) {
    this->isStunned = value;
}

bool Character::getIsStunned() const {
    return this->isStunned;
}

void Character::reset() {
    // 动画相关
    currentFrame = 0;
    timeSinceLastFrame = 0.0f;
    frameRate = baseFrameRate;  // 恢复基础帧率
    isAttacking = false;
    normalAttacking = false;
    attackCooldown = 0.0f;
    naCooldown = 0.0f;

    // 方向与位置（根据需要设置）
    facingRight = true;

    // 血量
    currentHealth = maxHealth;

    // 状态效果
    damageBuff = 1.0f;
    damageReduction = 0.0f;
    skillDuration = 0.0f;

    // 受击判定
    m_hasDealtDamage = false;

    // 控制状态
    isStunned = false;
    stunDuration = 0.0f;

    // 如果有 sprite，可以重设纹理为默认站立帧
    if (!rightTextures.empty()) {
        sprite->setTexture(*rightTextures[0]);  // 设置为第一个站立帧
    }
}