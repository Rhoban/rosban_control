#include "control_bridge.hpp"

#include "std_msgs/Float64.h"

ControlBridge::ControlBridge(ros::NodeHandle &nh,
                               const std::vector<std::string>& names,
                               const std::string &prefix,
                               const std::string &suffix)
{
  for (const std::string &name : names) {
    std::string topicName = prefix + name + suffix + "/command";
    std::cout << "publishing at " << topicName << std::endl;
    publishers[name] = nh.advertise<std_msgs::Float64>(topicName, 0);
  }
}

void ControlBridge::send(const std::map<std::string, double> &entries)
{
  for (const auto &e : entries) {
    std_msgs::Float64 msg;
    msg.data = e.second;
    publishers.at(e.first).publish(msg);
  }
}
