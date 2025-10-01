#include <iostream>
#include <iomanip>
#include <functional>
#include <memory>
#include <map>

#pragma once

namespace gate {

  using action_type = std::function<void ()>;
  using ref_action  = std::shared_ptr<action_type>;
  // using wref_action = std::week_ptr<action_type>; // ok, but prefer the following, it is nicer.
  using wref_action = ref_action::weak_type; 

  // Write all your code here
  // struct gate {
  //   double time;
  //   std::string name;
  //   bool status;

  //   gate(double time, std::string name, bool status) : time(time), name(name), status(status) {}
  
  // };

  ref_action action(action_type callable) {
    return std::make_shared<action_type>(callable);
  }

  void execute(ref_action ref_callable) {
    (*ref_callable)();

  }

  // WIRE:
  
  using _wire = std::pair<bool, std::vector<wref_action>>;
  using ref_wire = std::shared_ptr<_wire>;
  // using wref_action = std::week_ptr<action_type>; // ok, but prefer the following, it is nicer.
  using wref_wire = ref_wire::weak_type; 


  ref_wire wire() {
    return std::make_shared<_wire>(false, std::vector<wref_action>());
  }

 
  bool value(ref_wire wire_a) {
    return wire_a->first;
  }

  void link(ref_wire wire_a, ref_action gate_a) {
    auto out_trans_iter = std::back_inserter(wire_a->second);
    *(out_trans_iter++) = {gate_a};

  }

  void set(ref_wire wire_a, bool new_state) {

    if (wire_a->first != new_state) {
    
      wire_a->first = new_state;

      for (size_t i = 0; i < (wire_a->second).size(); ++i ){
        if (ref_action action = wire_a->second[i].lock()) {
          execute(action);

        }
      }
    }
  }

  // AGENDA:
  using _agenda = std::tuple<double, std::multimap<double, std::tuple<ref_wire, bool>>>;
  using ref_agenda = std::shared_ptr<_agenda>;

  ref_agenda agenda() {
    return std::make_shared<_agenda>(0, std::multimap<double, std::tuple<ref_wire, bool>>());
  }

  double now(ref_agenda agenda_a) {
    return std::get<0>(*agenda_a);
  }

  void notify(ref_agenda agenda_a, ref_wire wire_a, bool status, double duration) {
    std::get<1>(*agenda_a).insert({(now(agenda_a) + duration), {wire_a, status}});
  }

  bool next(ref_agenda agenda_a) {
    double& current_time = std::get<0>(*agenda_a);
    std::multimap<double, std::tuple<ref_wire, bool>> multimap = std::get<1>(*agenda_a);

    auto next_it = multimap.lower_bound(current_time + 0.01);
    
    if(next_it != multimap.end()) {
      current_time = next_it->first;

      auto p1 = multimap.equal_range(current_time);
      // (p1.first->second) me donne accès au tuple de l'élément du multimap

      while (p1.first->second != p1.second->second) {
        set(std::get<0>(p1.first->second), std::get<1>(p1.first->second));
        p1.first++;
      }

      return true;
    } else {
      return false;
    }
  }

  // DISPLAY FUNCTIONS:

  void ____() {
    std::cout.precision(2);
    std::cout << "+---------------+----------+----------+" << std::endl;
  }

  void ____display(double time, std::string name, bool status) {
    
    std::string str_status;
    if(status == 1) {
      str_status = "on";
    } else {
      str_status = "off";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << "|" << std::setw(15) << name << std::right << "|" << std::setw(10) << time << "|" << std::setw(10) << str_status << "|" << std::endl;
  }


}
