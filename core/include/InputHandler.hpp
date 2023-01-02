/*
** EPITECH PROJECT, 2020
** InputHandler.hpp
** File description:
** header for InputHandler.c
*/


#pragma once


#include "polymorph/engine/event-modules.hpp"
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/core.hpp"

namespace polymorph::engine::event
{
    class InputHandler
    {
    
    ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            InputHandler(api::PluginManager &Plugins);
    
            ~InputHandler() = default;
    
    //////////////////////--------------------------/////////////////////////
    
    
    
    ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
    
    
        private:
            Symbols::createInputDEF _createInput = nullptr;
            std::unique_ptr<IInput> _input;
    
    //////////////////////--------------------------/////////////////////////
    
    
    
    /////////////////////////////// METHODS /////////////////////////////////
        public:
            void update(std::shared_ptr<engine::Scene> &scene);
            
            void keyboardUpdate(std::shared_ptr<engine::Scene> &scene);
            void mouseUpdate(std::shared_ptr<engine::Scene> &scene);
    
        private:
            void _broadcastKeyboardPressed(
                    KeyboardEvent &event, std::shared_ptr<engine::Scene> &scene);
    
            void _broadcastKeyboardReleased(
                    KeyboardEvent &event, std::shared_ptr<engine::Scene> &scene);
    
            void _broadcastKeyboardDown(
                    KeyboardEvent &event, std::shared_ptr<engine::Scene> &scene);
    
            void _broadcastMouseButtonPressed(
                    MouseEvent &event, std::shared_ptr<engine::Scene> &scene);
    
            void _broadcastMouseButtonReleased(
                    MouseEvent &event, std::shared_ptr<engine::Scene> &scene);
    
            void _broadcastMouseButtonDown(
                    MouseEvent &event, std::shared_ptr<engine::Scene> &scene);
    
    //////////////////////--------------------------/////////////////////////
    
    };
}
