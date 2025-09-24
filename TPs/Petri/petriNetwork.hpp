#pragma once

#include <random>

#include <petriTransition.hpp> 

namespace petri {
  struct Network {
    std::mt19937 gen;   // random generator 
    std::vector<Transition> transitions;
    bool transition_verbosity;

    Network(unsigned int random_seed);
    Network() = delete; // We forbid the default construction.

    bool is_activable();
    operator bool();
    void activate(int transition_id);
    std::vector<int> get_activable_transactions();

    void operator()();
  };

  std::ostream& operator<<(std::ostream& os, Network N);
}
