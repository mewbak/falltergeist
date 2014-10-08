/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// C++ standard includes
#include <iostream>

// Falltergeist includes
#include "../../Engine/Graphics/AnimationQueue.h"
#include "../../Engine/Graphics/Animation.h"

// Third party includes

namespace Falltergeist
{

AnimationQueue::AnimationQueue() : ActiveUI()
{
}

AnimationQueue::~AnimationQueue()
{
    clear();
}

std::vector<Animation*>* AnimationQueue::animations()
{
    return &_animations;
}

void AnimationQueue::clear()
{
    while (!_animations.empty())
    {
        delete _animations.back();
        _animations.pop_back();
    }
}

void AnimationQueue::stop()
{
    _playing = false;
    _currentAnimation = 0;
}

void AnimationQueue::pause()
{
    _playing = false;
}

void AnimationQueue::start()
{
    _playing = true;
}

void AnimationQueue::setRepeat(bool value)
{
    _repeat = value;
}

void AnimationQueue::render()
{
    currentAnimation()->setX(this->x());
    currentAnimation()->setY(this->y());
    currentAnimation()->render();
}

void AnimationQueue::think()
{
    if (_playing)
    {
        currentAnimation()->think();
    }
}

Texture* AnimationQueue::texture()
{
    return currentAnimation()->texture();
}

unsigned int AnimationQueue::pixel(unsigned int x, unsigned int y)
{
    currentAnimation()->setX(this->x());
    currentAnimation()->setY(this->y());
    return currentAnimation()->pixel(x, y);
}

Animation* AnimationQueue::currentAnimation()
{
    return _animations.at(_currentAnimation);
}

unsigned int AnimationQueue::width()
{
    return currentAnimation()->width();
}

unsigned int AnimationQueue::height()
{
    return currentAnimation()->height();
}

int AnimationQueue::xOffset()
{
    return currentAnimation()->xOffset();
}

int AnimationQueue::yOffset()
{
    return currentAnimation()->yOffset();
}

}
