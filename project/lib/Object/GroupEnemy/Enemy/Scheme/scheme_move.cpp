//
// Created by mikhail on 22.12.23.
//

#include "scheme_move.h"
#include <chrono>
#include <queue>
#include <set>

SchemeMove::SchemeMove(Field& field, Manage& manage) : field(field), manage(manage), coord({0, 0}), point(0) {}
SchemeMove::SchemeMove(Field& field, Manage& manage, Tuple<unsigned> coord) : field(field), manage(manage), coord(std::move(coord)), point(0) {}

Tuple<unsigned> SchemeMove::get_offset_coord(Tuple<unsigned> cell_coord) {
    std::set<std::pair<int, int>> passed_cells;
    auto comp = [](const std::vector<std::pair<int, int>>& t1, const std::vector<std::pair<int, int>>& t2) {
        if ((t1[2].second + t1[2].first) == (t2[2].second + t2[2].first)) {
            if (t1[2].second == t2[2].second)
                return t1[2].first > t2[2].first;
            return t1[2].second > t2[2].second;
        }
        return (t1[2].second + t1[2].first) > (t2[2].second + t2[2].first);
    };

    std::priority_queue<std::vector<std::pair<int, int>>, std::vector<std::vector<std::pair<int, int>>>, decltype(comp)> pq(comp);
    pq.push({{manage.get_coord_cell()[0], manage.get_coord_cell()[1]}, {manage.get_coord_cell()[0], manage.get_coord_cell()[1]}, {0, 0}});
    while (!pq.empty()) {
        std::vector<std::pair<int, int>> cell = pq.top();
        if (cell[0].first == cell_coord[0] && cell[0].second == cell_coord[1])
            return {static_cast<unsigned>(cell[1].first) - cell_coord[0],
                    static_cast<unsigned>(cell[1].second) - cell_coord[1]};
        pq.pop();

        std::vector<std::pair<int, int>> nearby_coords {
                {cell[0].first, cell[0].second - 1},
                {cell[0].first - 1, cell[0].second},
                {cell[0].first, cell[0].second + 1},
                {cell[0].first + 1, cell[0].second},
        };

        passed_cells.insert(cell[0]);
        for (const auto& nearby_coord : nearby_coords)
            if (this->field.get_cell({static_cast<unsigned>(nearby_coord.first), static_cast<unsigned>(nearby_coord.second)}).is_passability())
                if (passed_cells.find(nearby_coord) == passed_cells.end())
                    pq.push({nearby_coord, cell[0],
                             {10, abs(nearby_coord.first - cell_coord[0]) + abs(nearby_coord.second - cell_coord[1])}});
    }

    return {0, 0};
}

bool SchemeMove::move() {
    if (this->point)
        this->point--;
    else {
        this->coord += this->get_offset_coord({(this->coord[0] + 15) / 32, (this->coord[1] + 15) / 32});
        this->point = 2;
    }
}

Tuple<unsigned> SchemeMove::get_position() { return this->coord; }

size_t SchemeMove::get_id() { return typeid(*this).hash_code(); }