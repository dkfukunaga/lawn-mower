#ifndef MOWER_H
#define MOWER_H

#include "coordinates.h"
#include "square.h"
#include "facing.h"
#include "lawn.h"
#include <random>
#include <string>


class Mower {
public:
    Mower(Lawn& lawn, Coordinates position, Facing::Direction facing):
        lawn_(lawn),
        position_(position),
        facing_(facing) {
        resetStats();
    };
    Mower(Lawn& lawn, Coordinates position):
    lawn_(lawn),
    position_(position) {
        facing_ = getRandomDirection();
        resetStats();
    };
    Mower(Lawn& lawn):
    lawn_(lawn) {
        position_ = Coordinates{1, 1};
        facing_ = getRandomDirection();
        resetStats();
    };

    SquareType          peek();
    bool                forward();
    void                turnRight();
    void                turnLeft();

    void                resetStats();
    bool                setPosition(Coordinates position);
    void                setFacing(Facing::Direction facing);

    Coordinates         getPosition() const;
    Facing::Direction   getFacing() const;
    int                 getPeeks() const;
    int                 getSteps() const;
    int                 getTurns() const;
    std::string         getMowerString() const;
    std::string         getFacingString() const;
private:
    Lawn&               lawn_;
    Coordinates         position_;
    Facing::Direction   facing_;
    int                 peeks_;
    int                 steps_;
    int                 turns_;

    const std::string   MOWER_STRINGS[4] = {"^", ">", "v", "<"};

    Facing::Direction   getRandomDirection() const;
    bool                isValidPosition(Coordinates position) const;
};





#endif