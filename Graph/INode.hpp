#pragma once

#include <memory>

class INode {
  public:
	virtual std::size_t successor_count() const = 0;
	virtual std::shared_ptr<INode> successor(std::size_t idx) const = 0;
	virtual std::size_t add_successor(std::shared_ptr<INode> node) = 0;

	virtual std::size_t print_me() const = 0;
};

inline std::unique_ptr<INode> create_node() { return nullptr; }