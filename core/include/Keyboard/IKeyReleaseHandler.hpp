/*
** EPITECH PROJECT, 2020
** IKeyReleaseHandler.hpp
** File description:
** header for IKeyReleaseHandler.c
*/

#ifndef INPUT_IKEYRELEASEHANDLER_HPP
#define INPUT_IKEYRELEASEHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"

namespace polymorph::engine::event
{
    enum KeyCode : int;

    class IKeyReleasedHandler
    {
        public:
            virtual ~IKeyReleasedHandler() = default;
            virtual void onKeyReleased(KeyCode code) = 0;
    };
}

#endif //INPUT_IKEYRELEASEHANDLER_HPP
