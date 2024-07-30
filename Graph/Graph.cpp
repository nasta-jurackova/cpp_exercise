#include "Graph.hpp"

#include <map>

std::shared_ptr<INode> Graph::get_root() const { return m_root; }

void Graph::print() const {
    std::map<std::size_t, bool> seen;
    print_rec(m_root, seen);
}

void print_rec(std::shared_ptr<INode> node, std::map<std::size_t, bool> seen)
{
    if(node == nullptr)
        return;

    std::size_t id = node->print_me();
    seen[id] = true;
    for(std::size_t count = 0; count < node->successor_count(); count++)
    {
        std::shared_ptr<INode> curr = node->successor(count);
        if(seen.at(curr->id()) == false)
        {
            print_rec(curr, seen);
        }
    }
}
