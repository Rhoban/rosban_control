#pragma once

#include <ros/ros.h>

#include <map>
#include <vector>

/// This class provides an easy way to send command to multiples controllers
/// - Publishers to controller topics are initialized at object creation
/// - Controllers must be drived by a single 'command', std_msgs::Float64
/// 
/// Controllers are referenced by a unique name which is not required to be the
/// same as the name of the topic.
/// Name of the topic is chosen at object creation.
/// 
class ControlBridge
{
private:
  std::map<std::string,ros::Publisher> publishers;

public:

  /// Published topic for every name in names is:
  /// - prefix + name + suffix + "/command"
  ControlBridge(ros::NodeHandle &nh,
                const std::vector<std::string> &names,
                const std::string &prefix = "/",
                const std::string &suffix = "_controller");
  void send(const std::map<std::string, double> &values);
};
