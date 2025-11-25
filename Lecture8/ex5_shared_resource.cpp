#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Texture {
    std::string name;
public:
    Texture(std::string n) : name(n) { std::cout << "Texture '" << name << "' loaded.\n"; }
    ~Texture() { std::cout << "Texture '" << name << "' unloaded.\n"; }
    void draw() { std::cout << "Drawing " << name << "\n"; }
};

class Sprite {
    std::shared_ptr<Texture> texture;
public:
    Sprite(std::shared_ptr<Texture> t) : texture(t) {}
    
    void render() {
        if(texture) texture->draw();
    }
};

int main() {
    std::vector<Sprite> level_sprites;

    {
        std::cout << "--- Loading Assets ---\n";
        // 1. Create a Master Texture
        auto master_texture = std::make_shared<Texture>("PlayerSkin");
        
        std::cout << "Texture Use Count: " << master_texture.use_count() << "\n"; // Should be 1

        // 2. Create Sprites that use this texture
        level_sprites.push_back(Sprite(master_texture));
        level_sprites.push_back(Sprite(master_texture));
        level_sprites.push_back(Sprite(master_texture));

        std::cout << "Texture Use Count after sprites: " << master_texture.use_count() << "\n"; // Should be 4

        std::cout << "--- Master Pointer going out of scope ---\n";
    } // master_texture dies here, but the texture itself should live on because Sprites hold it.

    std::cout << "--- Doing Game Logic ---\n";
    // Check that texture is still alive
    level_sprites[0].render();

    std::cout << "--- Clearing Level ---\n";
    level_sprites.clear(); // All sprites die. Texture ref count drops to 0.

    std::cout << "--- End of Main ---\n";
    return 0;
}