#include "joint_listener.hpp"

std::map<std::string, JointListener::JointState>
buildStatus(const sensor_msgs::JointState::ConstPtr &msg)
{
  std::map<std::string, JointListener::JointState> status;
  for (unsigned int i = 0; i < msg->name.size(); i++) {
    std::string name = msg->name[i];
    JointListener::JointState state;
    state.pos = msg->position[i];
    state.vel = msg->velocity[i];
    state.eff = msg->effort[i];
    status[name] = state;
  }
  return status;
}

JointListener::JointListener(ros::NodeHandle &nh,
                             const std::string &topicName)
{
  subscriber = nh.subscribe<sensor_msgs::JointState>(topicName, 1,
                                                     &JointListener::receive,
                                                     this);
}

void JointListener::receive(const sensor_msgs::JointState::ConstPtr &msg)
{
  statusLock.lock();
  status = buildStatus(msg);
  statusLock.unlock();
}

std::map<std::string, JointListener::JointState> JointListener::getStatus()
{
  statusLock.lock();
  auto copy = status;
  statusLock.unlock();
  return copy;
}
