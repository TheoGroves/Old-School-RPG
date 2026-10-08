#include <vector>
#include <string>
#include <memory>
#include "game/character.h"

struct Connection;

class Location : public std::enable_shared_from_this<Location> {
public:
    Location(std::string name)
        : name(name)
    {}

    void display_connections();
    void connect(std::shared_ptr<Location> location, float distance);

    std::string get_display_name() const;

private:
    std::string name;
    std::vector<Connection> connections;
};

struct Connection {
    std::weak_ptr<Location> destination;
    float distance;
};