#pragma once

#include "control_config.h"

#include <ros/ros.h>

#include <map>
#include <mutex>

#include <sensor_msgs/JointState.h>

/// This class provides an easy way to listen to the status of multiple joints
/// - Subscriber to controller topic is initialized at object creation
/// - The topic should publish messages of type, sensor_msgs::JointState
///
/// The values are accessibles through a map from joint name to JointState
/// - Access to consistent values is provided
class JointListener
{
public:
  /// Units depend on the type of the joint (linear or angular), cf below
  class JointState{
  public:
    double pos;// [m]   or [rad]
    double vel;// [m/s] or [rad/s]
    double eff;// [N]   or [N m]
  };

  typedef std::map<std::string, JointState> StateMap;

private:
  ros::Subscriber subscriber;

  std::mutex statusLock;
  StateMap status;

  void receive(const sensor_msgs::JointState::ConstPtr &msg);

public:

  JointListener(ros::NodeHandle &nh,
                const std::string &topicName);

  std::map<std::string, JointState> getStatus();
};
