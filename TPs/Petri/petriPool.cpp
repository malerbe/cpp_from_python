#include <petriPool.hpp>

// To be done
petri::Pool::Pool(const std::string& name, unsigned int nb_tokens)
    : name(name), nb_tokens(nb_tokens) {

}

petri::pool_ref petri::make_pool(const std::string& name, unsigned int nb_tokens) {

    petri::Pool* new_pool = new Pool(name, nb_tokens);

    // std::cout << "test " << new_pool->nb_tokens << std::endl;

    petri::pool_ref new_pool_ref(new_pool);

    // std::cout << "test " << (*new_pool_ref).nb_tokens << std::endl;

    return new_pool_ref;
}

std::ostream& petri::operator<<(std::ostream& os, pool_ref p) {

    os << "(" << (*p).name << ", " << (*p).nb_tokens << ")";

    return os;
}


bool petri::operator<(petri::pool_ref p, unsigned int required_number_of_tokens) {
    

    return ((*p).nb_tokens < required_number_of_tokens);
}