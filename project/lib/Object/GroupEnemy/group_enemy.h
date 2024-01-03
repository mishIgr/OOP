//
// Created by mikhail on 22.12.23.
//

#ifndef PROJECT_GROUP_ENEMY_H
#define PROJECT_GROUP_ENEMY_H

#include "Enemy/enemy.h"
#include <memory>
#include <vector>

struct GroupEnemy {

    template <typename T>
    void add(T&& obj) { this->objects.push_back(std::make_shared<Model<T>>(std::forward<T>(obj))); }

    void clear() { this->objects.clear(); }

    size_t size() { return objects.size(); }

    bool move() {
        bool f = true;
        for (auto& object : this->objects)
            f &= object->move();
        return f;
    }

    struct Concept {
        virtual ~Concept() {}
        virtual bool move() = 0;
        virtual bool interaction() = 0;
        virtual Tuple<unsigned> get_coord() = 0;
        virtual std::string get_loc_sprite() = 0;
        virtual size_t get_id() = 0;
    };

    template< typename T >
    struct Model : Concept {

        Model(const T& t) : object(t) {}
        bool move() { return object.move(); }
        bool interaction() { return object.interaction(); }
        Tuple<unsigned> get_coord() { return object.get_coord(); }
        std::string get_loc_sprite() { return object.get_loc_sprite(); }
        size_t get_id() { return object.det_id(); }

    private:

        T object;

    };

    auto begin() { return this->objects.begin(); }
    auto end() { return this->objects.end(); }

private:


    std::vector<std::shared_ptr<Concept>> objects;

};

#endif //PROJECT_GROUP_ENEMY_H
