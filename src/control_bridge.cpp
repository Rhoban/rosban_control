#include "control_bridge.hpp"

#include "std_msgs/Float64.h"

control_bridge::control_bridge(ros::NodeHandle &nh,
                               const std::vector<std::string>& names,
                               const std::string &prefix,
                               const std::string &suffix)
{
  for (const std::string &name : names) {
    std::string topicName = prefix + name + suffix + "/command";
    publishers[name] = nh.advertise<std_msgs::Float64>(topicName, 0);
  }
}

void control_bridge::send(const std::map<std::string, double> &entries)
{
  for (const auto &e : entries) {
    std_msgs::Float64 msg;
    msg.data = e.second;
    publishers.at(e.first).publish(msg);
  }
}
