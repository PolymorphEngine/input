/*
** EPITECH PROJECT, 2020
** IKeyDownHandler.hpp
** File description:
** header for IKeyDownHandler.c
*/

#ifndef INPUT_IKEYDOWNHANDLER_HPP
#define INPUT_IKEYDOWNHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"

namespace polymorph::engine::event
{
    enum KeyCode : int;
    class IKeyDownHandler
    {
        public:
            virtual ~IKeyDownHandler() = default;
            virtual void onKeyDown(KeyCode code) = 0;
    };
}


#endif //INPUT_IKEYDOWNHANDLER_HPP
