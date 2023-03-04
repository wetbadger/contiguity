#include "contiguity.h"

Contiguity::Contiguity() {}

// Define a function to determine if a shape is contiguous or not
bool Contiguity::isContiguous(Vector2 startingPoint) {
    // Initialize a stack for the depth-first search
    std::vector<std::pair<int, int>> stack;
    // Push the starting point onto the stack
    std::pair<int, int> sp = std::make_pair(startingPoint.x, startingPoint.y);
    stack.push_back(sp);
    // Initialize a variable to keep track of the number of points visited
    unsigned int visited = 0;
    // While the stack is not empty
    while (!stack.empty()) {

        // Pop the top element from the stack
        std::pair<int, int> current = stack.back();
        stack.pop_back();

        // If the current point has not been visited yet
        if (!shape.at(current)) {

            // Mark the point as visited
            shape.at(current) = true;
            // Increment the number of points visited
            visited++;
            // Add all contiguous points to the stack
            if (shape.count({current.first + 1, current.second})) stack.push_back({current.first + 1, current.second});
            if (shape.count({current.first - 1, current.second})) stack.push_back({current.first - 1, current.second});
            if (shape.count({current.first, current.second + 1})) stack.push_back({current.first, current.second + 1});
            if (shape.count({current.first, current.second - 1})) stack.push_back({current.first, current.second - 1});
        }
    }

    // Set all values in the map to unvisited.
    std::for_each(shape.begin(), shape.end(), [](auto& pair){ pair.second = false; });

    // Return true if all points have been visited, false otherwise
    return visited == shape.size();
}

// add a point to the set
void Contiguity::addPoint(Vector2 p)
{
    std::pair<int, int> newPoint = std::make_pair(p.x, p.y);
    shape.insert({newPoint, false});
}

// remove a point from the set
void Contiguity::removePoint(Vector2 p)
{
    std::pair<int, int> newPoint = std::make_pair(p.x, p.y);
    shape.erase(newPoint);
}

void Contiguity::_bind_methods() {
    ClassDB::bind_method(D_METHOD("addPoint", "p"), &Contiguity::addPoint);
    ClassDB::bind_method(D_METHOD("removePoint", "p"), &Contiguity::removePoint);
    ClassDB::bind_method(D_METHOD("isContiguous", "startingPoint"), &Contiguity::isContiguous);
}
