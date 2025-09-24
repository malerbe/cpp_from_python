#include <petriNetwork.hpp>

petri::Network::Network(unsigned int seed)
  : gen(seed) {
}

bool petri::Network::is_activable() {
  for(size_t i = 0; i < this->transitions.size(); ++i) {
    if (this->transitions[i]) {
      return true;
    }
  }
  std::cout << this->transitions[0] << std::endl;
  std::cout << (this->transitions[0] == true) << std::endl;
  return false;
}

petri::Network::operator bool() {
  return (*this).is_activable();
}

std::vector<int> petri::Network::get_activable_transactions() {
  std::vector<int> activable_transactions;
  int a = 0;  
  for(size_t i = 0; i < this->transitions.size(); ++i) {
    if (this->transitions[i]) {
      activable_transactions.push_back(i);
    }
    a += 1;
  }

  return activable_transactions;
}

void petri::Network::activate(int transition_id) {
    (*this).transitions[transition_id].activate();
}

void petri::Network::operator()() {
  std::vector<int> activable_transactions = this->get_activable_transactions();

  if (activable_transactions.empty()) {
    std::cout << "No transition possbile." << std::endl;
    return;
  }

  std::uniform_int_distribution<int> dist(0, activable_transactions.size() - 1);

  int randint = dist(gen);
  
  (*this).activate(activable_transactions[randint]);

  std::cout << "Transition done: ";
  if(this->transition_verbosity) {
    for(size_t i = 0; i < this->transitions[activable_transactions[randint]].outputs.size(); ++i) {
      if((*(this->transitions[activable_transactions[randint]].outputs[i].first)).nb_tokens == 1) {
        std::cout << this->transitions[activable_transactions[randint]].name << std::endl;
      }
    }
  }
}

std::ostream& petri::operator<<(std::ostream& os, petri::Network N) {


    return os;
}