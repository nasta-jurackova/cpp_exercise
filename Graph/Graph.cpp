#include "Graph.hpp"

std::shared_ptr<INode> Graph::get_root() const { return m_root; }

void Graph::print() const {
    if (m_root != nullptr)
        m_root->print_me();
}
