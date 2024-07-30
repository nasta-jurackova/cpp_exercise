#include "INode.hpp"

#include <vector>
#include <iostream>

class Node: public INode
{
    std::vector<std::shared_ptr<INode>> children = {};
    std::size_t count_children = 0;
    std::size_t id;

    public:
    static std::size_t curr_id;

    Node(std::size_t id):
    id(id)
    {}

    std::size_t successor_count() const
    {
        return count_children;
    }

    std::shared_ptr<INode> successor(std::size_t idx) const
    {
        return children[idx];
    }

    std::size_t add_successor(std::shared_ptr<INode> node)
    {
        children.push_back(node);
        count_children++;
    }

    std::size_t print_me() const
    {
        std::cout << id << '\n';
        return id;
    }
};

Node::curr_id = 0;

std::unique_ptr<INode> create_node()
{
    Node::curr_id++;
    return Node(Node::curr_id);
}
