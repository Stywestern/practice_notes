// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_HPP_
#define TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_Goal __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_Goal __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_Goal_
{
  using Type = RotateTurret_Goal_<ContainerAllocator>;

  explicit RotateTurret_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_angle = 0.0;
    }
  }

  explicit RotateTurret_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_angle = 0.0;
    }
  }

  // field types and members
  using _target_angle_type =
    double;
  _target_angle_type target_angle;

  // setters for named parameter idiom
  Type & set__target_angle(
    const double & _arg)
  {
    this->target_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_Goal
    std::shared_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_Goal
    std::shared_ptr<turret_control::action::RotateTurret_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_Goal_ & other) const
  {
    if (this->target_angle != other.target_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_Goal_

// alias to use template instance with default allocator
using RotateTurret_Goal =
  turret_control::action::RotateTurret_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control


#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_Result __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_Result __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_Result_
{
  using Type = RotateTurret_Result_<ContainerAllocator>;

  explicit RotateTurret_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_message = "";
    }
  }

  explicit RotateTurret_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_message = "";
    }
  }

  // field types and members
  using _result_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_message_type result_message;

  // setters for named parameter idiom
  Type & set__result_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_Result
    std::shared_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_Result
    std::shared_ptr<turret_control::action::RotateTurret_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_Result_ & other) const
  {
    if (this->result_message != other.result_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_Result_

// alias to use template instance with default allocator
using RotateTurret_Result =
  turret_control::action::RotateTurret_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control


#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_Feedback __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_Feedback_
{
  using Type = RotateTurret_Feedback_<ContainerAllocator>;

  explicit RotateTurret_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_angle = 0.0;
    }
  }

  explicit RotateTurret_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_angle = 0.0;
    }
  }

  // field types and members
  using _current_angle_type =
    double;
  _current_angle_type current_angle;

  // setters for named parameter idiom
  Type & set__current_angle(
    const double & _arg)
  {
    this->current_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_Feedback
    std::shared_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_Feedback
    std::shared_ptr<turret_control::action::RotateTurret_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_Feedback_ & other) const
  {
    if (this->current_angle != other.current_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_Feedback_

// alias to use template instance with default allocator
using RotateTurret_Feedback =
  turret_control::action::RotateTurret_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "turret_control/action/detail/rotate_turret__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_SendGoal_Request __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_SendGoal_Request_
{
  using Type = RotateTurret_SendGoal_Request_<ContainerAllocator>;

  explicit RotateTurret_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit RotateTurret_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    turret_control::action::RotateTurret_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const turret_control::action::RotateTurret_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_SendGoal_Request
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_SendGoal_Request
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_SendGoal_Request_

// alias to use template instance with default allocator
using RotateTurret_SendGoal_Request =
  turret_control::action::RotateTurret_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_SendGoal_Response __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_SendGoal_Response_
{
  using Type = RotateTurret_SendGoal_Response_<ContainerAllocator>;

  explicit RotateTurret_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit RotateTurret_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_SendGoal_Response
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_SendGoal_Response
    std::shared_ptr<turret_control::action::RotateTurret_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_SendGoal_Response_

// alias to use template instance with default allocator
using RotateTurret_SendGoal_Response =
  turret_control::action::RotateTurret_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control

namespace turret_control
{

namespace action
{

struct RotateTurret_SendGoal
{
  using Request = turret_control::action::RotateTurret_SendGoal_Request;
  using Response = turret_control::action::RotateTurret_SendGoal_Response;
};

}  // namespace action

}  // namespace turret_control


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_GetResult_Request __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_GetResult_Request_
{
  using Type = RotateTurret_GetResult_Request_<ContainerAllocator>;

  explicit RotateTurret_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit RotateTurret_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_GetResult_Request
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_GetResult_Request
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_GetResult_Request_

// alias to use template instance with default allocator
using RotateTurret_GetResult_Request =
  turret_control::action::RotateTurret_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control


// Include directives for member types
// Member 'result'
// already included above
// #include "turret_control/action/detail/rotate_turret__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_GetResult_Response __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_GetResult_Response_
{
  using Type = RotateTurret_GetResult_Response_<ContainerAllocator>;

  explicit RotateTurret_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit RotateTurret_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    turret_control::action::RotateTurret_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const turret_control::action::RotateTurret_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_GetResult_Response
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_GetResult_Response
    std::shared_ptr<turret_control::action::RotateTurret_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_GetResult_Response_

// alias to use template instance with default allocator
using RotateTurret_GetResult_Response =
  turret_control::action::RotateTurret_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control

namespace turret_control
{

namespace action
{

struct RotateTurret_GetResult
{
  using Request = turret_control::action::RotateTurret_GetResult_Request;
  using Response = turret_control::action::RotateTurret_GetResult_Response;
};

}  // namespace action

}  // namespace turret_control


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "turret_control/action/detail/rotate_turret__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__turret_control__action__RotateTurret_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__turret_control__action__RotateTurret_FeedbackMessage __declspec(deprecated)
#endif

namespace turret_control
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RotateTurret_FeedbackMessage_
{
  using Type = RotateTurret_FeedbackMessage_<ContainerAllocator>;

  explicit RotateTurret_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit RotateTurret_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    turret_control::action::RotateTurret_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const turret_control::action::RotateTurret_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turret_control__action__RotateTurret_FeedbackMessage
    std::shared_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turret_control__action__RotateTurret_FeedbackMessage
    std::shared_ptr<turret_control::action::RotateTurret_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RotateTurret_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const RotateTurret_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RotateTurret_FeedbackMessage_

// alias to use template instance with default allocator
using RotateTurret_FeedbackMessage =
  turret_control::action::RotateTurret_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace turret_control

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace turret_control
{

namespace action
{

struct RotateTurret
{
  /// The goal message defined in the action definition.
  using Goal = turret_control::action::RotateTurret_Goal;
  /// The result message defined in the action definition.
  using Result = turret_control::action::RotateTurret_Result;
  /// The feedback message defined in the action definition.
  using Feedback = turret_control::action::RotateTurret_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = turret_control::action::RotateTurret_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = turret_control::action::RotateTurret_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = turret_control::action::RotateTurret_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct RotateTurret RotateTurret;

}  // namespace action

}  // namespace turret_control

#endif  // TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_HPP_
