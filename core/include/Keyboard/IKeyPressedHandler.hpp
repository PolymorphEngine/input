/*
** EPITECH PROJECT, 2020
** IKeyPressedHandler.hpp
** File description:
** header for IKeyPressedHandler.c
*/

#ifndef INPUT_IKEYPRESSEDHANDLER_HPP
#define INPUT_IKEYPRESSEDHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"


namespace polymorph::engine::event
{
    enum KeyCode : int;
    class IKeyPressedHandler
    {
        public:
            virtual ~IKeyPressedHandler() = default;
            virtual void onKeyPressed(KeyCode code) = 0;
    };
}
#endif //INPUT_IKEYPRESSEDHANDLER_HPP
