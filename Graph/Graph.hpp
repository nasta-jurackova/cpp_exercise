#pragma once

#include "INode.hpp"
#include <vector>

class Graph {
  public:
	std::shared_ptr<INode> get_root() const;
    void print() const;

  private:
	std::shared_ptr<INode> m_root;
};