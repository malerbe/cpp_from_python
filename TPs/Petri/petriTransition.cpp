#include <petriTransition.hpp>

// To be done
petri::Transition::Transition(
    const std::string& name,
    const std::vector<slot>& inputs,
    const std::vector<slot>& outputs
) : name(name), inputs(inputs), outputs(outputs) {
}

std::ostream& petri::operator<<(std::ostream& os, petri::Transition t) {

    os << "{";

    for (size_t i = 0; i<t.inputs.size(); ++i) {
        os << t.inputs[i].first << "/" << t.inputs[i].second << " ";
    }

    os << "----> " << t.name << " ----> ";

    for (size_t i = 0; i<t.outputs.size(); ++i) {
        os << t.outputs[i].first << "/" << t.outputs[i].second << " ";
    }

    os << "}";

    return os;
}

bool petri::Transition::is_activable() {
    for (size_t i = 0; i<this->inputs.size(); ++i) {
        if ((*(this->inputs[i].first)).nb_tokens < this->inputs[i].second) {
            return false;
        }
    }

    return true;
}

petri::Transition::operator bool() {
    return this->is_activable();
}

void petri::Transition::operator()() {
    return (*this).activate();
}

void petri::Transition::activate() {
    for (size_t i = 0; i<this->inputs.size(); ++i) {
        this->inputs[i].first->nb_tokens -= this->inputs[i].second;
    }

    for (size_t i = 0; i<this->outputs.size(); ++i) {
        this->outputs[i].first->nb_tokens += this->outputs[i].second;
    }

}