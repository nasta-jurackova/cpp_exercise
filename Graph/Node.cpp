#include "INode.hpp"

#include <vector>
#include <iostream>
#include <memory>

class Node: public INode
{
    std::vector<std::shared_ptr<INode>> children = {};
    std::size_t count_children = 0;
    std::size_t _id;

    public:
    static std::size_t curr_id;

    Node(std::size_t id):
    _id(id)
    {}

    std::size_t successor_count() const override
    {
        return count_children;
    }

    std::shared_ptr<INode> successor(std::size_t idx) const override
    {
        return children[idx];
    }

    std::size_t add_successor(std::shared_ptr<INode> node) override
    {
        children.push_back(node);
        count_children++;
    }

    std::size_t print_me() const override
    {
        std::cout << _id << '\n';
        return _id;
    }

    std::size_t id() const override
    {
        return _id;
    }
};

std::size_t Node::curr_id = 0;

std::unique_ptr<INode> create_node()
{
    Node::curr_id++;
    return std::make_unique<Node>(Node::curr_id);
}
