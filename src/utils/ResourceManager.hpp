#ifndef GAME_RESOURCEMANAGER_HPP
#define GAME_RESOURCEMANAGER_HPP

#include "defines.hpp"

template<typename T>
class ResourceManager {
public:
    ResourceManager() : currentId(0) {

    }

    int add(const std::string &filepath) {
        auto it = resources.find(filepath);
        if (it != resources.end()) {
            return it->second.first;
        }

        std::shared_ptr<T> resource = std::make_shared<T>();
        if (!resource->loadFromFile(filepath)) {
            return -1;
        }
        resources.insert(std::make_pair(filepath, std::make_pair(currentId, resource)));
        return currentId++;
    }

    void remove(int id) {
        for (auto it = resources.begin(); it != resources.end(); it++) {
            if (it->second.first == id) {
                resources.erase(it->first);
            }
        }
    }

    std::shared_ptr<T> get(int id) {
        for (auto it = resources.begin(); it != resources.end(); it++) {
            if (it->second.first == id) {
                return it->second.second;
            }
        }
        return nullptr;
    }

    bool has(int id) {
        return get(id) != nullptr;
    }

private:
    unsigned int currentId;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};


#endif //GAME_RESOURCEMANAGER_HPP
