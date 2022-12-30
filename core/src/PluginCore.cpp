#include "PluginCore.hpp"
#include "ComponentFactory.hpp"
#include "SerializableObjectFactory.hpp"
#include "polymorph/engine/api/plugin/Symbols.hpp"

namespace polymorph::engine::api
{
    PluginCore::PluginCore(config::XmlNode &data, Engine &game,
                           std::string PluginsPath)
            : APlugin(data, game, PluginsPath), _inputHandler(game.getPluginManager())
    {

    }
    void PluginCore::preUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        _inputHandler.update(scene);
    }

    void PluginCore::updateInternalSystems(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::postUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::startScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::endScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::createConfig(std::vector<std::shared_ptr<APluginConfig>> &configs)
    {
    }

    std::unique_ptr<AComponentFactory> PluginCore::createComponentFactory()
    {
        return std::unique_ptr<AComponentFactory>(new ComponentFactory());
    }

    std::unique_ptr<ASerializableObjectFactory> PluginCore::createSerializableObjectFactory()
    {
        return std::unique_ptr<ASerializableObjectFactory>(new SerializableObjectFactory());
    }
}

EXPORT_MODULE polymorph::engine::api::APlugin *createPlugin(polymorph::engine::config::XmlNode &data,
                                                            polymorph::engine::Engine &game, std::string PluginsPath)
{
    return new polymorph::engine::api::PluginCore(data, game, std::move(PluginsPath));
}