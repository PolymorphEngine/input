/*
** EPITECH PROJECT, 2020
** InputHandler.cpp
** File description:
** header for InputHandler.c
*/

#include "InputHandler.hpp"
#include "Keyboard/IKeyPressedHandler.hpp"
#include "Keyboard/IKeyboardHandler.hpp"
#include "Keyboard/IKeyReleaseHandler.hpp"
#include "Keyboard/IKeyDownHandler.hpp"
#include "Mouse/IMouseButtonReleasedHandler.hpp"
#include "Mouse/IMouseButtonPressedHandler.hpp"
#include "Mouse/IMouseButtonDownHandler.hpp"
#include "Mouse/IMouseHandler.hpp"
#include "PluginCore.hpp"

void polymorph::engine::event::InputHandler::update(std::shared_ptr<engine::Scene> &scene)
{
    keyboardUpdate(scene);
    mouseUpdate(scene);
}

void polymorph::engine::event::InputHandler::_broadcastKeyboardPressed(
    polymorph::engine::event::KeyboardEvent &event, std::shared_ptr<engine::Scene> &scene)
{
    for (auto &components: scene->getComponentsInScene<IKeyPressedHandler>())
    {
        try {
            components->onKeyPressed(event.key);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::_broadcastKeyboardReleased(
        polymorph::engine::event::KeyboardEvent &event,
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &components: scene->getComponentsInScene<IKeyReleasedHandler>())
    {
        try {
            components->onKeyReleased(event.key);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::_broadcastKeyboardDown(
        polymorph::engine::event::KeyboardEvent &event,
        std::shared_ptr<engine::Scene> &scene)
{

    for (auto &components: scene->getComponentsInScene<IKeyDownHandler>())
    {
        try {
            components->onKeyDown(event.key);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::_broadcastMouseButtonPressed(
        polymorph::engine::event::MouseEvent &event,
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &components: scene->getComponentsInScene<IMouseButtonPressedHandler>())
    {
        try {
            components->onMouseButtonPressed(event);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::_broadcastMouseButtonReleased(
        polymorph::engine::event::MouseEvent &event,
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &components: scene->getComponentsInScene<IMouseButtonReleasedHandler>())
    {
        try {
            components->onMouseButtonReleased(event);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::_broadcastMouseButtonDown(
        polymorph::engine::event::MouseEvent &event,
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &components: scene->getComponentsInScene<IMouseButtonDownHandler>())
    {
        try {
            components->onMouseButtonDown(event);
        } catch (std::runtime_error &e) {
            if (e.what() != std::string("Object reference not set to an instance"))
                throw e;
        } catch (debug::ExceptionLogger &e) {
            e.what();
        }

        //TODO: /!\ warning need to check engine exiting or scene loading !
    }
}

void polymorph::engine::event::InputHandler::keyboardUpdate(
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &ev: _input->getKeyboardEvents())
    {
        switch (ev.inputType)
        {
            case PRESSED:
                _broadcastKeyboardPressed(ev, scene);
                break;
            case RELEASED:
                _broadcastKeyboardReleased(ev, scene);
                break;
            case T_DOWN:
                _broadcastKeyboardDown(ev, scene);
                break;
            default:
                break;
        }
        for (auto &components: scene->getComponentsInScene<IKeyboardHandler>())
        {
            try {
                components->onKeyEvent(ev);
            } catch (std::runtime_error &e) {
                if (e.what() != std::string("Object reference not set to an instance"))
                    throw e;
            } catch (debug::ExceptionLogger &e) {
                e.what();
            }
            //TODO: /!\ warning need to check engine exiting or scene loading !
        }
    }
}

void polymorph::engine::event::InputHandler::mouseUpdate(
        std::shared_ptr<engine::Scene> &scene)
{
    for (auto &ev: _input->getMouseEvents())
    {
        
        switch (ev.inputType)
        {
            case PRESSED:
                _broadcastMouseButtonPressed(ev, scene);
                break;
            case RELEASED:
                _broadcastMouseButtonReleased(ev, scene);
                break;
            case T_DOWN:
                _broadcastMouseButtonDown(ev, scene);
                break;
            default:
                break;
        }
        for (auto &components: scene->getComponentsInScene<IMouseHandler>())
        {
            try {
                components->onMouseEvent(ev);
            } catch (std::runtime_error &e) {
                if (e.what() != std::string("Object reference not set to an instance"))
                    throw e;
            } catch (debug::ExceptionLogger &e) {
                e.what();
            }
            //TODO: /!\ warning need to check engine exiting or scene loading !
        }
    }
}

polymorph::engine::event::InputHandler::InputHandler(
        api::PluginManager &Plugins)
{
    _createInput = Plugins.getSymbol<Symbols::createInputDEF>(Symbols::createInput);
    if (_createInput != nullptr)
        _input = std::unique_ptr<IInput>(_createInput());
}
