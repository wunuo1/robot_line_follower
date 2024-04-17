#ifndef LINE_FOLLOWER_H_
#define LINE_FOLLOWER_H_

#include "rclcpp/rclcpp.hpp"
#include "ai_msgs/msg/perception_targets.hpp"

#include "order_interpreter.hpp"

class LineFolloerNode : public rclcpp::Node{
public:
    LineFolloerNode(const std::string &node_name, const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
    ~LineFolloerNode() override;

private:
    rclcpp::Subscription<ai_msgs::msg::PerceptionTargets>::SharedPtr point_subscriber_;
    void point_subscription_callback(const ai_msgs::msg::PerceptionTargets::SharedPtr point_msg);
    std::shared_ptr<OrderInterpreter> order_interpreter_;

};



#endif //LINE_FOLLOWER_H_