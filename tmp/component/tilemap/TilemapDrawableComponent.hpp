#ifndef GAME_TILEMAPDRAWABLECOMPONENT_HPP
#define GAME_TILEMAPDRAWABLECOMPONENT_HPP

#include "../DrawableComponent.hpp"
#include "constants.hpp"
#include "../Component.hpp"
#include "../../objects/Object.hpp"
#include "TilemapComponent.hpp"

using namespace TilemapConsts;

class TilemapDrawableComponent : public Component, public DrawableComponent {
public:
    TilemapDrawableComponent(Object *owner);

    void draw(Window &window) override;

    void load(const std::string &tilesheet_file, const std::string &tilesheet_picture);

private:
    class Tilesheet {
    public:
        explicit Tilesheet(const std::string &tmj_path, const std::string &png_path);

        const sf::Texture &getTexture() const;

        sf::Vector2f getTextureCoord(const int &idx) const;

    private:
        sf::Texture texture;
        int sheetWidth;
        int margin;
    };

    std::shared_ptr<Tilesheet> tileSheet;

    Map<sf::VertexArray> vertices;
};


#endif //GAME_TILEMAPDRAWABLECOMPONENT_HPP
