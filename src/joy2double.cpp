#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Float64.h>


geometry_msgs::Twist cmd_vel;
std_msgs::Float64 keyX, keyY, keyZ, rot1, rot2, rot3, rot4;

void joy_callback(const sensor_msgs::Joy& joy_msg) {
    keyX.data = -joy_msg.axes[0];
    keyY.data = joy_msg.axes[1];
    keyZ.data = joy_msg.axes[4];
    rot1.data = -joy_msg.axes[0];
    rot2.data = joy_msg.axes[1];
    rot3.data = joy_msg.axes[4];
    rot4.data = -joy_msg.axes[3];
    // ROS_INFO("%lf", cmd_vel.linear.x);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "basic_twist_publisher");
    ros::NodeHandle nh("");

    // publish
    // ros::Publisher cmd_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    ros::Publisher key_pubX = nh.advertise<std_msgs::Float64>("keyX", 1000);
    ros::Publisher key_pubY = nh.advertise<std_msgs::Float64>("keyY", 1000);
    ros::Publisher key_pubZ = nh.advertise<std_msgs::Float64>("keyZ", 1000);
    ros::Publisher rot_pub1 = nh.advertise<std_msgs::Float64>("rot1", 1000);
    ros::Publisher rot_pub2 = nh.advertise<std_msgs::Float64>("rot2", 1000);
    ros::Publisher rot_pub3 = nh.advertise<std_msgs::Float64>("rot3", 1000);
    ros::Publisher rot_pub4 = nh.advertise<std_msgs::Float64>("rot4", 1000);

    // subscriibe
    ros::Subscriber joy_sub = nh.subscribe("joy", 10, joy_callback);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
      // cmd_pub.publish(cmd_vel);
        key_pubX.publish(keyX);
        key_pubY.publish(keyY);
        key_pubZ.publish(keyZ);
        rot_pub1.publish(rot1);
        rot_pub2.publish(rot2);
        rot_pub3.publish(rot3);
        rot_pub4.publish(rot4);
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}