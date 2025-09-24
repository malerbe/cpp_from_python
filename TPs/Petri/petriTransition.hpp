#pragma once

#include <utility> // for std::pair
#include <vector>
#include <string>

#include <petriPool.hpp> // For talking about pools.

namespace petri {
  using slot = std::pair<pool_ref, unsigned int>;
 
  struct Transition {
    std::string       name;
    std::vector<slot> inputs;
    std::vector<slot> outputs;
    Transition(const std::string& name, const std::vector<slot>& inputs, const std::vector<slot>& outputs);
    bool is_activable();
    void activate();
    operator bool();
    void operator()();
  };

  

  std::ostream& operator<<(std::ostream& os, Transition t);
}

